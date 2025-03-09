/* 
Author: Saeed Soukiah 
Date: December 8, 2024 
*/
#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>
using namespace std;

class ATM final {
private:
    double balance;
    int deposit;
    int widthDraw;
    int password;
    int choice = 0;
    string id;
public:
    ATM(string id,int balance,int deposit,int withdraw,int password) {
        this->id = id;
        this->balance = balance;
        this->deposit = deposit;
        this->widthDraw = withdraw;
        this->password = password;
    }
    
    void Show() {
        cout << "Hello: " << id << endl;
        cout << "***** Menue *****" << endl;
        cout << "1:balance" << endl;
        cout << "2:Withdraw" << endl;
        cout << "3:deposit" << endl;
        cout << "4:Exit" << endl;
        cout << "***** ***** *****" << endl;
    }
    
    void Process() {
        do
        {
            char operation;
            if (password == 1234)
            {
                cout << "Enter Your Choice:" << endl;
                cin >> choice;
                switch (choice)
                {
                case 1:
                    cout << "your balance is: " << balance << endl;
                    break;
                case 2:
                    cout << "Note: Your Balance is: " << balance << endl;
                    cout << "Enter your amount" << endl;
                    cin >> widthDraw;
                    if (widthDraw > balance) {
                        cout << "Sorry You can't whithdraw this amount" << endl;
                    }
                    else
                    {
                        balance -= widthDraw;
                        cout << "Now your balance is: " << balance << endl;
                    }
                    break;
                case 3:
                    cout << "Note: Your Balance is: " << balance << endl;
                    cout << "Enter your deposit money" << endl;
                    cin >> deposit;
                    balance += deposit;
                    break;
                case 4:
                    system("Color 90");
                    cout << "thank you" << endl;
                    break;
                default:
                    break;
                }
            }
            else {
                cout << "Wrong Password press [Y] for yes and [N] for NO" << endl;
                cin >> operation;
                if (operation == 'Y' || operation == 'y')
                {
                    cout << "enter your password" << endl;
                    cin >> password;
                }
                else
                {
                    system("Color 90");
                    Sleep(1000);
                    choice = 4;
                }
            }
        } while (choice < 4);

    }
};

void CheckName(string name) {
    bool wrongname = 0;
    do {
        try
        {

            for (char c : name) {
                if (!isalpha(c)) {
                    wrongname = 1;
                    throw 1;
                } // Checks if the character is not alphabetic return false; } }
                else {
                    wrongname = 0;
                    break;
                }
            }
        }
        catch (int e)
        {
            cout << "Error Wrong Data" << endl;
            cin >> name;
        }
    } while (wrongname == 1);
}
void CheckNum(int& password) {
    bool wrongNumber = false;
    do {
        try {
            string passwordStr = to_string(password);
            wrongNumber = false;
            for (char c : passwordStr) {
                if (!isdigit(c)) {
                    wrongNumber = true;
                    throw 1;
                }
            }
        }
        catch (int e) {
            cout << "Error: Wrong Data. Enter Password again." << endl;
            cin >> password;
        }
    } while (wrongNumber);
}
int getdigit(const int number) {
    return number % 10 + (number / 10 % 10);
}
int sumodddigits(const string cardnumber) {
    int sum = 0;
    for (int i = cardnumber.size() - 1; i >= 0; i -= 2)
    {
        sum += getdigit(cardnumber[i] - '0');
    }
    return sum;
}
int sumevendigit(const string cardnumber) {
    int sum = 0;
    for (int i = cardnumber.size() - 2; i >= 0; i -= 2)
    {
        sum += getdigit((cardnumber[i] - '0') * 2);
    }
    return sum;
}
void CheckATM() {
    int validcard = 0;
    do
    {
        int result = 0;
        string cardnumber;
        try
        {
            cout << "enter credit card number" << endl;
            cin >> cardnumber;
            result = sumevendigit(cardnumber) + sumodddigits(cardnumber);
            if (result % 10 == 0)
            {
                cout << cardnumber << "is valid" << endl;
                validcard = 0;
            }
            else
            {
                cout << cardnumber << "is not valid" << endl;
                validcard = 1;
                throw 1;
            }
        }
        catch (int e)
        {
            cout << "enter credit card number" << endl;
            cin >> cardnumber;
        }
    } while (validcard == 1);
}

int main()
{
    Sleep(1000);
    system("Color 94");
    Sleep(1000);
    cout << "Inirializing...." << endl;
    Sleep(1000);
    system("Color 90");
    string name;
    int password;
    
    cout << "Enter your name: ";
    cin >> name;
    CheckName(name);
    cout << "enter your password: ";
    cin >> password;
    CheckNum(password);

    CheckATM();

    ATM user(name, 1000, 500, 200, password);

    user.Show();
    user.Process();
}
