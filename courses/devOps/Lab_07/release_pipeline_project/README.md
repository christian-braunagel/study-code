# StatusAnalyzer release lab

This small C++17 application reports the average system load and its status.
It is the shared starter project for all sections of Lab 07.

## Build and test

Install GCC, CMake, Make, GoogleTest, and gcovr, then run:

```bash
cmake -S . -B build -G "Unix Makefiles"
cmake --build build
ctest --test-dir build --output-on-failure
gcovr --root . --filter src/ --txt coverage_report.txt
gcovr --root . --filter src/ --html-details coverage_report.html
```

Run `./build/status_analyzer_app` (`.exe` on Windows).
The pipeline builds a Linux executable in `gcc:14`; run that package in a
compatible Linux environment with the GCC runtime libraries, not directly in Windows.
This teaching package does not bundle runtime dependencies or provide an installer.

The three unit tests cover average calculation, the overload boundary, and empty input.
Coverage is filtered to production sources under `src/`, including `main.cpp`;
the unit tests do not execute the application's `main()`, so some uncovered lines are expected.

## Pipeline

Copy this directory's contents, including `.gitlab-ci.yml` and `.gitignore`, to
the root of your own GitLab repository. Build and test are separate stages.
GitLab downloads artifacts from successful jobs in earlier stages automatically.
The test stage uses the existing build; it does not compile again.

Extend this pipeline by following `../Lab_07.md`. The completed pipeline is in
`../solution/.gitlab-ci.yml`; copy it over this starter only after the exercises.
Keep generated keys outside Git and outside package/artifact directories.
