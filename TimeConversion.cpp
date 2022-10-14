#include <bits/stdc++.h>

using namespace std;

int main()
{
    int hr, min, sec;
    char ch, tmf;
    cin >> hr >> ch >> min >> ch >> sec >> tmf;
    if (tmf == 'P')
    {
        if (hr != 12)
        {
            hr = hr + 12;
        }
    }
    else if (tmf == 'A')
    {
        if (hr == 12)
        {
            hr = 0;
        }
    }
    cout << setw(2) << setfill('0') << hr << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0') << sec;

    return 0;
}
