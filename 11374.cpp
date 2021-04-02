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
  int from, to, weight;
  Edge() {};
  Edge(int t, int w) : to(t), weight(w) {};
};

void dijkstra(vector<vector<Edge>>& adj, int s, vector<double>& dist, vector<int>& p)
{
  dist = vector<double>(adj.size(), INFINITY); // use INFINITY in double if dist might be added
  dist[s] = 0;
  p = vector<int>(adj.size());
  priority_queue<PII, vector<PII>, greater<PII>> q; // weight, vertex
  q.emplace(0, s);
  while (!q.empty())
  {
    PII cur = q.top();
    q.pop();
    if (dist[cur.second] != cur.first)
      continue;
    for (Edge& edge : adj[cur.second])
      if (cur.first + edge.weight < dist[edge.to])
      {
        dist[edge.to] = cur.first + edge.weight;
        p[edge.to] = cur.second;
        q.emplace(dist[edge.to], edge.to);
      }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool first = true;
  int N, S, E;
  while (cin >> N >> S >> E)
  {
    if (first)
      first = false;
    else
      cout << '\n';

    vector<vector<Edge>> adj(N + 1);
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
      int X, Y, Z;
      cin >> X >> Y >> Z;
      adj[X].emplace_back(Y, Z);
      adj[Y].emplace_back(X, Z);
    }
    int K;
    cin >> K;
    vector<Edge> commercial(K);
    for (Edge& edge : commercial)
      cin >> edge.from >> edge.to >> edge.weight;

    vector<double> dist_from_s;
    vector<int> p_from_s;
    dijkstra(adj, S, dist_from_s, p_from_s);
    vector<double> dist_from_e;
    vector<int> p_from_e;
    dijkstra(adj, E, dist_from_e, p_from_e);

    double min_dist = dist_from_s[E];
    Edge min_edge(-1, -1);
    for (Edge& edge : commercial)
    {
      double cur_dist = dist_from_s[edge.from] + edge.weight + dist_from_e[edge.to];
      if (cur_dist < min_dist)
      {
        min_dist = cur_dist;
        min_edge.from = edge.from;
        min_edge.to = edge.to;
      }
      swap(edge.from, edge.to);
      cur_dist = dist_from_s[edge.from] + edge.weight + dist_from_e[edge.to];
      if (cur_dist < min_dist)
      {
        min_dist = cur_dist;
        min_edge.from = edge.from;
        min_edge.to = edge.to;
      }
    }

    if (min_dist == dist_from_s[E])
    {
      int cur = S;
      while (cur != E)
      {
        cout << cur << ' ';
        cur = p_from_e[cur];
      }
      cout << E << '\n'
        << "Ticket Not Used\n"
        << dist_from_s[E] << '\n';
    }
    else
    {
      deque<int> path {min_edge.from};
      while (path.front() != S)
        path.push_front(p_from_s[path.front()]);
      for (int i : path)
        cout << i << ' ';
      int cur = min_edge.to;
      while (cur != E)
      {
        cout << cur << ' ';
        cur = p_from_e[cur];
      }
      cout << E << '\n'
        << min_edge.from << '\n'
        << min_dist << '\n';
    }
  }
  return 0;
}
