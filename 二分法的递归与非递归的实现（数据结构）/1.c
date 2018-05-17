#include<stdio.h>
int digui(int *a,int left,int right,int k)
{	int mid=(right+left)/2;
	if(right<left)
	{
		return -1;
	}

	if(a[mid]>k)
	{
		return digui(a,left,mid-1,k);
	}
	if(a[mid]<k)
	{
		return digui(a,mid+1,right,k);
	}
	if(a[mid]==k)
	{
		return mid;
	}
}
int ndigui(int *a,int sz,int k)
{
	int left=0;
	int right=sz-1;
	int mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(a[mid]>k)
		{
			right=mid-1;
		}
		if(a[mid]<k)
		{
			left=mid+1;
		}
		if(a[mid]==k)
		{
			return mid;
		}
	}
}
int main()
{
	int a[]={1,2,3,4,5,6,7,8,9};
	int sz=sizeof(a)/sizeof(a[0]);
	int left=0;
	int right=sz-1;
	digui(a,left,right,4);
	ndigui(a,sz,4);
	return 0;
}