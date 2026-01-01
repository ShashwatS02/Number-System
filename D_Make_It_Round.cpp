#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a,b;
    if(!(cin>>a>>b)) return;
    ll x=a, c10=0,c2=0,c5=0;
    while(x>0 && x%10==0){ ++c10; x/=10; }
    while(x>0 && x%2==0){ ++c2; x/=2; }
    while(x>0 && x%5==0){ ++c5; x/=5; }

    ll k=1;
    while(c5>0 && k*2<=b){ k<<=1; --c5; }
    while(c2>0 && k*5<=b){ k*=5; --c2; }

    for(ll t=10;t>=2;--t){
        while(k*t<=b) k*=t;
    }

    cout<<k*a<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    cin>>T;
    while(T--) solve();
    return 0;
}
