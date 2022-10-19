#include <iostream>
using namespace std;

// Array

int main()
{
    int marks[4] = {23, 45, 56, 89};

    int mathMarks[4] = {2278, 22, 78, 228};    // this
                                              //  OR
    // mathMarks[0] = 2278;                  // this
    // mathMarks[1] = 22;
    // mathMarks[2] = 78;
    // mathMarks[3] = 228;




    cout << "This are marks" << endl;

    // cout << marks[0] << endl;
    // cout << marks[1] << endl;
    // cout << marks[2] << endl;                                               // diference
    // cout << marks[3] << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "The value of marks " << i << " is " << marks[i] << endl; // diference
    }


    cout << "This are mathMarks" << endl;
    // cout << mathMarks[0] << endl;
    // cout << mathMarks[1] << endl;                      // diference
    // cout << mathMarks[2] << endl;
    // cout << mathMarks[3] << endl;

    for (int i = 0; i < 4; i++)
    {                                                                       // diference
        cout << "The value of mathmarks " << i << " is " << marks[i] << endl;
    }







    return 0;
}
