#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, count = 0;
		cin >> n;
		int a[100005], b[100005];
		memset(b, 0, sizeof(b));
		map<int, int> mm;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mm[a[i]-1] = i;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[j] < a[i]) {
					b[a[i]]++;//把a[i]作为下标进行判断他右移的位数
				}
			}
		}
		cout << "Case " << "#" << ++count << ": ";
		for (int i = 0; i < n; i++) {
			//右移的位数加上初始位置即为最右边的距离 ,a[i]
			//int ans=abs(b[i]+mm[i]-min(mm[i],i));//在初始位置和最终取值
			int ans;
			//	cout<<mm[i]<<"\n";
			if (mm[i] >= i) {
				ans=mm[i]+b[i+1]-i;
			}
			else if (mm[i] < i) {
				ans=b[i+1];
			}
			cout << ans << " ";
		}
		cout << endl;

	}
}
