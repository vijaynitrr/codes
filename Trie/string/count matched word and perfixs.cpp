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
    node->prefixs=0;
    for(LL i=0;i<26;i++)
        node->child[i]=NULL;
}

void addWord(struct trie *node,char *str)
{
    if(str[0]=='\0'){
        node->words+=1;
        return;
    }
    else
    {
        node->prefixs+=1;
        char ch=str[0];
        if(node->child[ch-'a']==NULL)
        {
            node->child[ch-'a']=(struct trie *)malloc(sizeof(struct trie));
            initialize(node->child[ch-'a']);
        }
        addWord(node->child[ch-'a'],str+1);
    }
}

LL countWords(struct trie *node,char *str)
{
    if(str[0]=='\0')
        return node->words;
    else if(node->child[str[0]-'a']==NULL)
        return 0;
    else
        return countWords(node->child[str[0]-'a'],str+1);
}

LL countPrefix(struct trie *node,char *str)
{
    if(str[0]=='\0')
        return node->prefixs;
    else if(node->child[str[0]-'a']==NULL)
        return 0;
    else
        return countPrefix(node->child[str[0]-'a'],str+1);
}

int main()
{
    struct trie *root=NULL;
    root=(struct trie *)malloc(sizeof(struct trie));
    initialize(root);
    addWord(root,(char *)"vijay");
    addWord(root,(char *)"vikas");
    addWord(root,(char *)"vinay");
    addWord(root,(char *)"vinay");
    addWord(root,(char *)"vipin");
    addWord(root,(char *)"vijas");
    cout<<countWords(root,"vijay")<<endl;
    cout<<countPrefix(root,"vij")<<endl;
    return 0;
}
