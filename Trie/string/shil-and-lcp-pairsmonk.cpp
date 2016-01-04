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
    LL sum;
    struct trie *child[26];
    trie()
    {
        sum=0;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
};

LL ans[1000010];
LL maxlength=0;
void addWord(struct trie *node,string str,LL len)
{
    maxlength=max(maxlength,len);
    if(str.length()==len){
        ans[len]+=node->sum;
        node->sum++;
        return;
    }else{
        int ch=str[len]-'a';
        if(node->child[ch]==NULL){
            node->child[ch]=new trie;
        }
        ans[len]+=(node->sum)-(node->child[ch]->sum);
        addWord(node->child[ch],str,len+1);
        node->sum++;
    }
}


int main()
{
    LL t,n,i,j,k;
    struct trie *root=NULL;
    root=new trie;
    sll(n);
    string str;
    while(n--){
        cin>>str;
        addWord(root,str,0);
    }
    rep(i,maxlength+1)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
