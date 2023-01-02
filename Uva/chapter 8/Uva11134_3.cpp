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
这是第三种写法，同样是对点进行考虑，不同于上次的全部遍历，采用一个堆去维护每次右端点的最小值
做法是：当考虑位置 i 时，把位置 i 开始的区间全部加入小根堆中，然后选取堆中第一个元素
如果第一个元素也不能满足要求的话，那么必是 IMPOSSIBLE 直接判断退出即可
*/
#define MAXN 5005
int ans[MAXN][2];

bool cal(vector<vector<PII>> arr,int n, int pos);
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
        vector<vector<PII>> x(MAXN),y(MAXN);
        FOR(i,1,n+1) {
            int xl = read<int>(), yl = read<int>();
            int xr = read<int>(), yr = read<int>();
            x[xl].push_back(MK(xr,i));  y[yl].push_back(MK(yr,i));
        }
        bool flag = cal(x,n,0);
        if(flag) flag = cal(y,n,1);
        if(flag) FOR(i,1,n+1) cout << ans[i][0] << " " << ans[i][1] <<  "\n";
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}

bool cal(vector<vector<PII>> arr,int n, int pos) {
    static priority_queue<PII,vector<PII>,greater<PII> > p;
    while(!p.empty()) p.pop();
    FOR(i,1,n+1) {
        for(int j = 0; j < arr[i].size(); j++)  p.push(arr[i][j]);
        if(p.empty() || p.top().first < i) return false;
        ans[p.top().second][pos] = i;
        p.pop();
    }
    return true;
}
