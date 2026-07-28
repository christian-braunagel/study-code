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

