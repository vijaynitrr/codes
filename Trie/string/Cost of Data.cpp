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

LL cnt;

void addWord(struct trie *node,char *str)
{
    if(str[0]=='\0'){
        return ;
    }else{
        int ch=str[0]-'a';
        if(node->child[ch]==NULL){
            cnt++;
            node->child[ch]=new trie;
        }
        addWord(node->child[ch],str+1);
    }
}

char s[55];

int main()
{
    LL t,n,i,j,k;
    cnt=0;
    struct trie *root=NULL;
    root=new trie;
    sll(t);
    LL flag=0;
    while(t--)
    {
        scanf("%s",s);
        addWord(root,s);
    }
    plln(cnt);
    return 0;
}
