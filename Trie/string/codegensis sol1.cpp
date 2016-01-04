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
    LL words;
    LL prefixs;
    struct trie *child[26];
};

void initialize(struct trie *node)
{
    node->words=0;
    for(LL i=0;i<26;i++)
        node->child[i]=NULL;
}

LL addWord(struct trie *node,char *str)
{
    LL i;
    if(str[0]=='\0'){
        node->words=1;
        rep(i,26){
            if(node->child[i]!=NULL) return 1;
        }
        return 0;
    }
    else
    {
        if(node->words)
            return 1;
        char ch=str[0];
        if(node->child[ch-'a']==NULL)
        {
            node->child[ch-'a']=(struct trie *)malloc(sizeof(struct trie));
            initialize(node->child[ch-'a']);
        }
        addWord(node->child[ch-'a'],str+1);
    }
}

char s[mx];

int main()
{
    LL i,n,t,chk,flag;
    sll(t);
    while(t--)
    {
        flag=0;
        struct trie *root=NULL,*root1;
        root=(struct trie*)malloc(sizeof(struct trie));
        initialize(root);
        sll(n);
        rep(i,n){
            root1=root;
            scanf("%s",s);
            if(!flag){
                if(addWord(root1,s)) flag=1;
                else flag=0;
            }
        }
        if(flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
