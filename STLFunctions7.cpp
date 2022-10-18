#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Priority Queues
void ExplainPQ()
{
    priority_queue<int> pq;

    // Maximum heap
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10); // prints it in this order-{10,8,5,2}

    // Minimum heap
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10); //{2,5,8,10}

    cout << pq.top(); // prints 2
}