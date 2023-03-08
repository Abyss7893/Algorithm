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
#define endl "\n"
#define inf 0x3f3f3f3f
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
#define MAXN 10005

bool vis[MAXN];
int prime[MAXN], e[MAXN], top = 0;
void init(){
    for(re int i = 2; i <= MAXN; i++) {
        if(!vis[i]) prime[++top] = i;
        for(int j = 1; j <= top && i * prime[j] <= MAXN; j++) {
            vis[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}
void add(int num,int fun);
void add_factorial(int num, int fun);

int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    init();
    int p, q, r, s;
    while(scanf("%d %d %d %d",&p,&q,&r,&s) == 4) {
        clr(e,0);
        add_factorial(p,1);
        add_factorial(q,-1);
        add_factorial(p-q,-1);
        add_factorial(r,-1);
        add_factorial(s,1);
        add_factorial(r-s,1);
        double ans = 1.0;
        for(re int i = 1; i <= top; i++) if(e[i] != 0)
            ans *= pow(prime[i], e[i]);
        printf("%.5f\n",ans);
    }

#ifdef abyss
    cout << "\nTime used = ";
    cout << 1000 * (double)clock() / CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}

void add_factorial(int num, int fun) {
    for(re int i = 2; i <= num; i++)
        add(i,fun);
}

void add(int num,int fun) {
    for(re int i = 1; i <= top; i++) {
        while(num % prime[i] == 0) {
            e[i] += fun;
            num /= prime[i];
        }
        if(num == 1) break;
    }
}