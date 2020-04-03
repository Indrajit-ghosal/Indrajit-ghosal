#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int burst_time[20],arrival_time[10],n,i,j,temp,priority[10],st[10],ft[10],wt[10],ta[10];
    int totwt=0,totta=0;
    float awt,ata;
    char process_name[10][10],t[10];
    printf("Enter the number of process:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter Process Name : ");
        scanf("%s",process_name[i]);
        printf("Enter Arrival Time : ");
        scanf("%d",&arrival_time[i]);
        printf("Enter Burst Time : ");
        scanf("%d",&burst_time[i]);
        printf("Enter Priority : ");
        scanf("%d",&priority[i]);


    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(priority[i]<priority[j])
            {
                temp=priority[i];
                priority[i]=priority[j];
                priority[j]=temp;
                temp=arrival_time[i];
                arrival_time[i]=arrival_time[j];
                arrival_time[j]=temp;
                temp=burst_time[i];
                burst_time[i]=burst_time[j];
                burst_time[j]=temp;
                strcpy(t,process_name[i]);
                strcpy(process_name[i],process_name[j]);
                strcpy(process_name[j],t);
            }
        }
    for(i=0; i<n; i++)

    {

        if(i==0)
        {
            st[i]=arrival_time[i];
            wt[i]=st[i]-arrival_time[i];
            ft[i]=st[i]+burst_time[i];
            ta[i]=ft[i]-arrival_time[i];
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-arrival_time[i];
            ft[i]=st[i]+burst_time[i];
            ta[i]=ft[i]-arrival_time[i];
        }
        totwt+=wt[i];
        totta+=ta[i];
    }
    awt=(float)totwt/n;
    ata=(float)totta/n;
    printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround time");
    for(i=0; i<n; i++)
        printf("\n\t%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",process_name[i],arrival_time[i],burst_time[i],priority[i],wt[i],ta[i]);
    printf("\nAverage Waiting Time is : %.2f",awt);
    printf("\nAverage Turnaround Time is : %.2f",ata);
    getch();
    return 0;
}
