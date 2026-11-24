# Section III Solution: Possible Exam Questions for Verification

These sample answers correspond to [section III of Lab 3](../Lab_03.md#-section-iii-possible-exam-questions-for-verification). Equivalent explanations and correct alternative corrections are acceptable.

## 1. Verification, Validation, QA and QC

### a) Classification of activities

| Activity | Primary classification | Explanation |
| --- | --- | --- |
| A. Emergency responders evaluate support for their actual workflows. | Validation | Intended users assess whether the system meets their real needs in its intended context. |
| B. A developer checks the route calculation against the specified algorithm. | Verification | The implementation is checked against its specification. |
| C. The organization introduces mandatory coding guidelines and review procedures. | Quality Assurance (QA) | Process rules aim to prevent defects and establish consistent development practices. |
| D. The test team executes tests to identify defects in the finished software. | Quality Control (QC) | The team examines the product to detect defects. |

These concepts overlap: testing and reviews can be QC activities that support verification or validation. The table gives the primary classification requested in the question.

### b) Verification versus validation

**Verification** asks whether a work product satisfies its specified requirements: are we building the product correctly? For example, does the route calculation implement the specified algorithm?

**Validation** asks whether the resulting system meets users' needs and intended use: are we building the right product? A route calculation can implement its specification correctly while producing routes that are unsuitable for emergency responders.

### c) Why QA cannot be replaced entirely by QC

QA improves the processes that produce software, helping prevent defects and their recurrence. QC detects defects in the resulting work products. Detection alone does not address recurring process weaknesses, and tests cannot examine every possible behavior. Using both supports earlier prevention, systematic improvement, and product checks.

## 2. Review Metrics

### a) Defect density per KLOC

`Defect density = defects found / (reviewed LOC / 1,000)`

| Team | Calculation | Defect density |
| --- | --- | --- |
| A | 24 / (1,600 / 1,000) | 15 defects/KLOC |
| B | 30 / (3,000 / 1,000) | 10 defects/KLOC |

These values describe defects found in the reviewed code; they do not measure all defects present or remaining.

### b) Defect detection rate

`Defect detection rate = defects found / total review effort`

| Team | Calculation | Defect detection rate |
| --- | --- | --- |
| A | 24 / 8 | 3 defects per review hour |
| B | 30 / 15 | 2 defects per review hour |

### c) Review coverage

`Review coverage = reviewed LOC / component size in LOC * 100%`

| Team | Calculation | Review coverage |
| --- | --- | --- |
| A | 1,600 / 2,000 * 100% | 80% |
| B | 3,000 / 3,000 * 100% | 100% |

### d) Comparing effectiveness

Team A has the higher defect detection rate: **3 versus 2 defects per review hour**. This indicates more findings per unit of effort, but does not establish that its review process is more effective at detecting the defects present.

The components may differ in complexity and initial defect density. Team A reviewed only 80% of its component, whereas Team B reviewed all of its component. Defect severity, reviewer experience, and defects missed also matter. Neither team's total number of existing or remaining defects is known, so the proportion of defects detected cannot be calculated from these data.

### e) Defect severity distribution

Defects differ in their consequences. A critical defect that can disable a safety function usually needs attention before a minor presentation issue. Severity therefore helps prioritize corrective actions together with likelihood, exposure, and operational context.

Team A found 3 critical, 9 major, and 12 minor defects; Team B found 1 critical, 11 major, and 18 minor defects. Team B's larger total does not by itself imply greater risk. Team A's three critical findings deserve particular attention despite its smaller total.

## 3. Pair Programming

### a) Driver and Navigator

The **Driver** writes the code and focuses on the immediate implementation, including running relevant checks.

The **Navigator** actively reviews the work as it is written, considers requirements and design, and looks for defects, edge cases, and missing tests. Both developers discuss decisions and regularly exchange roles.

### b) Two advantages

1. **Earlier feedback:** The Navigator can spot incorrect assumptions or implementation errors while the code is being written, reducing the delay and rework associated with a later review.
2. **Shared understanding:** Both developers learn the implementation and its rationale, share knowledge, and reduce dependence on a single developer for future changes and maintenance.

Pair programming can support defect prevention, but does not establish correctness or replace other required verification activities.

### c) Disadvantage and mitigation

A potential disadvantage is that one developer dominates while the other becomes passive, reducing the value of the second perspective. Regular role rotation and explicit expectations for active review and discussion help both developers contribute.

## 4. Types of Static Analysis

The table gives the best-fit classification for each finding. Actual tools may support multiple categories. For H, SCA is the most direct match because the finding comes from a third-party dependency inventory; Compliance Checking can also be justified if the answer focuses on enforcement of the company's license policy.

| Finding | Analysis type | Reason |
| --- | --- | --- |
| A. Function name violates the project's naming convention. | Linting | Checks a local style or naming rule. |
| B. Third-party library contains a known CVE. | Software Composition Analysis (SCA) | Matches third-party components and versions against known vulnerabilities. |
| C. User input is concatenated into an SQL query. | Static Application Security Testing (SAST) | Identifies a potential SQL injection weakness in application code. |
| D. Several classes contain almost identical implementations. | Code Quality Analysis | Detects duplication that increases maintenance effort. |
| E. C++ implementation violates an AUTOSAR C++ coding rule. | Compliance Checking | Checks conformance to a specified coding standard. |
| F. Local variable could be declared `const`. | Linting | Suggests a local improvement to express that a value is not modified. |
| G. Deeply nested function is difficult to maintain. | Code Quality Analysis | Identifies complexity and maintainability concerns. |
| H. Dependency inventory identifies a prohibited library license. | Software Composition Analysis (SCA) | Evaluates third-party dependency licenses against the organization's policy. |
| I. Unsafe buffer operation may cause a buffer overflow. | Static Application Security Testing (SAST) | Identifies a potential memory-safety vulnerability in application code. |
| J. Source code violates a mandatory MISRA C++ rule. | Compliance Checking | Checks conformance to a specified coding standard. |

## 5. Static Code Analysis of C++

### Four issues and proposed corrections

| Issue | Explanation | Correction |
| --- | --- | --- |
| Assignment in `if (targetAirspeed = MAX_AIRSPEED_KNOTS)` | The assignment sets the target to 250. The assigned nonzero value makes the condition true, so the function returns 250 whenever the preceding dereference and addition have defined behavior. | Compare with `>` to detect a target exceeding the maximum. Replacing `=` with `==` would still fail to cap values above 250. |
| Macro used for the maximum airspeed | A preprocessor macro performs textual substitution and does not provide the type and scope of a C++ constant. A configured modern C++ linter may flag it. | Use a typed `constexpr` constant. |
| Repeated magic number `120` | The lower limit lacks a name explaining its meaning, and changing only one occurrence could make the check and assignment inconsistent. | Introduce a named minimum-airspeed constant and use it in both places. |
| Mutable pointer parameter `int* measuredAirspeed` | The function only reads the measured value, but the interface permits modifying it through the pointer. A const-correctness check may flag this. | Accept `const int* measuredAirspeed` to prevent modification through this parameter. |

Diagnostic availability depends on the tool and its enabled rules.

The question does not guarantee pointer validity or bounded input values. Two other acceptable findings, with suitable explanations and corrections, are:

* **Possible null-pointer dereference:** `*measuredAirspeed` is evaluated without checking the pointer. Define how a null input is handled and check it before dereferencing, or use a reference parameter when a required, valid input is part of the interface contract. Adding `const` alone does not make a pointer valid.
* **Possible signed integer overflow:** Adding the measured airspeed and correction can exceed the range of `int` before either limit check runs. Check that the addition is representable before performing it and define how out-of-range inputs are handled. Clamping after an overflowing addition does not correct the undefined behavior.

## Section IV Solution: Calculating Test Coverage

Here, D1 = `(A AND B) OR C` and D2 = `D`. Count only the True and False outcomes of each `if` for branch coverage. For MC/DC, use unique-cause pairs: change the condition being tested, keep the other conditions in the same decision fixed, and show that the decision outcome changes. Inputs belonging only to the other decision may differ.

### a) Trace the tests

| Test | D1 outcome | D2 outcome | Return value | Path (D1, D2) |
| --- | --- | --- | --- | --- |
| T1 | True | True | 3 | (True, True) |
| T2 | False | False | 0 | (False, False) |
| T3 | True | True | 3 | (True, True) |

### b) Branch coverage

| Decision | Observed outcomes | Covered / total |
| --- | --- | --- |
| D1 | True (T1, T3), False (T2) | 2 / 2 |
| D2 | True (T1, T3), False (T2) | 2 / 2 |

**Branch coverage = 4 / 4 × 100% = 100%.**

### c) Condition coverage

| Condition | True in | False in | Covered / total |
| --- | --- | --- | --- |
| A | T1, T3 | T2 | 2 / 2 |
| B | T1 | T2, T3 | 2 / 2 |
| C | T3 | T1, T2 | 2 / 2 |
| D | T1, T3 | T2 | 2 / 2 |

**Condition coverage = 8 / 8 × 100% = 100%.** The bitwise operators ensure every operand is evaluated on every call.

Condition coverage checks the individual conditions' outcomes. Branch coverage checks the overall decisions' outcomes. Seeing both values of each condition does not prove that each condition independently affects its decision.

### d) MC/DC

| Condition | Decision | Independence pair, or reason no pair exists |
| --- | --- | --- |
| A | D1 | None. T1–T2 also changes B; T2–T3 also changes C. |
| B | D1 | None. T1–T2 also changes A; T1–T3 also changes C and leaves D1 True. |
| C | D1 | None. T1–T3 also changes B and leaves D1 True; T2–T3 also changes A. |
| D | D2 | T1–T2: D and D2 change from True to False. D2 has no other conditions to hold fixed. |

Only D has a demonstrated independent effect. **MC/DC = 1 / 4 × 100% = 25%.** Both outcomes of each decision are already covered, but independence pairs for A, B, and C are missing.

Yes, a suite can achieve 100% branch and condition coverage without full MC/DC: T1–T3 does exactly that.

### e) Path coverage

| Feasible path (D1, D2) | Return value | Executed by |
| --- | --- | --- |
| (True, True) | 3 | T1, T3 |
| (True, False) | 1 | None |
| (False, True) | 2 | None |
| (False, False) | 0 | T2 |

**Path coverage = 2 / 4 × 100% = 50%.** T1 and T3 count as the same path.

There are 16 Boolean input combinations, but only four paths through the two `if` decisions. Several combinations follow the same path, so testing all 16 is unnecessary for full path coverage.

### f) Extend the suite

Keep T1–T3 and add these three tests:

| Test | A | B | C | D | D1 outcome | D2 outcome | Return value | Path (D1, D2) |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| T4 | False | True | False | True | False | True | 2 | (False, True) |
| T5 | True | False | False | False | False | False | 0 | (False, False) |
| T6 | True | True | False | False | True | False | 1 | (True, False) |

The combined suite demonstrates these independence pairs:

| Condition | Pair | Fixed conditions in the same decision | Decision change |
| --- | --- | --- | --- |
| A | T1–T4 | B = True, C = False | D1: True → False |
| B | T1–T5 | A = True, C = False | D1: True → False |
| C | T3–T5 | A = True, B = False | D1: True → False |
| D | T1–T6 | No other conditions in D2 | D2: True → False |

| Metric | Covered / total | Coverage |
| --- | --- | --- |
| Branch coverage | 4 / 4 decision outcomes | 100% |
| Condition coverage | 8 / 8 condition outcomes | 100% |
| MC/DC | 4 / 4 conditions with independence pairs | 100% |
| Path coverage | 4 / 4 paths | 100% |

**Three additional tests are the minimum.** To show A's independent effect, B must be True and C False, requiring the input triple `(A, B, C) = (False, True, False)`. To show B's independent effect, A must be True and C False, requiring `(True, False, False)`. Neither triple appears in T1–T3, so both must be added. Both make D1 False, so neither can cover the missing `(True, False)` path. A third additional test is therefore necessary. T4–T6 satisfy all requirements.
