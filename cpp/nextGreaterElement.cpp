/*
PROBLEM STATEMENT:
You are given an array of length N. You have to return a list of integers
containing the NGE(next greater element) of each element of the given array. The NGE for an element X is the first greater element on the right side of X in the array. Elements for which no greater element exists, consider the NGE as -1.

Example:
I/P: N=3, arr=[1,3,2]
O/P: [3,-1,-1]
*/

//T.C=O(N) S.C=O(N)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr,int N,vector<int> &ans){
    stack<int> st;
    for(int i=N-1;i>=0;i--){
        //smaller elements  cannot be the answers so pop it
        while(!st.empty() && st.top()<=arr[i])
            st.pop();

        if(i<N){
            if(!st.empty())
                ans[i]=st.top();
            else  
                //no greater element found on the right side so put -1
                ans[i]=-1;
        }
        st.push(arr[i]); //always push the element into stack
    }
}

int main(){
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++) cin>>arr[i];
    vector<int> ans(N);
    solve(arr,N,ans);
    for(int i=0;i<N;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}