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
#define mx 999999

LL tree[mx];

void build(LL node,LL l,LL r)
{
	LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if(l==r) { tree[node]+=a[l]; return;}
    build(lnode,l,mid);
    build(rnode,mid+1,r);
    tree[node]=tree[lnode]+tree[rnode];
}

void update(LL node,LL l,LL r,LL idx,LL val)
{
    LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if(l==r){
        a[l]=val;
        tree[node]+=val;
    }
    if( idx<=mid )
    {
        update(lnode,l,mid,idx,val);
    }
    else{
        update(rnode,mid+1,r,idx,val);
    }
    tree[node]=tree[lnode]+tree[rnode];
}

LL query(LL node,LL a,LL b,LL l,LL r)
{
    LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if( b<l || a>r ) return 0;
    if( a<=l && r<=b ) return tree[node];
    LL p1=query(lnode,a,b,l,mid);
    LL p2=query(rnode,a,b,mid+1,r);
    return (p1+p2);
}

int main()
{
    LL t,n,i,j,ans;
    sll(t);
    while(t--)
    {
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
