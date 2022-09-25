#include <bits/stdc++.h>
using namespace std;

class Account
{
    int id;
    string accNum;
    float balance;

public:
    Account()
    {
        id = -1;
        balance = 0.0;
    }

    Account(int id, string accNum)
    {
        this->id = id;
        this->accNum = accNum;
        this->balance = 0;
    }

    friend class Bank;
    friend class SavingsBank;
    friend class CheckingBank;
};

class Bank
{
protected:
    vector<Account> accounts;
    int lastAccount;

public:
    Bank() {}

    int search(int id)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].id == id)
                return i;
        }
        return -1;
    }

    int search(string accNum)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].accNum == accNum)
                return i;
        }
        return -1;
    }

    int add_account(int id)
    {
        if (search(id) == -1)
        {
            lastAccount++;
            accounts.push_back(Account(id, to_string(lastAccount)));
            cout << "Account successfully created!!" << endl;
            return 1;
        }
        else
        {
            cout << "An account with id " << id << " already exists." << endl;
            return 0;
        }
    }

    int acc_details(int id, string type)
    {
        int index = search(id);
        if (index == -1)
        {
            cout << "No " << type << " account with ID '" << id << "' found." << endl;
            return 0;
        }
        Account acc = accounts[index];
        cout << type << " Account details: " << endl;
        cout << "\tCustomer ID: " << acc.id << endl;
        cout << "\tAccount number: " << acc.accNum << endl;
        cout << "\tBalance: Rs. " << acc.balance << endl;
        return 1;
    }

    int credit(string accNum, int amount, int fee = 0)
    {
        int index = search(accNum);
        if (index == -1)
        {
            cout << "Account number " << accNum << " not found." << endl;
            return 0;
        }

        if (amount < 0)
        {
            cout << "Invalid amount: " << amount << endl;
            return 0;
        }
        if (accounts[index].balance + amount >= fee)
        {
            accounts[index].balance += amount;
            accounts[index].balance -= fee;
            cout << "Successfully credited " << amount << endl;
            cout << "Balance: Rs. " << accounts[index].balance << endl;
            return 1;
        }
        else
        {
            cout << "Insufficient Balance to complete transaction !!" << endl;
            return 0;
        }
    }

    int debit(string accNum, int amount, int fee = 0)
    {
        int index = search(accNum);
        if (index == -1)
        {
            cout << "Account number " << accNum << " not found." << endl;
            return 0;
        }

        if (amount < 0)
        {
            cout << "Invalid amount: " << amount << endl;
            return 0;
        }
        if (accounts[index].balance >= amount+fee)
        {
            accounts[index].balance -= amount+fee;
            cout << "Successfully debited " << amount << endl;
            cout << "Balance: Rs. " << accounts[index].balance << endl;
            return 1;
        }
        else
        {
            cout << "Insufficient Balance to complete transaction !!" << endl;
            return 0;
        }
    }
};

class SavingsBank: public Bank
{
    float interest;

public:
    SavingsBank() 
    {
        interest = 3.5;
        lastAccount = 100;
    }

    void add_account(int id)
    {
        if (Bank::add_account(id))
            acc_details(id);
    }

    void acc_details(int id)
    {
        if (Bank::acc_details(id, "Savings"))
            cout << "\tInterest: " << interest << "%" << endl;
    }

    void set_interest(float interest)
    {
        this->interest = interest;
    }

    float simple_interest(string accNum, int yr)
    {
        int index = search(accNum);
        if (index == -1)
        {
            cout << "Account number " << accNum << " not found." << endl;
            return -1.0f;
        }
        float si = accounts[index].balance * yr * interest /100.0;
        return si;
    }
};

class CheckingsBank: public Bank
{
    int fee;

public:
    CheckingsBank() 
    {
        fee = 10;
        lastAccount = 200;
    }

    void set_fee(int fee)
    {
        this->fee = fee;
    }

    int get_fee()
    {
        return fee;
    }

