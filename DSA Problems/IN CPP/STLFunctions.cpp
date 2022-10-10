#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Set has two main properties- Unique, Sorted
void ExplainSet()
{
    set<int> st;

    st.insert(1);
    st.emplace(2);
    st.insert(2);
    st.insert(4);
    st.insert(3); //{1,2,3,4}


    //{1,2,3,4,5}
    auto it=st.find(3);                 //points at 3

    //{1,2,3,4,5}
    auto it=st.find(6);                 //points at st.end()

    //{1,4,5}
    st.erase(5);                        //erases 5, takes log time

    int cnt =st.count(1);

    auto it=st.find(3);
    st.erase(it);                       //takes constant time

    //{1,2,3,4,5}
    auto it1=st.find(2);
    auto it2=st.find(4);

    st.erase(it1,it2);                  //after erasing->{1,4,5}

    auto it=st.lower_bound(2);
    auto it=st.upper_bound(3);
}