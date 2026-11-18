# Informatik III: Software Engineering – Test Exam

**Duration:** 75 min  
**Aids:** None  
**Total:** 46 Points

## 1. Requirements and Design Decisions (4 Points)

A public botanical garden plans to introduce a digital visitor information system. Consider the following statements:

A. Visitors can search for plants by their common or scientific name.  
B. Search results must appear within two seconds for at least 95% of requests.  
C. Garden staff can update plant descriptions.  
D. The system must remain available during at least 99.5% of published opening hours.  
E. The development team chose PostgreSQL to store the plant records.

**a)** Classify each statement as a functional requirement (FR), a non-functional requirement (NFR), or a design decision. **(2 Points)**

**b)** Explain how functional requirements, non-functional requirements, and design decisions differ. Use one statement from the scenario to illustrate each category. **(2 Points)**

## 2. Software Testing and Test Design (14 Points)

A parcel-delivery service calculates a shipping fee from the weight of a parcel. Valid weights are greater than 0 kg and at most 20 kg. The price is €5 for weights up to and including 2 kg, €8 for weights above 2 kg and up to 10 kg, and €12 for weights above 10 kg and up to 20 kg. All other weights are rejected.

**a)** Identify the equivalence classes for the input weight, including invalid classes. For each class, provide one representative test input and the expected result. **(6 Points)**

**b)** Apply boundary-value analysis: specify six distinct test inputs around relevant boundaries and their expected results. Briefly explain your selection. **(6 Points)**

**c)** Explain one key difference between unit testing and integration testing. Give one suitable example for each in this parcel-delivery system. **(2 Points)**

## 3. Software Architecture and Design Principles (9 Points)

A museum is developing software for interactive exhibition kiosks. The current design puts user-interface rendering, exhibit-content selection, and database queries into one large class. Every change to the display layout requires retesting database code.

**a)** Identify the design problem and explain which SOLID principle is most directly violated. **(3 Points)**

**b)** Sketch a layered architecture for the kiosk software. Name each layer, describe its responsibility, and show how the layers depend on one another. **(3 Points)**

**c)** The museum plans to support different storage systems. Explain how you would apply the principle you identified in part a) to your architecture from part b). Describe how your design addresses the original problem and which parts of the software would need to change when switching storage systems. **(3 Points)**

## 4. Requirements Engineering and Traceability (9 Points)

A city is commissioning a flood-level monitoring dashboard. The initial stakeholder statement is: “The dashboard should warn us quickly when water levels become dangerous and should be easy to use.” The system will display measurements from river sensors and notify municipal emergency coordinators.

**a)** Identify three ambiguities or missing details in the statement. **(3 Points)**

**b)** Rewrite the warning requirement as one measurable, verifiable requirement. State any reasonable assumptions explicitly. **(3 Points)**

**c)** Explain how a requirements traceability matrix can connect stakeholder needs, system requirements and test cases. Give one concrete traceability chain for this scenario. **(3 Points)**

## 5. UML Use-Case Diagram (10 Points)

A community makerspace offers an online system for managing workshop equipment. Registered members can browse available equipment and request a reservation for a chosen time slot. Before a reservation is confirmed, the system must check equipment availability. Members may optionally add an equipment induction session when making a reservation. Members can cancel their own reservations. Staff members can register new equipment and mark equipment as unavailable for maintenance. An external email service sends a confirmation message whenever a reservation is successfully confirmed.

**Task:** Draw a UML use-case diagram for the described system. Your diagram must include:

- The system boundary and all relevant actors.
- The use cases and correct actor–use-case associations.
- A suitable `«include»` relationship for mandatory behavior.
- A suitable `«extend»` relationship for optional behavior.
- Correct arrow directions and meaningful labels.

**(10 Points)**

### UML Use-Case Diagram – Drawing Area

<!-- Draw your UML use-case diagram here. -->
