# Lab 2: Architectural Design and Software Detailed Design

This lab is designed to help you understand the concepts of software architecture and detailed design.

🟢 __Simple__: A guided software engineering activity that introduces the basic concepts step by step. It should not take more than 15 - 20 minutes to finish.

🟡 __Moderate__: A software engineering activity that asks you to apply the concepts to a realistic team or project situation. These tasks can usually be completed in about 30 - 45 minutes, depending on your prior knowledge.

🔴 __Complex__: A more demanding or longer software engineering activity that requires you to combine concepts, make decisions as a team, and work through a broader project context. Such tasks might take up to a few hours to complete.


## 🟢 Section I: UML Sequence Diagrams

In this exercise, you will practice creating a UML sequence diagram from textual requirements.
The goal is to identify the participating actors and system components, model the order of messages, and show important decisions in the interaction.

### Task Description

Model the following system behavior as a UML sequence diagram and model it in Draw.io.

#### System: Library Book Reservation

A university library offers a web application where students can reserve books.
The reservation process should work as follows:

* A student searches for a book by entering a title, author, or ISBN.
* The library web application sends the search request to the library catalog.
* The catalog returns a list of matching books with their availability status.
* The student selects one available book and requests a reservation.
* The web application checks whether the student is logged in.
* The account service verifies that the student has not exceeded the maximum number of active reservations.
* If the account is valid, the web application creates a reservation in the reservation service.
* The reservation service marks the selected book as reserved in the catalog.
* The reservation service sends a confirmation email to the student.
* The web application shows a reservation confirmation with the pickup deadline.
* If the selected book is no longer available, the web application informs the student and asks them to select another book.
* If the account check fails, the web application shows the reason why the reservation cannot be completed.

#### 1. Identify Participants

Identify the actors and system components that should appear as lifelines in your sequence diagram.

#### 2. Model the Main Success Scenario

Create a sequence diagram for the successful reservation of an available book by a student with a valid account.


#### 3. Add Alternatives

Extend your diagram with alternative paths.

* The selected book is no longer available
* The student's account check fails

Use UML combined fragments.

