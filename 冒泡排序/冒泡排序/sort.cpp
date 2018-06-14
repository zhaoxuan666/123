
#include <stdio.h>
#include <Windows.h>
void Swap(int *a,int*b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void sort(int *arr,int len)
{
	for (int i=0;i<len;i++)
	{
		int flag=0;
		for (int j=0;j<len-i-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				flag=1;
				Swap(&arr[j],&arr[j+1]);
			}
		}
		if (flag==0)
		{
			return;
		}
	}
}
int main()
{
	int arr[]={9,8,7,6,5,4,3,2,1};
	int len=sizeof(arr)/sizeof(arr[0]);
	sort(arr,len);
	for (int i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
	system("pause");
}