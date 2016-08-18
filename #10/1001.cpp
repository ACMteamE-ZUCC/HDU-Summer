#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
#define mem(arr,n) memset(arr,n,sizeof(arr))
const int INF=0x7f7f7f7f;
typedef long long ll;
//GlobalVar
const int MAXN=100005;
//EndGlobalVar
struct seg{
	int *arr;
	int l1,r1,ll,rr,l2,r2;
	int lth1,lth2,lth3;
	seg(int *_arr,int kl1,int kr1,int kl2,int kr2){
		arr=_arr;
		kr1++;
		kr2++;
		if (kr1 > kr2) {
            swap(kl1, kl2);
            swap(kr1, kr2);
        }
        if(kr1>kl2){
        	if(kl1<kl2){
        		l1=kl1;
        		r1=kl2;
        		ll=kl2;
        		rr=kr1;
        		l2=kr1;
        		r2=kr2;
        	}
        	if(kl1>=kl2){
        		l1=kl2;
        		r1=kl1;
        		ll=kl1;
        		rr=kr1;
        		l2=kr1;
        		r2=kr2;
        	}
        }
        if(kr1<=kl2){
        	l1=kl1;
        	r1=kr1;
        	ll=kr1;
        	rr=kr1;
        	l2=kl2;
        	r2=kr2;
        }
        lth1=r1-l1;
        lth2=rr-ll;
        lth3=r2-l2;
	}
	int operator [](int n){
		if(n<=lth1){
			return arr[l1+n-1];
		}
		if(n>lth1&&n<=lth1+lth2*2){
			n-=lth1;
			return arr[ll+(n+1)/2-1];
		}
		if(n>lth1+lth2*2){
			n=n-lth1-lth2*2;
			return arr[l2+n-1];
		}
		exit(0);
	}
};
int a[MAXN];
int main(void)
{
	int T;
	scanf("%d",&T);
	rep(T){
		int n,m;
		scanf("%d%d",&n,&m);
		rep(n){
			scanf("%d",a+i);
		}
		rep(m){
			int l1,r1,l2,r2;
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			seg se(a,l1,r1,l2,r2);
			int lth=r1-l1+1+r2-l2+1;
			double ans;
			if(lth%2==1){
				ans=se[lth/2+1];
			}
			else{
				ans=((ll)se[lth/2]+(ll)se[lth/2+1])/2.0;
			}
			printf("%.1f\n",ans);
		}
	}
}
