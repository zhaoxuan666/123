#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#include<math.h>




//�����ж�����

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




	//���������������

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

			a=rand()%1000001+1000000;             //����һ��1000000��2000000֮�������

		}

	}



	for(i=0;i<1000000000;i++)   //��ֹ��������ͬ��������

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




	//���ɹ�Կn

	long long n;

	n=a*b;               //����λ��Խ���ƽ��ѶȻ�ָ������



	printf("n:%lld\n",n);



	//����n��ŷ������  

	long long m;

	m=(a-1)*(b-1);          //��ʽ



	printf("m:%lld\n",m);






	//���ɹ�Կe 

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



	//����˽Կd   

	long long d;



	for(d=0;;d++)         //��һ��forѭ������ŷ�������չ�㷨



	{

		if((e*d)%m==1)               

		{

			break;

		}

	}



	printf("d:%lld\n",d);




	//���ܹ��̣��ù�Կe,n����



	long int Message=888;

	long int CodedMessage;

	long int DecodedMessage

		CodedMessage=pow(Message,e)%n



		//���ܹ��̣���˽Կd,n����

		DecodedMessage=pow(CodedMessage,d)%n



		//�ƽ�.��������֪n�������,���԰�n�ֽ��������������ȥ�ƽ�˽Կ���˴���Ȼnֻ��ʮ����13λ�����ƽ�Ҳ�ǳ���ʱ����ˣ���ҵ��Ӧ��rsa�����������ó������ֽ�ĺ�ʱ������֤���ܵİ�ȫ�ԡ�



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
