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
#define mx 100005

LL arr[mx],n,sze[mx];
LL cnt[mx]={0};

void initialize()
{
	REP(i,1,n) { arr[i]=i; sze[i]=1;}
}

LL root(LL x)
{
	while(arr[x]!=x)
	{
		arr[x]=arr[arr[x]];
		x=arr[x];
	}
	return x;
}

void union_set(LL a,LL b)
{
	LL x=root(a);
	LL y=root(b);
	if(sze[x]>sze[y]){
		sze[x]+=sze[y];
		arr[y]=arr[x];
	}else{
		sze[y]+=sze[x];
		arr[x]=arr[y];
	}
}

int main()
{
	LL t,i,j,k,a,b,x,ans=0;
	sll(n);
	sll(k);
	LL minn=1,maxx=0;
	initialize();
	if(k==1){ s2ll(a,b); cout<<"0"<<endl;}
	else{
	    while(k--)
	    {
		    s2ll(a,b);
		    cnt[a]++;cnt[b]++;
		    if(cnt[a]==1) ans++;
		    if(cnt[b]==1) ans++;
		    if(root(a)!=root(b)){
			//untill all nodes is not visited size of minimum size set is 1.
		        if(ans==n) minn=mx;
		        else minn=1;
		        union_set(a,b);
		        minn=min(minn,sze[root(a)]);
		        maxx=max(maxx,sze[root(a)]);
		        ans=min(ans,maxx-minn);
		    }
		    plln(maxx-minn);
	    }
	}
	return 0;
}

