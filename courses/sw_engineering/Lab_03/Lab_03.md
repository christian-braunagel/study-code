# Lab 3: Software Implementation and Verification

This lab is designed to help you understand the implementation and verification phases of the software engineering lifecycle by implementing changes and using automated checks to verify their behavior.

🟢 __Simple__: A guided software engineering activity that introduces the basic concepts step by step. It should not take more than 15 - 20 minutes to finish.

🟡 __Moderate__: A software engineering activity that asks you to apply the concepts to a realistic team or project situation. These tasks can usually be completed in about 30 - 45 minutes, depending on your prior knowledge.

🔴 __Complex__: A more demanding or longer software engineering activity that requires you to combine concepts, make decisions as a team, and work through a broader project context. Such tasks might take up to a few hours to complete.


## 🟡 Section I: Case Study - Software License Review

In this exercise, you will review licensing decisions made during software implementation and preparation for release.
Some decisions contain mistakes; others are acceptable under the stated conditions. Your task is to distinguish them and justify your assessment.

### Task Description

#### Company: GreenByte Solutions

GreenByte Solutions develops C++ applications and internal tools.
During a review, the team collects the following eight scenarios from different projects.
Treat each scenario independently. All component names are fictional.
Assume that the stated licenses apply to the relevant versions and that no additional permissions, commercial agreements, or license exceptions exist unless explicitly mentioned.

#### Scenario A: A Useful Repository

Mara finds a public GitLab repository containing a substantial C++ parser that would save several days of work.
The repository has no license file, license headers, or other statement granting reuse rights.
She copies the parser into a product that will be delivered to customers and records the repository URL in an internal document.
Her colleague approves the change because anyone can download the repository without paying.

#### Scenario B: The Commercial Desktop Application

Jonas integrates an unmodified MIT-licensed library into a desktop application that GreenByte sells to customers.
The application remains proprietary, and customers receive no application source code.
The distributed package contains the library's complete MIT license text and copyright notice in an accessible third-party licenses file.
The team confirms that these notices accompany every distributed copy.

#### Scenario C: Cleaning Up the Headers

Lea copies several substantial functions from an MIT-licensed project into GreenByte's application.
Before release, she removes the original copyright and license notices from the copied files to make the source code look consistent.
The customer package contains only GreenByte's proprietary license; no copy of the MIT notice is supplied elsewhere.
Lea argues that the original license is unnecessary because the functions have been renamed and slightly modified.

#### Scenario D: The Downloadable Utility

Amir modifies an existing utility licensed under GPL-3.0-only and distributes the modified executable to customers through a download portal.
He includes the GPL license text and retains the original notices.
However, GreenByte provides neither the corresponding source code nor any GPL-compliant way to obtain it, and refuses source requests because the modifications are considered confidential.
The team believes the license text alone is sufficient because the utility is distributed free of charge.

#### Scenario E: An Internal Analysis Tool

Sofia modifies a GPL-3.0-only analysis tool for use by employees within GreenByte's single legal entity.
The tool and its modifications remain inside that organization: no copies are supplied to customers, contractors, or other organizations, and no external service is offered.
The team retains the existing license and copyright notices but does not publish its modifications on the internet.
A reviewer claims that every modification to GPL software must immediately be made publicly available.

#### Scenario F: The Reporting Component

Ben modifies an Apache-2.0-licensed reporting component and includes it in a proprietary application delivered to customers.
The team supplies the Apache 2.0 license text, preserves the applicable original notices, and includes the relevant attribution notices from the component's existing `NOTICE` file in the distribution.
Modified source files carry prominent statements that GreenByte changed them.
The team keeps its own application source private and claims no ownership of the original component.

#### Scenario G: The Updated Exporter

Nina changes several source files in an Apache-2.0-licensed exporter and distributes the modified source package to customers.
She includes the Apache license, preserves applicable existing copyright and attribution notices, and carries over the relevant contents of its `NOTICE` file.
The modified files contain no statements that they were changed.
Nina considers a private Git history sufficient evidence of the modifications.

#### Scenario H: A Small Open Source Project

Three colleagues create a standalone C++ testing helper entirely from their own code.
GreenByte owns the necessary rights and explicitly authorizes its release under the MIT license.
The published repository includes the complete MIT license with the appropriate copyright notice.
Another company uses the helper in a commercial product, retains the required notices, and does not publish its own product's source code or pay GreenByte a fee.
One colleague wants to object because they expected commercial users to request separate permission.

#### Your Review

For each scenario, identify the license of the reused component or published helper and classify its type: **permissive**, **weak copyleft**, or **strong copyleft**. If no license is provided, record **no license / no reuse permission stated** instead of assigning an open source license type.
Distinguish this component license from the license of the surrounding application. Not every category must appear in the scenarios.
Briefly justify your classification, then decide whether the actions are acceptable under the stated license conditions or whether a mistake has been made.

