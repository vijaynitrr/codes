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

vector<LL> v[mx];
LL a[mx];

void build(LL node,LL l,LL r)
{
	LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if(l==r) { v[node].push_back(a[l]); return;}
    build(lnode,l,mid);
    build(rnode,mid+1,r);
    merge(v[lnode].begin(),v[lnode].end(),v[rnode].begin(),v[rnode].end(),back_inserter(v[node]));
}

LL query(LL node,LL l,LL r,LL a,LL b,LL k)
{
    LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if( b<l || a>r ) return 0;
    if( a<=l && r<=b ) return (v[node].size()-(upper_bound(v[node].begin(),v[node].end(),k)-v[node].begin()));
    LL p1=query(lnode,l,mid,a,b,k);
    LL p2=query(rnode,mid+1,r,a,b,k);
    return (p1+p2);
}

int main()
{
    LL t,n,q,i,j,k,p,d,r,ans;
    sll(n);
    rep(i,n) sll(a[i]);
    sll(q);
    ans=0;
    build(1,0,n-1);
    vector<LL>::iterator it;
        for(it=v[1].begin();it!=v[1].end();it++){
            cout<<(*it)<<" ";
        }
    while(q--)
    {
        s3ll(i,j,k);
        p=ans^i;
        d=ans^j;
        r=ans^k;
        ans=query(1,0,n-1,p-1,d-1,r);
        plln(ans);
    }
    return 0;
}
