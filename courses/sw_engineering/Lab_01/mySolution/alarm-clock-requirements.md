
## Functional Requirements

1. The application shall allow the user to create an alarm by selecting an alarm time. 
2. The application shall allow the user to edit the time and settings of an existing alarm. 
3. The application shall allow the user to delete an existing alarm. 
4. The application shall allow the user to enable or disable an alarm without deleting it. 
5. The application shall allow the user to configure an alarm to repeat on selected days of the week. 
6. When an enabled alarm becomes due, the application shall produce an audible alarm and display an alarm notification.
7. While an alarm is sounding, the application shall allow the user to dismiss it. 
8. While an alarm is sounding, the application shall allow the user to snooze it for a configurable duration.
9. The application shall allow the user to select an alarm sound and set its volume. 
10. The application shall display all configured alarms, including their time, repeat schedule, and enabled or disabled status.

## Non-Functional Requirements

1. Under normal device operating conditions, an enabled alarm shall begin sounding no more than 5 seconds after its configured trigger time.
2. All interactive controls and status information shall provide text labels that can be interpreted by the device's screen reader.

## Requirements Refinement

### 1. Create an Alarm

#### User level

The user wants to set an alarm for a chosen time so that they are reminded or awakened at that time.

#### System level

The alarm-clock system shall allow the user to enter a valid alarm time, save the alarm, show it in the alarm list, and schedule it to trigger at the next occurrence of the selected time.

#### Software level

The software shall provide an input control for selecting the hour and minute in the device's configured 12-hour or 24-hour time format.

### 2. Snooze a Sounding Alarm

#### User level

The user wants to pause a sounding alarm temporarily so that it alerts them again after a short period.

#### System level

While an alarm is sounding, the alarm-clock system shall offer a snooze action that stops the current alert and schedules the same alarm to alert again after the configured snooze duration.

#### Software level

The software shall display a clearly labeled **Snooze** control while an alarm is sounding.