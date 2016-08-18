//#include<bits/stdc++.h>
#include<list>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
#define mem(arr,n) memset(arr,n,sizeof(arr))
const int INF=0x7f7f7f7f;
typedef long long ll;

//GlobalVar
ll s_cnt;
struct node{
	int num;
	ll cnt;
	node(int _num){
		num=_num;
		cnt=s_cnt++;
	}
	node(){
		num=0;
		cnt=0x7f7f7f7f7f7f7f7f;
	}
	inline friend bool operator <(const node &l,const node &r){
		return l.cnt<r.cnt?true:false;
	}
};
int N;
//node arr[3][100005];
//EndGlobalVar
int imain(void){
	list<node> a;
	//int ta=0;
	list<node> b;
	//int tb=0;
	//node* swp=arr[2];
	//int ts=0;

	s_cnt=0;
	rep(N){
		static char CMD[10];
		scanf("%s",CMD);
		if(CMD[0]=='p'){
			char c;
			scanf(" %c",&c);
			if(CMD[1]=='u'){//push
				int num;
				scanf("%d",&num);
				if(c=='A'){
					//a[ta++]=node(num);
					a.push_back(node(num));
				}
				if(c=='B'){
					b.push_back(node(num));
					//b[tb++]=node(num);
				}
			}
			else{//pop
				if(c=='A'&&!a.empty()){
					printf("%d\n",a.rbegin()->num);
					a.resize(a.size()-1);
				}
				if(c=='B'&&!b.empty()){
					printf("%d\n", b.rbegin()->num);
					b.resize(b.size() - 1);
				}
			}
		}
		else{//merge
			char c1,c2;
			scanf(" %c %c",&c1,&c2);
			if(c1=='B'){
				b.merge(a);
				a.clear();
			}
			else {
				a.merge(b);
				b.clear();
			}
		}
	}
	return 0;
}
int main(void)
{
	int cntt=0;
	while(scanf("%d",&N),N!=0){
		cntt++;
		printf("Case #%d:\n",cntt);
		imain();
	}
}
