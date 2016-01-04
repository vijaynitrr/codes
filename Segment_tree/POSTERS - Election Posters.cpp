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
#define mx 10000005

set<LL> s;

LL tree[mx],lazy[mx];

void shift(LL id)
{
    if(lazy[id])
        lazy[(2*id)]=lazy[(2*id)+1]=lazy[id];
    lazy[id]=0;
}

void update(LL node,LL l,LL r,LL a,LL b,LL val)
{
	LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
	if( b<l || a>r ) return;
    if((a<=l)&&(r<=b)) { lazy[node]=val; return;}
    shift(node);
    update(lnode,l,mid,a,b,val);
    update(rnode,mid+1,r,a,b,val);
}

void query(LL node,LL l,LL r)
{
    LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if(lazy[node])
    {
        s.insert(lazy[node]);
        return;
    }
    if(l==r) return;
    query(lnode,l,mid);
    query(rnode,mid+1,r);
}

int main()
{
    LL t,n,i,j,q,L,R,ans;
    sll(t);
    while(t--)
    {
        memset(lazy,0,sizeof(lazy));
        sll(q);
        rep1(i,q)
        {
            s2ll(L,R);
            L--;R--;
            update(1,0,mx-1,L,R,i);
        }
        query(1,0,mx-1);
        plln(s.size());
        s.clear();
    }
    return 0;
}
