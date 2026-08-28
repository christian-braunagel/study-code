# Lab 4: Software Evolution and Retirement

This lab is designed to help you understand how software systems evolve over time and how retirement decisions should be planned and executed.

🟢 __Simple__: A guided software engineering activity that introduces the basic concepts step by step. It should not take more than 15 - 20 minutes to finish.

🟡 __Moderate__: A software engineering activity that asks you to apply the concepts to a realistic team or project situation. These tasks can usually be completed in about 30 - 45 minutes, depending on your prior knowledge.

🔴 __Complex__: A more demanding or longer software engineering activity that requires you to combine concepts, make decisions as a team, and work through a broader project context. Such tasks might take up to a few hours to complete.


## 🟡 Section I: Case Study - The Retirement of FleetTrack

In this exercise, you will analyze a case study about software evolution and retirement.
The goal is to identify problems that occurred during different phases of the system's life cycle and propose better alternatives.

### Task Description

Read the following case study carefully.
The mistakes are not marked explicitly, so you need to decide which decisions were problematic and why.

#### Scenario: The Retirement of FleetTrack

FleetTrack is a logistics management system used by a transportation company to plan vehicle routes, assign drivers, track deliveries, and generate invoices.
The system was introduced 14 years ago and has continuously evolved since then.

Over the years, new customer requirements were added directly to the existing architecture.
Several modules grew significantly, and developers increasingly complained that changes in the route-planning module caused unexpected problems in invoicing and reporting.

Management monitored the evolution of FleetTrack primarily using two metrics:

* Lines of Code (LOC): increasing LOC was interpreted as evidence that the system was actively being developed.
* Number of released features: a high number of new features per year was considered an indicator of good software quality.

No other systematic measurements were collected.

After several years, releases became noticeably slower.
The average implementation time for new features increased, and customers reported more regressions after updates.
Developers proposed refactoring several highly coupled modules and improving the automated regression tests.
Management rejected the proposal because neither activity would directly deliver new functionality and business value.

Two years later, management decided that FleetTrack had become too expensive to maintain.
A new cloud-based system, CloudFleet, was selected as its replacement.
Because FleetTrack's architecture and technical documentation were outdated and customers requested additional features as soon as possible, management decided against a gradual migration and scheduled a complete replacement three months later.

The retirement date was announced internally one week before migration.
Several departments discovered that CloudFleet did not support specialized reporting functions they still relied on.
Nevertheless, management decided to continue with the planned date because the contract for the old hosting infrastructure had already been terminated.

Customer and driver data were exported from FleetTrack and imported into CloudFleet.
The team verified that the number of migrated database records matched the number in the old database.
No further validation of the migrated data was performed.

On the migration weekend, FleetTrack was deactivated.
On Monday morning, users discovered that some historical delivery records were associated with incorrect customers and that several old invoices could no longer be accessed.
The company also discovered that its finance department was legally required to retain some historical records for several more years.

The FleetTrack servers were nevertheless deleted two weeks later to reduce infrastructure costs.
Source code and database backups existed, but nobody had documented which software version, database version, configuration files, external libraries, and deployment environment would be required to restore the system.

CloudFleet remained in operation, and missing functionality was implemented during the following months.
No formal post-retirement review was performed.

#### Task

Analyze the evolution and retirement of FleetTrack.
Identify the mistakes made by the organization and propose how each should have been handled differently.

Use the following structure for your answer:

| Phase | Mistake / Problem | Why is it problematic? | Better approach |
| --- | --- | --- | --- |
| Software Evolution | | | |
| Decision to Retire | | | |
| Migration & Retirement | | | |
| After Retirement | | | |

You may add more than one row per phase.
