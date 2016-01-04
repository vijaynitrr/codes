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

LL tree[mx],a[mx];

void build(LL node,LL l,LL r)
{
	LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if(l==r) { tree[node]=a[l]; return;}
    build(lnode,l,mid);
    build(rnode,mid+1,r);
    tree[node]=tree[lnode]&tree[rnode];
}

LL query(LL node,LL a,LL b,LL l,LL r)
{
    LL lnode=(2*node),rnode=(2*node)+1,mid=(l+r)>>1;
    if( b<l || a>r ) return -1;
    if( a<=l && r<=b ) return tree[node];
    LL p1=query(lnode,a,b,l,mid);
    if(!p1) return 0;
    LL p2=query(rnode,a,b,mid+1,r);
    if(!p2) return 0;
    if(p1==-1) return p2;
    if(p2==-1) return p1;
    return p1&p2;
}

int main()
{
    LL t,n,i,j,k,ans;
    sll(t);
    while(t--)
    {
        s2ll(n,k);
        memset(tree,0,sizeof(tree));
        rep1(i,n) sll(a[i]);
        build(1,1,n);
        if(k>=n) k=n-1;
        rep1(i,n){
            LL ls=i-k;
            LL rs=i+k;
            if((ls>=1)&&(rs<=n)){
                printf("%lld ",query(1,ls,rs,1,n));
                continue;
            }else if((ls<1)&&(rs>n)){
                printf("%lld ",query(1,1,n,1,n));
                continue;
            }else if((ls<1)){
                ans=query(1,1,rs,1,n)&query(1,n-(ls*-1),n,1,n);
                printf("%lld ",ans);
                continue;
            }
            ans=query(1,ls,n,1,n)&query(1,1,rs-n,1,n);
            printf("%lld ",ans);
        }
        printf("\n");
    }
    return 0;
}
