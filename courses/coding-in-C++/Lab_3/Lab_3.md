# Lab 2: From C to C++

This lab focuses on getting started with C++ especially for programmers familiar with C.

All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

## 🟡 Section I: UML Modeling – Online Learning Platform

In this section you will model a simplified **Online Learning Platform** and focus on identifying and designing **relationships** between classes.

You will practice the following concepts:

- UML class diagrams  
- identifying **composition vs aggregation**  
- modeling multiplicities and associations  
- transferring UML into C++ code  

---

### 🧩 Task Description

You are asked to design a simplified **Online Learning Platform** (similar to Moodle).

The platform manages courses, learning content, and users.

---

### 📘 Requirements

- The platform offers multiple **courses**.
   - The number of courses is technically limited to **100**

- A **course** represents a learning unit:
  - it should have a title and a description  
  - it should allow adding or in general organizing its learning material 

- A course is structured into smaller parts called **lessons**:
  - each lesson can contain different types of **content**  
  - content could be, for example, text, video, or quizzes  

- Users can participate in courses:
  - a **user** should have identifying information  
  - users should be able to enroll or leave in courses  
  - users need to be registered **at least on one platform** (e.g. Moodle RV, FN, etc.) 

---

### Task Part 1 – UML Diagram

Create a UML class diagram in draw.io that:

1. Identifies all relevant classes based on the description  
2. Defines:
   - attributes with visibility and types  
   - methods (at least one meaningful method per class)

3. Models relationships:
   - clearly distinguish between:
     - **composition**
     - **aggregation**
     - **association**

4. Includes:
   - multiplicities (e.g. 1, 0..*, etc.)
   - roles or attributes connecting the classes

You must decide yourself:
- which elements should be modeled as **classes**
- which properties should be **attributes**
- which actions should be **methods**

and especially:

- which relationships are **compositions**
- which are **aggregations**
- which are simple **associations**

---

### Task Part 2 – Justification

Answer the following:

1. Which relationships did you model as **composition** and why?  
2. Which relationships did you model as **aggregation** and why?  
3. Which design decisions were not obvious and could be modeled differently?  

👉 There is not always a single correct answer — your reasoning is essential.

---

### Task Part 3 – C++ Implementation

Transfer your UML model into C++ code.

---

- Implement the classes you identified  
- Use appropriate access modifiers (`private`, `public`)  
- Represent relationships using:
  - direct members (for strong ownership)
  - pointers or references (for weaker relationships)

- In main, create objects of your classes
- Simulate interaction (e.g. enrolling, accessing content)  
- Call at least one method from each class  
