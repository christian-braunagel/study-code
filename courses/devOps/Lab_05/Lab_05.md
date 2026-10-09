# Lab 5: The Build Phase

This lab focuses on the build phase of a sw project.
You will first work directly with GCC compiler options, then automate the same build with `make`, and finally describe the project with CMake.

All the following sections of this lab are based on the following levels of difficulty:

🟢 **Simple**: A simple task that guides you step by step through the process and focuses on learning the basics. It should not take more than 15 minutes to finish.

🟡 **Moderate**: A task that states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30 minutes depending on your knowledge.

🔴 **Complex**: A difficult or longer task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours.

## 🟢 Section I: Work with GCC Compiler Options

In this section, you will use GCC directly.
The goal is to understand that `gcc` is more than a compiler executable: it acts as a driver that can call the preprocessor, compiler, assembler, and linker.

### Task Description

Open the folder `build_phase_project`.
Inspect the files in `include`, `src`, and `tests`.

Use a terminal from inside `build_phase_project`.

**Note**: You need to have GCC installed on your system. If you are using Windows, you can install MinGW.
On Linux or macOS, you can install GCC through your package manager.

### 1. Verify the Toolchain

Check which compiler is available:

```bash
gcc --version
gcc -v
```

Write down the compiler version and target platform in a file called `build_notes.md`.

Answer:

- Which target platform does your compiler use?
- Is this a native compiler or a cross-compiler?
- Why are cross-compilers important for embedded, automotive, aerospace, or IoT systems?

### 2. Build the Program with One Command

- Compile all application source files into one executable by using the -I option to specify the include directory.
- Verify the resulting executable by running it and observing the output.
- Add the command and the output to `build_notes.md`.

### 3. Explore Individual Build Steps

Run the build phase now step by step:

- Preprocess one source file with the -E option

- Compile to assembly with the -S option

- Compile to an object file with the -c option:

- Now compile the remaining object files and link the executable:

Document in `build_notes.md`:

- Which command creates preprocessed source code?
- Which command creates assembly code?
- Which command creates object code?
- Which command performs linking?

### 4. Use Debugging, Macro, Warning, and Standard Options

Compile the program with common professional options:

```bash
gcc -Iinclude -std=c11 -Wall -Wextra -Werror -g -DSTARTING_TIME=300 src/main.c src/board.c src/move.c src/util.c -o chess_clock
```

Change `STARTING_TIME` to another value and rebuild.

Then remove `-DSTARTING_TIME=...` and rebuild again.

Answer in `build_notes.md`:

- What does `-g` add to the executable?
- What does `-DSTARTING_TIME=300` do?
- Why should the language standard be specified explicitly with `-std=...`?
- What is the effect of `-Wall`, `-Wextra`, and `-Werror`?

### 5. Compare Optimization Levels

Build the program with different optimization settings:

```bash
gcc -Iinclude -std=c11 -O0 src/main.c src/board.c src/move.c src/util.c -o chess_clock_O0
gcc -Iinclude -std=c11 -O2 src/main.c src/board.c src/move.c src/util.c -o chess_clock_O2
gcc -Iinclude -std=c11 -Os src/main.c src/board.c src/move.c src/util.c -o chess_clock_Os
```

Compare the file sizes of the executables.

Answer in `build_notes.md`:

- Which executable is largest?
- Which optimization level would you choose for debugging?
- Which optimization level would you consider for a memory-constrained embedded system?
- Why is the highest optimization level not automatically the best choice?


## 🟡 Section II: Automate the Build with Make

In this section, you will replace long GCC command lines with a `Makefile`.
The goal is to understand targets, dependencies, incremental builds, and cleanup targets.

### Task Description

Create a file called `Makefile` in `build_phase_project`.

### 1. Create a First Makefile

Add variables for the compiler, compiler flags, source files, object files, and executable name.

Your Makefile should build the application with:

```bash
make
```

