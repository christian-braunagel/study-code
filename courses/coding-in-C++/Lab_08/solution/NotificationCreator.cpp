#include <string>
#include <iostream>
#include <memory>

class Notification
{
public:
    virtual ~Notification() = default;

    virtual void send(const std::string &message) const = 0;
};

class EmailNotification : public Notification
{
public:
    void send(const std::string &message) const override
    {
        std::cout << "Email: " << message << "\n";
    }
};

class SmsNotification : public Notification
{
public:
    void send(const std::string &message) const override
    {
        std::cout << "SMS: " << message << "\n";
    }
};

std::unique_ptr<Notification> createNotification(const std::string &type)
{
    if (type == "email")
    {
        return std::make_unique<EmailNotification>();
    }
    else if (type == "sms")
    {
        return std::make_unique<SmsNotification>();
    }
    else
    {
        std::cout << "Unknown type" << std::endl;
        return nullptr;
    }
}

void notifyUser(Notification &notification, const std::string &message)
{
    notification.send(message);
}

int main()
{
    std::unique_ptr<Notification> SmsNotifier = createNotification("sms");
    std::unique_ptr<Notification> EmailNotifier = createNotification("email");

    notifyUser(*SmsNotifier, "SMS Message");
    notifyUser(*EmailNotifier, "Email Message");
}