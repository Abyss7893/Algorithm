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
#define MOD 998244353 
#define ln(i)  ((i<<1))
#define rn(i)  (((i<<1|1)))
#define PII pair<int,int>
#define cp complex<double>
#define MK(a,b) make_pair(a,b)
#define __MAX__NUM__  2000006
#define PLL pair<long long, long long>
#define FOR(i,begin,end)   for(register int i = begin; i < end; ++i)
#define rFOR(i,begin,end)   for(register int i = begin; i > end; --i)
#define clr(x,y)  memset(x,y,sizeof(x))

int fac[__MAX__NUM__], ifac[__MAX__NUM__];
int fpm(int a, int b = MOD - 2) {
    int ans = 1;
    for(;b;b >>= 1, a = (LL)a * a % MOD)
        if(b & 1) ans = (LL) ans * a % MOD;
    return ans;
}
void initComb(int n) {
    fac[0] = 1;
    FOR(i,1,n+1) fac[i] = (LL)fac[i-1] * i % MOD;
    ifac[n] = fpm(fac[n]);
    rFOR(i,n,0) ifac[i-1] = (LL)ifac[i] * i % MOD;
}
int Comb(int n,int m) {
    return (LL)fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

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

int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    return 0;
}
