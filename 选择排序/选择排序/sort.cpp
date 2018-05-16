#include<stdio.h>
#include<Windows.h>
#include <assert.h>
void Swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

void sort(int *arr,int len)
{
	int left=0;
	int right=len-1;
	while (right>left)
	{
		int min=left;
		int max=left;
		for (int i=left;i<=right;i++)
		{
			
			if (arr[i]>arr[max])
			{
				max=i;
			}
			if (arr[i]<arr[min])
			{
				min=i;
			}
		}
		Swap(&arr[left],&arr[min]);
		/*�������Ԫ�����������Ԫ�أ���a[left] == a[Max]����ôSwap(&a[left], &a[min])ִ��������ֵ��λ�þ��Ѿ����ı䡣*/
		if (left!=max)
		{
			Swap(&arr[right],&arr[max]);
			--right;
		}
		++left;
	}
}

int main()
{
	int arr[]={9,8,5,3,1,2,6,4,7};
	//int arr[]={9,8,7,6,5,4,3,2,1};
	int len=sizeof(arr)/sizeof(arr[0]);
	sort(arr,len);

	for (int i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
	system("pause");
}