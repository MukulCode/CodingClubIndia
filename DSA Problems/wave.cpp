#include <iostream>
#include <vector>
using namespace std;

void printReverseWave(vector<vector<int>> v,int n,int m){
  
   // traversing column in reverse order
   for(int j = m-1;j>=0;j--)
   {

      // we are in column with odd index traverse rows in up down form
     if(j%2 != 0)
     {
         for(int i = 0;i<n;i++)
         {
             cout << v[i][j] <<" ";
         }
     }else
     {
         // else traverse down up
         for(int i = n-1;i>=0;i--)
         {
             cout << v[i][j] <<" ";
         }

     }


   }

}

int main() 
{

int n,m;
cin >> n >> m;

vector<vector<int>> v;

for(int i = 0;i<n;i++)
{
    vector<int> t;
    for(int j = 0;j<m;j++)
    {
        int x;
        cin >> x;
        t.push_back(x);
    }

    v.push_back(t);
}

printReverseWave(v,n,m);

}