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
const LL MAXN = 1e18 + 5LL;
LL num[105];
LL bias[105];

void init();
int getL(LL X);
void print(LL X);
int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    init();
    int Q = read<int>();
    while(Q--) {
        int Case = read<int>(), pos = 0;
        LL real = 0, X = 0, K = 0;
        switch(Case) {
            case 1: X = read<LL>(), K = read<LL>();
                    pos = getL(X); real = abs(K) % num[pos];
                    real = real * 2 % num[pos+1];
                    bias[pos+1] += real * (K < 0 ? 1 : -1);
                    break;
            case 2: X = read<LL>(), K = read<LL>(); 
                    pos = getL(X); real = abs(K) % num[pos];
                    bias[pos] += real * (K < 0 ? -1 : 1);
                    break;
            case 3: X = read<LL>();  
            print(X);   cout << "\n";
                    break;
        }
    }
    return 0;
}
void init() {
    int pos = 0;    num[0] = 1;
    while(num[pos] < MAXN) {
        pos++;
        num[pos] = num[pos-1] * 2LL;
    }
}

int getL(LL X) {
    int ans = 0;
    while(num[ans] <= X) ans++;
    return ans;
}

void print(LL X) {
    cout << X << " ";
    if(X == 1) return;
    int F = getL(X);
    X = (X + bias[F] + num[F-1]) % num[F-1] + num[F-1];
    print(X >> 1);
}