#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
#define mem(arr,n) memset(arr,n,sizeof(arr))
const int INF=0x7f7f7f7f;
typedef long long ll;

//GlobalVar

//EndGlobalVar
int calc(int n)
{
	if(n==1000)return 11;
	static const int ma[50]={4,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
	static const int am[50]={0,0,6,6,5,5,5,7,6,6};
	int ans=0;
	if(n>=100)
		ans+=ma[n/100]+7+(n%100==0?0:3);
	n%=100;
	if(n!=0){
		if(n<20){
			ans+=ma[n];
		}
		else{
			ans+=am[n/10];
			ans+=n%10==0?0:ma[n%10];
		}
	}
	return ans;
}
int main(void)
{
	ll a[1005];
	a[0]=0;
	rep(1000){
		a[i]=calc(i)+a[i-1];
	}
	int T;
	cin>>T;
	rep(T){
		int n;
		cin>>n;
		cout<<a[n]<<'\n';
	}
}
