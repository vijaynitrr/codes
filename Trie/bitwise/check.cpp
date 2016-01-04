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

struct ptrie
{
    LL leftcount,rightcount,indx;
    struct ptrie *left,*right;
};

void initialize(struct ptrie *root)
{
    root->leftcount=root->rightcount=0;
    root->indx=0;
    root->left=root->right=NULL;
}

void addNumber(struct ptrie *root,LL idx,LL num,LL level)
{
    if(level==-1) return;
    if(level==0) root->indx=idx;
    LL bit=(num>>level)&1;
    if(bit)
    {
        //cout<<"R";
        if(root->right==NULL){
            root->right=(struct ptrie *)malloc(sizeof(struct ptrie));
            initialize(root->right);
        }
        root->rightcount+=1;
        addNumber(root->right,idx,num,level-1);
    }
    else
    {
        //cout<<"L";
        if(root->left==NULL){
            root->left=(struct ptrie *)malloc(sizeof(struct ptrie));
            initialize(root->left);
        }
        root->leftcount+=1;
        addNumber(root->left,idx,num,level-1);
    }
}

LL query(struct ptrie *root,LL num,LL level)
{
    if(level==-1) return 0;
    if(level==0) return root->indx;
    LL bit=(num>>level)&1;
    if(bit)
    {
        if(root->left==NULL) return query(root->right,num,level-1);
        else return query(root->left,num,level-1);
    }
    else
    {
        if(root->right==NULL) return query(root->left,num,level-1);
        else return query(root->right,num,level-1);
    }
}

int main()
{
    LL t,n,i,j,ans;
    struct ptrie *root=(struct ptrie *)malloc(sizeof(struct ptrie));
    LL x;
    sll(n);
    LL m=0,pre=0;
    rep(i,n)
    {
        sll(x);
        pre=pre^x;
        addNumber(root,i+1,pre,31);
        cout<<query(root,pre,31)<<" ";
    }
    //cout<<m<<endl;
    return 0;
}
