//双指针算法
#include<iostream>
#include<algorithm>
using namespace std;

const int N=100010;
int a[N],s[N];
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);

    int res=0;

    for(int i=0,j=0;i<n;i++)
    {
        s[a[i]]++;
        while(s[a[i]]>1)
    {
        s[a[j]]--;
        j++;
    }
    res= max(res,i-j+1);
    }
    cout<<res;
}