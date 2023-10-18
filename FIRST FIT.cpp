#include<stdio.h>
int main()
{
	int m[10],p[10],flag[10],allocation[10];
	int n,q,i,j;
	for(i=0;i<10;i++)
	{
		flag[i]=0;
		allocation[i]=-1;
	}
	printf("enter the no of memory blocks=");
	scanf("%d",&n);
	printf("enter the size of each memory block\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&m[i]);
	}
	printf("enter the no of processes=");
	scanf("%d",&q);
	printf("enter the size of each process\n");
	for(i=0;i<q;i++)
	{
		scanf("%d",&p[i]);
	}
	for(i=0;i<q;i++)
	{
		for(j=0;j<n;j++)
		{
			if(flag[i]==0 && m[j]>=p[i])
			{
				allocation[j]=i;
				flag[j]=1;
				break;
			}
		}
	}
	printf("\nBlock no.\t\tsize\t\tprocess no.\t\tsize");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t\t%d\t\t",i+1,m[i]);
		
		if(flag[i]==1)
		{
			printf("%d\t\t\t%d",allocation[i]+1,p[allocation[i]]);
		}
		else
		printf("not allocated");
	}
}