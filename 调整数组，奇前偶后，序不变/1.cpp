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
	move1(a,6);//�����������ǰż���ں����˳���ܱ�
	/////////////˼�룺��һ��ѭ�����������i=0��ʼ �����һ��ѭ��������m=i��ʼ��
//�ҵ����¼����±���ֵ��Ȼ���i��m����������ƶ�һλ��
//Ȼ��a[m]���滻��¼�µ�ֵ��break��
	for (int i=0;i<6;i++)
	{
		cout<<a[i];
	}
	
	getchar();
}