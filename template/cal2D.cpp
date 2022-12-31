#include<bits/stdc++.h>
using namespace std;

//#define abyss
typedef unsigned int UI;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#define re register
#define eps 1e-10
#define pi acos(-1)
#define ln(i)  ((i<<1))
#define rn(i)  (((i<<1|1)))
#define PII pair<int,int>
#define cp complex<double>
#define MK(a,b) make_pair(a,b) 
#define PLL pair<long long, long long>
#define FOR(i,begin,end)   for(register int i = begin; i < end; ++i)
#define rFOR(i,begin,end)   for(register int i = begin; i > end; --i)
#define clr(x,y)  memset(x,y,sizeof(x))

LL gcd(LL a, LL b) {return b == 0 ? a : gcd(b,a%b);}
template <typename T> inline T read() {
    T x = 0, sgn = 1;
    char c = getchar();
    for(; c < '0' || c > '9' ; c = getchar())
        if(c == '-') sgn = -1;
    for(; c >= '0' && c <= '9'; c = getchar())
        x = (x << 1) + (x << 3) + (c ^ 48);
    return x * sgn;
}
int dCmp(double x) {if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;} 
struct Point {
    double x,y;
    void read() { scanf("%lf%lf",&x,&y);}
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    Point operator + (Point B) {return Point(x + B.x, y + B.y);}
    Point operator - (Point B) {return Point(x - B.x, y - B.y);}
    Point operator * (double B) {return Point(x * B, y * B);}
    Point operator + (double B) {return Point(x / B, y / B);}
    void operator *= (double B) {x *= B; y *= B;}
    void operator /= (double B) {x /= B; y /= B;}
    bool operator < (const Point &B) {return dCmp(x - B.x) == 0 ? y < B.y : x < B.x;}
    bool operator == (Point B) {return dCmp(x - B.x) == 0 && dCmp(y - B.y) == 0;}
    
    double Dot(Point B) {return x * B.x + y * B.y;}
    double Cross(Point B) {return x * B.y - y * B.x;}
    double Length() {return sqrt(x * x + y * y);}
    double Angel(Point B) {return acos(Dot(B) / Length() / B.Length());}
    double Area2(Point B) {return Cross(B);}
    Point rotate(double rad) {return Point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));}
    Point normal() {double L = Length(); return Point(x / L, y / L);}
};
typedef Point Vector;
double Area2(Point A, Point B, Point C) {return (B-A).Cross(C-A);}

/*
直线用参数方程表示： P + tv 和 Q + tw
即求两条直线的交点
使用前确保两条直线一定有交点，即 v.Cross(w) != 0
*/
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w) {
    Vector u = P - Q;
    double t = w.Cross(u) / v.Cross(w);
    return u + v * t;
}

/*
求点到直线距离
P 为所求的点
A 和 B 为直线上的两个点
*/
double DistanceToLine(Point P, Point A, Point B) {
    Vector v1 = B - A, v2 = P - A;
    return fabs(v1.Cross(v2)) / v1.Length();
}

/*
求点到线段距离
P 为所求点
A 和 B 为线段的两个端点
*/
double DistanceToSegment(Point P, Point A, Point B) {
    if(A == B) return (P-A).Length();
    Vector v1 = B - A, v2 = P - A, v3 = P - B;
    if(dCmp(v1.Dot(v2)) < 0) return v2.Length();
    else if(dCmp(v1.Dot(v3)) > 0) return v3.Length();
    return fabs(v1.Cross(v2)) / v1.Length();
}

/*
求点在直线上的投影
P 为所求点
A 和 B 为直线上的两个点
*/
Point GetLineProjection(Point P, Point A, Point B) {
    Vector v = B - A;
    return A + v * (v.Dot(P - A) / v.Dot(v));
}

/*
判断两线段是否规范相交
规范相交是指：两条线段只有一个公共点，且公共点不是任何一条线段的端点
A 和 B 为第一条线段端点
C 和 D 为第二条线段端点
*/
bool SegmentProperIntersection(Point A, Point B, Point C, Point D) {
    double c1 = (B - A).Cross(C - A), c2 = (B - A).Cross(D - A),
           c3 = (D - C).Cross(A - C), c4 = (D - C).Cross(B - C);
    return dCmp(c1) * dCmp(c2) < 0 && dCmp(c3) * dCmp(c4) < 0;
}

/*
判断点是否在线段上(不包含端点)
P 为所求的点
A 和 B 为线段两个端点
*/
bool OnSegment(Point P, Point A, Point B) {
    return dCmp((A-P).Cross(B-P)) == 0 && dCmp((A - P).Dot(B - P)) < 0;
}


/*
求凸包经典的 Andrew 算法
P 数组为全部点的数组，n 为 P 数组的长度， P 角标从零开始
ans 为结果数组，返回值为 ans 的长度
如果不希望凸包边上也有输入点，只需把 <= 改为 < 即可
*/
int ConvexHull(Point *P, int n, Point *ans) {
    sort(P, P + n);
    int m = 0;
    FOR(i,0,n)  {
        while(m > 1 && dCmp((ans[m - 1] - ans[m - 2]).Cross(P[i] - ans[m - 1])) <= 0) m--;
        ans[m++] = P[i];
    }
    int k = m;
    rFOR(i,n-2,-1) {
        while(m > k && dCmp((ans[m - 1] - ans[m - 2]).Cross(P[i] - ans[m - 1])) <= 0) m--;
        ans[m++] = P[i];
    }
    if(n > 1) m--;
    return m;
}
/*
旋转卡壳求凸包最远点对
ch 为凸包端点数组，n 为数组长度
*/
double RotateCalipers(Point *ch,int n) {
    double ans = 0;
    ch[n] = ch[0];
    int q = 1;
    FOR(i,0,n) { 
        while( dCmp((ch[q]-ch[i+1]).Cross(ch[i]-ch[i+1]) - 
        (ch[q+1]-ch[i+1]).Cross(ch[i]-ch[i+1])) < 0)    q = (q + 1) % n;
        ans = max(ans, max((ch[q]-ch[i]).Length(), (ch[q+1]-ch[i]).Length()));
    }
    return ans;
}
// #define MAXN 200005
// Point p[MAXN], ans[MAXN];

int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    /*
    int n = read<int>();
    FOR(i,0,n) p[i].read();
    int len = ConvexHull(p,n,ans);
    double res = RotateCalipers(ans,len);
    printf("%.6f\n",res);
    */
    return 0;
}
