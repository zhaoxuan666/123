#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#define x 15
#define y 15
int num[100][100];
int Num[100][100];
void color(short m) //自定义函根据参数改变颜色   
	{  
		    if(m>=0 && m<=15)//参数在0-15的范围颜色  
			       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m);    //只有一个参数，改变字体颜色   
		    else//默认的颜色白色  
			       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  
	}  

int Up(int X,int Y) 
{
	int K=0,i;
	if(num[X][Y]==0)
	{
		if(num[X-1][Y]==1||num[X-1][Y]==2)
		{
			K=1;
			for(i=1;i<4;i++)
			{
				if(num[X-1][Y]==num[X-1-i][Y])
					K++;
				else i=4;
			}
		}
	}
	return(K);
}
int Down(int X,int Y)
{
	int K=0,i;
	if(num[X][Y]==0)
	{
		if(num[X+1][Y]==1||num[X+1][Y]==2)
		{
			K=1;
			for(i=1;i<4;i++)
			{
				if(num[X+1][Y]==num[X+1+i][Y])
					K++;
				else i=4;
			}
		}
	}
	return(K);
}
int Left(int X,int Y)
{
	int K=0,i;
	if(num[X][Y]==0)
	{
		if(num[X][Y-1]==1||num[X][Y-1]==2)
		{
			K=1;
			for(i=1;i<4;i++)
			{
				if(num[X][Y-1]==num[X][Y-1-i])
					K++;
				else i=4;
			}
		}
	}
	return(K);
}
int Right(int X,int Y)
{
	int K=0,i;
	if(num[X][Y]==0)
	{
		if(num[X][Y+1]==1||num[X][Y+1]==2)
		{
			K=1;
			for(i=1;i<4;i++)
			{
				if(num[X][Y+1]==num[X][Y+1+i])
					K++;
				else i=4;
			}
		}
	}
	return(K);
}
int Up_right(int X,int Y)
{
	int K=0,i;
	if(num[X][Y]==0)
	{
		if(num[X-1][Y+1]==1||num[X-1][Y+1]==2)
		{
			K=1;
			for(i=1;i<4;i++)
			{
				if(num[X-1][Y+1]==num[X-1+i][Y+1+i])
					K++;
				else i=4;
			}
		}
	}
	return(K);
}
int Down_right(int X,int Y)
{
	int K=0,i;
	if(num[X][Y]==0)
	{
		if(num[X+1][Y+1]==1||num[X+1][Y+1]==2)
		{
			K=1;
			for(i=1;i<4;i++)
			{
				if(num[X+1][Y+1]==num[X+1+i][Y+1+i])
					K++;
				else i=4;
			}
		}
	}
	return(K);
}
int Down_left(int X,int Y)
{
	int K=0,i;
	if(num[X][Y]==0)
	{
		if(num[X+1][Y-1]==1||num[X+1][Y-1]==2)
		{
			K=1;
			for(i=1;i<4;i++)
			{
				if(num[X+1][Y-1]==num[X+1+i][Y-1-i])
					K++;
				else i=4;
			}
		}
	}
	return(K);
}
int Up_left(int X,int Y)
{
	int K=0,i;
	if(num[X][Y]==0)
	{
		if(num[X-1][Y-1]==1||num[X-1][Y-1]==2)
		{
			K=1;
			for(i=1;i<4;i++)
			{
				if(num[X-1][Y-1]==num[X-1-i][Y-1-i])
					K++;
				else i=4;
			}
		}
	}
	return(K);
}

