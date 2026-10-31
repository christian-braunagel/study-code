# Completed Lab 07 pipeline

Copy `.gitlab-ci.yml` from this directory to the root of the repository containing
the starter project's CMakeLists.txt, README.md, src/, include/, and tests/.
The starter pipeline is intentionally limited to build, tests, and coverage.

Before using the completed pipeline:

1. Generate a teaching RSA key outside Git, as described in Section III.
2. Add its PEM content as the protected GitLab **File** variable
   `SIGNING_PRIVATE_KEY`, with expansion disabled.
3. Protect the `v*` tag pattern and restrict who may create those tags.
4. Commit and push, then create a new protected version tag such as `v1.0.0`.

Branch pipelines build and test only. Version-tag pipelines also package, sign,
publish to the Generic Package Registry, and create a release with download links.
All jobs use simple stages and default artifact downloads from earlier stages.
No external Vault installation is required for this reference pipeline; the
vault design exercise explains how to replace the key retrieval mechanism.

The ZIP is built once in the tag pipeline and remains unchanged through signing
and publishing. Never include the private key in artifacts or source control.
