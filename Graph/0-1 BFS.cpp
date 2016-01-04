#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i,b) for(LL i=0;i<b;i++)
#define rep1(i,b) for(LL i=1;i<=b;i++)
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

vector< pair<LL,LL> > adj[mx];
deque<LL> q;
LL dist[mx];
LL n,e;

void bfs(LL src)
{
	q.push_back(src);
	dist[src]=0;
	while(!q.empty())
	{
		LL u=q.front();
		q.pop_front();
		for(LL  i=0;i<adj[u].size();i++){
			LL v=adj[u][i].first;
			if(dist[v]>dist[u]+adj[u][i].second)
			{
				dist[v]=dist[u]+adj[u][i].second;
				if(adj[u][i].second==0) q.push_front(v);
				else q.push_back(v);
			}
		}
	}
}

int main()
{
	LL t,i,j,k,a,b,w,ans;
	s2ll(n,e);
	rep1(i,e){
		s3ll(a,b,w);
		adj[a].push_back(make_pair(b,w));
		adj[b].push_back(make_pair(a,w));
	}
	rep1(i,n) dist[i]=mx;
	LL src;
	sll(src);
	bfs(src);
	rep(i,n) cout<<dist[i]<<" ";
	cout<<endl;
	return 0;
}
