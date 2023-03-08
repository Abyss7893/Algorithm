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
int Q[35];

int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int m = read<int>(), n = read<int>();
    FOR(i,0,n) {
        cout << m << endl; 
        int ans = read<int>();
        if(ans == 0) exit(0);
        Q[i] = ans < 0 ? 1 : -1;
    }
    int begin = 1, end = m-1 , mid = (begin + end) >> 1;
    int flag = 0;
    while(true) {
        mid = (begin + end) >> 1;
        cout << mid << endl;
        int ans = read<int>();
        if(ans == 0 || ans == -2) exit(0);
        ans = ans * Q[(flag++) % n];
        if(ans == 1) begin = mid + 1;
        else end = mid - 1;
    }
    return 0;
}
