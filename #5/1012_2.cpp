#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
//GlobalVar
const int MAXN=50005;
int a[MAXN];
//EndGlobalVar
struct BIT {
	typedef int BIT_c;
	int BIT_MAX = MAXN;
	BIT_c *BIT;
	BIT(BIT_c size) {
		BIT_MAX = size + 5;
		BIT=new BIT_c[BIT_MAX];
		memset(BIT,0,sizeof(BIT_c)*BIT_MAX);
	}
	int clear(){
		memset(BIT,0,sizeof(BIT_c)*BIT_MAX);		
	}
	~BIT(){
		delete []BIT;
	}
	inline int lowbit(const int &n) {
		return n & (-n);
	}
	inline int upper(const int &n) {
		return n + lowbit(n);
	}
	inline int lower(const int &n) {
		return n - lowbit(n);
	}
	int add(int ith, BIT_c dlt) {
		while (ith <= BIT_MAX) {
			BIT[ith] += dlt;
			ith = upper(ith);
		}
		return 0;
	}
	BIT_c sum(int ith) {
		BIT_c ans = 0;
		while (ith > 0) {
			ans += BIT[ith];
			ith = lower(ith);
		}
		return ans;
	}
}
int main(void)
{
	int n;
	while(scanf("%d",&n)!=EOF){
		unorderd_map<int,int> ma;
		int cnt=0;
		for(int i=0;i<n;i++){
			int t;
			scanf("%d",&t);
			if(ma[t]==0) ma[t]=++cnt;
			a[i]=ma[t];
		}
		BIT bit;
		for(int i=0;i<n;i++){
			
		}
	}
}