#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    int bt[20],at[10],n,i,j,temp,p[10],st[10],ft[10],wt[10],ta[10],pn[10];
    printf("Enter the number of process:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter process number,arrivaltime,burst time & priority:");
        scanf("%d%d%d%d",&pn[i],&at[i],&bt[i],&p[i]);
    }
    for(i=0; i<n; i++)
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
    printf("\nP No.\tarrival time\tburst time\tpriority\twaitingtime\tturn around time");
    for(i=0; i<n; i++)
        printf("\n%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d",pn[i],at[i],bt[i],p[i],wt[i],ta[i]);
    getch();
}
