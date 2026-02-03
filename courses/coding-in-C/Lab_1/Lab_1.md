# Lab 1: Getting to know the toolchain

## Introduction

This first Lab has the goal to get you started and help you to get more confidence in using the various tools needed to develop great C code.

## Section I: Your first steps in GitHub

1. Create a [Github](github.com) account.
2. (Optional) Register for the [Github Student Pack](https://education.github.com/pack) to increase your free Codespace limits.
3. Navigate to the GitHub repository [study-code](https://github.com/christian-braunagel/study-code).
4. Fork the GitHub repository.
5. Use GitHub Codespaces to open the repository remotely by selecting `Code > Codespaces > New with options`.
6. On the next page, open the C++ configuration under `Dev container configuration` and create the codespace.
7. After the remote workspace opened, do some free exploration to get familiar with the setup.
8. Create a first c-program (e.g. copy the file code or the file helloWorld.c from the subfolder [solution](https://github.com/christian-braunagel/study-code/blob/main/courses/coding-in-C/Lab_1/solution/helloWorld.c)).
9. Try and build the code using on of the methods described in section XI-A and XI-B below.
10. After you finished, close the codespace again and stop it.

## Section II: (Optional for DHBW Students) Working on a local computer in one of the pc labs

1. Login on one of the windows pc available in the used pc labs with your account and password.
2. Create a new folder for your future projects in a fitting directory (e.g. in `C:\Users\<yourUsername>\`).
3. Open the Visual Studio Developer Command Prompt.
4. Navigate to your newly created project folder within the terminal, For that, use the commands:
   * `cd C:\`
   * `cd <path>\<to>\<your>\<folder>`
5. In the project folder, use the command `code .` to open VSCode.
6. Do some free exploration to get familiar with the setup.
7. Create a first c-program (e.g. copy the file code or the file helloWorld.c from the subfolder [solution](https://github.com/christian-braunagel/study-code/blob/main/courses/coding-in-C/Lab_1/solution/helloWorld.c)).
8. Try and build the code using on of the methods described in section XI-C below.

## Section III: (Optional) Setup the toolchain on your own machine
1. Download and install [Visual Studio Code](https://code.visualstudio.com/download).
2. Verify the successful installation by opening VS Code.
3. Install the [C/C++ extension](https://code.visualstudio.com/docs/languages/cpp#_install-the-extension) in Visual Studio Code.
4. Install a [C-Compiler](https://code.visualstudio.com/docs/languages/cpp#_set-up-your-c-environment) (MinGW or GCC) if not yet available on your machine.
5. Set the path environment variable as described in [C-Compiler](https://code.visualstudio.com/docs/languages/cpp#_set-up-your-c-environment).
6. Verify if the compiler was successful installed and configured by checking for the compiler version in a terminal.
7. Download and install [Git](https://git-scm.com/install/). Set VS Code as default editor and "main" as default branch name.

## Section IV: Working in the terminal

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

## Section V: Let's Git going

For the following exercises, use can use either the bash terminal in Codespace or Git Bash installed on your machine.

1. Open your Bash terminal.
2. Navigate to a directory of your choice.
3. Verify that this directory is not yet a Git repository.
4. Verify your global Git configuration and if not yet done, configure your user name and mail in Git.
5. Verify the correct configuration settings afterwards.
6. Initialize a new Git repo in this directory.

## Section VI: A first commit

Follow-up section to section IV.

1. Create two new text files in your Git repository and verify the output of git status.
2. Move the two new text files into the Git staging area.
3. Verify the output of git status. What changed compared to the previous status?
4. Create a commit with a fitting commit message.
5. Verify the output of git status. What changed compared to the previous status?
6. Check the logs of git and the hash value of your new commit.

## Section VII: Branch away

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

## Section VIII: Merge it

Follow-up section to section VI.

1. Switch to the main branch and merge it with the branch "lorem-ipsum". 
2. Verify that the merge actually worked.
3. Create a new branch called "another-lorem-ipsum".
4. Switch to the branch and change the first line of the txt.-file which included the lorem ipsum text.
5. Commit the changes.
6. Switch to main and change the first line of the txt.-file which included the lorem ipsum text.
7. Try to merge main with "another-lorem-ipsum". What happens?
8. Resolve the conflict so that the changes from "another-lorem-ipsum" are preserved.

## Section IX: Working with remote repositories

This section describes the process you should follow for the upcoming labs:

* create a branch on your forked repository
* do your work on the branch and commit it
* push it to your fork and merge it remotely
* pull back the changes to the local main branch

You can also use Codesspaces for these exercises starting with point 3.


1. Configure SSH for your GitHub account and your local machine.
2. Clone the forked repository [study-code](https://github.com/christian-braunagel/study-code) from section I to your local machine via ssh.
3. Open your local terminal and navigate to the cloned project.
4. Create a new branch.
5. Create a file called test.md in this branch and fill in some random numbers.
6. Commit the changes.
7. Push the changes to GitHub. What happened and why?
8. Resolve the issue as suggested by Git and perform the push successfully.
9. Navigate to your repository on github.com and create a Pull Request.
10. Check out the pull requests and the changes you pushed to GitHub before merging them.
11. Pull the merged changes from the remote repository to your local main branch.

## Section X: Hello World!

Now, let's put everything of the above sections together and create your first running C-Program.
Note: The steps below can be performed on your local machine (after following section II) or using GitHub Codespaces (after following section VIII).
However, in the best case you tried both environments to build the program and run it.

1. If not yet done, clone the forked repository [study-code](https://github.com/christian-braunagel/study-code).
   * Note I: If you use a local machine, make sure you configured SSH for your GitHub account.
   * Note II: If you use GitHub codespaces, cloning is not neccessary because it is done automatically.
2. Create a new branch with a name of your choice.
3. Use the terminal and navigate into /courses/coding-in-C/Lab_1/ and create a new folder called "mySolution".
   * Note I: If you use a local machine, use the Git Bash to perform these and following steps.
4. Navigate into "mySolution" and open VSCode with ``` code . ```
5. Create a new file called "helloWorld.c" and write a short Hello World C-program.
6. Now it is time to build! We will try out several ways to do that.

## Section XI: Building C files

There are different ways on how to build/trigger the build process. Follow the tutorials below, to get familiar with all of them.
The steps follow directly after section X but can also be used to build other c-programs.

### A: Using the terminal to build and run (for Codespaces and your personal machine with gcc)
1. Either open a terminal (if not yet open) within VSCode (menu "Terminal" > "New Terminal") or switch back to the Git Bash terminal you used in the previous steps.
   * Note I: If you use a local machine and want to use a terminal within VSCode, make sure that the terminal is also a Git Bash. You can verify and change this on the right upper corner of the terminal view in VSCode.
   * Note II: If you use GitHub codespaces, you keep using the VSCode terminal from the start.
2. Enter the following command to build the program:
``` bash
gcc helloWorld.c -o helloWorld.o
```
3. Explanation of the command:
   * gcc: The command to execute the compiler
   * helloWorld.c: The c-file you want to compile
   * -o <name>: Define the name of the created output file (otherwise it will be named a.exe or something similar)
4. If the command runs successfully, it creates an executable file with the chosen name stored in your folder.
5. To run the program, you write the following command in your terminal:
``` bash
./helloWorld
```
6. It should print out the words "Hello World" (or whatever you coded into your c-file) on your terminal.

### B: Using VSCode to build and run (for Codespaces and your personal machine with gcc)
1. Open your file "helloWorld.c" in VSCode and press F5 (or use the menue ```Run > Start Debugging``` or ```Run > Run without Debugging```).

![Image of the icon in VSCode](https://github.com/christian-braunagel/study-code/blob/main/courses/coding-in-C/Lab_1/runCFileInVSCode.png)

2. A drop down window on the top of VSCode might occur, asking to select the debug configuration. If so, select the C/C++: gcc.exe

   ![Image of compiler selection drop down menu in VSCode](https://github.com/christian-braunagel/study-code/blob/main/courses/coding-in-C/Lab_1/selectCompiler.png)

3. Give it some seconds.
4. If everything works, it should print out the words "Hello World" (or whatever you coded into your c-file) on your terminal.
5. In case you get some errors of unknown paths/compiler usage or if there are some red, curly lines below ``` #include <stdio.h> ```, you might need to set the correct compiler configuration.
   * In VSCode, press Control+Shift+P and type C/C++: Edit Configurations (UI) and hit enter.
   * Under "compiler path" verify or change the path to the correct location of gcc. On Windows most likely: C:/msys64/ucrt64/bin/gcc.exe
   * Under "IntelliSense mode", select the fitting platform-compiler-architecture. On Windows that would be: Windows-gcc-x64
   * Then try again to build it.
   * If it still does not work, check if gcc --version is available in the terminal. If not, you might need to add gcc to your path variable or install it first (see section II).

### C: Using VSCode to build and run (on a local computer in one of the Windows pc labs at DHBW FN)
1. Open the terminal ```Visual Studio Developer Command Prompt```, navigate to your code folder and open Visual Studion Code with ```code .```.
2. Open your file "helloWorld.c" in VSCode and press F5 (or use the menue ```Run > Start Debugging``` or ```Run > Run without Debugging```).

![Image of the icon in VSCode](https://github.com/christian-braunagel/study-code/blob/main/courses/coding-in-C/Lab_1/runCFileInVSCode.png)

3. Note: A drop down window on the top of VSCode might occur, asking to select the debug configuration. If so, select the C/C++: cl.exe

   ![Image of compiler selection drop down menu in VSCode](https://github.com/christian-braunagel/study-code/blob/main/courses/coding-in-C/Lab_1/selectCompilerCLang.png)
4. Give it some seconds.
5. If everything works, it should print out the words "Hello World" (or whatever you coded into your c-file) on your terminal.
