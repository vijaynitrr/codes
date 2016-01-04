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

LL table[mx];
bool lazy[mx];

void update(LL node,LL l,LL r,LL a,LL b)
{
    LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if(lazy[node]){
        lazy[node]=false;
        table[node]=r-l+1-table[node];
        if(r>l){
            lazy[lnode]=!lazy[lnode];
            lazy[rnode]=!lazy[rnode];
        }
    }
    if( b<l || a>r ) return ;
    if( a<=l && r<=b ){
        table[node]=r-l+1-table[node];
        if(r>l){
            lazy[lnode]=!lazy[lnode];
            lazy[rnode]=!lazy[rnode];
        }
        return;
    }
    update(lnode,l,mid,a,b);
    update(rnode,mid+1,r,a,b);
    table[node]=table[lnode]+table[rnode];
}

LL query(LL node,LL a,LL b,LL l,LL r)
{
    LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if( b<l || a>r ) return 0;
    if(lazy[node]){
        lazy[node]=false;
        table[node]=r-l+1-table[node];
        if(r>l){
            lazy[lnode]=!lazy[lnode];
            lazy[rnode]=!lazy[rnode];
        }
    }
    if( a<=l && r<=b ) return table[node];
    LL p1=query(lnode,a,b,l,mid);
    LL p2=query(rnode,a,b,mid+1,r);
    return (p1+p2);
}

int main()
{
    LL t,n,i,j,x,m,L,R,ans;
    memset(table,0,sizeof(table));
    memset(lazy,false,sizeof(lazy));
    s2ll(n,m);
    while(m--)
    {
        sll(x);
        if(x==0){
            s2ll(L,R);
            update(1,1,n,L,R);
        }else{
            s2ll(L,R);
            plln(query(1,L,R,1,n));
        }
    }
    return 0;
}
