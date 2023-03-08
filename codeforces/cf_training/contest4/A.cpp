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
int rel[6][6];
inline bool check(int a,int b, int c) {
    int temp = rel[a][b] + rel[b][c] + rel[c][a];
    return temp == 3 || temp == 0;
}
int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int m = read<int>();
    clr(rel,0);
    while(m--) {
        int u = read<int>(), v = read<int>();
        rel[u][v] = 1; rel[v][u] = 1;
    }
    bool ans = false;
    FOR(i,1,6) FOR(j,1,6) FOR(k,1,6) 
        if(i != j && j != k && k != i && !ans)
            ans = check(i,j,k);
    if (ans) cout << "WIN\n";
    else cout <<"FAIL\n";
    return 0;
}

