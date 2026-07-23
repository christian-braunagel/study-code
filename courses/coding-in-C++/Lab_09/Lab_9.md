# Lab 9: Programming with AI Assistance

This lab focuses on **programming with AI assistance** and how tools like GitHub Copilot can support typical software development workflows.

You will practice the following concepts:

* Setting up GitHub Copilot in Visual Studio Code
* Using AI for code documentation
* Using AI for code explanation and error analysis
* Using AI for refactoring
* Using AI for unit-test generation
* Using AI for boilerplate generation

The goal of this lab is not to let the AI solve everything for you. The goal is to learn how to use AI as a development assistant while still keeping responsibility for correctness, architecture, code quality, and understanding.

All the following sections of this lab are based on the following levels of difficulty:

🟢 __Simple__: A simple task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it.

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

---

## 🟢 Section I: Set Up GitHub Copilot in Visual Studio Code

GitHub Copilot is an AI coding assistant that can be used directly inside Visual Studio Code. It can suggest code while you type, answer questions about code, explain errors, generate tests, and propose code changes.

GitHub Copilot Free can currently be used without a paid subscription. The free tier is limited, but sufficient for this lab. At the time of writing, GitHub lists **2,000 completions per month** and **50 chat or agent requests per month** for the free plan.

**NOTE**: You are free to use any AI coding assistant such as Claude Code, Cursor, or Continue with Ollama.

---

### Task Description

Set up GitHub Copilot in Visual Studio Code and verify that it works.

### Step 1: Check the Prerequisites

You need:

* Visual Studio Code installed
* A GitHub account
* Internet access
* Access to GitHub Copilot Free or another Copilot plan

---

### Step 2: Install the GitHub Copilot Extension

1. Open Visual Studio Code.
2. Open the Extensions view.

3. Search for:

   ```text
   GitHub Copilot
   ```

4. Install the official extension published by GitHub.
5. Also install the Copilot Chat functionality if VS Code asks for it or by just searching for the extension

   ```text
   GitHub Copilot Chat
   ```

---

### Step 3: Sign In with GitHub

1. Click the GitHub Copilot icon in the VS Code status bar or activity bar.
2. Select the option to sign in.
3. A browser window opens.
4. Sign in with your GitHub account.
5. Authorize Visual Studio Code to use GitHub Copilot.
6. Return to VS Code.

After sign-in, VS Code should show that Copilot is enabled.

---

### Step 4: Verify Inline Suggestions

Create a new file:

```text
copilot_test.cpp
```

Insert the following comment:

```cpp
// Create a function that returns the maximum of two integers
```

Then press Enter and wait shortly. Copilot should suggest a function implementation.

Accept a suggestion with:

```text
Tab
```

Depending on your internet connection, the suggstion might take some seconds to pop-up.
However, you can see if Copilot is processing something in the background on the Copilot icon with some loading shape.

If no suggestion appears, check:

* Are you signed in to GitHub?
* Is the GitHub Copilot extension enabled?
* Is the file recognized as C++?
* Is Copilot enabled in the status bar?

---

### Step 5: Verify Copilot Chat

Open Copilot Chat in VS Code via:

```text
Keyboard Shortcut: Ctrl + Alt + I or for macOS: Cmd + Ctrl + I
```
or
```text
Command Palette: Ctrl + Shift + P then type Chat: Open Chat
```
or by clicking on the icon on the top right called ```Toggle Secondary Side Bar```

Then ask:

```text
Explain the difference between a pointer and a reference in C++.
```

Read the answer critically. It should be technically correct and understandable.


## 🟢 Section II: AI-Assisted Documentation with Doxygen

AI is especially useful for documentation tasks because it can generate structured and readable first drafts very quickly. However, AI-generated documentation must still be checked carefully because it can describe behavior that the code does not actually implement.

---

### Task Description

Create a file:

```text
statistics.hpp
```

Add the following function declarations:

```cpp
double calculate_average(const std::vector<int>& values);

double calculate_median(std::vector<int> values);

int count_values_in_range(
    const std::vector<int>& values,
    int minimum,
    int maximum);
```

Create a second file:

```text
statistics.cpp
```

Implement all three functions yourself.

Requirements:

* Throw `std::invalid_argument` if the vector is empty
* Use `const` where appropriate
* Follow our C++ coding conventions
* contain at least one test call per function in main

Then use GitHub Copilot Chat or inline prompting to:

* generate Doxygen comments for all functions
* generate additional comments inside the .cpp file where useful

Feel free to use different prompts for different outputs.

---

### Required Result

Inspect the generated comments carefully and answer the following questions as comments in your code:

* What was/were your prompt(s)? Write them down.
* Did the AI generate unnecessary comments?
* Did the AI explain obvious code? Which comments were actually useful?
* Did the AI generate technically incorrect documentation?
* Did the AI mention exceptions or edge cases that do not exist?
* Would you keep all generated comments in a professional project or did you manually change something in the documentation?
* If you used different prompts: Did AI perform better for some prompts? 

---

## 🟢 Section III: AI-Assisted Code Explanation

AI can help explain existing code. This is useful when working with unfamiliar code, legacy code, or code written by another developer. However, the explanation must always be compared with the actual implementation.

---

### Task Description

Use your files from the previous section II and extend them with:

