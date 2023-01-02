#include<bits/stdc++.h>
using namespace std;

//#define abyss
typedef unsigned int UI;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#define re register
#define pi acos(-1)
#define eps 1e-9
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
/*
首先注意转化，x 和 y 坐标都是独立的因此可以分开考虑，这样就变成了一维的问题
对于每一维，考虑如下贪心策略：将所有区间按照右端点从小到大排序，然后选取每个区间里能满足放置要求的最小点
如何找每个区间内满足要求的最小点呢？数据点较弱遍历即可。
这样贪心的正确性：首先右端点越靠前一定要越先用，对于每个区间，考虑放在最前面，一定不劣于放在后面。
*/

#define MAXN 5005
typedef struct node{
    int l,r;
    int idx;
    bool operator < (const struct node sh) {
        if(r != sh.r) return r < sh.r;
        return l < sh.l;
    }
}node;
node x[MAXN], y[MAXN];
bool valid[MAXN];
int ans[MAXN][2];

int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n;
    while(scanf("%d",&n) && n) {
        FOR(i,1,n+1) {
            x[i].l = read<int>();    y[i].l = read<int>();  x[i].idx = i;
            x[i].r = read<int>();    y[i].r = read<int>();  y[i].idx = i;
        }
        sort(x + 1, x + 1 + n);
        sort(y + 1, y + 1 + n);
        bool flag = true;   clr(valid,false);
        FOR(i,1,n+1) {
            register bool temp = true;
            FOR(j,x[i].l,x[i].r+1) if(!valid[j]) {
                valid[j] = true;    ans[x[i].idx][0] = j;
                temp = false;    break;
            }
            if(temp) {flag = false; break;}
        }
        clr(valid, false);
        if(flag)    FOR(i,1,n+1) {
            register bool temp = true;
            FOR(j,y[i].l,y[i].r+1) if(!valid[j]) {
                valid[j] = true;    ans[y[i].idx][1] = j;
                temp = false;    break;
            }
            if(temp) {flag = false; break;}
        }
        if(flag)    FOR(i,1,n+1) cout << ans[i][0] << " " << ans[i][1] << "\n";
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}