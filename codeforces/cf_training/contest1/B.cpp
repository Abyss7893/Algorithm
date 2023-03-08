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

    int n = read<int>();
    if(n & 1) {
        int res = n >> 1;
        if(res & 1) {
            cout << "0\n";
            cout << res << " " << res + 2 << " ";
            for(int i = 3; i < res + 2; i += 2) cout << i << " " << n - i + 2 << " "; cout << "\n";
        }
        else {
            cout << 1 << "\n";
            cout << (n >> 1) + 1 << " " << 1 << " ";
            for(int i = 2; i <= res; i += 2) cout << i << " " << n - i + 2 << " ";    cout << "\n";
        }
    }
    else if(n == 2) cout << "1\n1 1\n";
    else {
        int res = n >> 1;
        if(res & 1) {
            cout << 1 << "\n";
            cout << res << " " << res << " ";
            for(int i = 1; i < res; i += 2) cout << i << " " << n - i + 1 << " "; cout << "\n";
        }
        else {
            cout << 0 << "\n";
            cout << res << " ";
            for(int i = 1; i <= res; i += 2) cout << i << " " << n - i + 1 << " "; cout << "\n";
        }
    }
    return 0;
}
