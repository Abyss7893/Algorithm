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
#define MAXN 100000
vector<LL>ans;
int cnt = 0, k;
void DFS(LL num, LL deep) {
    if(cnt > MAXN || deep > k) return;
    if(num == 1 || deep == k) {ans.emplace_back(num); cnt++; return;}
    for(LL i = 1; i <= num; i++) if(num % i == 0) {
        DFS(i, deep+1);
        if(cnt > MAXN) return;
    }
}
int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    LL X = read<LL>();  k = read<LL>();
    DFS(X,0);
    int len = ans.size();
    for(int i = 0; i < len; i++) cout << ans[i] << " ";
    return 0;
}
