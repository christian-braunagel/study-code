# Lab 2: Git Exercises

This lab provides a set of exercises to practice and improve your Git skills.
It is designed to help you become more comfortable with the basic Git commands and workflows such as branching.
In addition, you will learn more about advanced Git topics such as Branching strategies, Merging strategies, and Repository structures.

All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

## 🟢 Section I: Local Git Branching and Merging

In this exercise, you will create a new Git project on your local machine and practice a typical branching workflow.
You will create branches, add files, commit changes, perform a fast-forward merge, perform a three-way merge, and resolve your first merge conflict.

### Task Description

Create a new local Git repository for a small documentation project called `git-merge-practice`.
The project should contain a short project description, a planning file, and several changes created on different branches.

#### 1. Create a New Local Git Project

* Create a new folder called `git-merge-practice`
* Open the folder in your terminal
* Initialize a new Git repository
* Create a file called `README.md`
* Add a short project title and one sentence describing the project
* Add and commit the file with a meaningful commit message

Example commands:

```bash
mkdir git-merge-practice
cd git-merge-practice
git init
```

#### 2. Create and Commit Changes on a Branch

Create a branch called `docs-introduction`.

On this branch:

* Add a section called `Project Goal` to `README.md`
* Create a new file called `notes.md`
* Add at least three bullet points describing what you want to learn about Git
* Add and commit your changes

Afterwards, switch back to your main branch.

#### 3. Experience a Fast-Forward Merge

Merge the branch `docs-introduction` into your main branch.

Before merging, check the commit history with:

```bash
git log --oneline --graph --all
```

Since the main branch has not moved forward while you worked on `docs-introduction`, Git should be able to use a fast-forward merge.

After the merge:

* Check the commit history again
* Identify why this merge was a fast-forward merge
* Write one sentence in `notes.md` explaining what a fast-forward merge means
* Add and commit this explanation on the main branch

#### 4. Create a Three-Way Merge Situation

Create a new branch called `planning-update`.

On this branch:

* Create a file called `plan.md`
* Add a short list of three tasks for the project
* Add and commit your changes

Switch back to the main branch.

On the main branch:

* Add a new section called `Repository Structure` to `README.md`
* Describe the purpose of `README.md`, `notes.md`, and `plan.md`
* Add and commit your changes

Now merge `planning-update` into the main branch.
Because both branches contain new commits, Git should create a three-way merge.

After the merge:

* Check the commit history with `git log --oneline --graph --all`
* Identify the merge commit
* Write one sentence in `notes.md` explaining how this merge differed from the fast-forward merge
* Add and commit this explanation

#### 5. Create and Resolve Your First Merge Conflict

Create a new branch called `readme-version-a`.

On this branch:

* Edit the first descriptive sentence in `README.md`
* Add and commit your change

Switch back to the main branch.

On the main branch:

* Edit the same descriptive sentence in `README.md`, but write a different version
* Add and commit your change

Now merge `readme-version-a` into the main branch.
Git should report a merge conflict in `README.md`.

Resolve the conflict by:

* Opening `README.md`
* Finding the conflict markers `<<<<<<<`, `=======`, and `>>>>>>>`
* Editing the text so that the final sentence is clear and contains the best parts of both versions
* Removing all conflict markers
* Adding the resolved file
* Committing the merge

#### 6. Final Check

At the end of the exercise, your repository should contain:

* At least three branches that were created during the exercise
* Several meaningful commits
* One fast-forward merge
* One three-way merge
* One resolved merge conflict

Use the following command to inspect your result:

```bash
git log --oneline --graph --all
```

Be prepared to explain:

* What a branch is
* What a commit stores
* Why the first merge was a fast-forward merge
* Why the second merge created a merge commit
* What caused the merge conflict and how you resolved it

## 🟢 Section II: GitLab Branching and Merge Requests

In this exercise, you will practice a complete GitLab workflow.
You will create a new remote project on GitLab, clone it to your local machine, create a branch, push your changes, open a merge request, merge it into `main`, and update your local repository afterwards.

### Task Description

Create a new GitLab project called `gitlab-merge-request-practice`.
The project should be used to practice the connection between your local Git repository and a remote GitLab repository.

#### 1. Create a New Project on GitLab

* Log in to your GitLab account
* Select `New project`
* Choose `Create blank project`
* Enter the project name `gitlab-merge-request-practice`
* Set the visibility level to `Private`
* Enable the option to initialize the repository with a `README`
* Create the project
* Copy the clone URL of the project

#### 2. Clone the Project Locally

Clone the GitLab project to your local machine.

Example command:

```bash
git clone <your-gitlab-clone-url>
cd gitlab-merge-request-practice
```

After cloning:

* Check the current branch with `git branch`
* Check the remote connection with `git remote -v`
* Open the project folder in your editor

#### 3. Create a Branch and Make Changes

