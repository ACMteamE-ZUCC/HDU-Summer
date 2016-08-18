#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
#define mem(arr,n) memset(arr,n,sizeof(arr))
const int INF=0x7f7f7f7f;
typedef long long ll;
//GlobalVar
//EndGlobalVar
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
int main(void)
{
	ios_base::sync_with_stdio(false);
	ll n,m;
	while(cin>>n>>m,!(n==0&&m==0)){
		ll a=1;
		ll b=1;
		a=(m-1)*n;
		b=m*m;
		ll g=gcd(a,b);
		cout<<a/g<<'/'<<b/g<<'\n';
	}
}
