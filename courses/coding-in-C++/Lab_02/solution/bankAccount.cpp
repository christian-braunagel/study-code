/**
 * @file BankAccount.cpp
 * @brief Simple demonstration of a bank account class.
 */

#include <iostream>
#include <string>

/**
 * @class BankAccount
 * @brief Represents a simple bank account with an owner and balance.
 */
class BankAccount
{
private:
    std::string owner;
    double balance;

public:
    /**
     * @brief Sets the owner of the bank account.
     * @param ownerName Name of the account owner.
     */
    void setOwner(std::string ownerName)
    {
        owner = ownerName; // better: use this-pointer when already familiar with this concept
    }
    /**
     * @brief Gets the owner of the bank account.
     * @return Name of the account owner.
     */
    std::string getOwner()
    {
        return owner;
    }
    /**
     * @brief Deposits money into the account.
     * @param amount Amount of money to deposit. Must be greater than 0.
     */
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
    /**
     * @brief Withdraws money from the account.
     * @param amount Amount of money to withdraw.
     */
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
    /**
     * @brief Gets the current account balance.
     * @return Current balance.
     */
    double getBalance();
    /**
     * @brief Prints account information (owner and balance).
     */
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