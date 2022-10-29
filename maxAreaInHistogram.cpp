#include<bits/stdc++.h> 
using namespace std;


//Function to find largest rectangular area possible in a given histogram.
long long getMaxArea(long long arr[], int n)
{
    // Your code here
    stack <long long int> s;
    long long int res = 0;
    long long int tp;
    long long int curr;

    for (int i = 0;i < n;i++) {
        while (s.empty() == false && arr[s.top()] >= arr[i]) {
            tp = s.top();s.pop();
            curr = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            res = max(res, curr);
        }
        s.push(i);
    }
    while (s.empty() == false) {
        tp = s.top();s.pop();
        curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
        res = max(res, curr);
    }

    return res;
}



int main() {
    system("cls");
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << getMaxArea(arr, n) << "\n";

    return 0;
}