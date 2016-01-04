#include<bits/stdc++.h>

using namespace std;

#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)

#define plln(n) printf("%lld\n",n)

#define s3ll(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
#define s2ll(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll(n) scanf("%lld",&n)

typedef long long LL;

#define MOD 1000000007
#define mx 5000005

LL ans[mx],o[mx],c[mx];

string str;

void build(LL node,LL l,LL r)
{
	LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if(l==r) {
        if(str[l]=='(') o[node]=1;
        else c[node]=1;
        return;
    }
    build(lnode,l,mid);
    build(rnode,mid+1,r);
    LL temp=min(o[lnode],c[rnode]);
    ans[node]=ans[lnode]+ans[rnode]+temp;
    o[node]=o[lnode]+o[rnode]-temp;
    c[node]=c[lnode]+c[rnode]-temp;
}

typedef pair< LL,pair<LL,LL> > vertex;
typedef pair<LL,LL>  pll;

vertex query(LL node,LL a,LL b,LL l,LL r)
{
    LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if( l>b || a>r ) return vertex(0,pll(0,0));
    if( a<=l && r<=b ) return vertex(ans[node],pll(o[node],c[node]));
    vertex temp,x,y;
    LL m,n,p,q;
    x=query(lnode,a,b,l,mid);
    y=query(rnode,a,b,mid+1,r);
    m=min(x.second.first,y.second.second);
    n=x.first+y.first+m;
    p=x.second.first+y.second.first-m;
    q=x.second.second+y.second.second-m;
    return vertex(n,pll(p,q));
}

int main()
{
    LL t,n,q,L,R,i,j;
    cin>>str;
    n=str.length();
    memset(ans,0,sizeof(ans));
    memset(o,0,sizeof(o));
    memset(c,0,sizeof(c));
    sll(q);
    build(1,0,n-1);
    while(q--)
    {
        s2ll(L,R);
        L--;R--;
        //query(1,L,R,0,n-1);
        plln((query(1,L,R,0,n-1).first)*2);
    }
    return 0;
}

