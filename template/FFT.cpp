#include<bits/stdc++.h>
using namespace std;

//#define abyss
typedef unsigned int UI;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#define re register
#define pi acos(-1)
#define ln(i)  ((i<<1))
#define rn(i)  (((i<<1|1)))
#define PII pair<int,int>
#define MK(a,b) make_pair(a,b) 
#define PLL pair<long long, long long>
#define FOR(i,begin,end)   for(register int i = begin; i < end; ++i)
#define rFOR(i,begin,end)   for(register int i = begin; i > end; --i)
#define clr(x,y)  memset(x,y,sizeof(x))

typedef struct cp{
    double real,imag;
    cp(double a = 0.0, double b = 0.0) {real = a; imag = b;}
    cp operator + (const cp &p) { return cp(real + p.real, imag + p.imag);}
    cp operator - (const cp &p) { return cp(real - p.real, imag - p.imag);}
    cp operator * (const cp &p) {
        return cp(real * p.real - imag * p.imag, real * p.imag + imag * p.real);    
    }
    void operator *= (const cp &p) {
        double tmp = real;
        real = real * p.real - imag * p.imag;
        imag = tmp * p.imag + imag * p.real;
    }
    cp operator / (const double p) {return cp(real / p, imag / p);}
    void print() {cout << "real = " << real << " , imag = " << imag << endl;}
}cp;

void FFT(cp *a,int n,int inv);
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
#define MAXN 4000006
cp F[MAXN],G[MAXN];
char s1[MAXN],s2[MAXN];
int rev[MAXN],res[MAXN];

int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    /*
    scanf("%s",s1); scanf("%s",s2);
    int len1 = strlen(s1), len2 = strlen(s2);
    FOR(i,0,len1) F[i].real = s1[len1 - 1 - i] - '0';
    FOR(i,0,len2) G[i].real = s2[len2 - 1 - i] - '0';
    int limits = 1;
    while(limits <= len1 + len2) limits <<= 1;
    FFT(F,limits,1);    FFT(G,limits,1);
    FOR(i,0,limits) F[i] = F[i] * G[i];
    FFT(F,limits,-1);
    FOR(i,0,len1 + len2) {
        res[i] += (int)( F[i].real / limits + 0.5);
        if(res[i] >= 10) {
            res[i + 1] += res[i] / 10;
            res[i] %= 10;
        }
    }
    while(res[limits] == 0 && limits >= 0) limits--;
    rFOR(i,limits, -1) cout << res[i];  cout << "\n";
    */
   
    return 0;
}

void FFT(cp *a,int n,int inv) {
    int bit = 0;
    while ((1<<bit) < n) bit++;
    FOR(i,0,n) {
        rev[i]=(rev[i>>1] >> 1) | ((i&1) << (bit-1));
        if (i < rev[i]) swap(a[i], a[rev[i]]); //不加这条if会交换两次（就是没交换）
    }
    for (re int mid = 1; mid < n;mid *= 2) {  //mid是准备合并序列的长度的二分之一 
    	cp temp(cos(pi / mid), inv * sin(pi/mid) ); //单位根，pi的系数2已经约掉了
        for (re int i = 0;i < n; i += mid * 2) {  //mid*2是准备合并序列的长度，i是合并到了哪一位
            cp omega(1,0);
            for (re int j = 0; j < mid; j++, omega *= temp) {//只扫左半部分，得到右半部分的答案
                cp x = a[i + j], y = omega * a[i + j + mid];
                a[i + j] = x + y, a[i + j + mid] = x - y;//这个就是蝴蝶变换什么的
            }
        }
    }
}