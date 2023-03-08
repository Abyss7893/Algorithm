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
#define MAXN 10004
int nums[MAXN];

int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n = read<int>(), m = read<int>();
    bool flag = true;   
    while(m--) {
        int k = read<int>();    clr(nums,0);
        bool ans = false;
        for(int i = 1; i <= k; i++) {
            int num = read<int>();
            if(num < 0 && nums[-num] > 0) ans = true;
            else if(num > 0 && nums[num] < 0) ans = true;
            nums[abs(num)] = num > 0 ? 1 : -1;
        }
        if(ans == false) {flag = ans; break;}
    }
    if (!flag)   cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
