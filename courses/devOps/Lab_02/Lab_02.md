# Lab 2: Learn YAML

This lab focuses on the basics of YAML syntax and usage.

All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

## 🟢 Section I: Embedded System Configuration in YAML-Format

Your task is to create a YAML file for a small embedded control unit.

### Task Description

An embedded device controls temperature and status signals.

The device contains:

- one microcontroller
- two sensors
- two LEDs

#### 1. Device Information

Create a device structure on top-level including the fields:

- name
- version
- manufacturer
- whether the device is active
- one microcontroller
- two sensors
- two LEDs

#### 2. Microcontroller

Each Microcontroller has:

- type (e.g. STM32F103)
- clock frequency in MHz (72)
- RAM
- whether a watchdog timer is enabled


#### 3. Sensors

Create a list of two sensors.

Each sensor should contain:

- name
- type
- unit
- whether the sensor is calibrated

Example sensor types could be:

- temperature
- pressure
- voltage


#### 4. LEDs

Create a list of two LEDs.

Each LED should contain:

- color
- function
- whether the LED is enabled

---

### Requirements

- Use 2 spaces for indentation
- Use spaces, not tabs
- Use dictionaries and lists

