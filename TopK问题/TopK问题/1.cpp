#include <iostream>
using namespace std;
void AdjustDown(int *a,int n,int m)
{
	int parent=n;
	int child=parent*2+1;
	while (child<n)
	{
		if (a[child]<a[child+1]&&child+1<n)
		{
			++child;
		}
		if (a[child]<a[parent])
		{
			int tmp=a[child];
			a[child]=a[parent];
			a[parent]=tmp;

			parent=child;
			child=parent*2+1;
		}
		else
		{

			break;
		}
	}
}
int main()
{
	int a[]={2,3,1,4,52,2,12,5,7,1,33,3};
	for (int )
	{
	}
}