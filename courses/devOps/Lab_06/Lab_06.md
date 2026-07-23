# Lab 6: The Pre-Build Phase

This lab focuses on the steps that are performed before the actual build phase of a software project. This includes tasks such as linting, format checking, and checks of the formal process of the project.

All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

## 🟢 Section I: Code Formatting

In this section, you will learn how to automatically format your code using a code formatter. This ensures that your code adheres to a consistent style and improves readability.

## Part I: Installation

First we need to install the necessary tools for this lab. This includes a code formatter and a linter.

### Task Description

Select the operating system you are using and follow the instructions to install it.
Assumption: You have already installed MSYS2 and the UCRT64 environment on your system. If not, please refer to Lab ????? for installation instructions.

#### Windows
* Open your MSYS2 UCRT64 Shell and install the `clang-format` package by running the following command:
```bash
pacman -S mingw-w64-ucrt-x86_64-clang-tools-extra
```
* You will find the formatter executable `clang-format.exe` in the `C:\msys64\ucrt64\bin` directory. Add this directory to your system's PATH environment variable to make it accessible from any command prompt.

#### Ubuntu
* Open a terminal and install the `clang-format` package by running the following command:
```bash
sudo apt update
sudo apt install clang-tools
```

#### macOS
* Open a terminal and install the `clang-format` package using Homebrew by running the following command:
```bash
brew install llvm
```

#### Verify Installation

To verify that the installation was successful, open a new command prompt or terminal and run the following command:
```bash
clang-format --version
clang-tidy --version
clangd --version
```

## Part II: First usage of Code Formatting

### Task Description

In Part I you installed `clang-format`. Now you will configure it for a C/C++ project and use it to format source files automatically.

* Open the project in which you want to use automatic code formatting.
* Verify again that `clang-format` can be found from inside the project folder:
```bash
clang-format --version
```
* Create a new file named `.clang-format` in the root directory of your project.
* Generate a default formatting configuration based on an existing style:
```bash
clang-format -style=llvm -dump-config > .clang-format
```
Here is what each part means:
* ```clang-format``` starts the code formatting tool.
* ```-style=llvm``` tells it to use the predefined LLVM formatting style as the base style.
* ```-dump-config``` prints the complete configuration for that style.
* ```>``` redirects that printed output into a file instead of showing it in the terminal.
* ```.clang-format``` is the file that receives the configuration.

Open the ```.clang-format``` file and adapt some basic settings. For example:
```yaml
BasedOnStyle: LLVM
IndentWidth: 4
TabWidth: 4
UseTab: Never
ColumnLimit: 100
BreakBeforeBraces: Attach
```
* Create a small C or C++ source file with intentionally inconsistent formatting, for example `main.cpp`.
* Format this single file in place by running:
```bash
clang-format -i main.cpp
```
* Check the changed file and verify that the formatting now follows the rules from `.clang-format`.
* Format all C/C++ files in the current folder by running one of the following commands:

#### Windows PowerShell
```powershell
Get-ChildItem -Recurse -Include *.c,*.cpp,*.h,*.hpp | ForEach-Object { clang-format -i $_.FullName }
```

#### Ubuntu/macOS
```bash
find . -name "*.c" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" | xargs clang-format -i
```
* Add the `.clang-format` file to your Git repository so that all team members use the same formatting rules


### Part III: Learn more about Code Formatting

You have just joined a new development team that maintains a small C++ monitoring tool for a factory production line. The program works, but the codebase looks messy: indentation is inconsistent, braces are placed differently, include files are not ordered consistently, and some short functions are written on a single line.

During your first team meeting, you suggest using `clang-format` to make the code easier to read and to avoid future discussions about manual formatting. Your task is to inspect the existing code, read about possible `.clang-format` settings, and create a formatting configuration that matches the team's requested style.

### Task Description

* Open the folder `formatting_team_project`.
* Inspect the files in the `include` and `src` folders. Do not change the code manually.
* Go to the official clang-format documentation and read about the available style options:
  [https://clang.llvm.org/docs/ClangFormatStyleOptions.html](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)
* Create a `.clang-format` file in the root directory of `formatting_team_project`.
* Use the LLVM style as a starting point.
* Adapt the `.clang-format` file so that the project is formatted according to the requirements below.
* Run `clang-format` on all `.cpp` and `.hpp` files in the project.
* Check the changed files and verify that the requested style was applied.
* Add the `.clang-format` file to Git together with the formatted source files.

### Requirements

  * use 4 spaces for indentation
  * never use tabs
  * limit lines to 80 characters
  * place opening braces on a new line
  * align pointers to the left, for example `int* value`
  * sort include statements automatically
  * add spaces inside braced initializer lists, for example `{ 3, 7, 11, 15 }`
  * do not keep short functions on a single line

### Shift-Left



