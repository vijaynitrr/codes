//http://codeforces.com/contest/550/problem/C

#include<bits/stdc++.h>
#define d(x) (s[x]-'0')
using namespace std;

int dp[105][10] = {0};
string store[105][10];
char s[105];
int main(){
    scanf("%s", s);
    dp[0][0]++; store[0][0] = "";
    dp[0][d(0)%8]++; store[0][d(0)%8] = s[0];

    for(int i=1, l=strlen(s); i<l;i++)
        for(int j=0; j<8;j++){
            if(dp[i-1][j]){
                store[i][j] = store[i-1][j];
                store[i][(j*10 + d(i))%8] = store[i-1][j] + s[i];
            }
            dp[i][(j*10 + d(i))%8] |= dp[i-1][j];
            dp[i][j] |= dp[i-1][j];
        }

    for(int i=0, l=strlen(s); i<l;i++) if(dp[i][0] && store[i][0].length()){ cout << "YES" << endl << store[i][0] << endl;  return 0;}
    cout << "NO" << endl;
    return 0;
}
