#include<iostream>
using namespace std;

int find1(int *a,int len)
{
	if (len<2)
	{
		return a[0];
	}
	int tmp=0;
	int sum=-111;
	for (int i=0;i<len;i++)
	{
		
		if (a[i]<=0)
		{
			tmp=a[i];
		}
		else
		{
			tmp+=a[i];
		}
		if (tmp>sum)
		{
			sum=tmp;
		}
		tmp=a[i];
	}
	return sum;
}

int main()
{
	int n;
	int arr[6]={0};
	char c;
	int i=0;
	
	while ((c=getchar())!='\n')
	{
		/*if (c>='0'&&c<='9')
		{*/
			ungetc(c,stdin);
			cin>>arr[i++];
		/*}*/
	}
	int m=find1(arr,6);
	cout<<m<<endl;
	//for (int m=0;m<9;i++)
	//{
	//	cout<<arr[i]<<' ';
	//}
	getchar();
}