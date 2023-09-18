//离散化
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N=300030;
int n,m;
int a[N],s[N];

typedef pair <int,int> PII;

vector<int>alls;
vector<PII>add,query;


int find(int x)
{
	int l=0,r=alls.size()-1;
	
	while(l<r)
	{
	int mid=l+r>>1;
	if(alls[mid]>=x) r=mid;
	else l=mid+1;
	}

	//因为要使用前缀和，所以返回r+1
	return r + 1;
}

int main()
{
	cin>>n>>m;

	for(int i=0;i<n;i++)
	{
		int x,c;
		cin>>x>>c;
		add.push_back({x,c});

		alls.push_back(x);
	}

	for(int i=0;i<m;i++)
	{
		int l,r;
		cin>>l>>r;

		query.push_back({l,r});

		alls.push_back(l);
		alls.push_back(r);
	}

	//去重
	sort(alls.begin(),alls.end());
	unique((alls.begin(),alls.end()),alls.end());

	//处理输入
	for(auto item:add)
	{
		int x=find(item.first);
		a[x]+=item.second;
	}

	//预处理前缀和
	for(int i=1;i<=alls.size();i++)
		s[i]=s[i-1]+a[i];

	for(auto item:query)
	{
		int l=find(item.first),r=find(item.second);
		cout<<s[r]-s[l-1]<<endl;
	}

}