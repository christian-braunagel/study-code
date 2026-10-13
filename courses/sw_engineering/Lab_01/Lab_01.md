# Lab 1: Process Models and Requirements Engineering

This lab focuses on applying the knowledge of process models as well as helps you to practice the concepts of requirements engineering.

🟢 __Simple__: A guided software engineering activity that introduces the basic concepts step by step. It should not take more than 15 - 20 minutes to finish.

🟡 __Moderate__: A software engineering activity that asks you to apply the concepts to a realistic team or project situation. These tasks can usually be completed in about 30 - 45 minutes, depending on your prior knowledge.

🔴 __Complex__: A more demanding or longer software engineering activity that requires you to combine concepts, make decisions as a team, and work through a broader project context. Such tasks might take up to a few hours to complete.

## 🟡 Section I: Software Development Process Models

In this exercise, you will practice applying different software development process models. The tasks cover the Software Development Life Cycle (SDLC), Waterfall Model, V-Model, iterative and incremental development, and the Spiral Model.

Work individually or in pairs.

### Task Description

A university wants to develop a new Campus Mobility App.

The application should help students travel between different university locations. Users should be able to:

* View available university shuttle buses
* See current departure and arrival times
* Search for connections between university locations
* Receive notifications about delays
* Save frequently used connections as favorites

The university plans to add additional functionality in the future, such as bicycle sharing, public transport integration, and parking information.

Use this system as the basis for the following tasks.

#### 1. Software Development Life Cycle

Consider the following activities:

* A. Developers implement the connection search algorithm.
* B. Students test whether the application satisfies their expectations.
* C. The project team determines what functionality students need.
* D. The application is released to the university app store.
* E. Software architects define the components and interfaces of the system.
* F. Developers fix defects and adapt the application after its release.
* G. Testers check whether the complete application fulfills its specified requirements.

Assign each activity to an appropriate phase of the Software Development Life Cycle (SDLC).

Put the activities into a reasonable order.

Name one typical artifact that could be created during each of the following activities:

* Requirements Engineering
* Design
* Implementation
* Testing

#### 2. Waterfall Model

Assume that the university decides to develop the complete Campus Mobility App using the Waterfall Model.

Draw a simplified Waterfall Model and assign the major development activities to its phases.

Explain why the Waterfall Model could work well if the requirements of the university are stable and well understood.

After implementation has already started, the university requests integration with the local public transport provider.

Explain why this change can be problematic when using the Waterfall Model.

Name two potential advantages and two potential disadvantages of using the Waterfall Model for this project.

#### 3. V-Model

The project team decides that testing should be planned systematically together with the development activities.

Consider the following development activities:

* Requirements Specification
* System Design
* Software / Component Design
* Implementation

and the following test levels:

* Unit Testing
* Integration Testing
* System Testing
* Acceptance Testing

Draw a simplified V-Model containing these activities.

Assign each test level to the corresponding development activity.

Briefly explain what the connection between the two sides of the V represents.

#### 4. Iterative and Incremental Development

Instead of delivering the complete application at once, the development team considers developing it incrementally.

Assume the following functionality:

* Shuttle timetable
* Connection search
* Delay notifications
* Favorites
* Bicycle sharing
* Public transport integration
* Parking information

Divide the functionality into three meaningful increments.

Each increment should provide a usable extension of the system.

Explain why your first increment is already useful to students.

Explain the difference between an increment and an iteration.

Consider the connection search feature. During development, it evolves as follows:

* Version 1: Search between two university locations
* Version 2: Search considers current shuttle delays
* Version 3: Search combines shuttle buses and public transport

Is this primarily an example of iterative or incremental development? Explain your answer.

#### 5. Spiral Model

A new requirement is introduced:

In the future, the Campus Mobility App should automatically predict shuttle delays using live GPS data and machine learning.

The development team has never implemented such a prediction system before. It is unclear whether the available GPS data is accurate enough to produce useful predictions.

Explain why the Spiral Model could be suitable for developing this functionality.

