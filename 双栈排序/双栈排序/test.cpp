#include<iostream>
#include<stack>
using namespace std;
/*

	���дһ�����򣬰������ջ�������򣨼����Ԫ��λ��ջ������
	Ҫ�����ֻ��ʹ��һ�������ջ�����ʱ���ݣ������ý�Ԫ�ظ��Ƶ�������ݽṹ�С�
	����һ��int[] numbers(C++��Ϊvector&ltint>)��
	���е�һ��Ԫ��Ϊջ�����뷵��������ջ��
	��ע������һ��ջ����ζ�������������ֻ�ܷ��ʵ���һ��Ԫ�ء�
*/
stack<int> twoStacksSort(stack<int> st1)
{
	stack<int> st2;
	while (!st1.empty())//�ж�st1�Ƿ�Ϊ��Ϊѭ������
	{
		int tmp=st1.top();//��ջ1�Ķ���Ԫ��ȡ����ֵ����ʱ����
		st1.pop();
		while (!st2.empty()&&tmp<st2.top())//��ջ2�Ƿ�Ϊ����ջ��Ԫ���Ƿ����tmp  Ϊ����
		{
			st1.push(st2.top());//��ԭst2���ջ��Ԫ��ԭ����st2��
			st2.pop();
		}
		st2.push(tmp);
	}
	return st2;
}
int main()
{
	stack<int> st1;
	st1.push(1);
	st1.push(2);
	st1.push(3);
	st1.push(6);
	st1.push(5);
	st1.push(4);
	stack<int>st2;
	st2=twoStacksSort(st1);
	while(!st2.empty())
	{
		cout<<st2.top();
		st2.pop();
	}
	getchar();
}