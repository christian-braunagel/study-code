# Lab 7: Continuous Delivery and Release Management

This lab turns a verified software build into a package that can be signed, versioned, released, and
distributed. Extend one project and one pipeline throughout the lab.

Distinguish a package (the distributable files)
from a release (a version, notes, and the decision to make packages available).
You do not need Kubernetes or a deployment server for this lab.

All the following sections of this lab are based on the following levels of difficulty:

🟢 **Simple**: A simple task that guides you step by step through the process and focuses on learning the basics. It should not take more than 15 minutes to finish.

🟡 **Moderate**: A task that states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30 minutes depending on your knowledge.

🔴 **Complex**: A difficult or longer task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours.

The starter is in [release_pipeline_project](release_pipeline_project/).
The [completed pipeline](solution/.gitlab-ci.yml) is provided for comparison after
finishing the exercises. Create `release_notes.md` for observations and answers.

## 🟢 Preparation: One Project for the Complete Lab

Copy the contents of `release_pipeline_project`, including its hidden files, to
the root of a new GitLab repository. Use that repository for every section.

```text
release_pipeline_project/
├── .gitignore
├── .gitlab-ci.yml
├── CMakeLists.txt
├── README.md
├── include/status_analyzer.hpp
├── src/main.cpp
├── src/status_analyzer.cpp
└── tests/status_analyzer_tests.cpp
```

The production library `analyzer_core` calculates an average and classifies load
values. Three GoogleTest tests check the average, the overload boundary at `80.0`,
and empty input. CMake builds the application and tests with GCC coverage enabled.

The starter pipeline builds the project, runs its tests, and measures coverage:

* `build_app` configures and builds using CMake and Make, then stores `build/`.
* `test_app` uses that build, runs CTest, and creates text and HTML coverage reports.
* Artifacts pass files to subsequent stages and expire after one week.

Later jobs automatically download artifacts from successful jobs in earlier
stages. No `needs`, caches, templates, or custom pipeline scripts are necessary.

Inspect the files, build and test locally using the project README, then commit
and push the starter. Verify both jobs and download their coverage reports.
The CI executable is a **Linux binary** built in `gcc:14`; run it in a compatible
Linux environment with the necessary runtime libraries. It is not a Windows
executable or a self-contained installer.

Answer in `release_notes.md`:

* Why must tests pass before packaging starts?
* Why should later stages reuse the existing build instead of recompiling?
* Which production lines remain uncovered, and why? The coverage filter includes
  `src/main.cpp`, which the unit tests do not execute.

## 🟢 Section I: Package the Verified Build

Packaging collects the executable, documentation, version
information, and test evidence into one distributable archive.

### 1. Extend the Pipeline

Extend `.gitlab-ci.yml` so that it packages the verified build. Write the job
yourself using the following requirements:

1. Add a `package` stage after `test`. Packaging must start only after the build
   and tests have succeeded.
2. Define a top-level variable named `APP_VERSION` with the value
   `$CI_COMMIT_SHORT_SHA`. This identifies branch packages by their source commit.
3. Create a job named `package_app` in the new stage. Use the `gcc:14` image and
   install `zip` in `before_script` using the same `apt-get` pattern as the
   existing jobs.
4. In `script`, create a staging directory with `package/bin/` for the executable
   and `package/reports/` for test evidence. Create a separate `dist/` directory
   for the finished archive.
5. Copy the existing outputs into the staging directory:
   * `build/status_analyzer_app` into `package/bin/`.
   * All files matching `coverage_report*` into `package/reports/`. Include the
     HTML report's supporting files so that it works after extraction.
   * The complete `build/Testing/` directory into `package/reports/`.
   * `README.md` into `package/`.
6. Write `$APP_VERSION` and the full `$CI_COMMIT_SHA` into `package/VERSION.txt`.
7. Recursively zip the `package/` directory into
   `dist/status-analyzer-$APP_VERSION.zip`. Check `zip --help` for the option
   that includes subdirectories.
8. Configure the job to store `dist/` as pipeline artifacts with an expiration
   of one week.

Use `mkdir -p` to create directories and `cp` to copy files. Copying a complete
directory requires recursive copying. GitLab downloads the previous stages'
artifacts automatically: `build_app` supplies the executable, and `test_app`
supplies CTest results and coverage reports. Reuse those files without rebuilding
or rerunning tests in the packaging job.

### 2. Verify the Package

Push the change, download the ZIP from the package job, and extract it. Check its
executable, README, version, full commit SHA, CTest results, and coverage reports.
Open the extracted HTML coverage report.

Answer in your notes:

* What is the difference between the executable and the package?
* How can you trace the package back to the source commit?
* Why should a failed test prevent a package from being created?

