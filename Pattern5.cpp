//  Holllow Rectangle
/* 
    ****
    *  *
    *  *
    *  *
    ****
*/

#include<iostream>
using namespace std;

int main()
{
    int rows;
    int columns;
    cin>>rows>>columns;

    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=columns; j++)
        {
            if(i== 1 || i==rows|| j==columns || j== 1)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";   
            }
        
        }
        cout<<endl;
    }
    return 0;
}
