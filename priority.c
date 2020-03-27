#include<stdio.h>
#include<conio.h>
#include<stdlib.h> 
#include<sys/types.h>
#include<unistd.h> 
int main()
{
    int bt[20],at[10],n,i,j,temp,p[10],st[10],ft[10],wt[10],ta[10],pn[10];
    printf("Enter the number of process:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
    	pn[i]=i+1;
		printf("\nProccess %d",pn[i]);
        printf("\nArrival Time:");
        scanf("%d",&at[i]);
        printf("\nBurst Time:");
        scanf("%d",&bt[i]);
        printf("\nPriority:");
        scanf("%d",&p[i]);
    }
    for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=pn[i];
                pn[i]=pn[j];
                pn[j]=temp;
            }
        }
	}
    for(i=0; i<n; i++)
 	{
 		if(i==0)
        {
            st[i]=at[i];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+bt[i];
            ta[i]=ft[i]-at[i];
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+bt[i];
            ta[i]=ft[i]-at[i];
        }
    }
    printf("\nP No.\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");
    for(i=0; i<n; i++)
        printf("\n%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d",pn[i],at[i],bt[i],p[i],wt[i],ta[i]);
    getch();
}
