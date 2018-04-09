#include<stdio.h>
#include<stdlib.h>
int main()
{
int i,s,awt=0,atat=0,j,n,t,t1,t2;
int *bt,*at,*id,*wt,*tat;
printf("\nEnter number of processes == ");
scanf("%d",&n);
wt=(int *)malloc(sizeof(int)*n);
tat=(int *)malloc(sizeof(int)*n);
bt=(int *)malloc(sizeof(int)*n);
at=(int *)malloc(sizeof(int)*n);
id=(int *)malloc(sizeof(int)*n);
//Taking Input of process ID, Burst time and Arrival time.
for(i=0;i<n;i++){
printf("\nEnter process ID ==");
scanf("%d",&id[i]);
printf("\nEnter Burst time of process P[%d]==",id[i]);
scanf("%d",&bt[i]);
printf("\nEnter Arrival time of process P[%d]==",id[i]);
scanf("%d",&at[i]);
}
for(i=0;i<n;i++){
printf("Process ID=  %d    ",id[i]);
printf("Burst time=  %d    ",bt[i]);
printf("Arrival time=  %d  ",at[i]);
printf("\n");
}
//Sorting based on arrival time
for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
if((at[i]>at[j]) || ((at[i]==at[j]) && (bt[i]>bt[j]))){
t=at[i];
at[i]=at[j];
at[j]=t;
t1=bt[i];
bt[i]=bt[j];
bt[j]=t1;
t2=id[i];
id[i]=id[j];
id[j]=t2;
}
}
}
printf("\n\n\t\tAFTER SORTING\t\t\n\n");
for(i=0;i<n;i++){
printf("Process ID=  %d    ",id[i]);
printf("Burst time=  %d    ",bt[i]);
printf("Arrival time=  %d  ",at[i]);
printf("\n");
}
//AVERAGE WAITING TIME
for(i=0;i<n;i++){
s=at[0];
for(j=0;j<=i-1;j++){
if(i!=0)
s=s+bt[j];
}
wt[i]=s-at[i];
printf("\nWaiting time for P_ID[%d]  ==  %d",id[i],wt[i]);
}
for(i=1;i<n;i++)
awt=awt+wt[i];
printf("\n\nAVERAGE WAITING TIME==  %f  \n",awt*1.0/n);
//AVERAGE TURN AROUND TIME
for(i=0;i<n;i++){
s=at[0];
for(j=0;j<=i;j++){
s=s+bt[j];
}
tat[i]=s-at[i];
printf("\nTurn around time of P_ID[%d]  ==  %d ",id[i],tat[i]);
atat=atat+tat[i];
}
printf("\n\nAVERAGE TURN AROUND TIME ==  %f  \n",atat*1.0/n);
return 0;
}
