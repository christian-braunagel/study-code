# Vehicle Assistance System — Error List

## Error 1: Incorrect Speed Reset After Braking

### Location
`Vehicle::brake()`

### Problem
If the vehicle speed becomes negative after braking, the speed is incorrectly reset to the brake amount instead of `0.0`.

### Faulty Code
```cpp
if (speed_kmh < 0.0)
{
    speed_kmh = amount_kmh;
}
```

### Correct Solution
```cpp
if (speed_kmh < 0.0)
{
    speed_kmh = 0.0;
}
```

---

## Error 2: Incorrect Emergency Brake Condition

### Location
`EmergencyBrakeSystem::evaluate()`

### Problem
The emergency brake system triggers when the obstacle is far away instead of dangerously close.

### Faulty Code
```cpp
if (front_sensor.get_distance() > critical_distance_m)
```

### Correct Solution
```cpp
if (front_sensor.get_distance() < critical_distance_m)
```

---

## Error 3: Adaptive Cruise Control Accelerates When Too Close

### Location
`AdaptiveCruiseControl::evaluate()`

### Problem
The vehicle accelerates when the front vehicle is too close.

### Faulty Code
```cpp
vehicle.accelerate(5.0);
```

### Correct Solution
```cpp
vehicle.brake(5.0);
```

---

## Error 4: Exceptions Used for Normal Control Flow

### Location
`Vehicle::accelerate()`

### Problem
An exception is thrown and caught locally for simple input validation.
Exceptions should not be used for normal control flow.

### Faulty Code
```cpp
try
{
    if (amount_kmh <= 0.0)
    {
        throw std::invalid_argument("Acceleration must be positive.");
    }
}
catch (...)
{
}
```

### Correct Solution
```cpp
if (amount_kmh <= 0.0)
{
    return;
}
```

---

## Error 5: Public Sensor Distance

### Location
`DistanceSensor`

### Problem
`measured_distance_m` is public and can be modified directly from outside the class.
This violates encapsulation.

### Faulty Code
```cpp
public:
double measured_distance_m;
```

### Correct Solution
```cpp
private:
double measured_distance_m;
```

---

## Error 6: Incorrect Operator Overloading

### Location
`DistanceSensor::operator<`

### Problem
The comparison operator is implemented in reverse order.
Sorting produces the opposite result of what users expect.

### Faulty Code
```cpp
return measured_distance_m > other.measured_distance_m;
```

### Correct Solution
```cpp
return measured_distance_m < other.measured_distance_m;
```

---

## Error 7: Unsafe Getter Returning Non-Const Reference

### Location
`Vehicle::get_model()`

### Problem
The getter returns a non-const reference.
External code can modify the internal state of the object directly.

### Faulty Code
```cpp
std::string &get_model();
```

### Correct Solution
```cpp
const std::string &get_model() const;
```

---

## Error 8: Unsafe Floating Point Comparison

### Location
`DistanceSensor::is_exactly_at_warning_distance()`

### Problem
Floating point values are compared using `==`.
Due to floating point precision issues, exact comparisons are unreliable.

### Faulty Code
```cpp
return measured_distance_m == warning_distance;
```

### Correct Solution
```cpp
constexpr double EPSILON = 0.0001;
return std::abs(measured_distance_m - warning_distance) < EPSILON;
```

---

## Error 9: Missing Maximum Speed Limit

### Location
`Vehicle::accelerate()`

### Problem
The vehicle can accelerate indefinitely without any speed limitation.

### Possible Solution
```cpp
if (speed_kmh > MAX_SPEED_KMH)
{
    speed_kmh = MAX_SPEED_KMH;
}
```

---

## Error 10: Magic Numbers

### Location
Multiple assistance systems

### Problem
Hardcoded numeric values are used directly in the implementation.
This reduces readability and maintainability.

### Faulty Code
```cpp
vehicle.brake(30.0);
vehicle.accelerate(5.0);
```

### Correct Solution
```cpp
static constexpr double BRAKE_FORCE_KMH = 30.0;
static constexpr double SPEED_STEP_KMH = 5.0;
```

