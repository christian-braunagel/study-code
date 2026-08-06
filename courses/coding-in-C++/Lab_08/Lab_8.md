# Lab 8: Design guidelines and patterns


All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

---

## 🟢 Section I: SOLID BugHunt - FootballManager

In this section, you will analyze a small C++ project called `FootballManager`.

The project compiles and runs, but its design is intentionally poor.  
Your task is to find design problems related to the **SOLID principles** and refactor the code.

The SOLID principles are:

- **S**ingle Responsibility Principle
- **O**pen/Closed Principle
- **L**iskov Substitution Principle
- **I**nterface Segregation Principle
- **D**ependency Inversion Principle

---

## Task Description

Analyze the given project files:

- `FootballManager.hpp`
- `FootballManager.cpp`

The current implementation violates all five SOLID principles at least once.

Your tasks:

1. Identify at least **one violation for each SOLID principle**.
2. Write your findings as comments in the code or in a separate markdown file.
3. Refactor the project so that the SOLID principles are considered.
4. The program should still be able to:
   - manage a football player
   - train a player
   - select a match strategy
   - save player data
   - send a message to the player
   - print a sponsor report

Answer as comments in the code:

- Which class violates the Single Responsibility Principle?
- Where is the Open/Closed Principle violated?
- Where is the Interface Segregation Principle violated?
- Why is `InjuredPlayer` problematic regarding the Liskov Substitution Principle?
- Which concrete dependencies should be replaced by abstractions?

---

## 🟢 Section II: Factory Pattern - Notification Creator

In this section, you will practice the **Factory Pattern**.

The factory pattern is useful when your program should create objects based on a choice, but the rest of the program should work with a common interface instead of concrete classes.

For example, a notification system may support different message types such as e-mail, SMS, or push notifications. The code that sends the notification should not need to know which concrete class was created.

---

## Task Description

A notification system expects all notification types to use the following interface:

```cpp
class Notification
{
public:
    virtual ~Notification() = default;

    virtual void send(const std::string& message) const = 0;
};
```

Create two concrete notification classes:

```cpp
class EmailNotification : public Notification
{
public:
    void send(const std::string& message) const override
    {
        std::cout << "Email: " << message << "\n";
    }
};

class SmsNotification : public Notification
{
public:
    void send(const std::string& message) const override
    {
        std::cout << "SMS: " << message << "\n";
    }
};
```

Your task is to write a factory function that creates the correct notification object based on a string.

Your tasks:

1. Create a function `createNotification(const std::string& type)`.
2. The function should return a `std::unique_ptr<Notification>`.
3. If `type` is `"email"`, return an `EmailNotification`.
4. If `type` is `"sms"`, return an `SmsNotification`.
5. If the type is unknown, return `nullptr`.
6. Write a function `notifyUser(Notification& notification, const std::string& message)`.
7. Inside `notifyUser(...)`, call `notification.send(message)`.
8. In `main()`, use the factory function to create a notification object and pass it to `notifyUser(...)`.

Expected behavior:

- `createNotification("email")` should create an `EmailNotification`.
- `createNotification("sms")` should create an `SmsNotification`.
- Unknown notification types should be handled without crashing.

Questions to answer in comments:

- What is the common interface?
- Which classes are concrete products?
- Where is the factory?
- Why should `notifyUser(...)` depend on `Notification` instead of `EmailNotification` or `SmsNotification` directly?

---

## 🟢 Section III: Adapter Pattern - Legacy Payment Terminal

In this section, you will practice the **Adapter Pattern**.

The adapter pattern is useful when an existing class already provides the behavior you need, but its interface does not match the interface expected by the rest of your program.

You can use `reference/SensorAdapter.cpp` as a small example:

- `Sensor` is the target interface used by the modern code.
- `LegacyTemperatureDevice` is an existing class with an incompatible method name.
- `TemperatureAdapter` wraps the legacy device and makes it usable as a `Sensor`.

---

## Task Description

A new checkout system expects all payment devices to use the following interface:

```cpp
class PaymentProcessor
{
public:
    virtual ~PaymentProcessor() = default;

    virtual bool pay(double amount) = 0;
};
```

However, the company still owns an older payment terminal with a different interface:

```cpp
class LegacyPaymentTerminal
{
public:
    bool makeTransaction(int cents)
    {
        // Here we would have some logic to process the payment
        // Returns true if the transaction was accepted, otherwise false
        return cents > 0;
    }
};
```

Your task is to write an adapter so that the old terminal can be used wherever a `PaymentProcessor` is expected.

Your tasks:

1. Create a class `PaymentTerminalAdapter` that inherits from `PaymentProcessor`.
2. Store a reference to a `LegacyPaymentTerminal` inside the adapter.
3. Implement `pay(double amount)` by converting the amount from euros to cents.
4. Call `makeTransaction(...)` on the legacy terminal.
5. Write a function `checkout(PaymentProcessor& processor, double amount)`.
6. Inside `checkout(...)`, call the pay method of the interface and print whether the payment was successful.
7. In `main()`, create a `LegacyPaymentTerminal` and wrap it in a `PaymentTerminalAdapter`.
8. Call `checkout(...)` with the adapter.

Expected behavior:

- `pay(12.50)` should call the legacy terminal with `1250` cents.
- Invalid or negative payments should fail.

Questions to answer in comments:

- What is the target interface?
- Which class is incompatible with the target interface?
- Which class is the adapter?
- Why should the `checkout(...)` function depend on `PaymentProcessor` instead of `LegacyPaymentTerminal` directly?
