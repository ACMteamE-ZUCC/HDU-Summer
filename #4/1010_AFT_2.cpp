#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
//GlobalVar
const int MAX_N = 100005;
const int INF = 0x7f7f7f7f;
int n;
int a[MAX_N];
//EndGlobalVar

int LIS() {
	//static int s[MAX_N];
	static int d[MAX_N];
	memset(d, INF, sizeof(d));
	int ans = 0;
	d[0]=-1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			int ith=0;
			int bef=d[0]-1;
			while(d[ith]!=INF){
				int t=d[ith]+1;
				d[ith]=bef;
				bef=t;
				ith++;
			}
			d[ith]=bef;
			ans++;
		}
		else {
			int pos = lower_bound(d, d + n, a[i])-d;
			d[pos] = min(d[pos], a[i]);
			ans = max(ans, pos);
		}
	}
	return ans;
}
int imain(void)
{
	cin >> n;
	rep(n) cin >> a[i - 1];
	return LIS();
}
int main(void)
{
	int T;
	cin >> T;
	rep(T) {
		int ans=imain();
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
