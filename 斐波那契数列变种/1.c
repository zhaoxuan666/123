#include<stdio.h>
const int N=1000000;
int Fbi[N];

int main()
{
    int n,i;
    Fbi[0]=1;
    Fbi[1]=0;
    for(int i=2;i<N;i++)
    {
        Fbi[i]=Fbi[i-1]+Fbi[i-2];
    }
    scanf("%d",&n);
    for(i=1;i<N;i++)
        if(Fbi[i-1]<=n&&Fbi[i]>=n)
            break;
    int m=Fbi[i]-n<n-Fbi[i-1]?Fbi[i]:Fbi[i-1];
    int s=(m-n>0?m-n:n-m);
    printf("%d", s);
}