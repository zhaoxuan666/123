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
		vector<string> tmp;//������һ������
		for (int i=0;i<a.size();i++)
		{
			if (a[i]!=' ')
			{
				s.push_back(a[i]);//�����ڿո��ʱ���ֵ����s��
				
			}
			else	
			{
				while (!s.empty())//��s���÷���m��
				{
					m.push_back(s[s.size()-1]);
					s.pop_back();
				}
				
				tmp.push_back(m);//��m����������
				m.clear();//����m��ֵ
			}
		}
		///////////////////////�����һ�ε�ֵ����������
		while (!s.empty())
		{
			m.push_back(s[s.size()-1]);
			s.pop_back();
		}
		tmp.push_back(m);

		///////////////////////////////////�����ӡ��
		for (int j=tmp.size()-1;j>0;j--)
		{
			cout<<tmp[j]<<' ';
		}
		cout<<tmp[0];
	}
	
}