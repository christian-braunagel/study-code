# Lab 1: Process Models

This lab focuses on applying the knowledge of process models in software engineering.

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

## 🟢 Section I: Agile Principles

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

## 🟡 Section II: Scrum Paper Airplane Game

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

## 🟡 Section III: Scrum Backlog Refinement Game

In this exercise, you will practice several Scrum-related activities by working with an unclear product vision and an unfinished initial backlog.
You will create backlog items in GitLab or GitHub, take turns acting as Product Owner and Developers, improve backlog items, discuss uncertainty, and estimate work using planning poker.

### Task Description

Form teams of at least four people.
Each team receives the same product vision and the same initial backlog.
The backlog is intentionally incomplete: the stories are poorly written, not ordered, and have no story points.

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

#### 1. Create the Backlog in GitLab or GitHub

Create a new project or repository for your team in GitLab or GitHub.
Use issues, project items, or another backlog feature available in your platform.

Your task:

* Create one issue or item for each rough backlog item
* Use the rough backlog item text as the initial title
* Do not rewrite the items yet
* Make sure every team member can access the backlog
* Keep the backlog unordered at first

#### 2. Play Product Owner: Order the Backlog

Read the product vision and the complete backlog as a team.
Then play the role of the Product Owner together.

Your task:

* Discuss which backlog items seem most important for the first version
* Move the most important items to the top in GitLab or GitHub
* Move less important or unclear items lower
* Be prepared to explain your top five priorities

Do not estimate the items yet.
Focus only on priority and product value.

#### 3. Play Product Owner and Developers: Improve Stories

Starting from the top of the ordered backlog, each team member takes one backlog item.

For your selected item:

* Improve the item into a clearer user story in GitLab or GitHub
* Add at least one short acceptance criterion
* Add open questions, uncertainties, or assumptions

Use the following format:

```text
As a ...
I want ...
So that ...

Acceptance criterion:
...

Open questions:
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

#### 4. Planning Poker

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

#### 5. Short Retrospective

Perform a three-minute retrospective as a team.

Discuss these questions:

* Was it easy to transfer the rough backlog into GitLab or GitHub?
* Was it easy to turn rough backlog items into good user stories?
* Was the product vision clear enough?
* Which backlog items were hardest to understand?
* Was it difficult to agree on priorities?
* Was it difficult to agree on story points?
* What would help the team write better stories next time?

#### 6. Short Presentation

Choose one person from your team to briefly present your result.

The presentation should explain:

* Which backlog item your team placed at the highest priority
* One improved user story created by your team
* The story point estimate for that story
* One difficulty your team noticed during refinement or estimation

No slides are required. A short oral explanation is sufficient.
