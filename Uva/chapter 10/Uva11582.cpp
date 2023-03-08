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
#define endl "\n"
#define inf 0x3f3f3f3f
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
#define MAXN 1003
int ans[MAXN][MAXN];
int num[MAXN * MAXN];
int F(int idx,int mod);
int fast_pow(ULL a, ULL b, int n);
int cal(int f1, int f2, int pos, int n);
int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int T = read<int>();
    while(T--) {
        ULL a = read<ULL>(), b = read<ULL>();
        int n = read<int>();
        clr(ans,0);
        int loop = cal(1,1,1,n);
        int idx = fast_pow(a,b,loop);
        cout << F(idx,n) << endl;
    }
#ifdef abyss
    cout << "\nTime used = ";
    cout << 1000 * (double)clock() / CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}

int cal(int f1, int f2, int pos, int n) {
    if(ans[f1][f2]) return pos - ans[f1][f2] - 1;
    ans[f1][f2] = pos;
    int f3 = (f1 + f2) % n;
    return cal(f2, f3, pos+1, n);
}

int fast_pow(ULL a, ULL b, int n) {
    a %= n;
    int res = 1;
    if(b == 0) return res;
    while(b) {
        if(b&1) res = (res * a) % n;
        a = (a * a) % n;
        b >>= 1;
    }
    return res;
}

int F(int idx, int mod) {
    num[1] = 1; num[2] = 1;
    for(int i = 3; i <= idx; i++)
        num[i] = (num[i-1] + num[i-2]) % mod;
    return num[idx];
}