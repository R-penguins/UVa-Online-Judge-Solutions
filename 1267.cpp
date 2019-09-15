/**
 * Network
 * 2007 Seoul
 * LA 3902
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> p;
vector<vector<int>> dep, adj;
vector<bool> cov;
int k;
void calc(int cur, int pa, int d)
{
    p[cur] = pa;
    if (adj[cur].size() == 1)
        dep[d].push_back(cur);
    ++d;
    for (int u : adj[cur])
        if (u != pa)
            calc(u, cur, d);
}
void cover(int ser, int pa, int d)
{
    cov[ser] = true;
    if (++d > k)
        return;
    for (int u : adj[ser])
        if (u != pa)
            cover(u, ser, d);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s >> k;
        adj = vector<vector<int>>(n + 1);
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        p = vector<int>(n + 1);
        dep = vector<vector<int>>(n + 1);
        cov = vector<bool>(n + 1, false);
        calc(s, -1, 0);
        int ans = 0;
        for (int d = n - 1; d > k; --d)
            for (int u : dep[d])
                if (!cov[u])
                {
                    ++ans;
                    int ser = u;
                    for (int i = 0; i < k; ++i)
                        ser = p[ser];
                    cover(ser, -1, 0);
                }
        cout << ans << "\n";
    }
}