## 🟡 Section II: Sign the Package with SHA-256

A checksum detects changes; a signature also allows verification
using a trusted public key. Signing does not encrypt the package.

The private key will be a **randomly generated key stored in a file**. Arbitrary
random bytes are not a valid RSA private key. OpenSSL generates random key
material and writes a valid PEM file. `openssl dgst -sha256 -sign` hashes the ZIP
using SHA-256 and signs it using the private key.

### 1. Add Signing

Extend `.gitlab-ci.yml` with a signing job. Write it yourself using these requirements:

1. Add a `sign` stage after `package` and create a job named `sign_package`.
2. Use the `gcc:14` image and install `openssl` in `before_script`.
3. Generate a random 2048-bit RSA private key and save it as `private.pem` in the
   job's working directory. Keep it outside the package and `dist/` directories.
4. Derive the matching public key and save it as `dist/public.pem`.
5. Sign the existing `dist/status-analyzer-$APP_VERSION.zip` using SHA-256 and
   the private key. Save the detached signature alongside the ZIP as
   `dist/status-analyzer-$APP_VERSION.zip.sig`.
6. Verify the signature using the public key. A verification failure must fail
   the job. Do not modify or recreate the ZIP after signing it.
7. Remove the temporary private key once signing and verification are complete.
8. Store `dist/` as job artifacts with an expiration of one week. Include the ZIP,
   signature, and public key, but never the private key.

Use `openssl genpkey` to generate the key; its `-algorithm RSA`,
`-pkeyopt rsa_keygen_bits:2048`, and `-out` options control the algorithm, size,
and output file. Use `openssl pkey` with `-in`, `-pubout`, and `-out` to derive
the public key. For signing, investigate `openssl dgst` and its `-sha256`,
`-sign`, and `-out` options. The verification command in the next task shows
how to check the result.

The ZIP remains unchanged. The detached `.sig` file accompanies it, and
`public.pem` supports verification. The private key stays outside `dist/` and is
never uploaded. This first exercise generates a different key in every pipeline;
Section III changes that to a persistent signer identity.

### 2. Verify Integrity

Download and extract the signing artifacts. From the directory containing the ZIP,
signature, and public key, run this with your actual archive name:

```bash
openssl dgst -sha256 -verify public.pem -signature status-analyzer-VERSION.zip.sig status-analyzer-VERSION.zip
```

Expect `Verified OK`. Make a copy of the ZIP, append a byte to that copy, and verify
it using the original signature. Verification must fail.

Answer in your notes:

* What roles do SHA-256, the private key, and the public key play?
* Why is `sha256sum package.zip` alone not a digital signature?
* Why must a private key never appear in Git, packages, or job artifacts?
* Why must receivers obtain or validate the public key through a trusted channel,
  rather than trust any key downloaded alongside a package?
* Why is a new signing key in every pipeline unsuitable for releases?

## 🟡 Section III: Secret Management and a Vault

First reuse a key through a GitLab variable, then discuss how a
vault improves secret storage and access control.

### 1. Store the Private Key as a GitLab Variable

Generate a disposable teaching key locally, **outside your repository**. Reuse
the OpenSSL commands you developed in Section II to create a 2048-bit RSA private
key named `private.pem` and derive its public key as `public.pem`.

In **Settings > CI/CD > Variables**, create `SIGNING_PRIVATE_KEY`:

* Choose type **File** and paste the full private PEM content, including BEGIN/END
  lines and a final newline.
* Disable variable expansion and enable **Protect variable**.
* Protect the `v*` tag pattern in the repository's protected-tag settings and
  restrict who may create matching tags.
* Multiline PEM content generally cannot meet masked/hidden value requirements.
  A file variable is not automatically masked. Never print its contents into logs.

A file variable exposes a temporary **file path**, rather than the PEM text,
through `$SIGNING_PRIVATE_KEY`. Do not put the private key in YAML or Git. The
project `.gitignore` excludes PEM files as an additional safeguard.

Adapt your existing `sign_package` job:

1. Remove the command that generates a new private key on every pipeline run.
2. Check that `$SIGNING_PRIVATE_KEY` points to an existing file. Use `test -f`
   with the quoted variable so that a missing key fails the job.
3. Change the public-key derivation and signing commands to read from that file
   instead of `private.pem`.
4. Keep signature verification and the existing artifact configuration. Remove
   the cleanup command for the locally generated `private.pem`, which this job
   no longer creates.
5. Add a `rules` condition that includes the job only when `$CI_COMMIT_TAG` has a
   value. This predefined variable is set for tag pipelines.

