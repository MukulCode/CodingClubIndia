// Shortest Job First (SJF)  (Non Pre-emptive)

// Intuition: SJF non pre-emptive all logic is same as FCFS only difference is just sort the processes
// based on their burst time first and then whole code is same as FCFS

#include<stdio.h>
 
int main()
{
    int n,p[20],bt[20],wt[20],tat[20],i,j, temp, pos;
    float avwt=0,avtat=0;
    
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);
 
    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
        p[i] = i+1;
    }
    
    //as name suggests SJF: Shortest Job First
    //sorting burst time in ascending order using selection sort 
    
    for(i=0;i<n;i++)
    {
       pos = i;
       for(j=i+1; j<n; j++){
           if(bt[j] < bt[pos])
                pos = j;
       }
       
       temp = bt[pos];
       bt[pos] = bt[i];
       bt[i] = temp;
       
       temp = p[pos];
       p[pos] = p[i];
       p[i] = temp;
    }
    
    wt[0]=0;    //waiting time for first process is 0
 
    //calculating waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
 
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
 
    avwt= (float) avwt/i;
    avtat =(float)avtat/i;
    
    printf("\n\nAverage Waiting Time:%f",avwt);
    printf("\nAverage Turnaround Time:%f",avtat);
 
    return 0;
}