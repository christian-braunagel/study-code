# Lab 1: Getting to know the toolchain

## Introduction

This first Lab has the goal to get you started and help you to get more confidence in using the various tools needed to develop great Visual Basic.NET code.

## Section I: Your first steps in GitHub

1. Create a [Github](github.com) account.
2. (Optional) Register for the [Github Student Pack](https://education.github.com/pack) to increase your free Codespace limits.
3. Navigate to the GitHub repository [study-code](https://github.com/christian-braunagel/study-code).
4. Fork the GitHub repository.
5. Use GitHub Codespaces to open the repository remotely.
6. Create a folder with name and location of your choice.
7. Navigate with the terminal into the folder and run the following command to setup a new VB project called "HelloWorld":
```bash
dotnet new console -lang "VB" -n HelloWorld
```
8. Navigate into the created folder HelloWorld and build the project by running:
```bash
dotnet build
```
9. To execute the programm, run in the same folder:
```bash
dotnet run
```

## Section II: (Optional) Setup the toolchain on your own machine
1. Download and install [Visual Studio](https://visualstudio.microsoft.com/de/downloads/).
2. Run the downloaded VisualStudioSetup.exe.
3. Select the .NET Package within the installation wizard.
4. Download and install [Git](https://git-scm.com/install/). Set VS Code as default editor and "main" as default branch name.

## Section III: Working in the terminal

For the following exercises, use can use either the bash terminal in Codespace or Git Bash installed on your machine.

1. Open your Bash terminal.
2. Verify in which directory you are currently located.
3. Print the content of the directory.
4. Create a directory with the name "terminal_challenge".
5. Move into the directory "terminal_challenge".
6. Again, verify in which directory you are currently located.
7. Inside of "terminal_challenge", create the following sub-directories: notes and results
8. Create a file in each folder: notes/input.txt and results/output.txt
9. Write in each file the current location the file is stored in.
10. Print the content of each file to the terminal. Start with notes/input.txt.
11. Delete each file first and then the complete directory "terminal_challenge".

## Section IV: Let's Git going

For the following exercises, use can use either the bash terminal in Codespace or Git Bash installed on your machine.

1. Open your Bash terminal.
2. Navigate to a directory of your choice.
3. Verify that this directory is not yet a Git repository.
4. Verify your global Git configuration and if not yet done, configure your user name and mail in Git.
5. Verify the correct configuration settings afterwards.
6. Initialize a new Git repo in this directory.

## Section V: A first commit

Follow-up section to section IV.

1. Create two new text files in your Git repository and verify the output of git status.
2. Move the two new text files into the Git staging area.
3. Verify the output of git status. What changed compared to the previous status?
4. Create a commit with a fitting commit message.
5. Verify the output of git status. What changed compared to the previous status?
6. Check the logs of git and the hash value of your new commit.

## Section VI: Branch away

Follow-up section to section V.

1. Create a new branch called "lorem-ipsum".
2. Display all existing branches and then switch onto the new branch.
3. Create a new .txt-file. Navigate to the webpage [loremipsum.de](https://www.loremipsum.de/) and copy/paste some text into the file.
4. Verify git status and then move the changes to the staging area.
5. Verify git status again and then commit these changes.
6. Switch back to the main branch.
7. Create another branch called "absolute-wisdom" and __immediately__ switch over to it.
8. Create a new .txt-file. Navigate to the webpage [felipemotabr.github.io/rick-and-morty-ipsum-generator/](https://felipemotabr.github.io/rick-and-morty-ipsum-generator/) and copy/paste some text into the file.
9. Create a new commit for these changes.
10. Display all existing branches.

## Section VII: Merge it

Follow-up section to section VI.

1. Switch to the main branch and merge it with the branch "lorem-ipsum". 
2. Verify that the merge actually worked.
3. Create a new branch called "another-lorem-ipsum".
4. Switch to the branch and change the first line of the txt.-file which included the lorem ipsum text.
5. Commit the changes.
6. Switch to main and change the first line of the txt.-file which included the lorem ipsum text.
7. Try to merge main with "another-lorem-ipsum". What happens?
8. Resolve the conflict so that the changes from "another-lorem-ipsum" are preserved.

## Section VIII: Working with remote repositories

This section describes the process you should follow for the upcoming labs:

* create a branch on your forked repository
* do your work on the branch and commit it
* push it to your fork and merge it remotely
* pull back the changes to the local main branch

You can also use Codesspaces for these exercises starting with point 3.


1. Optional: Configure SSH for your GitHub account and your local machine.
2. Clone the forked repository [study-code](https://github.com/christian-braunagel/study-code) or any GitHub repository created by yourself from section I to your local machine via ssh or https.
3. Open your local terminal and navigate to the cloned project.
4. Create a new branch.
5. Create a file called test.md in this branch and fill in some random numbers.
6. Commit the changes.
7. Push the changes to GitHub. What happened and why?
8. Resolve the issue as suggested by Git and perform the push successfully.
9. Navigate to your repository on github.com and create a Pull Request.
10. Check out the pull requests and the changes you pushed to GitHub before merging them.
11. Pull the merged changes from the remote repository to your local main branch.