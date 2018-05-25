#include<iostream>
using namepace std;
void rever(int *a,,int len,int n)
{
	for(int i=1;i<n;i++)
		{
			char m=a[len-1];
			for(int j=n-1;j>0;j--)
			{
				a[j]=a[j-1];
			}
			a[0]=m;
		}
}
int main()
{
	char k[6]="ABCDE";
	rever(k,6,2);
}