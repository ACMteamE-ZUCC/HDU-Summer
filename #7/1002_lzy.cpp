#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    ll temp;
    while(b)
    {    
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m,!(n==0&&m==0)){
        ll x= n*(m-1);
        ll y= m*m;
        ll g= gcd(x,y);
        cout<<x/g<<'/'<<y/g<<'\n';
    }
    return 0;
}
