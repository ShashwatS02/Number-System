#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        if(n==1||(n==x&&n==y)||(x+y+2<=n))puts("Yes");
        else puts("No");
    }
}
