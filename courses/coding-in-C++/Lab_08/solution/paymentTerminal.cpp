#include <iostream>

class PaymentProcessor
{
public:
    virtual ~PaymentProcessor() = default;

    virtual bool pay(double amount) = 0;
};

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

class PaymentAdapter : public PaymentProcessor
{
private:
    LegacyPaymentTerminal &legacyTerminal;

public:
    PaymentAdapter(LegacyPaymentTerminal &legacyTerminal) : legacyTerminal(legacyTerminal) {};
    bool pay(double amount) override
    {
        // transform amount into cents
        int cents = amount * 100;
        return this->legacyTerminal.makeTransaction(cents);
    }
};

void checkout(PaymentProcessor &processor, double amount)
{
    std::cout << "Make a transaction of the amount " << amount << " EUR" << std::endl;

    bool paymentSuccessful = processor.pay(amount);

    std::cout << "Status of the transaction: "
              << std::boolalpha << paymentSuccessful << std::endl;
}

int main()
{

    LegacyPaymentTerminal legacyTerminalTest;
    PaymentAdapter adapterTest(legacyTerminalTest);

    checkout(adapterTest, 100);
}
