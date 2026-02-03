# Lab 6: Sensor Fusion

## Introduction
In this lab exercise, you will process time-discrete sensor measurements and detect object occurrences based on sensor-specific thresholds.  
You will use **structs**, **typedef**, and file input/output in C.  

The goal is to:

- read measurement data from files
- model the data using structured types
- determine when objects are detected based on thresholds
- identify overlapping detections from multiple sensors
- output detection intervals in a clear textual format

No plotting is required; the focus is on **data processing and analysis**.

## Section I 
### Requirements

#### Data Structures

1. Define a structure `SensorData` with:
   - `time` : float, the time of the sample in seconds (step size 0.02 s)
   - `probability` : double, the measured signal (between 0 and 1)

2. Define a structure `Sensor` with:
   - `id` : int, sensor ID
   - `threshold` : double, detection threshold
   - `data` : array of `SensorData` containing all samples
   - `object_detection` : array of int, stores detection (1 if signal > threshold, 0 otherwise)

---

#### Input Files

Two measurement files are provided:

- `sensor1.txt` : Sensor 1 measurements
- `sensor2.txt` : Sensor 2 measurements

Each file contains two columns:


- Time in seconds (0 to 60 s, step 0.02 s)  
- Signal probability (0 to 1)  

For each sensor, a threshold value is provided which determines if the probability is high enough and an object detection can be derived

- `sensor 1`: threshold 0.8 
- `sensor 2`: threshold 0.7  
---

#### Program Tasks

Implement the following in `main`:

1. Read the two measurement files into `Sensor` structs.
2. For each sensor, generate a **binary detection signal** based on its threshold:
   - 1 if `probability > threshold`  
   - 0 otherwise
3. Determine **start and end times** for each detection interval per sensor.
4. Determine **overlapping intervals** where both sensors detect the object simultaneously.
5. Output all intervals in a clear textual format:
   - Sensor 1 detections
   - Sensor 2 detections
   - Overlapping detections (fusion)

---

### Example

--- Object Detection Results ---

Sensor 1 detections:
Start: 10.00 s End: 20.00 s
Start: 30.00 s End: 40.00 s
Start: 45.00 s End: 55.00 s

Sensor 2 detections:
Start: 15.00 s End: 25.00 s
Start: 30.00 s End: 40.00 s
Start: 50.00 s End: 59.98 s

Fused signal (both sensors):
Start: 15.00 s End: 20.00 s Start: 30.00 s End: 40.00 s Start: 50.00 s End: 55.00 s

### Hints

- Use **arrays of fixed size** (3000 samples)
- Keep track of active intervals using a state variable
- Start a detection interval when `signal[i]` changes from 0 → 1  
- End the interval when it changes from 1 → 0 (i.e. at the last index where it is still 1)
- Implement the program logic into fitting function and call them from main
- No dynamic memory allocation required

## Section II

Create in a separate source file a program to generate two txt-files which exactly correspond with the used `sensor1.txt` and `sensor2.txt` files of section I.

Use the function `fprintf()` to write the generated data into the files.