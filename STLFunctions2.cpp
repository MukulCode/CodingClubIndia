#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Vectors
void Explainvector()
{
    vector<int> v;     //{}
    v.push_back(1);    //{1}
    v.emplace_back(2); //{1,2}

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(1, 2); // no need of curly brackets in emplace unlike push

    // to define initially
    vector<int> v(5, 100); //{100,100,100,100,100}
    vector<int> v(5);      //{0,0,0,0,0} or some garbage value

    vector<int> v1(5, 20);
    vector<int> v2(v1); // to copy vector v1 in v2

    vector<int>::iterator it = v1.begin(); // we can use anything in place of 'it' (it's a variable)
    it++;
    cout << *(it) << " ";

    //{10,20,30,40,50} is an array with addresses 100,104,108,112,116
    // cout<<v.begin();    // gives 100 (address)
    cout << *(v.begin()); // gives 10(the value)
    // cout<<it;           // gives 100 (since 'it' is defined by the iterator with v.begin())
    cout << *it; // gives 10

    // Similarly to v.begin(), there are functions like v.end(), v.rend(), v.rbegin()

    //{10,20,30,40,50} is an array with addresses 100,104,108,112,116

    // v.end points to the next address which is after 116
    // Note- it doesn't point to 116

    // to print all elements
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    for (auto it = v.begin(); it != v.end(); it++) // auto automatically assigns the required value
    {
        cout << *(it) << " ";
    }

    // erase some element

    v.erase(v.begin() + 1);
    // Example-
    // Input- 10 20 30 40
    // Output- 10 30 40

    v.erase(v.begin() + 2, v.begin() + 4); //(start, end(n-1)) or [start, end)
    // Output- 10 20

    // insert some element
    vector<int> v(2, 100);          //{100,100}
    v.insert(v.begin(), 300);       //{300,100,100}
    v.insert(v.begin() + 1, 2, 10); //{300,10,10,100,100}

    vector<int> copy(2, 50);                       //{50,50}
    v.insert(v.begin(), copy.begin(), copy.end()); //{50,50,300,10,10,100,100}

    //{10,20}
    cout << v.size(); // 2

    //{10,20}
    v.pop_back(); //{10}

    // v1-> {10,20}
    // v2-> {30,40}
    v1.swap(v2); // v1->{30,40} and v2->{10,20}

    // to clear entire vector
    v.clear();

    cout << v.empty(); // checks if its empty or not
}
