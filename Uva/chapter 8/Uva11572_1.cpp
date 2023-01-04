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
暴力 STL 即可，用 set 维护一下区间，然后双指针移动即可(比较喜欢左右都是闭区间)
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
        set<int> tag;
        FOR(i,1,n+1) num[i] = read<int>();
        int L = 1, R = 1, ans = 0;
        while(R <= n) {
            if(tag.count(num[R]) != 0) {
                while(num[L] != num[R]) tag.erase(num[L++]);
                L++;
            }
            else tag.insert(num[R]);
            ans = max(ans, R - L + 1);   R++;
        }
        cout << ans << "\n";
    }
    return 0;
}
