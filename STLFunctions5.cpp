#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Lists
void ExplainList()
{
    list<int> ls;

    ls.push_back(2);    //{2}
    ls.emplace_back(4); //{2,4}

    ls.push_front(5);     //{5,2,4}
    ls.emplace_front(10); //{10,5,2,4}

    // All the other functions are similar to vectors
}