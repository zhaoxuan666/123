#include<iostream>

using namespace std;
void move1(int a[],int len)
{
	for(int m=0;m<len;m++)
	for(int i=m;i<len;i++)
	{
		int tmp;
		int cur;
		if (a[i]%2==1)
		{
			tmp=i;
			cur=a[i];
			for (int j=tmp;j>m;j--)
			{
				a[j]=a[j-1];
			}
			a[m]=cur;
			break;
		}
	}
}
int main()
{
	int a[6]={1,2,3,4,5,6};
	move1(a,6);//数组的奇数在前偶数在后相对顺序不能变
	/////////////思想：在一个循环遍历数组从i=0开始 在里边一个循环找奇数m=i开始，
//找到后记录这个下标与值，然后从i到m的数组向后移动一位。
//然后a[m]处替换记录下的值，break；
	for (int i=0;i<6;i++)
	{
		cout<<a[i];
	}
	
	getchar();
}