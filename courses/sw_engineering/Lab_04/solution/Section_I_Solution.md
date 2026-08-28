# Section I Solution: The Retirement of FleetTrack

This is one possible solution.
Students may identify additional issues or group the problems differently.

| Phase | Mistake / Problem | Why is it problematic? | Better approach |
| --- | --- | --- | --- |
| Software Evolution | Management used LOC as a main evolution metric. | LOC measures system size, not quality, maintainability, or successful evolution. Growing LOC can also indicate unnecessary complexity. | Use quality and maintainability metrics such as defect trends, complexity, coupling, cohesion, test coverage, change effort, regression rate, and maintenance cost. |
| Software Evolution | Management used number of released features as a quality indicator. | Feature count measures output, but it does not show whether the system is stable, maintainable, or reliable. | Combine feature delivery metrics with defect rates, customer incidents, lead time, rework, and technical debt indicators. |
| Software Evolution | New requirements were added directly to the existing architecture without enough architectural control. | Modules became highly coupled, and changes in one area caused unexpected failures in other areas. | Regularly review architecture, manage technical debt, and refactor modules before coupling and complexity become too expensive. |
| Software Evolution | Refactoring and improved regression tests were rejected because they did not deliver visible new functionality. | Preventive and perfective maintenance are needed to keep long-lived systems changeable and reliable. Ignoring them increases future maintenance cost. | Treat refactoring and test automation as planned maintenance work with explicit budget and measurable goals. |
| Decision to Retire | The replacement decision was made after years of poor evolution monitoring. | The organization lacked reliable data to compare continued maintenance, refactoring, reengineering, and replacement. | Perform a structured assessment using maintenance cost, business value, risk, technical debt, system quality, and replacement cost. |
| Decision to Retire | Management chose a complete replacement within three months despite outdated documentation. | Poor documentation increases migration risk because dependencies, data structures, interfaces, and business rules may be unknown. | Reconstruct critical documentation first and use it to plan migration scope, risks, dependencies, and validation activities. |
| Migration & Retirement | Stakeholders were informed only one week before migration. | Important requirements were discovered too late, including specialized reporting functions still needed by departments. | Involve users, operations, finance, and other stakeholders early. Perform requirements analysis and gap analysis before committing to the retirement date. |
| Migration & Retirement | No proper gap analysis was performed between FleetTrack and CloudFleet. | Missing functionality only became visible shortly before migration and had to be implemented after go-live. | Compare old and new systems feature by feature, especially for business-critical workflows and reports. |
| Migration & Retirement | The organization chose a Big Bang migration despite high uncertainty. | Switching everything at once increases risk and makes rollback harder if data or functionality problems appear. | Use a pilot, phased migration, parallel run, or migration by department or workflow where possible. |
| Migration & Retirement | Data validation only checked whether the number of records matched. | Equal record counts do not prove that migrated data is correct, complete, or consistently linked. | Validate data completeness, correctness, referential integrity, transformations, representative samples, and business-level consistency. |
| Migration & Retirement | FleetTrack was deactivated before CloudFleet had proven that required functionality and migrated data worked correctly. | Users lost access to correct historical deliveries and old invoices after migration. | Keep the legacy system available during an acceptance period and define a rollback strategy before migration. |
| Migration & Retirement | Legal retention requirements were discovered after migration. | The company risked violating legal or regulatory obligations for historical finance records. | Identify retention, audit, compliance, and archiving requirements during retirement planning. |
| After Retirement | FleetTrack servers were deleted only two weeks after migration. | Infrastructure was removed before all data, functionality, rollback, and compliance questions were resolved. | Keep the old environment available until migration acceptance, retention requirements, and rollback windows are complete. |
| After Retirement | Backups existed, but restorability was not documented or tested. | Source code and database backups alone may be insufficient if required versions, dependencies, configuration, and runtime environments are unknown. | Archive source code, database backups, schemas, configuration files, dependency versions, deployment instructions, and environment information. Test restore procedures. |
| After Retirement | No formal post-retirement review was performed. | The organization missed a chance to learn from the problems and improve future migration and retirement projects. | Conduct a lessons-learned review and verify whether retirement objectives, compliance needs, and user needs were actually met. |

## Teaching Notes

The case shows that poor retirement often begins years before the actual shutdown.

Poor evolution monitoring leads to architectural degradation.
Architectural degradation leads to a late and expensive replacement decision.
A rushed replacement leads to incomplete migration planning.
Incomplete planning leads to weak validation, premature shutdown, and avoidable business problems.

The key connection is:

```text
Poor evolution monitoring -> architectural degradation -> late replacement decision -> rushed migration -> inadequate validation -> premature shutdown
```
