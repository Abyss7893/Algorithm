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
int st[40];
char str[200];

/*
也算是一道模拟题。可以如紫书所说类比于选择排序的思路。
实际上，我们考虑将问题分解，因为要想使得每一个饼都符合要求，那么一定要先满足大的饼在下面合适
才可能实现上面饼的排列，因此就可以转化为子问题：找到当前最大的饼然后放在最下面。如何找？遍历即可。
如何放？因为其一变就是整个部分全部变，因此要想变到最下面只有两种情况：要么本来在下面，要么只能从
开头变到最下面。因此调整一个饼的步骤即为：先放在第一个，再调整到最下面。然后循环调整直至全部满足要求即可。

这个题值得借鉴的地方还是有的，下次遇到题目能否想到拆分为一个一个子问题的求解，每个子问题如何分析都很有趣。
*/


inline bool check(int top);
inline int askFine(int top);
inline void reverse(int begin, int end);
inline int askMax(int begin, int top);
int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    while(gets(str) != NULL) {
        int len = strlen(str), top = 0, pos = 0;
        while(pos < len) {
            if(isdigit(str[pos])) {
                st[++top] = str[pos++] - '0';
                while(pos < len && isdigit(str[pos])) st[top] = st[top] * 10 + str[pos++] - '0';
            }
            pos++;
        }
        FOR(i,1,top) cout << st[i] << " "; cout << st[top] << "\n";
        reverse(1,top);
        vector<int> ans;
        while(!check(top)) {
            int sorted = askFine(top);
            pos = askMax(sorted, top);
            if(pos != top) {reverse(pos,top); ans.emplace_back(pos);}
            reverse(sorted, top); ans.emplace_back(sorted);
        }
        ans.emplace_back(0);
        for(int i = 0; i < ans.size() - 1; i++) cout << ans[i] << " "; 
        cout << *ans.rbegin() << "\n";
    }
    return 0;
}

inline void reverse(int begin, int end) {
    for(int i = 0; begin + i < end - i; i++) {
        int p = st[end - i];
        st[end - i] = st[begin + i];
        st[begin + i] = p;
    }
}

inline bool check(int top) {
    FOR(i,2,top+1) {if(st[i] > st[i-1]) return false;}
    return true;
}

inline int askMax(int begin, int top) {
    int pos = begin, res = st[begin];
    FOR(i,begin,top+1) if(res < st[i]) {pos = i; res = st[i];}
    return pos;
}

inline int askFine(int top) {
    int ans = 1;
    FOR(i,1,top+1) {
        int temp = st[i];
        FOR(j,i+1,top+1) if(st[j] > temp) return ans;
        ans++;
    }
    return ans;
}