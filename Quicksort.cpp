#include<bits/stdc++.h>
using namespace std;

void quicksort(int input[],int low,int high,int& cnt,int t){

    if(low>=high)
        return ;

    int mid=(low+high)/2;
    int pivot=input[mid];
    int i=low,j=high;
    int temp;
    while(i<j){

        if(input[i]>=pivot && input[j]<=pivot){
            temp=input[j];
            input[j]=input[i];
            input[i]=temp;
          
            i++;
            j--;
            cnt++;
        }
        else{
            i++;
        }
        
         for(int i=0;i<t;i++){
        cout<<input[i]<<" ";
    }
        cout<<"\n";
    }
    quicksort(input,low,mid,cnt,t);
    quicksort(input,mid+1,high,cnt,t);
}
int main()
{
    int t;
    cout<<"Enter size of Input array : ";
    cin>>t;
    int input[t];
    cout<<"Enter space separated Elements of array : "
    
    
    for(int i=0;i<t;i++)
        cin>>input[i];

    int cnt = 0;
    quicksort(input,0,t-1,cnt,t);

    cout<<"\nSorted Input Array is : ";

    for(int i=0;i<t;i++)
        cout<<input[i]<<" ";

    cout<<"\nNumber of swaps : " <<cnt; 

    return 0;
}
