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
#define mx 100010

LL n,e;
LL ans1=0,ans2=0;

int main()
{
	LL t,c,e,i,j,a,b,k,x,ans;
	sll(t);
	rep1(c,t)
	{
		vector<LL> adj[mx];
		bool visited[mx];
		LL level[mx];
		queue<LL> q;
		ans=ans1=ans2=0;
		sll(e);
		LL mi,mxx;
		rep(i,e){
			s2ll(a,b);
			visited[a]=visited[b]=false;
			adj[a].push_back(b);
			adj[b].push_back(a);
			if(i==0){
				mi=min(a,b);
				mxx=max(a,b);
			}
			else{
				mi=min(mi,min(a,b));
				mxx=max(mxx,max(a,b));
			}
		}
		REP(p,mi,mxx){
			ans1=ans2=0;
			if( (adj[p].size()) && (!visited[p]) ) {
				level[p]=0;
				visited[p]=true;
				ans1++;
				q.push(p);
				while(!q.empty())
				{
					LL  u=q.front();
					q.pop();
					for(LL i=0;i<adj[u].size();i++)
					{
						LL v=adj[u][i];
						if(!visited[v]){
							level[v]=level[u]+1;
							visited[v]=true;
							if(level[v]%2==0) ans1++;
							else ans2++;
							q.push(v);
						}
					}
				}
				//check for each connected component
				ans+=max(ans1,ans2);
			}
		}
		cout<<"Case "<<c<<": ";
		plln(ans);
		REP(i,mi,mxx) adj[i].clear();
	}
	return 0;
}
