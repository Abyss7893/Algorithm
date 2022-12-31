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

/*
非常妙的思路，要求 a + b + c + d = 0 的配对个数有多少。
我们可以用一个 map 把 a + b 的值存起来，时间复杂度 O(n^2 log n)
再遍历 c 和 d 找出 -(c + d) 的值再于 map 中进行匹配即可。这样子拆分以后时间复杂度大大下降

同理这样的思路可以进一步扩展，其本质是分类，既然之前 a + b + c = 0我们可以先选 a+b,那么别的地方
也可以类似这样分类。比如要求 a^2 + b^2 + c^3 + d^4 = e(常数)均可以。

另外值得一提的是，Uva卡了 map 的一个大 log 的常数。可以改用 __gnu_pbds 中的类来实现，时间大大下降
*/


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
#define MAXN 4005
int a[MAXN], b[MAXN], c[MAXN], d[MAXN]; 

__gnu_pbds::gp_hash_table<int,int> ab;

int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int Case = read<int>(), n;
    FOR(k,0,Case) {
        if(k != 0) cout << "\n";
        scanf("\n%d",&n);
        FOR(i,1,n+1) {
            a[i] = read<int>(); b[i] = read<int>();
            c[i] = read<int>(); d[i] = read<int>();
        }
        FOR(i,1,n+1) FOR(j,1,n+1) ab[a[i] + b[j]]++;
        LL ans = 0;
        FOR(i,1,n+1) FOR(j,1,n+1) ans += ab[-c[i] - d[j]];
        cout << ans << "\n";
        ab.clear(); 
    }
    return 0;
}