Use the following structure:

| Scenario | License and type | Acceptable or mistake? | Reason and supporting license provision | Required correction, or why none is needed |
| --- | --- | --- | --- | --- |
| A | | | | |
| B | | | | |
| C | | | | |
| D | | | | |
| E | | | | |
| F | | | | |
| G | | | | |
| H | | | | |

Support your decisions with the relevant license wording or section number. A link alone is not an explanation.
For a problematic scenario, propose a concrete correction that would allow the team to proceed.

#### Reference Material

Use these references when reviewing the scenarios:

* [MIT license text](https://opensource.org/license/mit)
* [Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0), especially Section 4
* [GNU GPL version 3](https://opensource.org/license/gpl-3.0), especially Sections 2, 5, and 6
* [Repositories without a license](https://choosealicense.com/no-permission/)
* [License comparison and copyleft categories](https://choosealicense.com/licenses/)


## 🟡 Section II: Your First GitLab Pipeline

In this exercise, you will create a continuous integration (CI) pipeline that automatically checks a small C++ implementation.
You will trigger it by pushing a commit and by creating or updating a merge request (MR), then experience how a failing test provides feedback before a change is merged.

### Prerequisites

* A GitLab account and permission to push branches and create merge requests in your project.
* Git installed locally and authentication configured for your GitLab instance.
* An available Linux runner using the Docker or Kubernetes executor that can run the `gcc:14` image. Check **Settings > CI/CD > Runners**; ask your instructor if no suitable runner is available. This exercise uses jobs without runner tags.

The C++ compiler runs inside the pipeline's container, so a local compiler installation is optional.
A **pipeline** contains automated **jobs**; a **runner** executes those jobs. **Stages** group jobs and determine their order.

### Task Description

#### 1. Prepare a Repository

Create a blank GitLab project named `first-pipeline` and initialize it with a README.
Clone the project using the clone URL shown by GitLab, then enter its directory:

```bash
git clone <your-project-clone-url>
cd first-pipeline
git switch -c ci/first-pipeline
```

Replace `<your-project-clone-url>` with your actual URL.
If you use an instructor-provided practice project, clone that project instead and choose an unused branch name.

#### 2. Add a Small Implementation and Tests

Create `calculator.hpp` in the repository root:

```cpp
#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

int add(int a, int b);

#endif // CALCULATOR_HPP
```

Create `calculator.cpp` beside it:

```cpp
#include "calculator.hpp"

int add(int a, int b)
{
    return a + b;
}
```

Create `test_calculator.cpp` in the same directory:

```cpp
#include "calculator.hpp"
#include <iostream>

int main()
{
    int failures = 0;

    const auto check = [&failures](const char* name, int actual, int expected)
    {
        std::cout << name << ": expected " << expected
                  << ", actual " << actual;
        if (actual != expected)
        {
            std::cout << " [FAIL]\n";
            ++failures;
        }
        else
        {
            std::cout << " [PASS]\n";
        }
    };

    check("Positive numbers", add(2, 3), 5);
    check("Negative number", add(-2, 3), 1);

    return failures == 0 ? 0 : 1;
}
```

This small test program checks expected behavior without an external test framework.
It returns exit code `0` when both checks pass and `1` if any check fails. GitLab uses a command's exit code to determine success or failure.

#### 3. Define the Pipeline

Create `.gitlab-ci.yml` in the repository root. Preserve the leading dot and use spaces for YAML indentation.

```yaml
default:
  image: gcc:14

workflow:
  rules:
    - if: '$CI_PIPELINE_SOURCE == "merge_request_event"'
    - if: '$CI_COMMIT_BRANCH && $CI_OPEN_MERGE_REQUESTS && $CI_PIPELINE_SOURCE == "push"'
      when: never
    - if: '$CI_COMMIT_BRANCH && $CI_PIPELINE_SOURCE == "push"'

stages:
  - build
  - test

build_tests:
  stage: build
  script:
    - g++ -std=c++17 -Wall -Wextra -Werror calculator.cpp test_calculator.cpp -o test_calculator
  artifacts:
    paths:
      - test_calculator

unit_tests:
  stage: test
  script:
    - 'echo "Pipeline source: $CI_PIPELINE_SOURCE"'
    - ./test_calculator
```

`build_tests` compiles and links the implementation and test program. After it succeeds, `unit_tests` runs the resulting executable to check behavior.
The `gcc:14` image supplies the C++ compiler. The build job saves `test_calculator` as an **artifact**, which GitLab downloads into the test job because it runs in a later stage. Jobs have separate working environments, so this explicitly passes the executable between them.

The `workflow` rules create a branch pipeline for a push when the branch has no open MR. Once an MR is open, GitLab uses merge request pipelines instead, avoiding duplicate branch and MR pipelines for the same push.
You do not need to memorize these rules for this exercise.

#### 4. Trigger a Pipeline with a Push

Commit and push the four files:

```bash
git add calculator.hpp calculator.cpp test_calculator.cpp .gitlab-ci.yml
git commit -m "Add implementation, tests, and first CI pipeline"
git push -u origin ci/first-pipeline
```

Open **Build > Pipelines** in your GitLab project and select the new pipeline.

* Confirm that `build_tests` runs before `unit_tests` and that both pass.
* Open the `unit_tests` job log. Find the two test results and the pipeline source, which should be `push`.
* Identify the branch and commit associated with this pipeline.

If a job stays pending, check whether a runner is available and eligible to run untagged jobs on your branch. If the configuration is rejected, check the YAML indentation and filename; use GitLab's pipeline editor validation if available.

#### 5. Trigger a Merge Request Pipeline and Experience a Failure

Create an MR in GitLab from `ci/first-pipeline` into the project's default branch. Leave it open.
Creating the MR should start a merge request pipeline. Open it from the MR's pipeline area and find `merge_request_event` in the `unit_tests` job log.

Now deliberately introduce a bug in `calculator.cpp` by changing the function to:

```cpp
int add(int a, int b)
{
    return a - b;
}
```

Keep the `#include "calculator.hpp"` line at the top of the file.

Commit and push the change to the same branch:

```bash
git add calculator.cpp
git commit -m "Introduce a calculation bug to observe CI feedback"
git push
```

Inspect the new pipeline associated with the open MR.

* Verify that `build_tests` passes, but `unit_tests` fails.
* Read the failure output and identify the expected and actual results.
* Explain why successful compilation does not imply correct behavior.

Restore `return a + b;`, commit the fix, and push again. Confirm that a new MR pipeline passes.
A push updates the existing MR; you do not need to create another one.

#### 6. Reflect on Implementation and Verification

Record the pipeline link and result for the initial push, the failing MR update, and the successful fix.
Then answer briefly:

* Do you understand the complete pipeline code and how it works? If not, which parts are unclear? Try to figure it out and explain them in your own words.
* What triggered each pipeline, and which commit did it verify?
* How did the pipeline connect implementation work to verification?
* Does a passing pipeline prove that the entire program is correct? Explain one limitation of these tests.

Submit your MR link and these observations. Keep the successful MR available for review.

GitLab references: [Merge request pipelines](https://docs.gitlab.com/ci/pipelines/merge_request_pipelines/) and [switching between branch and merge request pipelines](https://docs.gitlab.com/ci/yaml/workflow/#switch-between-branch-pipelines-and-merge-request-pipelines).

## 🟡 Section III: Possible Exam Questions for Verification

This section contains a selection of possible exam questions related to software verification and quality assurance. They are based on the slides and exercises from the course.

### 1. Verification, Validation, QA and QC

A company develops a navigation system for emergency vehicles. The following activities are performed during development.

**a)** Classify each activity as primarily **Verification, Validation, Quality Assurance (QA), or Quality Control (QC)**. Explain your decision.

| Activity | Classification |
|---|---|
| A. Emergency responders evaluate whether the system supports their actual workflows. | |
| B. A developer checks whether the implemented route calculation matches the specified algorithm. | |
| C. The organization introduces mandatory coding guidelines and review procedures. | |
| D. The test team executes tests to identify defects in the finished software. | |

**b)** Explain the fundamental difference between Verification and Validation.

**c)** Explain why QA should not be replaced entirely by QC activities.


### 2. Review Metrics

Two development teams review different software components. The following results are available:

| Metric | Team A | Team B |
|---|---:|---:|
| Component size (LOC) | 2,000 | 3,000 |
| Reviewed LOC | 1,600 | 3,000 |
| Defects found | 24 | 30 |
| Total review effort | 8 h | 15 h |
| Critical defects | 3 | 1 |
| Major defects | 9 | 11 |
| Minor defects | 12 | 18 |

**a)** Calculate the **defect density per KLOC** for each team, using reviewed LOC as the denominator.

**b)** Calculate the **defect detection rate** in defects per review hour.

