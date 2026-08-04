# Lab 9: GitLab Tags

TBD.....................................

All the following sections of this lab are based on the following levels of dificulty:

Green __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it.

Yellow __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

Red __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

## Green Section I: Create a Release from a Git Tag

In this section, you will create a GitLab release automatically when a Git tag is pushed to the repository. Tags are commonly used to mark stable versions of a project, for example `v1.0.0` or `v2.3.1`.

## Part I: Tag-Based Release Pipeline

### Task Description

Create a `.gitlab-ci.yml` pipeline that adds a release job only when the pipeline is started by a Git tag. The job should create a GitLab release that uses the tag name as the release version.

### Requirements

* Add a `release` stage to the pipeline.
* Add a job named `release_job`.
* Configure the job so it only runs for tag pipelines.
* Use the GitLab CLI image: `registry.gitlab.com/gitlab-org/cli:latest`.
* Use the GitLab CI/CD variable `$CI_COMMIT_TAG` as the release tag name.
* Give the release a readable name and description.

### Example Configuration

Create or update `.gitlab-ci.yml` with the following release job:

```yaml
stages:
  - release

release_job:
  stage: release
  image: registry.gitlab.com/gitlab-org/cli:latest
  rules:
    - if: $CI_COMMIT_TAG
  script:
    - echo "Creating release for $CI_COMMIT_TAG"
  release:
    tag_name: "$CI_COMMIT_TAG"
    name: "Release $CI_COMMIT_TAG"
    description: "Release created automatically from tag $CI_COMMIT_TAG."
```

### Create and Push a Tag

After committing your `.gitlab-ci.yml` file, create and push a tag:

```bash
git add .gitlab-ci.yml
git commit -m "Add tag-based release pipeline"
git tag v1.0.0
git push origin main
git push origin v1.0.0
```

### Verify the Release

Open your project in GitLab and check the following:

* A new pipeline was started for the tag `v1.0.0`.
* The `release_job` job ran successfully.
* A new release is visible under `Deploy > Releases`.
* The release name and description contain the tag name.

### Questions

Answer the following questions in your lab notes:

* Why should the release job run only when `$CI_COMMIT_TAG` exists?
* What is the difference between a branch pipeline and a tag pipeline?
* Why are tags useful for release management?
