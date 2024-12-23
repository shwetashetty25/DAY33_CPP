// write a program to simulate an online purchase. If the credt card number is invalid or the balance is insufficient, throw an exceptions for each case and handle then in seperate catch blocks:
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class CreditCard
{
private:
    string cardNumber;
    double balance;

public:
    CreditCard(string cardNumber, double balance)
    {
        this->cardNumber = cardNumber;
        this->balance = balance;
    }

    string getCardNumber()
    {
        return cardNumber;
    }

    double getBalance()
    {
        return balance;
    }

    void setBalance(double balance)
    {
        this->balance = balance;
    }
};

class InsufficientBalance : public exception
{
public:
    const char *what() const throw()
    {
        return "Insufficient balance in your account.";
    }
};

class InvalidCreditCard : public exception
{
public:
    const char *what() const throw()
    {
        return "Invalid credit card number.";
    }
};

class OnlinePurchase
{
private:
    CreditCard creditCard;
    double purchaseAmount;

public:
    OnlinePurchase(CreditCard creditCard, double purchaseAmount)
    {
        this->creditCard = creditCard;
        this->purchaseAmount = purchaseAmount;
    }

    string makePurchase()
    {
        if (creditCard.getCardNumber().length() != 16)
        {
            throw InvalidCreditCard();
        }

        if (creditCard.getBalance() < purchaseAmount)
        {
            throw InsufficientBalance();
        }

        creditCard.setBalance(creditCard.getBalance() - purchaseAmount);
        return "Purchase successful. Remaining balance: $" + to_string(creditCard.getBalance());
    }
};

int main()
{
    try
    {
        string creditCardNumber;
        double balance;
        double purchaseAmount;

        cout << "Enter your credit card number: ";
        cin >> creditCardNumber;

        cout << "Enter your account balance: $";
        cin >> balance;

        cout << "Enter the purchase amount: $";
        cin >> purchaseAmount;

        CreditCard creditCard(creditCardNumber, balance);
        OnlinePurchase purchase(creditCard, purchaseAmount);
        string result = purchase.makePurchase();
        cout << result << endl;
    }
    catch (const InvalidCreditCard &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (const InsufficientBalance &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cout << "An error occurred: " << e.what() << endl;
    }

    return 0;
}