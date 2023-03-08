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
#define MAXN 100005
LL pre[MAXN], cnt = 0;

void init();
int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    init();
    int T;  LL n;
    scanf("%d",&T);
    while(T--) {
        scanf("%lld",&n);
        int num = 1;
        while(n - pre[num] >= 0) num++;
        int pos = n - pre[num-1];
        printf("133");
        FOR(i,1,pos+1) printf("7");
        FOR(i,3,num) printf("3");
        printf("7\n");
    }
    return 0;
}

void init() {
    cnt = 1;
    while(pre[cnt] < 1e9 + 1e7) {
        cnt++;
        pre[cnt] = cnt * (cnt - 1) / 2;
    }
    pre[2] = 1;
}