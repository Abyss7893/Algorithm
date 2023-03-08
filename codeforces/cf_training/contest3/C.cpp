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
struct node{
    int x,y;
    int d[4];
    void read() {scanf("%d%d",&x,&y);   FOR(i,0,4) scanf("%d",&d[i]);}
}node[MAXN];
int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int Q = read<int>();
    while(Q--) {
        int n = read<int>();
        FOR(i,1,n+1)    node[i].read();
        int xL = -MAXN + 5, xR = MAXN - 5, yL = -MAXN + 5, yR = MAXN - 5;
        FOR(i,1,n+1) {
            if(!node[i].d[0]) xL = max(xL, node[i].x);
            if(!node[i].d[1]) yR = min(yR, node[i].y);
            if(!node[i].d[2]) xR = min(xR, node[i].x);
            if(!node[i].d[3]) yL = max(yL, node[i].y);
        }
        if(xL <= xR && yL <= yR) cout << "1 " << xL << " " << yL << "\n";
        else cout << "0\n";
    }
    return 0;
}
