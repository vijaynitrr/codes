//http://codeforces.com/contest/550/problem/C
#include <iostream>
using namespace std;
int main()
 {
     int a=0;
     string s;cin>>s;
     s="00"+s;
     int l=s.length();
     for(int i=0;i<l;i++){
        for(int j=i+1;j<l;j++){
     for(int k=j+1;k<l;k++){a=100*(s[i]-'0')+10*(s[j]-'0')+(s[k]-'0');if (a%8==0) {cout<<"YES"<<"\n"<<a;return 0;}}}}
     cout<<"NO";
     return 0;
 }
