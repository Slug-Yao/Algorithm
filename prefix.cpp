//一维前缀和
#include<iostream>
using namespace std;

const int N=1010;

int n,m;
int a[N],s[N];

int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++) 
    scanf("%d",a[i]);//注意使用前缀和时i要从1开始
    for(int i=1;i<=n;i++) 
    s[i]=s[i-1]+a[i];

    while(m--)
    {
        int l, r;
        scanf("%d%d",&l,&r);
        printf("%d",s[r]-s[l-1]);
    }

}