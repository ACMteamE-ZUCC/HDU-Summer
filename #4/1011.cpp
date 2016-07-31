#include<bits/stdc++.h>
//extra includes
using namespace std;
#define rep(n) for(int i=1;i<=(n);i++)
//GlobalVar
const string s[23] = {
	"Baltimore Bullets",
	"Boston Celtics",
	"Chicago Bulls",
	"Cleveland Cavaliers",
	"Dallas Mavericks",
	"Detroit Pistons",
	"Golden State Warriors",
	"Houston Rockets",
	"L.A. Lakers",
	"Miami Heat",
	"Milwaukee Bucks",
	"Minneapolis Lakers",
	"New York Knicks",
	"Philadelphia 76ers",
	"Philadelphia Warriors",
	"Portland Trail Blazers",
	"Rochester Royals",
	"San Antonio Spurs",
	"Seattle Sonics",
	"St. Louis Hawks",
	"Syracuse Nats",
	"Washington Bullets"
};
const int num[23] = {
	1,
	17,
	6,
	1,
	1,
	3,
	2,
	2,
	11,
	3,
	1,
	5,
	2,
	2,
	2,
	1,
	1,
	5,
	1,
	1,
	1,
	1
};
//EndGlobalVar
int main(void)
{
	map<string,int> m;
	for(int i=0;i<22;i++){
		m[s[i]]=num[i];
	}
	int T;
	cin>>T;
	getchar();
	rep(T){
		string ss;
		getline(cin,ss);
		printf("Case #%d: %d\n",i,m[ss]);
	}
}