```cpp
std::vector<int> find_unique_sorted_values(const std::vector<int>& values)
{
    std::vector<int> result = values;

    std::sort(result.begin(), result.end());

    const auto new_end = std::unique(result.begin(), result.end());
    result.erase(new_end, result.end());

    return result;
}

std::vector<int> calculate_prefix_sums(const std::vector<int>& values)
{
    std::vector<int> result(values.size());

    std::partial_sum(values.begin(), values.end(), result.begin());

    return result;
}

std::vector<std::pair<int, int>> count_value_frequencies(
    const std::vector<int>& values)
{
    std::map<int, int> frequencies;

    for (const int value : values)
    {
        ++frequencies[value];
    }

    return {
        frequencies.begin(),
        frequencies.end()
    };
}
```

Use Copilot Chat to answer the following prompts per function:

```text
Explain what this function does step by step.
```

```text
Which edge cases should be tested for this function?
```

```text
Can this function be improved? If yes, how?
```

---

### Required Result

Create a file:

```text
section_3_code_explanation.md
```

Document for each prompt you used:

* the most important points from Copilot's explanation
* whether the explanation was correct
* at least two edge cases suggested by Copilot
* one improvement suggestion and whether you agree with it

---

## 🟡 Section IV: AI-Assisted Error Analysis

AI is often helpful when compiler errors, linker errors, runtime errors, stack traces, or CI/CD logs are long and difficult to read. The AI should be treated as a debugging assistant that proposes hypotheses, not as an authority.

---

### Task Description

Use the file in this folder called:

```text
broken_sensor.cpp
```

Then:
* Copy the file and call it **broken_sensor_myFix.cpp**
* Prepare a clock and start the timer:
* Try to compile the file e.g. via:
```bash
g++ -std=c++20 -Wall -Wextra -pedantic broken_sensor_myFix.cpp -o broken_sensor_myFix
```
* You will get some error messages. Try to fix the code by yourself. DO NOT USE AI OR ANY HELP!
* Note down which changes you made e.g. as comments.
* If you think you got every error, compile it again and check it.
* Repeat the process until you found all the errors or if you are out of ideas.
* Then stop your timer and write down how much time you spent.

Afterwards:
* Copy the file ```broken_sensor.cpp``` and call it **broken_sensor_aiFix.cpp**
* Prepare a clock and start the timer:
* Try to compile the file e.g. via:
```bash
g++ -std=c++20 -Wall -Wextra -pedantic broken_sensor_myFix.cpp -o broken_sensor_myFix
```
* You will get some error messages. Try to fix the code by using a Chat Bot e.g. Copilot Chat.
* Note down which changes you made e.g. as comments.
* If you think you got every error, compile it again and check it.
* Repeat the process until you found all the errors or if AI repeats itself.
* Then stop your timer and write down how much time you spent.

---

### Required Results

* Compare time and the result (i.e. found all errors) with and without AI
* Was AI able to find all the bugs?
* Was there something that AI had some troubles with?

---

## 🟡 Section V: AI-Assisted Refactoring

Refactoring means improving the internal structure of existing code without changing its externally visible behavior. AI can suggest useful refactorings, but every change must be reviewed carefully because behavior can accidentally change.

---

### Task Description

For the following tasks, use the file in this folder called:

```text
stock_analyzer.cpp
```

In the code of this file, many design guidelines and patterns are ignored such as:

* SOLID Principles
* Factory Pattern

Your task is to improve the code base without changing the visible output and behaviour of the code.
Ask Copilot to refactor the code following two separate approaches:

__First approach:__
* Copy the file and name the copy ```stock_analyzer_simplePrompt.cpp```. 
* Use one simple prompt such as:

```text
Refactor this code to improve the overall coding style and the code design to increase readability and maintainability.
```
* Review the proposal carefully and apply only changes that you understand

__Second approach:__
* Copy the original file again and name the copy ```stock_analyzer_multiplePrompts.cpp```. 
* Refactor the code by using small and very precise prompts such as:
```text
Improve the class StockAnalyzer by applying the Single Responsibility principle so that the size of the class is reduced. Do not change the observable behavior of the code.
```
* Review the proposal carefully and apply only changes that you understand.
* Repeat the process with more detailed and smaller prompts until you are satisfied.

---

### Required Result

Answer the following questions for both approaches:

```text
1. Which refactorings did Copilot suggest?
2. Which suggestions did you accept?
3. Which suggestions did you reject?
4. Did the behavior of the program change?
```
In addition: Which differences did you experience between the two approaches?

---

## 🟡 Section VI: AI-Assisted Unit-Test Generation

AI can generate unit tests quickly. This is useful for improving test coverage and discovering edge cases. However, AI-generated tests are often too shallow, redundant, or focused on implementation details instead of behavior.

---

### Task Description

Reuse your files from the previous sections:

* `statistics.hpp`
* `statistics.cpp`

Ask Copilot to generate tests for atleast three of the functions.
Start with the function

```cpp
calculate_average(...)
```

Use a prompt like:

```text
Generate simple C++ unit tests for calculate_average. Include normal cases, edge cases, and exception tests. Use assert instead of a test framework.
```

Create a file:

```text
statistics_test.cpp
```

The tests for ``` calculate_average(...) ``` should cover at least:

* average of positive values
* average of negative values
* average of mixed positive and negative values
* vector with one value
* empty vector throws an exception

For the other functions, think about which test-cases would make sense.

Compile and run your tests.

Example command:

```bash
g++ -std=c++20 -Wall -Wextra -pedantic statistics.cpp statistics_test.cpp -o statistics_test
./statistics_test
```

---

### Required Result

Create a file called `section_6_unit_tests.md` answering:

```text
1. Which test cases did Copilot generate?
2. Which important test cases were missing?
3. Did you modify the generated tests?
4. Did all tests pass?
5. Why should AI-generated tests be reviewed manually?
```