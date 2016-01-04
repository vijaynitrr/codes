#include<bits/stdc++.h>

using namespace std;

#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)

#define plln(n) printf("%lld\n",n)

#define s3ll(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
#define s2ll(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll(n) scanf("%lld",&n)

#define countSetBits(n) __builtin_popcountll(n)

typedef long long LL;

#define mod 1000000007
#define mx 999999

LL T[mx],s[mx];

void build(LL node,LL l,LL r)
{
    LL lnode=(2*node),rnode=lnode+1,mid=(l+r)>>1;
    if(l==r) { T[node]=1; return;}
    build(lnode,l,mid);
    build(rnode,mid+1,r);
    T[node]=T[lnode]+T[rnode];
}

void update(LL node,LL l,LL r,LL idx)
{
    LL lnode=(2*node),rnode=lnode+1,mid=(l+r)>>1;
    if(l==r) { T[node]=0; return;}
    if(idx<=mid) update(lnode,l,mid,idx);
    else update(rnode,mid+1,r,idx);
    T[node]=T[lnode]+T[rnode];
}

LL query(LL node,LL l,LL r,LL cnt)
{
    LL lnode=(2*node),rnode=lnode+1,mid=(l+r)>>1;
    if(l==r) { return l;}
    if(T[lnode]>=cnt) query(lnode,l,mid,cnt);
    else query(rnode,mid+1,r,cnt-T[lnode]);
}
int main()
{
    LL t,n,i,j,k,x,ans;
    rep(i,mx) s[i]=i+1;
    sll(t);
    while(t--)
    {
        sll(n);
        LL res[n+6],a[n+6];
        rep(i,n) sll(a[i]);
        build(1,0,n-1);
        for(i=n-1;i>=0;i--)
        {
            res[i]=query(1,0,n-1,i+1-a[i]);
            update(1,0,n-1,res[i]);
        }
        rep(i,n) cout<<s[res[i]]<<" ";
        cout<<endl;
    }
    return 0;
}
