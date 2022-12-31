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
char ans[60];

/*
构造题，这类题的经典标识：找到一个合理解满足xxxxx
因为限制条件比较少，只需要满足不同国家之间有相邻即可。哪里能相邻？同楼层相邻或者不同楼层上下临。
假设有 n 个国家，那么每个国家要跟其他的 n - 1 个国家都相邻，也即每个国家至少有 n - 1 个房间。
不妨来两层，每一层均是 n * n 个房间，第一层以行为单位放置 n 个房间，第二层以列为单位放置 n 个房间即可。
*/

inline void init() {FOR(i,0,26) {ans[i] = 'A' + i; ans[i + 26] = 'a' + i;}}
int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n;
    init();
    while(~scanf("%d",&n)) {
        cout << "2 " << n << " " << n << endl;
        FOR(i,0,n) {FOR(j,0,n) cout << ans[i];  cout << "\n";}
        cout << "\n";
        FOR(i,0,n) {FOR(j,0,n) cout << ans[j];  cout << "\n";}
        cout << "\n";
    }
    return 0;
}
