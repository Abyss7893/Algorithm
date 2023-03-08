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

void ex_gcd(LL a,LL b, LL &gcd, LL &x, LL &y) {
    if(b == 0) {gcd = a; x = 1; y = 0;}
    else {
        ex_gcd(b, a%b, gcd, y, x);
        y -= x * (a / b);
    }
}

#define MAXN 105
#define MOD 10001

int num[MAXN * 2];
int B[MAXN];
int add(LL num, LL GCD);
int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int tt = read<int>();
    for(int i = 1; i <= tt * 2; i+=2) num[i] = read<int>();

    for(LL a = 0; a < MOD; a++) {
        LL c = num[3] - a * a * num[1], x, y, GCD;
        ex_gcd(a+1, MOD, GCD, x, y);
        if(c % GCD) continue;
        x = x * (c / GCD);
        int top = add(x,GCD);

        //cout << "a = " << a << ", x = " << x << endl;
        for(int j = 1; j <= top; j++) {
            int b = B[j];
            bool ok = true;
            for(int i = 2; i <= tt * 2; i += 2) {
                num[i] = (num[i-1] * a + b) % MOD;
                if(i != 2 * tt && (num[i]*a+b) % MOD != num[i+1] ) {
                    ok = false;
                    break;
                } 
            }
            if(ok) {
                //cout << "a = " << a << ", b = " << b << endl;
                for(int i = 2; i <= 2 * tt; i += 2)
                    cout << num[i] << endl;
                return 0;
            }
        }
    }

#ifdef abyss
    cout << "\nTime used = ";
    cout << 1000 * (double)clock() / CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}

int add(LL num, LL GCD) {
    LL part = MOD / GCD;
    if(num < 0) num -= (num / part) * part;
    else  num -= (num / part + 1) * part;
    int top = 0;
    while(num < MOD) {
        if(num >= 0) B[++top] = num;
        num += part;
    }
    return top;
}