int win(int X,int Y)//输赢判断
{
	int a=0,b=0,c=0,d=0,i,t;
	if(num[X][Y]==1||num[X][Y]==2)
	{ 
		for(i=0;i<5;i++)// 、
		{
			if(num[X][Y]==num[X+i][Y+i])
				a++;
		}
		for(i=0;i<5;i++)// |
		{
			if(num[X][Y]==num[X][Y+i])
				b++;
		}
		for(i=0;i<5;i++)// -
		{
			if(num[X][Y]==num[X+i][Y])
				c++;
		}
		for(i=0;i<5;i++)// /
		{
			if(num[X][Y]==num[X-i][Y+i])
				d++;
		}
	}
	a=(a>b)?a:b;
	a=(a>c)?a:c;
	a=(a>d)?a:d;
	t=num[X][Y];//t就是传进来的数字 1 或者 2
	a=a*t;
	return (a);
}
int main()
{//system ("color e");
	int i,j,a,t=6,k=6; 
	int q1,q2,q3,q4,q5,q6,q7,q8; /*8个方向的权值变量*/
	int M=0,m=0,Max=0,p1,p2,Q,W; /*------M为空位的最大权值、m为跳转变量、QW为胜利变量---*/
	
	
	while(1)//开始执行
	{
		printf("\n\t五子棋人机对战\n\n");
		printf("   ");
		for (i=1;i<=x;i++)
		{
			printf("%2d",i);
		}
		printf("\n");
		for(i=0;i<x;i++)
		{
			printf("%2d ",i+1);
			for(j=0;j<y;j++)
			{
				//判断输赢  
				Q=win(i,j);
				if(Q==5)
					W=1;
				else if(Q==10)
					W=2;


				if(i==t&&j==k) /*-----原始坐标输出光标-------*/
					printf("■");
				else if(num[i][j]==1) /*--------输出白棋------------*/
					printf("●");//
				else if(num[i][j]==2) /*--------输出黑棋------------*/
				{ printf("○");//system ("color 8e");
				}
				//else printf("  "); /*-□----输出棋盘空白位置-------*/
			
				
				else if(i==0&&j==0)//以下为边缘棋盘样式
					printf("┏ ");
				else if(j==x-1&&i==0)
					printf("┓ ");
				else if(i==x-1&&j==y-1)
					printf("┛ ");
				else if(j==0&&i==y-1)
					printf("┗ ");
				else if(j==0)
					printf("┠ ");
				else if(j==y-1)
					printf("┨ ");
				else if(i==0)
					printf("┯ ");
				else if(i==y-1)
					printf( "┷ ");
				else
					printf("┼ ");//中间的空位
			}
			printf("\n");
		}
		if(W==1)
		{
			
		color(7);	printf("黑棋赢！！！\n");
			getchar();
			return 0;
		}
		else if(W==2)
		{
			
		color(7);	  printf("白棋赢！！！\n");
			getchar();
			return 0;
		} //键盘输入方向移动与放棋子
		for(i=0;i<2;i++)
		{
			a=getch();
			if(a!=224) 
				i=2; /*-----------跳出循环-------------*/
		}
		switch(a)
		{
		case(72):if(t>0) /*-----左边不能超出棋盘上边缘---------*/
					 t=t-1;break; /*-----方向键输入↑时向上移动---------*/
		case(80):if(t<x-1)
					 t=t+1;break; /*-----方向键输入↓时向下移动---------*/
		case(75):if(k>0)
					 k=k-1;break; /*-----方向键输入←时向左移动---------*/
		case(77):if(k<y-1)
					 k=k+1;break; /*-----方向键输入→时向右移动---------*/
		case(32):
			if(m==0&&num[t][k]!=1&&num[t][k]!=2)
			{
				num[t][k]=1;
				m=1; /*-------电脑AI 走------------*/
			}
			if(m==1)
			{
				for(i=0;i<15;i++) //遍历棋盘，看在哪一点计算的值最大
				{
					for(j=0;j<15;j++)
					{
						q1=Up(i,j);
						q2=Down(i,j);
						q3=Left(i,j);
						q4=Right(i,j);
						q5=Up_right(i,j);
						q6=Down_right(i,j);
						q7=Down_left(i,j);
						q8=Up_left(i,j);
						M=(q1>q2)?q1:q2;
						M=(M>q3)?M:q3;
						M=(M>q4)?M:q4;
						M=(M>q5)?M:q5;
						M=(M>q6)?M:q6;
						M=(M>q7)?M:q7;
						M=(M>q8)?M:q8;
						Num[i][j]=M;
					}
				}
				for(i=0;i<15;i++) //遍历Num数组取最大的
				{
					for(j=0;j<15;j++)
					{
						if(Num[i][j]>Max)
						{
							p1=i;
							p2=j;
							Max=Num[p1][p2];
						}
						//if(num[i-1][j]==2||num[i+1][j]==2||num[i][j-1]==2||num[i][j+1]==2||num[i-1][j-1]==2||num[i+1][j+1]==2)
					}
				}
				num[p1][p2]=2; //下黑棋

				//初始化从人开始
				m=0; 
				Max=0; 
			}break; 
		}
		system("cls");
	}
}