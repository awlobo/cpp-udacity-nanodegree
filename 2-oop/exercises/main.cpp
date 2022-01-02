#include <iostream>
#include <string>

class BankAccount
{
private:
    std::string accountNumber;
    std::string owner;
    double balance;

public:
    BankAccount();
    BankAccount(std::string accountNumber, std::string owner, double balance);
    void print();
    void setAccountNumber(std::string accountNumber);
    void setOwner(std::string owner);
    void setBalance(double balance);

    std::string getAccountNumber() const;
    std::string getOwner() const;
    double getBalance() const;
};

BankAccount::BankAccount()
{
    accountNumber = "0";
    owner = "";
    balance = 0.0;
}

BankAccount::BankAccount(std::string accountNumber, std::string owner, double balance)
{
    this->accountNumber = accountNumber;
    this->owner = owner;
    this->balance = balance;
}

void BankAccount::print()
{
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Owner: " << owner << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}

void BankAccount::setAccountNumber(std::string accountNumber)
{
    this->accountNumber = accountNumber;
}

void BankAccount::setOwner(std::string owner)
{
    this->owner = owner;
}

void BankAccount::setBalance(double balance)
{
    this->balance = balance;
}

std::string BankAccount::getAccountNumber() const
{
    return accountNumber;
}

std::string BankAccount::getOwner() const
{
    return owner;
}

double BankAccount::getBalance() const
{
    return balance;
}

int main()
{
    BankAccount account = BankAccount("1234567890", "John Doe", 1000.23);
    account.print();
}
