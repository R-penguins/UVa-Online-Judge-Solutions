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

vector<vector<Edge>> adj;
vector<double> dist;

void dijkstra(int s, int t)
{
  dist = vector<double>(adj.size(), INFINITY); // use INFINITY in double if dist might be added
  dist[s] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> q; // weight, vertex
  q.emplace(0, s);
  while (!q.empty())
  {
    PII cur = q.top();
    q.pop();
    if (cur.second == t)
      break;
    if (dist[cur.second] != cur.first)
      continue;
    for (Edge& edge : adj[cur.second])
      if (cur.first + edge.weight < dist[edge.to])
      {
        dist[edge.to] = cur.first + edge.weight;
        q.emplace(dist[edge.to], edge.to);
      }
  }
}

vector<int> path_num;
int num(int u)
{
  if (u == 1)
    return 1;
  if (path_num[u])
    return path_num[u];
  for (Edge& edge : adj[u])
    if (dist[edge.to] < dist[u])
      path_num[u] += num(edge.to);
  return path_num[u];
}

bool bellman_ford(vector<vector<double>>& w, int s, vector<double>& dist, vector<int>& p)
{
  dist = vector<double>(w.size(), INFINITY); // use INFINITY in double if dist might be added
  dist[s] = 0;
  p = vector<int>(w.size());
  vector<bool> in_queue(w.size());
  vector<int> cnt(w.size());

  queue<int> q;
  q.push(s);
  while (!q.empty())
  {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < w.size(); ++i)
      if (w[cur][i] != NAN && dist[cur] + w[cur][i] < dist[i])
      {
        dist[i] = dist[cur] + w[cur][i];
        p[i] = cur;
      }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  for (int x = 1; x <= N; ++x)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> adj(n);
  }
  return 0;
}
