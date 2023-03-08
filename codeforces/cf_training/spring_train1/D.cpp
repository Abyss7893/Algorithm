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
#define MAXN 1000006
int bucket[MAXN], nums[MAXN];
int dp[MAXN];
int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n = read<int>(), MAX = 0;
    for(int i = 1; i <= n; i++) {
        nums[i] = read<int>();
        MAX = max(MAXN, nums[i]);
        bucket[nums[i]]++;
    }
    sort(nums+1, nums+1+n);
    int tot = unique(nums+1,nums+1+n) - nums - 1;
    for(int i = 1; i <= tot; i++) {
        int t = nums[i];
        dp[t] = max(dp[t], bucket[t]);
        for(int j = 2; j * t <= MAX; j++)
            dp[j*t] = max(dp[j*t], bucket[j*t]+dp[t]);
    }
    int res = 0;
    for(int i = 1; i <= tot; i++)
        res = max(res, dp[nums[i]]);
    cout << res << "\n"; 
#ifdef abyss
    cout << "\nTime used = ";
    cout << 1000 * (double)clock() / CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}
