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
    LL isEnd;
    struct trie *child[26];
    trie()
    {
        isEnd=0;
        for(LL i=0;i<26;i++)
            child[i]=NULL;
    }
};

LL addWord(struct trie *node,char *str)
{
    LL i;
    if(str[0]=='\0'){
        node->isEnd=1;
        for(i=0;i<26;i++){
            if(node->child[i]) return 1;
        }
        return 0;
    }else{
        if(node->isEnd)
            return 1;
        int ch=str[0]-'a';
        if(node->child[ch]==NULL){
            node->child[ch]=new trie;
        }
        addWord(node->child[ch],str+1);
    }
}

char s[55];

int main()
{
    LL t,n,i,j,k;
    struct trie *root=NULL;
    root=new trie;
    sll(t);
    LL flag=0;
    while(t--)
    {
        scanf("%s",s);
        if(!flag){
            if(addWord(root,s)) flag=1;
            else flag=0;
        }
    }
    if(flag) cout<<"vulnerable"<<endl;
    else cout<<"non vulnerable"<<endl;
    return 0;
}
