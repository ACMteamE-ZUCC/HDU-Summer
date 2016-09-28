#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
#define mem(arr,n) memset(arr,n,sizeof(arr))
const int INF = 0x7f7f7f7f;

//GlobalVar
vector<int> a;
int L, N, M;
//EndGlobalVar

int test(int t) {
	int cnt = 0;
	rep(N + 1) {
		if (a[i] < t) {
			int j=a[i];
			while(j<t&&i<=N+1){
				i++;
				cnt++;
				j+=a[i];
			}
		}
	}
	return cnt<=M;
}
int idiv(int l,int r) {
	if(r-l<=7){
		for(int i=r;i>=l;i--){
			if(test(i)){
				return i;
			}
		}
	}
	int ave = (l + r) / 2;
	if(test(ave)){
		return idiv(ave,r);
	}
	else{
		return idiv(l,ave);
	}

}
int main(void)
{
	cin >> L >> N >> M;
	a.push_back(0);
	rep(N) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	a.push_back(L);
	for(int i=N+1;i>=1;i--){
		a[i] = a[i] - a[i - 1];
	}
	cout << idiv(1, L) << '\n';
}
