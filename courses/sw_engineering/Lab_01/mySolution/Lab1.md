# Lab 1 – Section I: Software Development Process Models

## 1. Software Development Life Cycle

### Assignment of Activities to SDLC Phases

| Activity | SDLC Phase |
| --- | --- |
| C. The project team determines what functionality students need. | Requirements Engineering |
| E. Software architects define the components and interfaces of the system. | Design |
| A. Developers implement the connection search algorithm. | Implementation |
| G. Testers check whether the complete application fulfills its specified requirements. | System Testing |
| B. Students test whether the application satisfies their expectations. | Acceptance Testing |
| D. The application is released to the university app store. | Deployment |
| F. Developers fix defects and adapt the application after its release. | Maintenance |

### Reasonable Order

```text
C → E → A → G → B → D → F
```

First, the project team determines the requirements. The architecture and system components are then designed. After that, the developers implement the application. The complete system is tested against its requirements, followed by acceptance testing with students. Finally, the application is deployed and maintained.

### Typical Artifacts

| Activity | Typical Artifact |
| --- | --- |
| Requirements Engineering | Requirements specification or collection of user stories |
| Design | Architecture diagram or component diagram |
| Implementation | Source code or executable application |
| Testing | Test cases, test report, or defect report |

## 2. Waterfall Model

### Simplified Waterfall Model

```text
Requirements
     ↓
Design
     ↓
Implementation
     ↓
Testing
     ↓
Deployment
     ↓
Maintenance
```

### Major Development Activities

| Waterfall Phase | Activity for the Campus Mobility App |
| --- | --- |
| Requirements | Determine which mobility functions students need. |
| Design | Define the architecture, components, interfaces, and data model. |
| Implementation | Implement the timetable, connection search, notifications, and favorites. |
| Testing | Verify that the functions satisfy the specification. |
| Deployment | Release the application in the university app store. |
| Maintenance | Fix defects and adapt the application after its release. |

### Suitability for Stable Requirements

The Waterfall Model could work well if the university's requirements are stable and well understood. In this case, the project team can plan, document, review, and complete each phase before starting the next phase. The required budget, schedule, and responsibilities can also be estimated more easily.

### Problem with the Public Transport Integration

The request to integrate the local public transport provider is problematic because implementation has already started. In the Waterfall Model, the requirements and design phases are supposed to be mostly completed before implementation begins.

The new requirement may affect the architecture, external interfaces, data model, connection search algorithm, test cases, budget, and project schedule. Therefore, the team may have to return to earlier phases and revise already completed work.

### Advantages

- The model provides a clear and understandable phase structure.
- Planning and documentation are easier when requirements are stable.

### Disadvantages

- Late requirement changes are difficult and expensive.
- A usable product and user feedback are usually available only late in the project.

## 3. V-Model

### Simplified V-Model

```text
Requirements Specification  ←────────→  Acceptance Testing
              \                              /
               \                            /
          System Design       ←────→  System Testing
                  \                      /
                   \                    /
        Software/Component Design ←→ Integration Testing
                         \          /
                          \        /
                       Implementation
                              ↕
                         Unit Testing
```

### Corresponding Development and Test Activities

| Development Activity | Corresponding Test Level |
| --- | --- |
| Requirements Specification | Acceptance Testing |
| System Design | System Testing |
| Software/Component Design | Integration Testing |
| Implementation | Unit Testing |

### Meaning of the Connection

The connection between the two sides of the V represents the relationship between development artifacts and test activities. Each test level checks whether the result satisfies the corresponding specification or design level.

Unit testing checks individual software components. Integration testing checks whether the components work together correctly. System testing checks the complete application against the system design. Acceptance testing checks whether the application satisfies the original user and business requirements.

## 4. Iterative and Incremental Development

### Proposed Increments

| Increment | Functionality |
| --- | --- |
| Increment 1 | Shuttle timetable and basic connection search |
| Increment 2 | Delay notifications and favorites |
| Increment 3 | Bicycle sharing, public transport integration, and parking information |

### Usefulness of the First Increment

The first increment is already useful because students can view the available shuttle buses and search for connections between university locations. It therefore supports the application's most important basic use case even though the remaining functionality has not yet been implemented.

### Difference Between an Increment and an Iteration

An increment adds new usable functionality to the product. After an increment has been completed, the product provides capabilities that were not available before.

An iteration is a repeated development cycle in which the team plans, implements, tests, and improves the product or an existing feature. An iteration does not necessarily have to add a completely new function because it can also improve an existing one.

### Development of the Connection Search

The development of the connection search is primarily an example of iterative development. The same feature is improved over several versions:

- Version 1 provides a basic search between two university locations.
- Version 2 improves the search by considering current shuttle delays.
- Version 3 improves it further by combining shuttle buses and public transport.

Version 3 also has an incremental aspect because public transport integration introduces an additional capability. However, the main focus is the repeated improvement of an existing feature.

## 5. Spiral Model

### Suitability of the Spiral Model

The Spiral Model is suitable for the delay prediction functionality because the project contains significant technical uncertainty and risk. The team has no previous experience with this type of prediction system, and it is not yet clear whether the available GPS data is accurate enough.

The Spiral Model allows the team to investigate these uncertainties with small experiments and prototypes before committing to a complete implementation.

### Project Risks

1. The GPS data may be inaccurate, incomplete, delayed, or inconsistent.
2. The machine-learning model may not predict delays accurately enough to be useful to students.

### Investigation During an Early Spiral

During an early spiral, the team could collect a small sample of historical GPS and shuttle delay data. It could then create a simple prototype prediction model.

The predicted delays would be compared with the actual delays. This experiment would show whether the available data has sufficient quality and whether the model can achieve useful prediction accuracy. Based on the results, the team could continue, change its approach, or stop the development of the feature.

### Activities in One Spiral Cycle

1. **Determine objectives and alternatives:**  
   The team defines what should be achieved during the cycle and identifies possible solution approaches.

2. **Identify and evaluate risks:**  
   The team analyzes technical, financial, organizational, usability, and schedule risks.

3. **Develop and verify a solution:**  
   The team develops a prototype or part of the product and evaluates the results.

4. **Plan the next cycle:**  
   Based on the results, the team decides whether to continue, change the approach, or stop the project.

## 6. Identify the Process Model

### Scenario A

**Process Model:** V-Model

**Supporting characteristic:** Every specification level has a corresponding test level. The relationships between development artifacts and tests are planned and documented.

### Scenario B

**Process Model:** Iterative and Incremental Development

**Supporting characteristic:** A small but usable version is released first. New functionality is added in later releases, while existing functionality is continuously improved.

### Scenario C

**Process Model:** Spiral Model

**Supporting characteristic:** Prototypes are created specifically to investigate important technical risks before the team commits to the final architecture.

### Scenario D

**Process Model:** Waterfall Model

**Supporting characteristic:** The requirements are detailed and stable, and the development phases are performed largely sequentially.

## 7. Final Comparison

| Characteristic | Waterfall | V-Model | Iterative / Incremental | Spiral |
| --- | --- | --- | --- | --- |
| Development mainly sequential? | Yes | Yes | No | No |
| Explicit relationship between development and testing? | Limited | Yes | Possible, but not the central feature | Possible, but not the central feature |
| Early delivery of partial functionality possible? | Usually no | Usually no | Yes | Possible |
| Explicit focus on risk analysis? | No | No | Not necessarily | Yes |
| Well suited to changing requirements? | No | Limited | Yes | Yes, especially when changes are risk-driven |