**c)** Calculate the **review coverage** of each team as a percentage.

**d)** Which team has the higher defect detection rate? Does this necessarily mean that its review process is more effective? Justify your answer.

**e)** Explain why the defect severity distribution is relevant when prioritizing corrective actions.


### 3. Pair Programming

Two developers implement a safety-critical monitoring component using pair programming.

**a)** Describe the responsibilities of the **Driver** and **Navigator**.

**b)** Explain two advantages of pair programming compared with working individually and reviewing the code only after implementation.

**c)** State one potential disadvantage of pair programming and propose one measure to mitigate it.


### 4. Types of Static Analysis

Assign the most appropriate type of static analysis to each finding.

Choose from: **Linting, Static Application Security Testing (SAST), Software Composition Analysis (SCA), Code Quality Analysis, Compliance Checking.**

Tools may cover several categories; select the best fit. Types may be used more than once.

| Finding | Analysis type |
|---|---|
| A. A function name violates the project's naming convention. | |
| B. A third-party library contains a known CVE. | |
| C. User input is concatenated into an SQL query. | |
| D. Several classes contain almost identical implementations. | |
| E. A C++ implementation violates an AUTOSAR C++ coding rule. | |
| F. A local variable could be declared `const`. | |
| G. A component contains a deeply nested function that is difficult to maintain. | |
| H. A third-party dependency inventory identifies a library whose license is prohibited by company policy. | |
| I. An unsafe buffer operation may cause a buffer overflow. | |
| J. Source code violates a mandatory MISRA C++ rule. | |

