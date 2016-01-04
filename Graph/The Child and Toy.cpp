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
#define mx 1000005

vector<LL> adj[mx];
bool visited[mx];
LL n,e;
stack<LL> st;

void dfs(LL s)
{
	visited[s]=true;
	for(LL i=0;i<adj[s].size();i++)
	{
		LL v=adj[s][i];
		if(!visited[v])
			dfs(v);
	}
}

vector< pair<LL,LL> > v;

int main()
{
	LL t,i,j,a,b,k,x,ans=0;
	s2ll(n,k);
	LL val[n+5];
	REP(i,1,n) { sll(val[i]); v.push_back(make_pair(val[i],i));}
	rep(i,k){
		s2ll(a,b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	sort(v.begin(),v.end());
	REV(i,v.size()-1,0){
		LL p = v[i].second;
		rep(j,adj[p].size()){
			LL node = adj[p][j];
			ans+=val[node];
			adj[node].erase(find(adj[node].begin(),adj[node].end(),p),adj[node].end());
		}
	}
	plln(ans);
	return 0;
}
