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

struct trie
{
    LL maxweight;
    LL child[27];
};

trie node[200005];
LL root,cnt;
void addWord(string str,LL wt)
{
    LL curr=root,i;
    rep(i,str.length()){
        int ch=str[i]-'a';
        if(node[curr].child[ch]==-1)
        {
            node[curr].child[ch]=cnt;
            node[cnt].maxweight=0;
            memset(node[cnt].child,-1,sizeof(LL)*27);
            cnt++;
        }
        node[curr].maxweight=max(node[curr].maxweight,wt);
        curr=node[curr].child[ch];
    }
    node[curr].child[26]=0;
}

LL wordsearch(string str)
{
    LL curr=root,ans,i;
    rep(i,str.length()){
        int ch=str[i]-'a';
        if(node[curr].child[ch]==-1) return -1;
        curr=node[curr].child[ch];
        ans=node[curr].maxweight;
    }
    return ans;
}

int main()
{
    LL t,n,i,j,k,q,w,ans;
    root=0;
    cnt=1;
    node[root].maxweight=0;
    memset(node[root].child,-1,sizeof(LL)*27);
    s2ll(n,q);
    string str;
    rep(i,n){
        cin>>str;
        sll(w);
        addWord(str,w);
    }
    while(q--){
        cin>>str;
        LL flag=wordsearch(str);
        if(flag==-1) cout<<"-1"<<endl;
        else cout<<flag<<endl;
    }
    return 0;
}
