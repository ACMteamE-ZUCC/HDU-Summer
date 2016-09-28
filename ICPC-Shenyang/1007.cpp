#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
#define mem(arr,n) memset(arr,n,sizeof(arr))
const int INF = 0x7f7f7f7f;
typedef long long ll;
//GlobalVar
const int ODD = 5;
const int EVEN = 4;
//EndGlobalVar
ll dp[20][6];
ll dfs(int index, int status) {
	if (dp[index][status] != -1) {
		return dp[index][status];
	}
	ll ans[6];
	memset(ans, 0, sizeof(ans));
	ans[1] += dfs(index - 1, 0) * ODD;
	ans[2] += dfs(index - 1, 0) * EVEN;
	ans[4] += dfs(index - 1, 0);

	ans[5] += dfs(index - 1, 1) * ODD;

	ans[0] += dfs(index - 1, 2) * EVEN; //
	ans[3] += dfs(index - 1, 2);

	ans[1] += dfs(index - 1, 5) * ODD;
	ans[0] += dfs(index - 1, 5) * EVEN; //
	ans[3] += dfs(index - 1, 5);

	ans[1] += dfs(index - 1, 3) * ODD;
	ans[2] += dfs(index - 1, 3) * EVEN;
	ans[4] += dfs(index - 1, 3);

	ans[0] += dfs(index - 1, 4) * EVEN; //
	ans[3] += dfs(index - 1, 4);

	for (int i = 0; i < 6; i++) {
		dp[index][i] = ans[i];
	}
	return ans[status];
}

int askws(ll n, int ws[]) {
	int ans = 0;
	while (n != 0) {
		ws[ans+1] = n % 10;
		n /= 10;
		ans++;
	}
	return ans;
}
ll sumup(int index) {
	return dfs(index, 0) + dfs(index, 5);
}
int next(int status, int n) {
	if (status == -1) {
		status = n % 2 == 1 ? 1 : 0;
	}
	else {
		if (n % 2 == 1) {
			if (status == 0)
				status = 1;
			else if (status == 1)
				status = 5;
			else if (status == 2)
				status = -2;
			else if (status == 5)
				status = 1;
		}
		else {
			if (status == 0)
				status = 2;
			else if (status == 1)
				status = - 2;
			else if (status == 2)
				status = 0;
			else if (status == 5)
				status = 0;
		}
	}
	return status;
}
ll count(ll n) {
	ll ans = 0;
	int ws[20];
	int LTH = askws(n, ws);
	for (int i = 1; i < LTH; i++)
		ans += sumup(i);
	int status = -1;
	for (int i = LTH; i >= 1; i--) {
		int ss=i;
		if (status == -2) break;
		dp[0][2]=1;
		dp[0][0]=dp[0][1]=dp[0][3]=dp[0][4]=dp[0][5]=0;
		if (status == -1) {
			for (int i = 1; i < ws[ss]; i++) {
				if (i % 2 == 0) { //Even
					ans += dfs(ss - 1, 2) + dfs(ss - 1, 5) + dfs(ss - 1, 4);
				}
				else { //Odd
					ans += dfs(ss - 1, 1);
				}
			}
		}
		else {
			for(int i=0;i<ws[ss];i++){
				int sta=next(status,i);
				if(sta==0)
					ans+=ss==1?1:dfs(ss-1,5)+dfs(ss-1,4);
				if(sta==1)
					ans+=dfs(ss-1,1);
				if(sta==2)
					ans+=dfs(ss-1,0)+dfs(ss-1,3);
				if(sta==5)
					ans+=ss==1?1:dfs(ss-1,0)+dfs(ss-1,3);
			}
		}
		/*for(int i=1;i<ws[i];i++){
			if(i%2==0){//Even
				ans+=dfs(i-1,2)+dfs(i-1,5)+dfs(i-1,4);
			}
			else{//Odd
				ans+=dfs(i-1,1);
			}
		}*/
		status=next(status,ws[i]);
	}
	return ans;
}
int init() {
	memset(dp, -1, sizeof(dp));
	dp[1][0] = 4;
	dp[1][1] = 5;
	dp[1][2] = 0;
	dp[1][3] = 1;
	dp[1][4] = 0;
	dp[1][5] = 0;
	return 0;
}

int main(void)
{
	init();
	int T;
	scanf("%d", &T);
	rep(T) {
//		ll L, R;
//		scanf("%lld%lld", &L, &R);
//		ll ans = count(R+1) - count(L);
//		printf("Case #%d: %lld\n",i,ans);
		
		ll ii;
		cin>>ii;
		cout<<count(ii)<<'\n';
	}
}
