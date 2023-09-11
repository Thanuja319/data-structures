#include<stdio.h>
void main()
{
	int a[20];
	int n,temp,i,j;
	printf("enter the number of elements:");
	scanf("%d",&n);
	printf("enter the elements:");
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
    }
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("\nthe numbers in ascending order:");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