### 5. Static Code Analysis of C++

Consider the following simplified C++ code for calculating an aircraft's target climb airspeed. All airspeeds and corrections are expressed in knots; the limits are illustrative values for this question.

```cpp
#define MAX_AIRSPEED_KNOTS 250

int CalculateTargetAirspeed(int* measuredAirspeed, int correctionKnots)
{
    int targetAirspeed = *measuredAirspeed + correctionKnots;

    // Keep the target above the minimum climb airspeed.
    if (targetAirspeed < 120)
    {
        targetAirspeed = 120;
    }

    // Limit the target to the maximum permitted airspeed.
    if (targetAirspeed = MAX_AIRSPEED_KNOTS)
    {
        targetAirspeed = MAX_AIRSPEED_KNOTS;
    }

    return targetAirspeed;
}
```

Identify **four issues** that could be reported by a linter or code quality analysis tool. For each issue, briefly explain the problem and propose a correction.


## 🟡 Section IV: Calculating Test Coverage

In this exercise, you will calculate **branch coverage, condition coverage, modified condition/decision coverage (MC/DC), and path coverage** for the same test suite. You will then extend the suite to meet each coverage target.

### Task Description

A monitoring component activates an alarm when both sensors report a fault or when a manual override is active. It also records whether logging is enabled.

Consider the following C++ function. All inputs are independent Boolean values, and every input combination is valid.

```cpp
int EvaluateAlarm(bool sensorA, bool sensorB, bool manualOverride, bool loggingEnabled)
{
    int result = 0;

    // Boolean bitwise operators to avoid short-circuiting and ensure all conditions are evaluated.
    const bool alarmRequired = (sensorA & sensorB) | manualOverride;

    if (alarmRequired) // D1: (A AND B) OR C
    {
        result += 1;
    }

    if (loggingEnabled) // D2: D
    {
        result += 2;
    }

    return result;
}
```

Use these condition labels: **A** = `sensorA`, **B** = `sensorB`, **C** = `manualOverride`, and **D** = `loggingEnabled`.

The initial test suite contains three tests:

| Test | A | B | C | D |
|---|---|---|---|---|
| T1 | True | True | False | True |
| T2 | False | False | False | False |
| T3 | True | False | True | True |




For each metric, show the covered items, the total number of items, and the resulting percentage:

`Coverage = covered items / total items * 100%`

### Tasks

**a) Trace the tests.** Complete the table before calculating coverage.

In **Path (D1, D2)**, record the two `if` outcomes in order. For example, `(True, False)` means the first `if` body executes and the second is skipped. Tests with the same pair follow the same path.


| Test | D1 outcome | D2 outcome | Return value | Path (D1, D2) |
|---|---|---|---|---|
| T1 | | | | |
| T2 | | | | |
| T3 | | | | |

**b) Calculate branch coverage.** List the observed outcomes for D1 and D2, then calculate the coverage of the initial suite.

**c) Calculate condition coverage.** List the observed outcomes for A, B, C, and D, then calculate the coverage of the initial suite. Explain why condition coverage and branch coverage measure different things.

**d) Calculate MC/DC.** For each condition, identify a valid independence pair from T1–T3 or explain why no pair exists. Calculate the percentage using the counting rules above. Can a suite reach 100% branch and condition coverage without achieving full MC/DC? Use your results to justify your answer.

| Condition | Decision | Independence pair, or reason no pair exists |
|---|---|---|
| A | D1 | |
| B | D1 | |
| C | D1 | |
| D | D2 | |

**e) Calculate path coverage.** Enumerate all feasible paths, identify those executed by T1–T3, and calculate the coverage. Explain why testing every Boolean input combination is not required for full path coverage in this function.

**f) Extend the suite.** Keep T1–T3 and add tests until the combined suite achieves **100% of all four metrics**. Use as few additional tests as you can, and justify your choice. Give every added test a unique ID and specify its inputs, expected decision outcomes, and expected return value.
