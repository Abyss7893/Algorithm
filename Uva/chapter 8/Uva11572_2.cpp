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
这个是利用 map 储存起来上一个节点在哪里，然后区间时左开右闭(必须注意的是59行先++)
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
#define MAXN 1000006
int num[MAXN];

int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int Case = read<int>();
    while(Case--) {
        int n = read<int>();
        __gnu_pbds::gp_hash_table<int,int> tag;
        FOR(i,1,n+1) num[i] = read<int>();
        int L = 0, R = 1, ans = 0;
        while(R <= n) {
            if(tag[num[R]]) {
                int newL = tag[num[R]];   
                while(L != newL) tag[num[++L]] = 0;
            }
            tag[num[R]] = R;
            ans = max(ans, R - L);   R++;
        }
        cout << ans << "\n";
    }
    return 0;
}
