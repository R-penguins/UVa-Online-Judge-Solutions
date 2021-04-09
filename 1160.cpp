/**
 * @file 1160.cpp
 * @author R-penguins
 * @brief Online Judge 1160 X-Plosives
 * @date 2021-04-06
 * 
 * Live Archive 3644
 * ICPC SWERC 2006
 * 
 * Disjoint-set
 */
#include <bits/stdc++.h>
using namespace std;

struct Uf {
  Uf(int n) : p(n), size(n, 1) {
    iota(p.begin(), p.end(), 0);
  }
  int find(int x) {
    if (x != p[x])
      p[x] = find(p[x]);
    return p[x];
  }
  int merge(int x, int y) {
    int xp = find(x), yp = find(y);
    if (xp == yp)
      return;
    if (size[xp] > size[yp])
      swap(xp, yp);
    p[xp] = yp;
    size[yp] += xp;
  }
  vector<int> p, size;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Uf uf(100001);
  int a, b;
  while (cin >> a) {
    iota(uf.p.begin(), uf.p.end(), 0);
    int refusal = 0;
    while (a != -1) {
      cin >> b;
      int pa = uf.find(a), pb = uf.find(b);
      if (pa == pb)
        ++refusal;
      else
        uf.p[pa] = pb;
      cin >> a;
    }
    cout << refusal << '\n';
  }
  return 0;
}
