#include<bits/stdc++.h>
using namespace std;

#define abyss
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
#define MAXN 15
vector<vector<int> > G(MAXN);
int deg[MAXN], f[MAXN], ans;
bool vis[MAXN];

void DFS(int pos) {
    vis[pos] = true;
    if(deg[pos] == 1) {f[pos] = 1; return;}
    for(auto x : G[pos]) {
        if(f[x] == 0 && !vis[x]) DFS(x);
        ans = max(ans, f[x] + f[pos]);
        f[pos] = max(f[pos], f[x] + deg[pos] - 1);
    }
}

int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int q = read<int>();
    while(q--) {
        ans = 0;
        int n = read<int>();
        for(int i = 1; i <= n; i++) G[i].clear(), f[i] = 0, vis[i] = false;
        for(int i = 1; i < n; i++) {
            int u = read<int>(), v = read<int>();
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) deg[i] = G[i].size();
        DFS(1);
        cout << ans << "\n";
    }
    return 0;
}
