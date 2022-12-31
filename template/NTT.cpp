#include<bits/stdc++.h>
using namespace std;

//#define abyss
typedef unsigned int UI;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#define re register
#define pi acos(-1)
#define ln(i)  ((i<<1))
#define rn(i)  (((i<<1|1)))
#define PII pair<int,int>
#define MK(a,b) make_pair(a,b) 
#define PLL pair<long long, long long>
#define FOR(i,begin,end)   for(register int i = begin; i < end; ++i)
#define rFOR(i,begin,end)   for(register int i = begin; i > end; --i)
#define clr(x,y)  memset(x,y,sizeof(x))
const int MOD = 998244353, Gn = 3, Gi = 332748118; 

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
inline void NTT(LL *A, int limits, int type);
inline LL fastPow(LL a, LL k) {
	LL base = 1LL;
	while(k) {
		if(k & 1) base = (base * a) % MOD;
		a = (a * a) % MOD;
		k >>= 1;
	}
	return base % MOD;
}
#define MAXN 1000006
int rev[4 * MAXN];
LL F[4 * MAXN], G[4 * MAXN];

int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    /*
    int n = read<int>(), m = read<int>();
    FOR(i,0,n + 1) F[i] = (read<LL>() + MOD) % MOD;
    FOR(i,0,m + 1) G[i] = (read<LL>() + MOD) % MOD;
    int limits = 1;
    while(limits <= m + n) limits <<= 1;
    NTT(F,limits,1); NTT(G,limits,1);
    FOR(i,0,limits) F[i] = (F[i] * G[i]) % MOD;
    NTT(F,limits,-1);
    LL inv = fastPow(limits, MOD - 2);
    FOR(i,0,m + n + 1) cout << (F[i] * inv) % MOD << " ";
    */

    return 0;
}

inline void NTT(LL *A, int limit, int type) {
    int bit = 0;
    while ((1<<bit) < limit) bit++;
    FOR(i,0,limit) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
        if(i < rev[i]) swap(A[i], A[rev[i]]);
    }	
	for(re int mid = 1; mid < limit; mid <<= 1) {	
		LL Wn = fastPow( type == 1 ? Gn : Gi , (MOD - 1) / (mid << 1));
		for(re int j = 0; j < limit; j += (mid << 1)) {
			LL w = 1;
			for(re int k = 0; k < mid; k++, w = (w * Wn) % MOD) {
				 int x = A[j + k], y = w * A[j + k + mid] % MOD;
				 A[j + k] = (x + y) % MOD,
				 A[j + k + mid] = (x - y + MOD) % MOD;
			}
		}
	}
}