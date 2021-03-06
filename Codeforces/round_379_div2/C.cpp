#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))  // Leading zeros
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#ifdef QWERTIER
#define err(x) cerr << #x << " : " << x << endl
#else
#define err(x)
#endif

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 200010
int a[N], b[N], c[N], d[N];
#define se second
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, m, k;
  LL x;
  int s;
  scanf("%d%d%d", &n, &m, &k);
  scanf("%I64d%d", &x, &s);
  FOR (i, m) {
    scanf("%d", &a[i]);
  }
  FOR (i, m) {
    scanf("%d", &b[i]);
  }
  a[++m] = x;
  b[m] = 0;
  FOR (i, k) {
    scanf("%d", &c[i]);
  }
  FOR (i, k) {
    scanf("%d", &d[i]);
  }
  LL ans = x * n;
  FOR (i, m) {
    if (b[i] > s)
      continue;
    int rem = s - b[i];
    auto it = upper_bound(d, d+k+1, rem) - d;
    --it;
    int maxC = c[it];
    //printf("%d %d\n", a[i], maxC);
    ans = min(ans, a[i] * LL(n - maxC));
  }
  printf("%I64d\n", ans);
  return 0;
}