Create a new branch called `project-documentation`.

On this branch:

* Add a section called `Project Overview` to `README.md`
* Create a new file called `documentation.md`
* Add a short description of the purpose of this repository
* Add a list of at least three GitLab features you used in this exercise
* Save your changes

#### 4. Add and Commit Your Changes

Check which files were changed:

```bash
git status
```

Then add and commit your changes.


Check the commit history:

```bash
git log --oneline
```

#### 5. Push the Branch to GitLab

Push your branch to the remote GitLab repository.

Example command:

```bash
git push -u origin project-documentation
```

After pushing:

* Open the GitLab project in your browser
* Check that the branch `project-documentation` exists on GitLab
* Check that your commit is visible on GitLab

#### 6. Create a Merge Request

Create a merge request from your branch into `main`.

In GitLab:

* Select `Merge requests`
* Create a new merge request
* Select `project-documentation` as the source branch
* Select `main` as the target branch
* Add a meaningful title and short description
* Create the merge request
* Review the changed files in the merge request

#### 7. Merge the Branch into Main

After reviewing the merge request:

* Merge the merge request into `main`
* Delete the source branch if GitLab offers this option
* Open the repository file view and check that the changes are now visible on `main`

#### 8. Update Your Local Repository

Your local `main` branch is now behind the remote `main` branch because the merge happened on GitLab.
Update your local repository.

Example commands:

```bash
git switch main
git pull origin main
```

After pulling:

* Check that `README.md` contains your merged changes
* Check that `documentation.md` exists locally
* Check the commit history with `git log --oneline --graph --all`
* Check your local and remote branches with `git branch -a`

If you deleted the source branch on GitLab, you can also remove the old local branch:

```bash
git branch -d project-documentation
git fetch --prune
```

#### 9. Final Check

At the end of the exercise, you should be able to explain:

* What the difference between a local and a remote repository is
* Why you created a branch before making changes
* What a merge request is used for
* Why your local `main` branch had to be updated after the merge request was merged on GitLab

## 🔴 Section III: Rebase Hell

In this exercise, you will reuse the GitLab project from Section II.
You will intentionally create a situation where a long-running branch has several commits that conflict with newer changes on `main`.
Then you will rebase the branch and resolve conflicts commit by commit.

### Task Description

Use your local clone of `gitlab-merge-request-practice`.
Make sure your local `main` branch is up to date before you begin.

Example commands:

```bash
git switch main
git pull origin main
```

#### 1. Create a Long-Running Branch

Create a new branch called `rebase-experiment`.

On this branch, make three separate commits that all edit the same area of `README.md`.

For example:

* Commit 1: Change the first project description sentence
* Commit 2: Add two bullet points below `Project Overview`
* Commit 3: Rewrite one of the bullet points from commit 2

After each change, add and commit the file separately.

Check your result:

```bash
git log --oneline --graph --all
```

#### 2. Move Main Forward with a Second Merge Request

Switch back to `main` and create a second branch called `main-update-for-rebase`.

Now edit the same area of `README.md` that you changed on `rebase-experiment`.
Make changes that are different from the changes on your branch.

Create two separate commits on `main-update-for-rebase`.

For example:

* Commit 1: Rewrite the first project description sentence in a different way
* Commit 2: Add a different bullet list below `Project Overview`

Push the second branch to GitLab.

Create a merge request from `main-update-for-rebase` into `main`.
Review the changes, merge the merge request, and delete the source branch if GitLab offers this option.

#### 3. Start the Rebase

Update your local `main` branch so it contains the changes that were merged on GitLab.

```bash
git switch main
git pull origin main
```

Switch back to your rebase-experiment branch.

Rebase it onto the updated `main` branch.

```bash
git rebase main
```

Git should stop when it reaches the first conflicting commit.
This is the beginning of "rebase hell": Git replays your commits one by one, so you may need to resolve several conflicts during one rebase.

#### 4. Resolve Each Conflict

Whenever Git reports a conflict:

* Open the conflicting file
* Find the conflict markers `<<<<<<<`, `=======`, and `>>>>>>>`
* Decide what the final version should look like
* Remove all conflict markers
* Add the resolved file
* Continue the rebase

Example commands:

```bash
git status
git add README.md
git rebase --continue
```

Repeat these steps until the rebase is complete.

If your rebase becomes too confusing, you can stop and return to the branch state before the rebase:

```bash
git rebase --abort
```

After aborting, inspect the history and try the rebase again.

#### 5. Inspect the Result

After the rebase has finished, inspect the commit history.

```bash
git log --oneline --graph --all
```

Compare the history before and after the rebase.

Answer the following questions in `documentation.md`:

* Which commits were replayed during the rebase?
* How many conflicts did you need to resolve?
* Why can rebasing a long-running branch become difficult?
* How could you avoid this situation in a real project?

Add and commit your answers.
