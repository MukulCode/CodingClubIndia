#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Pairs
void ExplainPair()
{
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second; // 1 3

    pair<int, pair<int, int>> po = {1, {3, 4}};
    cout << po.first << " " << po.second.first << " " << po.second.second; // 1 3 4

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[1].second; // gives output 5
}