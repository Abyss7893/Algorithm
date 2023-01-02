#include<bits/stdc++.h>
#include<bits/extc++.h>
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
#define MAXN 250050

/*
判断欧拉路问题。
无向图存在欧拉路的条件：
1. 图是连通图   2. 无向图中度为奇数的点只有 0 个(闭合回路)或者两个(欧拉链两个顶点)
剩下的只需要并查集判断是否连通以及记录每个顶点的度数即可。

这个题的读入是字符串，因此还涉及到一个字符串与数字 index 的一个映射，第一反应是哈希。
如果用哈希的话就是 gp_hash_table 来写，普通的 map 会 tle，或者也可以采用字典树来构造

推广到有向图，给出有向图的结论：
* 连通有向图是欧拉图当且仅当每个顶点的入度等于出度
* 连通有向图中存在欧拉路要么全部定点入度等于出度；要么除两个顶点外，
  其余顶点的出度与入度都相等，而这两个顶点中一个顶点的出度与入度之差为 1，另一个顶点的出度与入度之差为 -1
*/

__gnu_pbds::gp_hash_table<string,int> h;
int fa[MAXN], degree[MAXN];
char l[15], r[15];
int cnt = 0;
int getF(int pos) {
    if(fa[pos] != pos) fa[pos] = getF(fa[pos]);
    return fa[pos];
}
int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    while(scanf("%s%s",l,r) != EOF) {
        if(cnt > 250010) break;
        if(!h[l]) {h[l] = ++cnt; fa[cnt] = cnt;}    degree[h[l]] ^= 1;
        if(!h[r]) {h[r] = ++cnt; fa[cnt] = cnt;}    degree[h[r]] ^= 1;
        int lf = getF(h[l]), rf = getF(h[r]);
        fa[rf] = lf;
    }
    int single = 0;
    FOR(i,1,cnt+1) if(degree[i]&1) single++;
    bool flag = (single == 0 || single == 2 ? true : false);
    if(cnt > 250005) flag = false;
    if(flag) {
        int father = getF(1);
        FOR(i,2,cnt + 1) if(getF(i) != father) {flag = false; break;}
    }
    if(flag) cout << "Possible\n";
    else cout << "Impossible\n";
    return 0;
}
