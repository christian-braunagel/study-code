# Lab 6: The Pre-Build and Verification Phase

This lab focuses on the steps that are performed to verify the code quality before and after the build phase. This includes tasks such as linting, format checking, unit testing, and many more.

All the following sections of this lab are based on the following levels of difficulty:

🟢 **__Simple__**: A simple task that guides you step by step through the process and focuses on learning the basics. It should not take more than 15 minutes to finish.

🟡 **__Moderate__**: A task that states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30 minutes depending on your knowledge.

🔴 **__Complex__**: A difficult or longer task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours.

## 🟢 Section I: Code Formatting

In this section, you will learn how to automatically format your code using a code formatter. This ensures that your code adheres to a consistent style and improves readability.

## Part I: Installation

First we need to install the necessary tools for this lab. This includes a code formatter and a linter.

### Task Description

Assumption: You have already installed MSYS2 and the UCRT64 environment on your system. If not, please refer to section III of [Lab_01](https://gitlab.com/braunagel.christian/study-code/-/blob/main/courses/coding-in-C/Lab_1/Lab_1.md?ref_type=heads) for installation instructions.

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
IndentWidth: 4
TabWidth: 4
UseTab: Never
ColumnLimit: 100
BreakBeforeBraces: Linux
```
* Create a small C or C++ source file with intentionally inconsistent formatting, for example `main.cpp` which consists of a main function with only one line of code.

* You might need to edit the file in a simple text editor to make it look messy without getting it automatically formatted by the editor when saving.

* Format this single file in place by running:
```bash
clang-format -i main.cpp
```
* Check the changed file and verify that the formatting now follows the rules from `.clang-format`.

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
* Commit the changes and push them to your remote repository.
* On the remote repository, create a pipeline that runs `clang-format` on all source files and fails if any file is not formatted correctly.
* Test the pipeline by changing a source file and pushing it to the remote repository. The pipeline should fail and show which files are not formatted correctly.

### Requirements

  * use 4 spaces for indentation
  * never use tabs
  * limit lines to 80 characters
  * place opening braces on a new line
  * align pointers to the left, for example `int* value`
  * sort include statements automatically
  * add spaces inside braced initializer lists, for example `{ 3, 7, 11, 15 }`
  * do not keep short functions on a single line

## 🟡 Section II: Static Code Analysis with a Linter

In this section, you will use a linter to find suspicious code before the build or test phase.
Formatting tools mainly change how code looks.
Linters inspect the code and warn about possible bugs, unsafe constructs, unused values, and maintainability problems.

### Task Description

The folder `linting_sensor_project` contains a small C++ project with typical defects that a linter can detect.
Your task is to run the linter manually first and then extend the GitLab pipeline from Section I with an automated linting job.

### 1. Inspect the Project

* Open the folder `linting_sensor_project`.
* Inspect the files in the `include` and `src` folders.
* Do not fix the code yet.
* Open the `.clang-tidy` file and check which checks are enabled.

### 2. Run the Linter Manually

Run `clang-tidy` from inside the `linting_sensor_project` folder.

#### Windows PowerShell
```powershell
Get-ChildItem -Recurse -Include *.cpp,*.hpp | ForEach-Object { clang-tidy --config-file=.clang-tidy $_.FullName -- -std=c++17 -Wall -Iinclude }
```

#### Ubuntu/macOS
```bash
clang-tidy --config-file=.clang-tidy src/*.cpp include/*.hpp -- -std=c++17 -Wall -Iinclude
```

Write down the reported warnings in a file called `linting_notes.md`.

Answer:

* Which warnings point to real bugs?
* Which warnings point to maintainability or readability problems?
* Why is it useful to run the linter before the build job?

### 3. Fix the Reported Problems

* Fix the problems reported by `clang-tidy`.
* Run the manual lint command again.
* Repeat this until the linter no longer reports errors.
* Commit the fixed source files together with `linting_notes.md`.

### 4. Add Linting to the GitLab Pipeline

Copy `linting_sensor_project` into the GitLab repository that already contains the formatting pipeline from Section I, or create a new repository for this project and reuse the same pipeline structure.

Update `.gitlab-ci.yml` so that the pipeline contains a linting job.
The job should:

* use a Linux image that contains or installs `clang-tidy`
* run after the formatting job from Section I
* run `clang-tidy` on all `.cpp` and `.hpp` files
* fail the pipeline when the linter reports warnings or errors

Commit and push the pipeline update.
Create a new file with a small formatting or linting problem and push it to the remote repository.
The pipeline should fail and show the reported problems.

## 🟡 Section III: Security Scanning with GitLab and Trivy

In this section, you will extend the pipeline with security scanning.
Use GitLab's predefined CI/CD templates for Secret Detection and SAST, and add a separate job using Trivy for dependency scanning.
Trivy runs as a regular CI job and does not require GitLab Ultimate dependency scanning.

You will enable:

* Secret Detection using a GitLab template
* Static Application Security Testing (SAST) using a GitLab template
* Dependency scanning using Trivy

### Task Description

Use the GitLab repository from the previous sections.
Your task is to update the existing `.gitlab-ci.yml` file so that GitLab runs security scans automatically in the pipeline.

### 1. Read About the Security Scanners

Read the documentation for:

* Secret Detection:
  [https://docs.gitlab.com/user/application_security/secret_detection/pipeline/](https://docs.gitlab.com/user/application_security/secret_detection/pipeline/)
* Trivy filesystem scanning:
  [https://trivy.dev/docs/latest/target/filesystem/](https://trivy.dev/docs/latest/target/filesystem/)
* Trivy Python dependency detection:
  [https://trivy.dev/docs/latest/coverage/language/python/](https://trivy.dev/docs/latest/coverage/language/python/)
* SAST:
  [https://docs.gitlab.com/user/application_security/sast/](https://docs.gitlab.com/user/application_security/sast/)

Answer in `security_notes.md`:

* What kind of problem does each scanner try to find?

### 2. Prepare a Small Dependency Example

Dependency scanning needs dependency information.
Add a small dependency manifest to your repository, for example a Python requirements file:

```text
flask==2.0.0
requests==2.25.0
```

Store it as `requirements.txt` in the repository root.
These older versions are intentional training examples for finding known vulnerabilities.

Add a small source file called `app.py` so that SAST has source code to inspect:

```python
from flask import Flask, request

app = Flask(__name__)

@app.route("/search")
def search():
    query = request.args.get("q", "")
    return "Search query: " + query
```

Do not add real credentials to the repository.
If you want to test secret detection, use only an obviously fake training value and remove it again after the experiment.

### 3. Include GitLab Native Security Templates

Update `.gitlab-ci.yml`.
Keep the formatting and linting jobs from the previous sections and include the GitLab security templates for Secret Detection and SAST:

GitLab security scanning jobs use the `test` stage by default, so the pipeline must contain a `test` stage.

### 4. Add a Separate Trivy Dependency Scanning Job

Create a job called `trivy-dependencies` in `.gitlab-ci.yml`.
The job should:

* run in the `test` stage
* use the official `aquasec/trivy` container image with a specific release tag
* override the image entrypoint with `entrypoint: [""]` so GitLab can execute the job script
* scan the repository's dependency files using `trivy fs --scanners vuln .`
* save a JSON vulnerability report and a CycloneDX Software Bill of Materials (SBOM)
* fail when vulnerabilities with severity `HIGH` or `CRITICAL` are found
* upload both report files as ordinary job artifacts, even when the job fails, using `artifacts: when: always` and `paths`

Use these commands in the job script, in this order:

```bash
trivy --version
trivy fs --scanners vuln --exit-code 0 --format json --output trivy-report.json .
trivy fs --format cyclonedx --exit-code 0 --output trivy-sbom.cdx.json .
trivy fs --scanners vuln --severity HIGH,CRITICAL --exit-code 1 .
```

The first two scans save reports before the final scan checks the severity threshold.
`--exit-code 1` makes the job fail when matching vulnerabilities are found; scanner execution errors also fail the job.

For this example, Trivy reads the exact package versions from `requirements.txt` without installing the application.
It only detects dependencies listed in that file. Indirect (transitive) dependencies must also be listed to be scanned, for example by generating a complete requirements file with `pip-compile`.
See the [Trivy Python documentation](https://trivy.dev/docs/latest/coverage/language/python/) for this limitation.

Answer in `security_notes.md`:

* What is the difference between scanning source code with SAST and scanning dependencies with Trivy?
* Why are the report commands executed before the command with `--exit-code 1`?
* What information could be missing when scanning only the two-line `requirements.txt`?

### 5. Run and Inspect the Pipeline

Commit and push the updated files.

Open GitLab and inspect:

* the jobs created by the included security templates
* the separate `trivy-dependencies` job
* the job logs of the security scanners
* the security findings, if your GitLab project shows a security or vulnerability report

Open the artifacts of `trivy-dependencies` and inspect:

```text
trivy-report.json
trivy-sbom.cdx.json
```

The JSON report contains vulnerability findings; the SBOM lists the detected packages and versions.
Inspect these ordinary artifacts through the job page. They are not automatically displayed as a native GitLab dependency scanning vulnerability report.
With the intentionally old dependencies, the Trivy job is expected to fail if the database reports `HIGH` or `CRITICAL` vulnerabilities.
If a report is missing, inspect the job log for scanner errors and verify that `requirements.txt` is committed and artifact upload uses `when: always`.

Answer in `security_notes.md`:

* Which new jobs were added by the templates?
* Which job did you add manually for dependency scanning?
* Which stage did the security jobs run in?
* Did the pipeline pass or fail?
* Where can you see the scanner results in GitLab?
* Was an SBOM artifact created? If yes, what is the file name?
* Which dependencies are listed in the SBOM?
* Which vulnerabilities caused the Trivy job to fail, and which fixed versions does the report suggest?


## Section IV: Unit Testing with GoogleTest, CMake, and a Pipeline

In this section, you will add automated unit tests to a small C++ project and run them in a GitLab pipeline.
The CMake basics were already introduced in Lab 05, so this section focuses on the new parts: integrating GoogleTest, registering tests with CTest, and making the pipeline fail when a test fails.

The folder `gtest_pipeline_project` contains a small C++ program that analyzes system load samples.
Your task is to write meaningful tests for this code and verify that the same tests run locally and in GitLab CI.

### Task Description

Open the folder `gtest_pipeline_project`.
Inspect the files in `include` and `src`.

The production code contains:

* `StatusAnalyzer::averageLoad`, which calculates the average of integer load samples
* `StatusAnalyzer::isOverloaded`, which checks whether the average load is at least `80.0`
* `StatusAnalyzer::statusMessage`, which returns either `OK` or `OVERLOADED`

Create a file called `testing_notes.md` and use it to document your observations.

### 1. Extend the CMake Project with GoogleTest

Use the tools from Lab 05 and verify that they are available.
GoogleTest must also be installed on the system so CMake can find it.

Create a `CMakeLists.txt` file for `gtest_pipeline_project`.
Use the target-based CMake style from Lab 05:

* define a C++17 project
* create a library target for `src/status_analyzer.cpp`
* add the `include` folder to that library target
* create an application target for `src/main.cpp`
* link the application target against the library target

Then add GoogleTest support.
Use an installed GoogleTest package and let CMake find it:

```cmake
find_package(GTest REQUIRED)
```

`find_package` asks CMake to locate an installed library and make its CMake targets available.
For GoogleTest, the important target in this lab is `GTest::gtest_main`.

Create a test target in the same `CMakeLists.txt`.
It should:

* build `tests/status_analyzer_tests.cpp`
* link against your production library
* link against `GTest::gtest_main`
* be registered with CTest by using `gtest_discover_tests`

You will need these CMake lines around the test target:

```cmake
include(CTest)
enable_testing()

include(GoogleTest)
gtest_discover_tests(<your-test-target>)
```

`gtest_discover_tests` asks the compiled GoogleTest executable which tests it contains and then registers those tests with CTest.
This is the bridge between GoogleTest and the `ctest` command.

Answer in `testing_notes.md`:

* Which CMake target contains the reusable production code?
* Which CMake target contains the tests?
* Why should the tests link against the production library instead of compiling a second copy of the same implementation manually?

### 3. Write Unit Tests

Create a `tests` folder and a file called `tests/status_analyzer_tests.cpp`.

Use this minimal structure as a starting point:

```cpp
#include "status_analyzer.hpp"

#include <gtest/gtest.h>

TEST(StatusAnalyzerTest, DescriptiveTestName)
{
    // Arrange: create the object and input data
    // Act: call the function under test
    // Assert: check the result with a GoogleTest expectation
}
```

Write your own test cases.
Your test suite should verify at least:

* the average of several load samples
* the overload boundary at exactly `80.0`
* a non-overloaded value below the boundary
* the status text for a normal load
* the status text for an overloaded load
* the behavior for an empty sample list

Useful GoogleTest expectations:

* `EXPECT_DOUBLE_EQ(actual, expected)` for floating-point results
* `EXPECT_TRUE(expression)` for conditions that must be true
* `EXPECT_FALSE(expression)` for conditions that must be false
* `EXPECT_EQ(actual, expected)` for exact equality
* `EXPECT_THROW(statement, exception_type)` when an exception is expected

Answer in `testing_notes.md`:

* Which input values did you choose for each test?
* Which edge case did you test?
* Why is the boundary value `80.0` important?

### 4. Build and Run the Tests Locally

Configure the project:

```bash
cmake -S . -B build -G "Unix Makefiles"
```

The `-G "Unix Makefiles"` parameter tells CMake to generate Makefiles.
This keeps the build step close to the Make-based workflow from Lab 05.

Build the project:

```bash
cmake --build build
```

Run the tests through CTest:

```bash
ctest --test-dir build --output-on-failure
```

The `--output-on-failure` parameter is useful in pipelines because it prints the failing test output directly into the job log.

Run the application as an additional manual check:

```bash
./build/status_analyzer_app
```

On Windows PowerShell, the executable may be called:

```powershell
.\build\status_analyzer_app.exe
```

Answer in `testing_notes.md`:

* How many tests were discovered by CTest?
* Which command builds the test executable?
* Which command runs the tests?
* Why is it useful to run tests through CTest instead of only starting the test executable manually?

### 5. Prove That the Tests Can Fail

Temporarily introduce one small bug into `src/status_analyzer.cpp`.
For example, change the overload boundary so that exactly `80.0` is handled incorrectly.

Rebuild and rerun the tests:

```bash
cmake --build build
ctest --test-dir build --output-on-failure
```

At least one test should fail.
After observing the failure, undo the temporary bug and run the tests again.
The tests should pass again.

Answer in `testing_notes.md`:

* Which test failed?
* What did the failure message tell you?
* Why is a deliberately failing test useful before trusting a new pipeline?

### 6. Add GoogleTest to the GitLab Pipeline

Create a `.gitlab-ci.yml` file in the root of `gtest_pipeline_project` based on the pipeline from Section III.
Add a job called `gtest-cmake` that configures, builds, and tests the project.

The job should:

* run in the `test` stage
* use a Linux container with a recent GCC toolchain, for example `gcc:14`
* install CMake, Make, and GoogleTest before the build commands are executed
* run the same three commands that you used locally:

```yaml
script:
  - cmake -S . -B build -G "Unix Makefiles"
  - cmake --build build
  - ctest --test-dir build --output-on-failure
```

The `-G "Unix Makefiles"` parameter selects Makefiles as the generated build system.
The `--output-on-failure` parameter should stay in the pipeline because otherwise failed tests may be hard to diagnose from the job log.
In a Debian-based CI image, the GoogleTest package is called `libgtest-dev`.

Store `build/Testing/` as a pipeline artifact so the CTest output can be inspected after the job finishes.

Commit and push the CMake file, pipeline file, test file, and notes.
Open GitLab and inspect the pipeline result.

Answer in `testing_notes.md`:

* Which job ran the tests?
* Which commands are visible in the job log?
* Did the pipeline pass or fail?
* Where can you find the CTest output artifacts?

### 7. Verify That the Pipeline Protects the Project

Repeat the temporary bug from step 5 and push it.
The `gtest-cmake` job should fail.
Open the job log and find the failing test.

After verifying the failure, fix the bug again and push the fix.
The pipeline should pass again.

Answer in `testing_notes.md`:

* Which test caught the bug?
* Why did the pipeline fail?
* Why is it useful that the same test command runs locally and in GitLab?
* How could this job be combined with the formatting, linting, and security jobs from the previous sections?

## Section V: Measuring Test Coverage with gcov and gcovr

In this section, you will measure which parts of a small C++ project are executed by its tests.
Coverage does not tell you whether the tests are good, but it can show which code has not been executed at all.

First you will use `gcov` directly in the terminal.
After that, you will use `gcovr` to create a more readable summary.

### Task Description

Open the folder `gcov_coverage_project`.
Inspect the files in `include`, `src`, and `tests`.

The project contains a small temperature statistics module and a simple test program that uses `assert`.
The test program already checks some behavior, but it does not cover every branch.

Create a file called `coverage_notes.md` and use it to document your observations.

### 1. Verify the Required Tools

Check that GCC, gcov, and gcovr are available:

```bash
g++ --version
gcov --version
gcovr --version
```

If `gcovr` is missing, install it with your package manager or with Python:

```bash
python -m pip install gcovr
```

Notes:

* `g++` compiles the C++ source files.
* `gcov` reads coverage data produced by GCC.
* `gcovr` collects gcov data and creates compact reports.
* `python -m pip install gcovr` installs `gcovr` through Python's package installer.

Answer in `coverage_notes.md`:

* Which versions of `g++`, `gcov`, and `gcovr` do you use?
* Why should the compiler and coverage tool belong to the same toolchain?

### 2. Compile the Test Program with Coverage Flags

Compile the test program from inside `gcov_coverage_project`:

```bash
g++ --coverage -O0 -g -Iinclude src/temperature_stats.cpp tests/test_temperature_stats.cpp -o coverage_test
```

Important parameters:

* `--coverage` enables GCC's coverage instrumentation.
* `-O0` disables optimization, which makes coverage results easier to understand.

After compiling, inspect the generated files.
You should see files ending in `.gcno`.
These files contain coverage structure information that is created at compile time.

Answer in `coverage_notes.md`:

* Which `.gcno` files were created?
* Why is coverage instrumentation needed before running the program?

### 3. Run the Test Program

Run the executable:

```bash
./coverage_test
```

On Windows PowerShell, the executable may be called:

```powershell
.\coverage_test.exe
```

If the program exits without output, the assertions passed.
Inspect the generated files again.
You should now also see files ending in `.gcda`.
These files contain the execution counts collected while the program ran.

Answer in `coverage_notes.md`:

* Which `.gcda` files were created?
* Why are `.gcda` files created only after the executable has run?

### 4. Inspect Coverage with gcov

Run `gcov` for the production source file.
Depending on your compiler and platform, the generated coverage data file can have a slightly different name.
Look for the `.gcno` file that belongs to `temperature_stats.cpp` and pass it to `gcov`.

Example:

```bash
gcov coverage_test-temperature_stats.gcno
```

If your generated file has a different name, use that file instead.

`gcov` creates a readable file such as `temperature_stats.cpp.gcov`.
It may also create `.gcov` files for standard library headers.
For this task, focus on the report for `src/temperature_stats.cpp`.
Open it and inspect the left column:

* a number means the line was executed that many times
* `#####` means the line was not executed
* `-` means the line is not executable code

Answer in `coverage_notes.md`:

* Which functions were covered by the existing test program?
* Which lines or branches were not covered?
* Why does uncovered code not automatically mean that the code is wrong?

### 5. Improve the Test Program

Extend `tests/test_temperature_stats.cpp` with additional assertions.
Try to cover behavior that was missing in the first report.

Possible cases to consider:

* a high temperature classification
* a critical temperature above `80`
* a critical temperature below `-20`
* a list without critical temperatures
* an empty input vector for functions that reject empty input

Rebuild, rerun, and regenerate the gcov report:

```bash
g++ --coverage -O0 -g -Iinclude src/temperature_stats.cpp tests/test_temperature_stats.cpp -o coverage_test
./coverage_test
gcov coverage_test-temperature_stats.gcno
```

If your `.gcno` file has a different name, use your local file name again.

Answer in `coverage_notes.md`:

* Which new assertions did you add?
* Which coverage gaps disappeared?
* Which code is still uncovered?
* Can 100 percent line coverage still miss bugs? Explain briefly.

### 6. Create a Summary with gcovr

Using `gcov` directly is useful for understanding the raw coverage files, but larger projects need a compact summary.
Use `gcovr` from inside `gcov_coverage_project`:

```bash
gcovr --root . --print-summary
```

Important parameters:

* `--root .` tells `gcovr` that the current folder is the project root.
* `--print-summary` prints a short coverage summary in the terminal.

Create a detailed text report:

```bash
gcovr --root . --txt coverage_report.txt
```

Create an HTML report:

```bash
gcovr --root . --html --html-details coverage_report.html
```

Open `coverage_report.txt` and `coverage_report.html`.

Answer in `coverage_notes.md`:

* What line coverage percentage does `gcovr` report?
* Which report is easier to inspect: the gcov file, the text report, or the HTML report?
* Why might a pipeline prefer a compact text or XML coverage report?

### 7. Clean and Repeat

Remove the generated coverage and executable files, then rebuild from a clean state.

Typical generated files are:

* `coverage_test` or `coverage_test.exe`
* `*.gcno`
* `*.gcda`
* `*.gcov`
* `coverage_report.txt`
* `coverage_report.html`
* `coverage_report.*.html`

Run the complete workflow again:

```bash
g++ --coverage -O0 -g -Iinclude src/temperature_stats.cpp tests/test_temperature_stats.cpp -o coverage_test
./coverage_test
gcovr --root . --print-summary
```

Answer in `coverage_notes.md`:

* Why is it useful to clean generated coverage files before a new measurement?
* Which steps would you automate later in a pipeline?

