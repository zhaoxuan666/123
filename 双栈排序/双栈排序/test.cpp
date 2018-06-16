#include<iostream>
#include<stack>
using namespace std;
/*

	请编写一个程序，按升序对栈进行排序（即最大元素位于栈顶），
	要求最多只能使用一个额外的栈存放临时数据，但不得将元素复制到别的数据结构中。
	给定一个int[] numbers(C++中为vector&ltint>)，
	其中第一个元素为栈顶，请返回排序后的栈。
	请注意这是一个栈，意味着排序过程中你只能访问到第一个元素。
*/
stack<int> twoStacksSort(stack<int> st1)
{
	stack<int> st2;
	while (!st1.empty())//判断st1是否为空为循环条件
	{
		int tmp=st1.top();//把栈1的顶部元素取出赋值给临时变量
		st1.pop();
		while (!st2.empty()&&tmp<st2.top())//以栈2是否为空与栈顶元素是否大于tmp  为条件
		{
			st1.push(st2.top());//把原st2里的栈顶元素原返回st2中
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