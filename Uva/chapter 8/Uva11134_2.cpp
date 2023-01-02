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
/*
根据韩老师的意见写出的第二版。之前那一个是按照区间来考虑，考虑每个区间能放的位置。这个是从点(位置)来考虑
考虑包括这个位置的所有区间，在这些区间里选择右端点最小的即可
当然还是用遍历寻找，还可以进一步优化
*/
#define MAXN 5005
typedef struct node{
    int l, r, idx;
    bool valid;
    bool operator < (const struct node sh) {
        if(r != sh.r) return r < sh.r;
        return l < sh.l;
    }
}node;
node x[MAXN], y[MAXN];
int ans[MAXN][2];

bool cal(node *arr, int n, int pos);
int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n;
    while(scanf("%d",&n) && n) {
        FOR(i,1,n+1) {
            x[i].l = read<int>();    y[i].l = read<int>();  x[i].idx = i;   x[i].valid = false;
            x[i].r = read<int>();    y[i].r = read<int>();  y[i].idx = i;   y[i].valid = false;
        }
        sort(x + 1, x + 1 + n); sort(y + 1, y + 1 + n);
        bool flag = cal(x,n,0);
        if(flag) flag = cal(y,n,1);
        if(flag) FOR(i,1,n+1)   cout << ans[i][0] << " " << ans[i][1] << "\n";
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}

bool cal(node *arr, int n, int pos) {
    bool flag = true;
    FOR(i,1,n+1) {
        register bool temp = true;
        FOR(j,1,n+1) {
            if(!arr[j].valid && arr[j].l <= i && arr[j].r >= i) {
                arr[j].valid = true;  ans[arr[j].idx][pos] = i;   
                temp = false;    break;
            }
        }
        if(temp) {flag = false; break;}
    }
    return flag;
}
