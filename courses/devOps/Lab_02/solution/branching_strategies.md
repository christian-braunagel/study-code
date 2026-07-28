# Branching Strategies Solution

This file explains one possible setup for the three branching strategy projects from Section IV.
Branch names can vary between teams, but the following structures are common and suitable for this exercise.

## GitHub Flow

GitHub Flow uses one permanent production branch and short-lived work branches.
The main line should always be deployable.

Recommended branches:

* `main`
* `feature/update-readme`

Example setup:

```bash
git clone <gitlab-clone-url>
cd branching-github-flow
git switch main
git pull origin main
git switch -c feature/update-readme
```

Example workflow:

* Make a small change on `feature/update-readme`
* Commit the change
* Push the branch with `git push -u origin feature/update-readme`
* Create a merge request from `feature/update-readme` into `main`
* Review and merge the merge request
* Delete the feature branch
* Update the local repository with `git switch main` and `git pull origin main`

GitHub Flow is simple because work branches are created from `main` and merged back into `main` after review.

## Gitflow

Gitflow uses several branch types to separate production code, ongoing development, releases, features, and urgent fixes.
It is more structured than GitHub Flow and is often used when releases are planned explicitly.

Recommended branches:

* `main`
* `develop`
* `feature/login-page`
* `release/1.0.0`
* `hotfix/fix-readme-typo`

Example setup:

```bash
git clone <gitlab-clone-url>
cd branching-gitflow
git switch main
git pull origin main
git switch -c develop
git push -u origin develop
```

Feature workflow:

```bash
git switch develop
git switch -c feature/login-page
```

* Make and commit the feature change
* Push `feature/login-page`
* Create a merge request from `feature/login-page` into `develop`
* Merge the feature into `develop`

Release workflow:

```bash
git switch develop
git pull origin develop
git switch -c release/1.0.0
```

* Make final release preparation changes
* Push `release/1.0.0`
* Create a merge request from `release/1.0.0` into `main`
* Create another merge request from `release/1.0.0` back into `develop`
* Merge both merge requests

Hotfix workflow:

```bash
git switch main
git pull origin main
git switch -c hotfix/fix-readme-typo
```

* Make and commit the urgent fix
* Push `hotfix/fix-readme-typo`
* Create a merge request from `hotfix/fix-readme-typo` into `main`
* Create another merge request from `hotfix/fix-readme-typo` into `develop`
* Merge both merge requests

Gitflow is powerful, but it can create many long-running branches.
Teams should use it only when the extra release structure is useful.

## Trunk-Based Development

Trunk-based development uses one shared main line and very small, short-lived branches.
Changes are integrated frequently.

Recommended branches:

* `main`
* `short/update-readme`

Example setup:

```bash
git clone <gitlab-clone-url>
cd branching-trunk-based
git switch main
git pull origin main
git switch -c short/update-readme
```

Example workflow:

* Make a very small change on `short/update-readme`
* Commit the change
* Push the branch with `git push -u origin short/update-readme`
* Create a merge request from `short/update-readme` into `main`
* Merge it quickly after review
* Delete the short-lived branch
* Update local `main` with `git switch main` and `git pull origin main`

In strict trunk-based development, developers may commit directly to `main` when the team has strong automated tests and clear rules.
For this lab, use a short-lived branch and merge request because GitLab projects often protect `main`.

## Comparison

Possible student conclusions:

* GitHub Flow is simple and works well for continuous delivery.
* Gitflow is more complex but supports planned releases and hotfixes.
* Trunk-based development minimizes long-running branches and encourages frequent integration.
* Long-running branches increase the risk of merge conflicts and delayed integration problems.
* Protected branches and merge requests help teams review changes before they enter the main line.
