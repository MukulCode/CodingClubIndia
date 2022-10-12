// Round Robin CPU Scheduling Algorithm (Non Pre-emptive)

#include<stdio.h>
 
int main()
{
 
  int i,j,n,time,remain,flag=0,tq;
  int avwt=0,avtat=0,bt[10],rt[10];
  
  printf("Enter Total Process:\t ");
  scanf("%d",&n);
  
  remain=n;
  for(i=0;i<n;i++)
  {
    printf("Enter Burst Time for Process Number %d:",i+1);
    scanf("%d",&bt[i]);
    rt[i]=bt[i];
  }
  
  printf("Enter Time Quantum:\t");
  scanf("%d",&tq);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(time=0,i=0;remain!=0;)
  {
    if(rt[i]<=tq && rt[i]>0)
    {
      time+=rt[i];
      rt[i]=0;
      flag=1;
    }
    else if(rt[i]>0)
    {
      rt[i]-=tq;
      time+=tq;
    }
    if(rt[i]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time,time-bt[i]);
      avwt+=time-bt[i];
      avtat+=time;
      flag=0;
    }
    if(i==n-1)
      i=0;
    else
      i++;
  }
  
  printf("\nAverage Waiting Time= %f\n",avwt*1.0/n);
  printf("Avg Turnaround Time = %f",avtat*1.0/n);
  
  return 0;
}