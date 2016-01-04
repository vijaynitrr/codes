#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i,b) for(LL i=0;i<b;i++)
#define REP(i,a,b) for(LL i=a;i<=b;i++)
#define REV(i,b,a) for(LL i=b;i>=a;i--)

#define plln(n) printf("%lld\n",n)

#define s3ll(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
#define s2ll(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll(n) scanf("%lld",&n)

#define countSetBits(n) __builtin_popcountll(n)
#define gcd(a,b) __gcd(a,b)

#define mod 1000000007
#define mx 999999

vector<LL> adj[mx];
bool visited[mx];
LL n,e;

queue<LL> q;

void bfs(LL src)
{
	visited[src]=true;
	q.push(src);
	while(!q.empty())
	{
		LL  u=q.front();
		q.pop();
		cout<<u<<"->";
		for(LL i=0;i<adj[u].size();i++)
		{
			LL v=adj[u][i];
			if(!visited[v]){
				q.push(v);
				visited[v]=true;
			}
		}
	}
}

int main()
{
	LL t,i,j,a,b,k,x,ans;
	s2ll(n,e);
	rep(i,e){
		s2ll(a,b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	LL cnt=0;
	memset(visited,false,sizeof(visited));
	LL src;
	sll(src);
	bfs(src);
	return 0;
}