    void add_account(int id)
    {
        if (Bank::add_account(id))
            acc_details(id);
    }

    void acc_details(int id)
    {
        if (Bank::acc_details(id, "Checkings"))
            cout << "\tTransaction Fee: " << fee << endl;
    }

    void credit(string accNum, int amount)
    {
        Bank::credit(accNum, amount, fee);
        cout << "Transaction Fee: " << fee << endl;
    }

    void debit(string accNum, int amount)
    {
        Bank::debit(accNum, amount, fee);
        cout << "Transaction Fee: " << fee << endl;
    }
};



int main()
{
    int choice = 0;
    cout << "1. Open Account (Savings or Checking Account)" << endl;
    cout << "2. Credit (Savings or Checking Account)" << endl;
    cout << "3. Debit (Savings or Checking Account)" << endl;
    cout << "4. Change/Update Interest rate (Savings Account)" << endl;
    cout << "5. Calculate Interest (Savings Account - Print)" << endl;
    cout << "6. Calculate and Update Principle Amount with Interest (Savings Account - Credit)" << endl;
    cout << "7. Change/Update Fee Amount (Checking Account)" << endl;
    cout << "8. Print Checking Fee (Checking Account)" << endl;
    cout << "9. Search Customer Details" << endl;
    cout << "10. Exit" << endl;

    SavingsBank savings;
    CheckingsBank checking;

    while (choice != 10)
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id;
            cout << "Enter Customer ID (4-digit): ";
            cin >> id;

            int type;
            cout << "\n1. Savings Account" << endl;
            cout << "2. Checking Account" << endl << "> ";
            cin >> type;

            if (type == 1)
            {
                savings.add_account(id);
            }
            else if (type == 2)
            {
                checking.add_account(id);
            }
            else
            {
                cout << "Invalid Account Type" << endl;
            }
        }
        else if (choice == 2)
        {
            string accNum;
            cout << "Enter Account Number: ";
            cin >> accNum;

            float amount;
            cout << "Enter the amount to credit: ";
            cin >> amount;
            
            if (accNum[0] == '1')
            {
                savings.credit(accNum, amount);
            }
            else if (accNum[0] == '2')
            {
                checking.credit(accNum, amount);
            }
            else
            {
                cout << "Invalid Account Number" << endl;
            }
        }
        else if (choice == 3)
        {
            string accNum;
            cout << "Enter Account Number: ";
            cin >> accNum;

            float amount;
            cout << "Enter the amount to debit: ";
            cin >> amount;

            if (accNum[0] == '1')
            {
                savings.debit(accNum, amount);
            }
            else if (accNum[0] == '2')
            {
                checking.debit(accNum, amount);
            }
            else
            {
                cout << "Invalid Account Number" << endl;
            }
        }
        else if (choice == 4)
        {
            float rate;
            cout << "Enter the updated Interest rate: ";
            cin >> rate;
            savings.set_interest(rate);
        }
        else if (choice == 5 || choice == 6)
        {
            string accNum;
            cout << "Enter Account Number: ";
            cin >> accNum;
            int yr;
            cout << "Enter number of years: ";
            cin >> yr;
            float si = savings.simple_interest(accNum, yr);
            if (si != -1.0f)
            {
                cout << "Simple Interest: Rs. " << si << endl;
            }

            if (choice == 6)
            {
                savings.credit(accNum, si);
            }
        }
        else if (choice == 7)
        {
            int fee;
            cout << "Enter the updated Transaction Fee: ";
            cin >> fee;
            checking.set_fee(fee);
        }
        else if (choice == 8)
        {
            cout << "Checking fees: " << checking.get_fee() << endl;
        }
        else if (choice == 9)
        {
            int id;
            cout << "Enter Customer ID: ";
            cin >> id;
            savings.acc_details(id);
            checking.acc_details(id);
        }
        else if (choice == 10)
        {
            cout << "Exiting..." << endl;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}