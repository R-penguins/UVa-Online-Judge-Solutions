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

struct Edge
{
  int to, weight;
  Edge() {};
  Edge(int t, int w) : to(t), weight(w) {};
};

bool bellman_ford(vector<vector<Edge>>& adj, double test)
{
  int n = adj.size();
  vector<double> dist(n, 0);
  vector<bool> in_queue(n, true);
  vector<int> bit(n, 1);

  queue<int> q;
  for (int i = 0; i < n; ++i)
    q.push(i);
  while (!q.empty())
  {
    int cur = q.front();
    q.pop();
    in_queue[cur] = false;
    for (Edge& edge : adj[cur])
      if (dist[cur] + edge.weight - test < dist[edge.to])
      {
        dist[edge.to] = dist[cur] + edge.weight - test;
        if (!in_queue[edge.to])
        {
          if (++bit[edge.to] > n)
            return true;
          q.push(edge.to);
          in_queue[edge.to] = true;
        }
      }
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
  }
  return 0;
}
