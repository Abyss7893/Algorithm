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
#define MAXN 1005
char ss[MAXN][MAXN];
bool valid(char *temp, int n);
int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n, m;
    scanf("%d %d\n",&n, &m);
    FOR(i,1,n+1) scanf("%s",ss[i]+1);
    int positive = 1, negative = 0;
    for(int i = 2; i <= n; i++) {
        if(strcmp(ss[1]+1, ss[i]+1) == 0) {
            positive ++;
            continue;
        }
        bool flag = true;
        for(int j = 1; j <= m; j++) if(ss[1][j] == ss[i][j]) {
            flag = false;
            break;
        }
        if(flag) negative++;
        else {
            cout << "-1\n";
            return 0;
        }
    }
    int B = 0, W = 0; 
    for(int i = 1; i <= m; i++)
        if(ss[1][i] == 'B') B++;
        else W++;
    int color = min(B, W), side = min(positive, negative);
    cout << color + side << endl;

#ifdef abyss
    cout << "\nTime used = ";
    cout << 1000 * (double)clock() / CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}