Identify two project risks associated with the new functionality.

Describe how the team could investigate one of these risks during an early spiral.

Name and briefly explain the major activities that are typically performed during one cycle of the Spiral Model.

#### 6. Identify the Process Model

For each of the following projects, identify the process model that is described.

Choose from:

* Waterfall Model
* V-Model
* Iterative / Incremental Development
* Spiral Model

**Scenario A**

A medical software company defines the system requirements and architecture before implementation begins. For every specification level, a corresponding test level is planned. The relationship between development artifacts and tests must be documented.

**Scenario B**

A startup develops an application whose requirements are expected to change frequently. A small but usable version is released first. Additional functionality is added in subsequent releases while existing functionality is continuously improved.

**Scenario C**

A company develops an experimental autonomous robot. Several important technologies have never been used by the company before. During development, prototypes are created specifically to investigate technical risks before committing to the final architecture.

**Scenario D**

A customer provides a detailed and stable specification at the beginning of a project. Requirements, design, implementation, testing, and deployment are performed largely sequentially.

For each scenario:

* Identify the most appropriate process model
* Name one characteristic from the scenario that supports your answer

#### 7. Final Comparison

Complete the following table.

| Characteristic | Waterfall | V-Model | Iterative / Incremental | Spiral |
| --- | --- | --- | --- | --- |
| Development mainly sequential? | | | | |
| Explicit relationship between development and testing? | | | | |
| Early delivery of partial functionality possible? | | | | |
| Explicit focus on risk analysis? | | | | |
| Well suited to changing requirements? | | | | |

## 🟡 Section II: The Marshmallow Tower Challenge

### Objective

Build the **tallest possible free-standing tower** using only the materials provided.
The marshmallow must be placed at the very top of the tower.

### Team Setup

* Team size: 3-4 participants
* Total building time: 18 minutes, divided into two sprints

### Materials

Each team receives:

* 20 uncooked spaghetti sticks
* 1 meter of masking tape
* 1 meter of string
* 1 marshmallow
* 1 pair of scissors

### Rules

1. The tower must stand on its own without any external support.
2. The entire marshmallow must be placed at the top of the tower.
3. You may break the spaghetti and cut the tape and string as needed.
4. You may not use any additional materials.
5. The tower must remain standing without anyone touching or supporting it when time runs out.
6. The height is measured from the table surface to the top of the marshmallow.

### Challenge Schedule

#### 1. Sprint 1: Build

Time: 8 minutes

Work together to design, build, and test your tower.

#### 2. Retrospective

Time: 3 minutes

Pause your work and discuss the following questions with your team.

* What went well during the first sprint?
* What problems did you encounter?
* What will you do differently in the second sprint?

Agree on at least one concrete improvement for the next sprint.

#### 3. Sprint 2: Improve

Time: 7 minutes

Improve your tower and ensure that it can support the marshmallow.

#### 4. Final Evaluation

Time: 5 minutes

Stop building and step away from your tower.
Each tower will be measured.
The team with the tallest free-standing tower wins.

### Final Reflection

Time: 10 minutes

Discuss your experiences with the other teams:

* How did your team approach the challenge?
* Did you build and test early, or spend most of your time planning?
* How did the intermediate review and retrospective influence your approach?
* What did you learn about teamwork, prototyping, feedback, and iterative development?
* How can these lessons be applied to agile software development?

## 🟡 Section III: Scrum Paper Airplane Game

In this exercise, you will play a short agile game to practice working in sprints.
The goal is to experience planning, time-boxed implementation, testing, review, and retrospective improvement in a simple physical activity.

