/**
 * @file 1428.cpp
 * @author R-penguins
 * @brief Online Judge 1428 Ping Pong
 * @date 2021-04-04
 * 
 * Live Archive 4329
 * ICPC Beijing 2008
 * 
 * Solution with Binary Indexed Tree. O(n log n)
 */
#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VD = vector<double>;
using VVD = vector<VD>;
using VS = vector<string>;
using VVS = vector<VS>;
using VB = vector<bool>;
using VVB = vector<VB>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PDI = pair<double, int>;
constexpr double pi = 3.1415926535897932385;
constexpr double EPS = 1e-12;

struct Bit
{
  Bit(int size) : tree(size + 1) { }
  Bit(vector<int>& arr) : tree(arr)
  {
    for (int i = 1; i < tree.size(); ++i)
    {
      int p = i + (i & -i);
      if (p < tree.size())
        tree[p] += tree[i];
    }
  }
  int sum(int ind)
  {
    int ans = 0;
    while (ind)
    {
      ans += tree[ind];
      ind -= (ind & -ind);
    }
    return ans;
  }
  void add(int ind, int val)
  {
    while (ind < tree.size())
    {
      tree[ind] += val;
      ind += (ind & -ind);
    }
  }
  vector<int> tree;
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--)
  {
    int N;
    cin >> N;
    VI a(N + 1);
    for (int i = 1; i < N + 1; ++i)
      cin >> a[i];
    vector<PII> a_index(N);
    for (int i = 1; i < N + 1; ++i)
      a_index[i - 1] = {a[i], i};
    sort(a_index.rbegin(), a_index.rend());
    Bit bit(N);
    long long ans = 0;
    int tot = 0;
    for (PII& p : a_index)
    {
      int ind = p.second;
      long long left_greater = bit.sum(ind - 1);
      long long right_greater = tot - left_greater;
      ans += (ind - 1 - left_greater) * right_greater;
      ans += left_greater * ((N - ind) - right_greater);
      bit.add(ind, 1);
      ++tot;
    }
    cout << ans << "\n";
  }
  return 0;
}
