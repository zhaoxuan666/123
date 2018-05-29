#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int array[4][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int hight=4;
	int wight=4;
	int j=wight-1;
	int i=0;
	int target=15;
	while(i<hight&&0<j)
	{
		if(array[i][j]>target)//当这个数小于坐标数，则肯定不在这列，这列是递增的
		{
			--j;
		}
		if(array[i][j]<target)
		{
			++i;
		}
		if(array[i][j]==target)
			return true;
	} 
	return false;
}
