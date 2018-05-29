#include<iostream>
using namespace std;

void rever(string &s,int fist,int end)
{
	while(fist<end)
	{
		swap(s[fist++],s[end--]);
	}
}
string ReverseSentence(string str) {
	rever(str,0,str.size()-1);
	int tmp=0;
	for(int i=0;i<str.size();++i)
	{    

		if(str[i]==' ')
		{
			rever(str,tmp,i-1);
			tmp=i+1;
		}
	}
	return str;
}
int main()
{

	string s("123 456 678");
	ReverseSentence(s);

}