Required targets:

- `all`
- `chess_clock`
- one rule that turns `.c` files into `.o` files
- `clean`

Use the following compiler flags:

```makefile
-Iinclude -std=c11 -Wall -Wextra -Werror -g -DSTARTING_TIME=300
```

### 2. Add a Test Target

The test file `tests/test_move.c` uses the same production code except for `main.c`.

Add a `test` target that builds and runs a test executable called `test_move`.

The target should compile:

- `tests/test_move.c`
- `src/board.c`
- `src/move.c`
- `src/util.c`

Run:

```bash
make test
```

### 3. Observe Incremental Builds

Run the following commands:

```bash
make clean
make
make
```

Then modify only `src/move.c` and run:

```bash
make
```

Answer in `build_notes.md`:

- What happens when `make` is executed a second time without changes?
- Which files are rebuilt after changing only `src/move.c`?
- How does Make decide whether a target must be rebuilt?
- What are cascading dependencies?

### 4. Improve the Makefile

Improve your Makefile so that:

- `all`, `clean`, and `test` are marked as phony targets
- object files are stored in a separate `build` folder
- `clean` removes generated executables and object files
- compiler flags are defined only once

Answer in `build_notes.md`:

- Why is a build system useful compared to manually typing GCC commands?
- What does Make know about dependencies that a single compiler command does not know?

## 🟡 Section III: Describe the Build with CMake

In this section, you will use CMake as a meta-build system.
CMake does not replace the compiler. It generates build files for other tools such as Make, Ninja, Visual Studio, or Xcode.

### Task Description

Create a file called `CMakeLists.txt` in `build_phase_project`.

### 1. Create a First CMake Project

Your `CMakeLists.txt` should:

- require a recent CMake version
- define a project name and version
- specify C as the project language
- create a library target from `src/board.c`, `src/move.c`, and `src/util.c`
- create an executable target from `src/main.c`
- link the executable against the library target
- add the `include` directory through `target_include_directories`
- request the C11 language standard

Configure and build the project:

```bash
cmake -S . -B build
cmake --build build
```

Run the generated executable from the build folder.

### 2. Add Target-Based Compiler Options

Add compiler options to your CMake targets.

For GCC:
* show all warnings and extra warnings
* treat warnings as errors
* add debugging information
* optimize for performance

For the Microsoft Visual C++ compiler from Visual Studio, use an `if(MSVC)` block so that the project can be configured on different platforms.

Also add a compile definition for `STARTING_TIME` which is used in `main.c`.

Answer in `build_notes.md`:

- Why should compiler options be attached to targets instead of being global wherever possible?
- What is the difference between `target_compile_options` and `target_compile_definitions`?
- Why does CMake need platform-specific handling for compiler options?

### 3. Add a Test Executable

Add an executable target called `test_move` that uses:

- `tests/test_move.c`
- the library target created from the production source files

Build and run the test executable.

Answer in `build_notes.md`:

- What does `target_link_libraries` express?
- Why is it useful to separate reusable code into a library target?

### 4. Build the Project in a Small GitLab Pipeline

In this task, you will move the CMake build into a small GitLab CI pipeline.
The goal is to connect the local build phase with an automated build job.

Create a GitLab repository for `build_phase_project` or copy the project into an existing private GitLab repository.

Add a `.gitlab-ci.yml` file in the repository root.
The pipeline should have at least one stage called `build`.

Create a job called `cmake-build`.
The job should:

- use a Linux image that contains or installs GCC, Make, and CMake
- configure the project with CMake
- build the project with CMake
- run the `test_move` executable
- store the `build/` directory as an artifact

Commit and push the pipeline file.
Open GitLab and inspect the pipeline result.

Answer in `build_notes.md`:

- Where can you see compiler warnings or errors in GitLab?
- Why is it useful to run the build phase automatically in a pipeline?
- What would happen in a team project if a commit breaks the build?
