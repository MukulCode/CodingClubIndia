#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Deque
void ExplainDeque()
{
    deque<int> dq;

    dq.push_back(1);    //{1}
    dq.emplace_back(2); //{1,2}

    dq.push_front(4); //{4,1,2}
    dq.emplace_front(3);

    dq.pop_back();
    dq.pop_front();

    dq.back();
    dq.front();

    // begin, end, rbegin, rend, swap, etc are similar to vectors
}
