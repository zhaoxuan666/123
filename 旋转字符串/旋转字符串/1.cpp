#include <iostream>
using namespace std;
class Solution {
public:
	int StrToInt(string str) {
	int n = str.size();
				int s = 1;
		long long res = 0;
				if(n==0) 
		return 0;
	if(str[0] == '-')
											s = -1;
										int M=(str[0]=='-' || str[0] == '+') ? 1 : 0;
					for(int i =M;  i < n; ++i){
					if(!( str[i] <= '9'&&'0' <= str[i]) ) 
																	return 0;
			res =res=res*10+str[i]-'0';
						}?
					return res * s;



	}
};




class StringRotation {
public:
	string rotateString(string A, int n, int p) {
		// write code here

		if(p==n-1)
			return A;
		string tmp;
		tmp=A.substr(p+1)+A.substr(0,p+1);
		return tmp;
	}
}