This exercise is based on the Paper Airplane Game described by Miro: [Agile games to boost team building and creativity](https://miro.com/blog/agile-games-to-boost-team-building/).

### Task Description

You will work in small teams to build paper airplanes over several short sprints.
Each team tries to produce as many valid paper airplanes as possible.
A paper airplane only counts if it flies at least the minimum distance defined by the class before the first sprint starts.

#### 1. Setup

* Form teams of at least four people
* Each team receives a stack of paper
* Define a common minimum flight distance for all teams
* Decide where airplanes will be tested
* Make sure each team has enough space to fold, pass, and test airplanes safely

#### 2. Rules

* The team goal is to produce as many valid paper airplanes as possible
* A plane is valid only if it reaches the minimum flight distance
* Team members may only make one fold at a time
* After making one fold, the paper must be passed to the next team member
* Every sprint starts with an estimation of how many valid airplanes the team expects to produce
* Only airplanes completed and tested within the sprint count

#### 3. Sprint Structure

The game takes about 45 minutes.
Each sprint lasts nine minutes and consists of three time boxes:

* 3 minutes planning
* 3 minutes building and testing
* 3 minutes retrospective

During planning:

* Estimate how many valid airplanes your team will produce
* Decide how you want to organize the folding process
* Decide how you want to test the airplanes

During building and testing:

* Build airplanes according to the rules
* Test whether each airplane reaches the minimum distance
* Count only valid airplanes

During the retrospective:

* Compare your estimate with the actual result
* Discuss what worked well
* Discuss what slowed the team down
* Decide one concrete improvement for the next sprint

#### 4. Run Multiple Sprints

Play several sprints using the same structure.
After each retrospective, apply your improvement in the next sprint.

Keep track of:

* Estimated number of valid airplanes
* Actual number of valid airplanes
* Main improvement idea for the next sprint
* Observations about teamwork and communication

#### 5. Reflection

After the game, discuss the following questions in your team:

* How did your estimates change from sprint to sprint?
* Which process change had the biggest effect?
* How did the time boxes influence your work?
* What did the retrospective change about your next sprint?
* Which parts of the game felt similar to Scrum?

#### 6. Short Presentation

Choose one person from your team to briefly present your result.

The presentation should explain:

* How many valid airplanes your team produced in each sprint
* Which improvement helped your team the most
* What your team learned about planning, iteration, and retrospectives

No slides are required. A short oral explanation is sufficient.

## 🟢 Section IV: Writing and Refining Requirements

### Task Description

In this exercise, you will practice writing requirements for a simple alarm-clock application.
The goal is to describe what the alarm clock should do, how well it should work, and how requirements can become more detailed across different levels of a system.

#### 1. Individual Preparation

Imagine an alarm-clock application for a smartphone or small digital device.

Write a first set of requirements for this application:

* Write at least 8 functional requirements
* Write at least 2 non-functional requirements

Then select two of your requirements and refine each of them on different levels:

* User level: what the user wants to achieve
* System level: what the complete alarm-clock system must provide
* Software level: what the software must do to support the system behavior

**Important**: Document your requirements in a text file, markdown file, or any other format that can be shared without any special software.

#### 2. Group Discussion

Gather in a group of three people.

In your group:

* Each person briefly presents their functional and non-functional requirements
* Compare requirements that describe similar behavior and merge duplicates
* Clarify open questions, such as assumptions about time zones, snooze behavior, volume, vibration, or alarm repetition
* Create one shared requirements document for your group
* Include two refined requirements in the shared document, each shown on user, system, and software level

#### 3. Short Presentation

Choose one person from your group to briefly present your result.

The presentation should explain:

* The functional requirements your group agreed on
* The non-functional requirements your group included
* One example of a requirement refined across the different levels
* One question or ambiguity your group had to clarify

No need to prepare slides for this presentation. A short oral explanation is sufficient.


## 🟢 Section V: Getting Started with Enterprise Architect

In this short exercise, you will get familiar with Enterprise Architect as a tool for documenting requirements.
The goal is to create one or two simple requirements and generate a first requirements document.

### Task Description

Work individually or at max in pairs.
This task should take about 20 to 30 minutes.
If you need orientation, use the Enterprise Architect User Guide pages on [Getting Started](https://sparxsystems.org/enterprise_architect_user_guide/17.1/getting_started/ea_getting_started.html) and [Creating and Viewing Requirements](https://sparxsystems.com/enterprise_architect_user_guide/17.1/modeling_domains/creating_and_viewing_requirements.html).

#### 1. Create Requirements

Create one or two first requirements for the alarm-clock application from Section IV.

Use the following workflow:

* Open Enterprise Architect
* Select **Create new**
* Click **Model**, then use the **Select:** icon and choose **New Package**
* Select **Only Package** and set the name to **Requirements**
* Right-click the **Requirements** package and select **Specification Manager**; alternatively, use **Ctrl+0**
* Use the **Add New** button, then choose **Other -> Requirements > Requirement Type**
  * After selecting the requirement type once, it is sufficient to press the **Add New** button directly instead of using the arrow on the right side of the button again
* Right-click the table columns to open the **Field Chooser**
  * Use the **Field Chooser** to add or remove columns
* Enter the main requirement text in **Notes**; the **Notes** window is located at the bottom right of the screen

For each requirement, fill in the most relevant fields:

* **Item** -> short title
* **Notes** or description -> actual requirement text
* **Status** -> for example **Proposed**, **Approved**, or **Implemented**
* **Priority**
* **Alias** -> optional own requirement ID, for example **SYS-ICE-042**
* **Stereotype**
* **Author**

Structure the document through packages. Create additional packages if they help you organize functional and non-functional requirements.

#### 2. Generate Documentation

Create a first requirements document from your Enterprise Architect model.

Use the following workflow:

* Switch to the **Publish** area
* Select the package that should be documented
* Open **Report Builder** and choose **Generate Documentation**
* Define the filename and file type
* Select a template of your choice
* Click **Generate** and optionally **View**

Note: In professional use, a suitable custom template, individual columns, and automatic values such as IDs usually have to be created first.


## 🟢 Section VI: Getting Started with GitLab Issues

In this short exercise, you will get familiar with GitLab Issues as a lightweight tool for documenting and discussing requirements.
The goal is to explore the issue interface, create one or two simple requirements, and notice which features could support requirements engineering work.

### Task Description

Work individually or at max in pairs.
This task should take about 10 to 15 minutes.
If you need orientation, use the GitLab documentation on [Issues](https://docs.gitlab.com/user/project/issues/).

#### 1. Explore GitLab Issues

Open a GitLab project and take a few minutes to look around the Issues area.

Focus especially on:

* Where issues are listed
* How new issues can be created
* Where descriptions, labels, assignees, and comments can be added
* Which views or filters seem useful for requirements engineering

#### 2. Create Requirements

Create one or two issues for requirements of the alarm-clock application from Section IV.

For each issue:

* Give it a clear title
* Add a short description
* Decide whether it describes a functional or non-functional requirement
* Add a suitable label if labels are available in your project


## 🔴 Section VII: Scrum Backlog Refinement Game

In this exercise, you will practice several Scrum-related activities by working with an unclear product vision and an unfinished initial backlog.
You will create backlog items in GitLab or GitHub, take turns acting as Product Owner and Developers, improve backlog items, discuss uncertainty, and estimate work using planning poker.

### Task Description

Form teams of at least four people.
Each team receives the same product vision and the same initial backlog.
The backlog is intentionally incomplete: the stories are just poorly written titles, not ordered, and have no story points.

#### Product Vision

Your team is building a mobile app called `Smart Fridge`.
The app should help households reduce food waste and plan grocery shopping.
Users should be able to track food items in their fridge, see expiry dates, receive reminders, create shopping lists, and get simple recipe ideas based on ingredients they already have.
The first version should focus on helping users know what food they have at home and what should be used soon.

#### Initial Backlog

The following backlog items are intentionally rough.
Do not fix them before the exercise starts.

* Add food
* Expiry warnings
* Shopping list
* Login
* Scan receipt
* Fridge overview
* Recipe ideas
* Remove eaten food
* Notifications
* Share fridge with family
* Search food
* Categories
* Dark mode
* Barcode scan
* Weekly meal plan
* Low stock reminder
* Favorite recipes
* Settings
* Statistics
* Sync between phones

#### 1. Create the Backlog in GitLab (10 minutes)

Create a new project or repository for your team in GitLab.

Your task:

* Create one issue for each rough backlog item
* Use the rough backlog item text as the initial title
* Do not rewrite the items yet
* Make sure every team member can access the backlog
* Keep the backlog unordered at first

#### 2. Play Product Owner: Order the Backlog (10 minutes)

Read the product vision and the complete backlog as a team.
Then play the role of the Product Owner together.

Your task:

* Discuss which backlog items seem most important for the first version
* Move the most important items to the top in GitLab
* Move less important or unclear items lower
* Be prepared to explain your top five priorities

Do not estimate the items yet.
Focus only on priority and product value.

#### 3. Play Product Owner and Developers: Improve Stories (25 minutes)

Starting from the top of the ordered backlog, each team member takes one backlog item.

For your selected item:

* Improve the item into a clearer user story in GitLab
* Add acceptance criteria
* Add open questions, uncertainties, or assumptions

Use the following format:

```text
As a ...
I want ...
So that ...

Acceptance criterion:
...

Open questions or additional information:
...
```

After preparing your story, present it to your team.
While presenting, you play the Product Owner.

The rest of the team plays the Developers and should check:

* Is the story understandable?
* Is the user or target group clear?
* Is the value clear?
* Is the acceptance criterion testable?
* Are there unanswered questions or hidden assumptions?
* Is the story small enough to be discussed and estimated?

Improve the story together until the team agrees that it is good enough for estimation.
Update the issue or item with the improved version.

#### 4. Planning Poker (15 minutes)

Estimate the improved stories with planning poker.
The person who prepared and presented the story acts as Product Owner for that story and does not estimate it.
All other team members estimate as Developers.

For each story:

* The Product Owner reads the story again
* Developers ask clarification questions
* Developers estimate silently
* Developers reveal their estimates at the same time
* If estimates differ strongly, discuss the reasons
* Estimate again until the team reaches an agreement
* Add the final story point estimate to the issue or item

Use this estimation scale:

```text
1, 2, 3, 5, 8, 13
```

If a story feels larger than `13`, split it into smaller stories or write down why it is too unclear.

Repeat the process for all stories in the backlog until every story has been improved and estimated.

#### 5. Short Retrospective (10 minutes)

Perform a three-minute retrospective as a team.

Discuss these questions:

* Was it easy to turn rough backlog items into good user stories?
* Was the product vision clear enough?
* Which backlog items were hardest to understand?
* Was it difficult to agree on priorities?
* Was it difficult to agree on story points?
* What would help the team write better stories next time?

#### 6. Short Presentation (5 minutes)

Choose one person from your team to briefly present your result.

The presentation should explain:

* Which backlog item your team placed at the highest priority
* One improved user story created by your team
* The story point estimate for that story
* One difficulty your team noticed during refinement or estimation

No slides are required. A short oral explanation is sufficient.

## 🟢 Section VIII: Agile Principles

### Task Description

The Agile Manifesto contains twelve principles that describe important ideas for agile software development.
In this exercise, you will first reflect on these principles individually and then discuss them in a small team.

#### 1. Individual Preparation

* Read the twelve principles of the Agile Manifesto by yourself
* Select the two principles that are most important from your point of view
* Write down a short explanation for each selected principle
* Be prepared to explain why these two principles matter to you

#### 2. Group Discussion

Gather in a group of three people.

In your group:

* Each person explains which two principles they selected and why they selected them
* Discuss similarities and differences between your choices
* Decide together which one principle is the most important one for your team

#### 3. Short Presentation

Choose one person from your group to briefly present your result.

The presentation should explain:

* Which principle your team selected
* Why your team selected this particular principle
* How this principle could influence the way a software team works

No need to prepare slides for this presentation. A short oral explanation is sufficient.
