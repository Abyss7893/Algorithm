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

#define MAXN 1000000
#define MAXP 78500

bool vis[MAXN+10];
int p[MAXP+10], ip[MAXN+10], pcnt = 0, S;
vector<int> e[MAXP+10];
// 欧拉筛预处理出质数储存在 p 中，ip 为对应的下标， S 为 1000 以内质数的个数
void prime() {
    vis[1] = true;  ip[1] = p[++pcnt] = S = 1;
    for(re int i = 2; i <= MAXN; i++) {
        if(!vis[i]) {   // 找到质数
            p[++pcnt] = i;  ip[i] = pcnt;
            S += (i <= 999);
        }
        for(int j = 1; j <= pcnt && i * p[j] <= MAXN; j++) {
            vis[i * p[j]] = true;
            //if(i % p[j] == 0 && p[j] != 1) break;
        }
    }
}
int E = 1, to[MAXN];
void add(re int u,re int v) { // 加双向边
    e[u].emplace_back(++E); to[E] = v;   
    e[v].emplace_back(++E); to[E] = u;
}

void Add(re int num) {  // 把数转化为边
    re int dcnt = 0, div[4];
    for(re int j = 2; j <= pcnt && p[j] * p[j] <= num; j++) 
        if(num % p[j] == 0) {
            while(num%(p[j]*p[j]) == 0) num /= (p[j] * p[j]);
            if(num % p[j] == 0) div[++dcnt] = j, num /= p[j];
        }
    if(num > 1) div[++dcnt] = ip[num], num = 1;
    if(dcnt == 0) puts("1"), exit(0);
    else if(dcnt == 1) add(1, div[1]);
    else if(dcnt == 2) add(div[1], div[2]);
}

// 暴力 BFS
int size = inf, q[MAXP+10][2], deep[MAXP+10];
void BFS(re int s) {
    fill(deep + 1, deep + 1 + MAXP, inf);
    re int qcnt = 0;
    q[++qcnt][1] = s, deep[s] = 0;
    for(re int ft = 1; ft <= qcnt; ft++) {
        re int x = q[ft][1], fa = q[ft][0];
        for(int i : e[x])    if(i != (fa ^ 1)) {
            if(deep[to[i]] == inf) {
                deep[to[i]] = deep[x] + 1;
                q[++qcnt][1] = to[i];
                q[qcnt][0] = i;
            }
            else size = min(size, deep[x] + deep[to[i]] + 1);
        }
    }
}

int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    prime();
    int n = read<int>();
    FOR(i,0,n) Add(read<int>());
    for(int i = 1; i <= S; i++) BFS(i);
    if(size == inf) cout << "-1\n";
    else cout << size << endl;

#ifdef abyss
    cout << "\nTime used = ";
    cout << 1000 * (double)clock() / CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}
