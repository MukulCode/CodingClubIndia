//Nature of roots
#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int a,b,c,d;
    cout<<"\tNature Of Roots"<<endl<<endl;
    cout<<"Enter a, b & c of a quadratic equation(ax2+bx+c=0):";
    cin>>a>>b>>c;
    d=pow(b,2)-(4*a*c);
    cout<<"d is equal to:"<<d;
    cout<<endl;
    if(d==0)
    {
        cout<<"Real and equal roots";
    }
    else if(d>0)
    {
            cout<<"Real and unequal roots";
    }
    else
    {
        cout<<"Imaginary roots";
    }    
    return 0;
}