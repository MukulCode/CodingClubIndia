#include <iostream>
using namespace std;

class bankAcc
{
    int acc_no;
    float Balance;
    string name;

public:
    void display();
    void set(int num, float bal, string naam)
    {
        acc_no = num;
        name = naam;
        Balance = bal;
    }

    void deposit()
    {
        int bal;
        cout << "Enter Amount to deposit: " << endl;
        cin >> bal;
        Balance += bal;
        cout << "New Balance = " << Balance << endl;
    }

    void withdraw()
    {
        int n;
        cout << "Enter amount to withdraw: " << endl;
        cin >> n;
        if (n > Balance)
        {
            cout << "Kama le phele " << endl;
        }
        cout << "New Balance = " << Balance << endl;
    }
};

void bankAcc ::display()
{
    cout << "Account number : " << acc_no << endl;
    cout << "Balance : " << Balance << endl;
    cout << "Name: " << name << endl;
}
int main()
{
    bankAcc b1;
    int a;
    cout << "Enter 1 to deposit and 2 to withdraw" << endl;
    cin >> a;
    b1.set(100829, 100, "Vatsal");
    switch (a)
    {
    case 1:
        b1.deposit();
        break;
    case 2:
        b1.withdraw();
        break;
    default:
        cout << "Invalid Input!" << endl;
    }

    b1.display();
    return 0;
}