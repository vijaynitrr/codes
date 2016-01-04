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
#define xx 1000000005

LL tree[mx],a[mx];

void build(LL node,LL l,LL r)
{
	LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if(l==r) { tree[node]=a[l]; return;}
    build(lnode,l,mid);
    build(rnode,mid+1,r);
    tree[node]=min(tree[lnode],tree[rnode]);
}

LL query(LL node,LL a,LL b,LL l,LL r)
{
    LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if( b<l || a>r ) return xx;
    if( a<=l && r<=b ) return tree[node];
    LL p1=query(lnode,a,b,l,mid);
    LL p2=query(rnode,a,b,mid+1,r);
    return min(p1,p2);
}

int main()
{
    LL t,n,i,j,k,L,R,ans;
    sll(t);
    rep1(j,t)
    {
        cout<<"Scenario #"<<j<<":"<<endl;
        memset(tree,0,sizeof(tree));
        s2ll(n,k);
        rep1(i,n) sll(a[i]);
        build(1,1,n);
        while(k--)
        {
            s2ll(L,R);
            plln(query(1,L,R,1,n));
        }
    }
    return 0;
}
