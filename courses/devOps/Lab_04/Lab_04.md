# Lab 4: GitLab CI Basics

This lab focuses on the basics of GitLab CI.
You will create your first `.gitlab-ci.yml` file, run a pipeline, inspect runner logs, work with stages and jobs, use predefined CI variables, pass artifacts between jobs, and control when jobs should run.

All the following sections of this lab are based on the following levels of difficulty:

🟢 __Simple__: A simple task that guides you step by step through the process and focuses on learning the basics. It should not take more than 15 minutes to finish.

🟡 __Moderate__: A task that states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30 minutes depending on your knowledge.

🔴 __Complex__: A difficult or longer task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours.

## 🟢 Section I: Create Your First GitLab CI Pipeline

In this exercise, you will create a first GitLab CI pipeline and observe how GitLab executes jobs.

### Task Description

Use a GitLab project from the previous labs or create a new private project called `gitlab-ci-basics`.
Clone the project to your local machine and open it in your editor.
Alternatively, you can use the GitLab Web IDE to edit files directly in the browser.

### 1. Create the Pipeline File

Create a file called `.gitlab-ci.yml` in the root directory of your repository.

Add one job called `hello-ci`.
The job should use a lightweight Linux image and print a short message that is visible in the logs.

Add, commit, and push the file if you are working locally.

### 2. Inspect the Pipeline Run

Open your project in GitLab and navigate to `Build` > `Pipelines`.

Open the newest pipeline and inspect:

- the pipeline status
- the job status
- the job log
- the runner information
- the printed output from your script

Rerun the job of your pipeline manually.


### 3. Define Stages

Modify the pipeline and define three stages `prepare`, `build`, and `test`.

### 4. Add Jobs to the Stages

Create three jobs:

- `prepare-environment`
- `build-application`
- `test-application`

Each job should:

- use `alpine:latest`
- belong to the correct stage
- print at least one meaningful message
- run a simple command such as `pwd`, `ls`, or `date`

### 5. Run and Inspect the Pipeline

Commit and push your changes.
Open the pipeline in GitLab and inspect the stage view.

Answer the following questions in a file called `ci_notes.md`:

- Which stage started first?
- Did the `test` stage start before the `build` stage finished?
- What happens when one stage fails?
- Why are stages useful in a CI/CD pipeline?


## 🟡 Section II: Use CI Variables

In this exercise, you will use predefined and custom GitLab CI variables.

### Task Description

Extend your pipeline with jobs that print predefined variables and create temporary files.

### 1. Print Predefined CI Variables

Add a job called `show-ci-variables` in the `prepare` stage.

The job should print:
- the project name
- the commit branch
- the commit hash
- the id of the pipeline
- the job name

and three more variables of your choice.

Commit and push the change.
Inspect the job log.

### 2. Custom Variables

Create two custom variables in the GitLab project settings:
- `CUSTOM_VAR_1` which is a normal variable with a value of your choice
- `CUSTOM_VAR_2` which is a masked variable with a value of your choice

Add a job called `show-custom-variables` in the `prepare` stage.
The job should print the values of both custom variables.

Observe and document the behavior of the masked variable in the job log.


## 🟡 Section III: Pass Build Results with Artifacts and Needs

In this exercise, you will pass a generated file from one job to another.
You will also use `needs` to describe that a job depends on the result of another job.

### Task Description

Create a small C++ source file and build it inside GitLab CI.
Then pass the compiled result to a test job.

### 1. Add a Small C++ Program

Create a file called `main.cpp`:

```cpp
#include <iostream>

int main()
{
    std::cout << "GitLab CI C++ build successful" << std::endl;
    return 0;
}
```

Commit the file.

### 2. Add a Build Job

Add a job called `build-cpp-application`.
The job should use a compiler image, compile `main.cpp`, and store the compiled program as an artifact.

### 3. Add a Test Job

Add a job called `run-cpp-application`.
The job should use `needs` to download the artifact from the build job and execute the program.

Commit and push the pipeline.
Inspect the pipeline graph and job logs.

### 4. Document the Behavior

Add answers to `ci_notes.md`:

- What does `needs` describe?
- How is this different from relying only on stage order?


## 🟡 Section IV: Control Pipelines with Rules and Schedules

In this exercise, you will control when jobs and pipelines run.
You will practice job rules, pipeline schedules, and workflow rules.

### Task Description

Extend your pipeline so that different jobs run in different situations.

### 1. Run a Job Only on the Main Branch

Add a job called `main-branch-check`.
The job should only run when the current branch is `main`.

Check if the job runs when you push to a feature branch.
Then merge the feature branch into `main` and check if the job runs.

### 2. Running on Merge Requests or Pushes 

Create two more jobs or modify existing jobs:
- one job should only run on git pushes
- the other job runs only on merge requests

Verify that the jobs run in the correct situations.

### 3. Create a Scheduled Pipeline

In GitLab, navigate to `Build` > `Pipeline schedules`.
Create a schedule for your project.

Configure the schedule so it:

- uses the default branch
- runs every 1st day of the month at 01:00

Check with AI if your Cron Syntax is correct.

### 4. Add a Workflow Rule

Add a `workflow` section that allows to run the pipeline only on merge requests.

Explicitly state that the pipeline should not run in any other situation.

Commit and push the change.

Observe the behavior of the pipeline when you push to a feature branch and when you create a merge request.

### 5. Document the Rules

Add answers to `ci_notes.md`:

- What is the difference between job `rules` and `workflow` rules?
