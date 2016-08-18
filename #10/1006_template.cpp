#include<iostream>  
#include<cstring>  
#include<cmath>  
#include<cstdio>  
#include<algorithm>  
int m;  
const int maxn = 105;  
using namespace std;  
struct Point//表示坐标  
{  
    double x,y;  
};  
struct Seg//s,e分别表示第一条线段和第二条线段  
{  
    Point s,e;  
}p[maxn];  
double cross(Point p1,Point p2,Point p3)    //叉积  
{  
    double d1 = p2.x - p1.x;//用了int型，WA了几发  
    double d2 = p2.y - p1.y;  
    double d3 = p3.x - p2.x;  
    double d4 = p3.y - p2.y;  
    return d1 * d4 - d3 * d2;  
}  
bool cal(Seg a,Seg b)  
{  
   if (max(a.s.x,a.e.x) >= min(b.s.x,b.e.x) &&  //排斥试验  
   max(b.s.x,b.e.x)>=min(a.s.x,a.e.x) &&  
   max(a.s.y,a.e.y) >= min(b.s.y,b.e.y) &&  
   max(b.s.y,b.e.y)>=min(a.s.y,a.e.y) &&  
   cross(b.s,a.e,a.s) * cross(b.e,a.e,a.s)<=0 &&    //跨立试验  
   cross(a.s,b.e,b.s) * cross(a.e,b.e,b.s)<=0)  
        return true;  
   else  
        return false;  
}  
int res()//两两判断，时间复杂度为(O(n^2))  
{  
    int i,j,cnt = 0;  
    for(i=1;i<=m;i++)  
    {  
        for(j=i+1;j<=m;j++)  
        {  
            if(cal(p[i],p[j]))  
                cnt++;  
        }  
    }  
    return cnt;  
}  
int main()  
{  
    //freopen("1.in","r",stdin);  
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        cin>>m;
        for(int i=1;i<=m;i++)  
        {  
            cin>>p[i].e.x>>p[i].e.y>>p[i].s.x>>p[i].s.y;  
        }  
        int result = res();  
        cout<<result<<endl; 
    } 
    return 0;  
}  
