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

int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int t = read<int>();
    while(t--) {
        int d = read<int>();
        int delta = d * d - 4 * d;
        if(delta < 0) puts("N");
        else {
            double x1 = (d + sqrt(double(delta))) / 2.0;
            double x2 = (d - sqrt(double(delta))) / 2.0;
            if(x1 >= 0 && x2 >= 0)  printf("Y %.9lf %.9lf\n",x1,x2);
            else puts("N");
        }
    }
    return 0;
}

/*
Y 67.98507130 1.01492870
Y 0.00000000 0.00000000
N
Y 2.00000000 2.00000000
Y 3.61803399 1.38196601
Y 997.99899699 1.00100301
Y 998.99899799 1.00100201
*/