Only protected refs receive the protected variable. Use protected `v*` tags for
signing; an unprotected tag cannot access the key. Branch pipelines still build,
test, and package, but skip signing.

Commit and push the pipeline, then create and push a test tag such as `v0.1.0`.
Check that signing succeeds and its public key matches your local public key.
Retain a trusted local public-key copy for later verification.

### 2. Discuss the Downsides

Answer before reading about external vaults:

* How is a CI/CD variable better than a private key in Git?
* Can a malicious job receiving the key still read or copy it?
* What do masked, hidden, and protected variables each protect against?
* Who can change the pipeline receiving the key? Why does code review matter?
* How would you rotate or revoke a key used across several projects?
* **How could you improve this design using a vault?**

### 3. Design a Vault-Based Improvement

Read the [external secrets overview](https://docs.gitlab.com/ci/secrets/) and
[HashiCorp Vault integration](https://docs.gitlab.com/ci/secrets/hashicorp_vault/).
Design an alternative to the GitLab file variable and document it in your notes:

1. Draw the signing job, Vault, and the package outputs. Mark where the private
   key is stored and which information crosses each boundary.
2. Choose how the job authenticates without storing a permanent Vault password
   in the repository. Investigate GitLab identity tokens and their lifetime.
3. Describe an access policy that allows only the intended project and protected
   release tags to use the signing key.
4. Explain how the job obtains the key temporarily and how your existing signing
   commands would use it. Which pipeline steps can remain unchanged?
5. Compare retrieving a private key with requesting a signature from a service
   that keeps the key inside Vault. Which approach limits key exposure?
6. Explain how audit logging and key rotation help when multiple projects use
   the same secret-management system.

Distinguish the lifetime of the job's authentication token from the lifetime of
the stored signing key. Also consider what a compromised job could still access.

This is a design exercise. A running Vault server and integration are not required
for the remaining lab; continue with the protected file variable. If your instructor
supplies Vault, use the supplied project-specific policy and role to replace only
the key retrieval step. Packaging and signing should remain unchanged.

## 🟢 Section IV: Create a Release from a Git Tag

A Git tag identifies the source version; a GitLab release adds a name and release notes.
Creation follows successful build, tests, packaging, and signing.

### 1. Use the Tag as the Version

Adapt the pipeline so that release packages use the tag as their version:

1. Change the top-level `APP_VERSION` variable to use `$CI_COMMIT_TAG` instead
   of `$CI_COMMIT_SHORT_SHA`.
2. Restrict `package_app` to tag pipelines using the same `rules` condition you
   added to `sign_package` in Section III.
3. Keep `build_app` and `test_app` available for branch pipelines as well as tags.
   Check that a branch pipeline cannot attempt packaging with an empty version.

Branch pipelines now run only build and test. Tag pipelines also package and sign.
Use version tags of the form `vMAJOR.MINOR.PATCH` throughout this lab.

### 2. Add a Tag-Based Release Job

Write a job that creates a GitLab release after successful signing:

1. Add a `release` stage after `sign` and create `release_job` in that stage.
2. Use the image `registry.gitlab.com/gitlab-org/cli:latest`, which provides the
   GitLab CLI needed for release creation.
3. Restrict the job to tag pipelines using the same condition as the packaging
   and signing jobs.
4. Add a short `script` command that prints which version is being released.
   The job still needs a `script` even though release creation uses another keyword.
5. Add a `release` configuration. Set `tag_name` to `$CI_COMMIT_TAG`, choose a
   readable `name` containing the version, and write a `description` summarizing
   the application and its test and coverage evidence.
6. Commit the pipeline and push your branch. Create an annotated version tag
   such as `v1.0.0` on that commit and push the tag separately to start its pipeline.

The `release:` keyword creates a GitLab release page after the job's `script`
has succeeded. Use this example as a starting point for step 5:

```yaml
  release:
    tag_name: "Here you reference the Git tag for this release"
    name: "Here you give the release a readable title"
    description: "Here you describe what the release contains"
    assets:
      links:
        - name: "Here you name the package download"
          url: "https://example.com/path-to-your-package"
        - name: "Here you name the signature download"
          url: "https://example.com/path-to-your-signature"
        - name: "Here you name the public-key download"
          url: "https://example.com/path-to-your-public-key"
```

Place this block inside `release_job`, at the same indentation level as `script`
and `rules`. `tag_name` selects the Git tag associated with the release; `name`
is the title displayed on the release page, and `description` contains its release
notes. Replace every placeholder with the appropriate text, variable, or registry
URL for your project. This block creates the release
page; uploading package files is a separate task added in Section V.

`assets.links` adds download links to the release page. Each entry has a visible
`name` and a destination `url`; it does not upload the file itself. The example
shows the structure of the release configuration used at the end of the lab.
For now, omit `assets` until Section V, where you construct the actual registry
URLs and publish the files to those locations
before creating the release.

Use `git tag -a` with a message to create an annotated tag and `git push origin`
with the tag name to publish it. Use the protected `v*` pattern configured in
Section III. Do not move published release tags; use a new version for changed
release contents.

### 3. Verify the Release

Inspect the tag pipeline and Releases page. Check all jobs passed, the archive is
named `status-analyzer-v1.0.0.zip`, and the release uses the tag name. Its files are
still temporary job artifacts until Section V.

Answer in your notes:

* Why should `release_job` run only when `$CI_COMMIT_TAG` exists?
* What is the difference between branch and tag pipelines?
* Which changes require major, minor, or patch version increments?
* How do tag, package version, commit file, and test evidence support traceability?
* Where would release approvals fit in a safety-relevant process?

## 🟡 Section V: Publish to the GitLab Package Registry

Artifacts transfer intermediate outputs; a registry stores
versioned release packages beyond a pipeline's artifact lifetime. Use the
**Generic Package Registry**, rather than the Container Registry, for ZIP files.

### 1. Publish Before Creating the Release

Add a job that uploads the signed files to the Generic Package Registry:

1. Insert a `publish` stage between `sign` and `release`. Publishing is introduced
   last in this lab, but the files must exist before the release is announced.
2. Create `publish_package` in that stage, use `gcc:14`, and install `curl` in
   `before_script`.
3. Restrict the job to tag pipelines, matching the other release-related jobs.
4. In `script`, upload the ZIP, its `.sig` file, and `dist/public.pem` using three
   `curl` commands. Use `--upload-file` to select each local file and
   `--fail-with-body` so that HTTP errors fail the job.
5. Authenticate each request using the header `JOB-TOKEN: $CI_JOB_TOKEN`.
   This predefined token supports uploads to the same project; you do not need
   a personal access token.
6. Construct each destination URL from the template below. Use package name
   `status-analyzer`, version `$APP_VERSION`, and the matching filename.

```text
$CI_API_V4_URL/projects/$CI_PROJECT_ID/packages/generic/<package-name>/<version>/<filename>
```

GitLab provides `CI_API_V4_URL` and `CI_PROJECT_ID`. Files are organized as
**package name > version > filename**. Consult the
[Generic Package Registry documentation](https://docs.gitlab.com/user/packages/generic_packages/)
for the upload syntax.

Quote each complete `curl` command in YAML so that the colon in `JOB-TOKEN:` is
not interpreted as a mapping. Outer single quotes around the YAML value and
double quotes around shell arguments allow the shell to expand the variables.

Upload the exact ZIP that was signed. Do not rebuild or change it after signing.
The public key is distributed alongside it, but receivers must still validate
that key against a trusted copy.

### 2. Link the Release to the Registry Files

Extend `release_job` so that users can download the published files from the
release page:

1. Use the `assets.links` example from Section IV to extend the existing `release`
   configuration now that the publishing job uploads the files.
2. Add three entries: one for the ZIP, one for its SHA-256 signature, and one for
   the public key.
3. Give each entry a readable `name` and a `url` pointing to its registry file.
   Reuse the destination URLs you constructed for the upload commands.
4. Check the YAML indentation: `assets` belongs inside `release`, and each link
   is a separate list item with its own `name` and `url`.

The links must refer to the versioned registry files, rather than artifacts of
a particular pipeline job.

### 3. Verify the Complete Flow

Commit and push the change, then create a new protected tag such as `v1.0.1`.
Verify the following on the Package Registry and Releases pages:

* Package `status-analyzer`, version `v1.0.1`, contains ZIP, signature, and public key.
* Release download links point to registry files, rather than temporary artifacts.
* The ZIP contains the executable, documentation, version, and coverage/test evidence.
* Verification with your trusted public key succeeds; a modified ZIP fails.

For private projects, use authenticated downloads. Release links do not make
private packages public.

Answer in your notes:

* Why are job artifacts alone unsuitable for long-term release storage?
* How does a package registry differ from a container registry?
* What happens if uploading fails? Should the release job run?
* Why should a version identify fixed content even if the registry permits duplicates?
* What does “build once, release many times” mean? This lab reuses one build across
  the jobs of a tag pipeline. Later promotion to another environment should also
  reuse the stored package instead of starting a new build.

The final flow is **build > test and coverage > package > sign > publish > release**.
Commit source, tests, CMake, the pipeline, and your notes. Keep keys and generated
artifacts out of Git. A successful pipeline does not replace organizational
approvals needed before customer delivery.
