#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string a;
	while (getline(cin,a))
	{
		string s;
		string m;
		vector<string> tmp;//定义了一个容器
		for (int i=0;i<a.size();i++)
		{
			if (a[i]!=' ')
			{
				s.push_back(a[i]);//不等于空格的时候把值发在s中
				
			}
			else	
			{
				while (!s.empty())//把s逆置放在m中
				{
					m.push_back(s[s.size()-1]);
					s.pop_back();
				}
				
				tmp.push_back(m);//把m放在容器里
				m.clear();//清理m的值
			}
		}
		///////////////////////把最后一次的值放入容器里
		while (!s.empty())
		{
			m.push_back(s[s.size()-1]);
			s.pop_back();
		}
		tmp.push_back(m);

		///////////////////////////////////倒序打印出
		for (int j=tmp.size()-1;j>0;j--)
		{
			cout<<tmp[j]<<' ';
		}
		cout<<tmp[0];
	}
	
}