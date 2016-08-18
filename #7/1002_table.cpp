#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
#define mem(arr,n) memset(arr,n,sizeof(arr))
const int INF=0x7f7f7f7f;
typedef long long ll;
//GlobalVar
int n,m;
//EndGlobalVar
ll gcd(ll x, ll y)
{
	if(y == 0) return x;    
	if(x < y) return gcd(y,x);    
	else return gcd(y, x%y); 
} 
template <class T> 
    class fenshu
    {
        public:
        	T a;
            T b;
            fenshu(T m, T n){
            	ll g=gcd(m,n);
            	a=m/g;
            	b=n/g;
            }
            fenshu(): a(0),b(1){}
            T geta()const{ return a;}
            T getb() const {return b;}
    };
template <class T>
    ostream& operator<< (ostream &out, T &v)
    {
        out << v.geta() << '/' << v.getb() << endl;
        return out;
    }
template <class T>
    T operator*(T v1, T v2)
    {
        T a(v1.geta()*v2.geta(), v1.getb()*v2.getb());
        return a;
    }
template <class T>
    T operator/(T v1, T v2)
    {
        T a(v1.geta()*v2.getb(), v1.getb()*v2.geta());
        return a;
    }
template <class T>
    T operator+(T v1, T v2)
    {
        T a(v1.geta()*v2.getb()+ v1.getb()*v2.geta(), v1.getb() * v2.getb());
        return a;
    }
template <class T>
    T operator-(T v1, T v2)
    {
        T a(v1.geta()*v2.getb()- v1.getb()*v2.geta(), v1.getb() * v2.getb());
        return a;
    }
typedef fenshu<ll> FS;
FS C(ll a,ll b){
	FS c(1,1);
	rep(a) c=c*FS(b-i+1,1);
	rep(a) c=c/FS(i,1);
	return c;
}
FS P(ll c){
	FS ans(1,1);
	ans=C(c,n);
	rep(n-c) ans=ans*FS(m-1,1);
	rep(n) ans=ans/FS(m,1);
	ans=ans*FS(m,1);
	return ans;
}
int imain(void)
{
	FS ans;
	for(int i=0;i<=n;i++){
		FS tmp(1,1);
		FS dlt;
		if(i<(double)n/m){
			dlt=FS(n,m)-FS(i,1);
		}
		else{
			dlt=FS(i,1)-FS(n,m);
		}
		FS p=P(i);
		tmp=tmp*p*dlt*dlt;
		ans=ans+tmp;
	}
	ans=ans/FS(m,1);
	cout<<ans.a<<'/'<<ans.b<<endl;
	return 0;
}
int main(void)
{
	printf("n\tm\tans\n");
	rep(10){
		cout<<3<<'\t'<<i<<'\t';
		n=3;
		m=i;
		imain();
	}
	return 0;
}
