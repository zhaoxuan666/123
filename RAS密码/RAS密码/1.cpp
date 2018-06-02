#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#include<math.h>




//质数判定函数

intlong PrimeDet(intlong n)

{

	int i=2;

	int m=sqrt(n);

	if(n<=1)

	{

		return 0;

	}

	for(i=2;i<=m;i++)

	{

		if(n%i==0)

		{

			break;

		}

	}

	if(i>m)

	{

		return 1;

	}

	else

	{

		return 0;

	}

}




int main()

{




	//随机生成两个质数

	srand(time(NULL));

	intlong a=rand()%1000001+1000000;

	int i;

	for(i=0;;i++)

	{

		if(PrimeDet(a))

		{

			break;

		}

		else

		{

			a=rand()%1000001+1000000;             //生成一个1000000到2000000之间的质数

		}

	}



	for(i=0;i<1000000000;i++)   //防止产生两个同样的质数

	{}




	srand(time(NULL));

	intlong b=rand()%1000001+1000000;

	for(i=0;;i++)

	{

		if(PrimeDet(b))

		{

			break;

		}

		else

		{

			b=rand()%1000001+1000000;

		}

	}

	printf("a:%ld\nb:%ld\n",a,b);




	//生成公钥n

	long long n;

	n=a*b;               //此数位数越大，破解难度会指数上升



	printf("n:%lld\n",n);



	//生成n的欧拉函数  

	long long m;

	m=(a-1)*(b-1);          //公式



	printf("m:%lld\n",m);






	//生成公钥e 

	long  long e;



	for(i=0;i<1000000000;i++)

	{}



	srand(time(NULL));

	e=rand()%m+1;

	for(i=0;;i++)

	{

		if(PrimeDet(e))

		{

			break;

		}

		else

		{

			e=rand()%m+1;

		}

	}



	printf("e:%lld\n",e);



	//生成私钥d   

	long long d;



	for(d=0;;d++)         //用一个for循环代替欧几里得扩展算法



	{

		if((e*d)%m==1)               

		{

			break;

		}

	}



	printf("d:%lld\n",d);




	//加密过程，用公钥e,n加密



	long int Message=888;

	long int CodedMessage;

	long int DecodedMessage

		CodedMessage=pow(Message,e)%n



		//解密过程，用私钥d,n解密

		DecodedMessage=pow(CodedMessage,d)%n



		//破解.下面在已知n的情况下,尝试把n分解成两个质数进而去破解私钥，此处虽然n只有十进制13位，但破解也非常耗时，因此，商业级应用rsa加密正是利用超大数分解的耗时性来保证加密的安全性。



		int long a1,b1;



	for(a1=1;a1<m;a1++)

	{

		for(b1=1;b1<m;b1++)

		{

			if(PrimeDet(b1))

			{

				if(PrimeDet(a1))

				{

					if(a1*b1==n)

					{

						break;

					}

				}

				else

				{

					continue;

				}

			}

			else

			{

				continue;

			}



		}

		if(a1*b1==n)

		{

			break;

		}



	}



	printf("a1=%ld,b1=%ld,n=%ld",a1,b1,a1*b1);



	return 0;

}
