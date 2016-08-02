#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
typedef long long ll;
//GlobalVar
const int MAXN=50005;
int n;
int a[MAXN];
//EndGlobalVar
int main(void)
{
	while(scanf("%d",&n)!=EOF){
		unordered_map<int,int> ma;
		ll sumr=0;
		ll ans=0;
		rep(n) scanf("%d",&a[i-1]);
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]>a[j]){
					sumr++;
					ma[a[i]]++;
					ma[a[j]]++;
				}
			}
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				int &ta=a[i];
				int &tb=a[j];
				if(ta<tb){
					ans+=sumr-ma[ta]-ma[tb];
				}
			}
		}
		cout<<ans<<'\n';
	}
}
