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
#define MAXN 5005
char str[MAXN];
int dp[MAXN][3];
int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    scanf("%s",str);
    vector<pair<int,char>> nums;
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        char ch = str[i];   int LEN = 1;
        while(i + 1 < len && ch == str[i+1]) i++,LEN++;
        nums.push_back(MK(LEN,str[i]));
    }
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        if(nums[i].second == 'a') {
            dp[i+1][0] = dp[i][0] + nums[i].first;
            dp[i+1][1] = dp[i][1];
            dp[i+1][2] = max(max(dp[i][0], dp[i][1]), dp[i][2]) + nums[i].first;
        }
        else {
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = max(dp[i][0], dp[i][1]) + nums[i].first;
            dp[i+1][2] = dp[i][2];
        }
    }
    int ans = max(dp[size][0], dp[size][1]);
    cout << max(ans, dp[size][2]) << endl;
    return 0;
}
