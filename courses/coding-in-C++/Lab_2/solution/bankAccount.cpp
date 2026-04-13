#include <iostream>
#include <string>

class BankAccount
{
private:
    std::string owner;
    double balance;

public:
    void setOwner(std::string ownerName)
    {
        owner = ownerName; // better: use this-pointer when already familiar with this concept
    }
    std::string getOwner()
    {
        return owner;
    }
    void deposit(double amount)
    {
        // ensure valid amount of money
        if (amount <= 0)
        {
            std::cout << "Invalid amount to deposit. Deposit cancelled." << std::endl;
            return;
        }
        balance += amount;
        std::cout << "New balance after deposit: " << getBalance() << std::endl;
    }
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            std::cout << "You do not have enough money for the withdrawal of " << amount << "Euro" << std::endl;
            return;
        }
        balance -= amount;
        std::cout << "New balance after withdrawal: " << getBalance() << std::endl;
    }
    double getBalance();
    void getAccountInfo();
};

void BankAccount::getAccountInfo()
{
    std::cout << "Owner: " << getOwner() << std::endl;
    std::cout << "Balance: " << getBalance() << std::endl;
}

double BankAccount::getBalance()
{
    return balance;
}

int main()
{
    BankAccount myAccount;
    myAccount.setOwner("Max Power");

    // problem here: Since there is no constructor initializing balance, it starts with a random trash value
    myAccount.getAccountInfo();

    myAccount.deposit(1234.12);

    myAccount.getAccountInfo();

    myAccount.withdraw(99999);
    myAccount.getAccountInfo();

    myAccount.withdraw(20);

    myAccount.getAccountInfo();
}