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

struct node
{
    LL i;
    LL j;
    LL k;
    LL pos;
}inp[mx];

bool cmp(const node &a,const node &b)
{
    return a.k<b.k;
}

void build(LL node,LL l,LL r)
{
	LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if(l==r){ tree[node]=1; return;}
    build(lnode,l,mid);
    build(rnode,mid+1,r);
    tree[node]=tree[lnode]+tree[rnode];
}

void update(LL node,LL l,LL r,LL idx)
{
    LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if(l==r){
        tree[node]=0;
        return;
    }
    if( idx<=mid )
    {
        update(lnode,l,mid,idx);
    }
    else{
        update(rnode,mid+1,r,idx);
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
    LL t,n,i,d,j,q,p,c;
    vector< pair<LL,LL> > v;
    sll(n);
    LL a[n+5];
    build(1,0,n-1);
    rep(i,n){
        sll(a[i]);
        v.push_back(make_pair(a[i],i));
    }
    sort(v.begin(),v.end());
    sll(q);
    LL ans[q+5];
    rep(p,q){
        s3ll(inp[p].i,inp[p].j,inp[p].k);
        inp[p].pos=p;
    }
    sort(inp,inp+q,cmp);
    LL loc=0;
    rep(c,q){
        while((loc<n)&&(v[loc].first<=inp[c].k)){
            update(1,0,n-1,v[loc].second);
            loc++;
        }
        //cout<<inp[c].i<<" "<<inp[c].j<<" "<<inp[c].k<<" "<<inp[c].pos<<endl;
        ans[inp[c].pos]=query(1,inp[c].i-1,inp[c].j-1,0,n-1);
    }
    rep(i,q){
        cout<<ans[i]<<endl;
    }
    return 0;
}
