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
const int N = 100010, M = 1000010;
int n, m;
int nex[N];
char s[M], p[N];  // p 是匹配串，s 是被匹配串

int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> s + 1 >> p + 1;
    n = strlen(p + 1);
    m = strlen(s + 1);
    for (int i = 2, j = 0; i <= n; i ++ ) {
        while (j && p[i] != p[j + 1]) j = nex[j];
        if (p[i] == p[j + 1]) j ++ ;
        nex[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i ++ ) {
        while (j && s[i] != p[j + 1]) j = nex[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == n)
        {
            printf("%d\n", i - n + 1);
            j = nex[j];
        } 
    }
    for(int i = 1; i <= n;i++) cout << nex[i] << " ";
    //system("pause");
    return 0;
}