/**
 * AOAPC II Example 6-20 Ideal Path
 * ICPC NEERC 2010
 */
#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int u, c;
    Edge(int u, int c) : u(u), c(c) { }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m)
    {
        vector<vector<shared_ptr<Edge>>> g(n + 1);
        while (m--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back(make_shared<Edge>(b, c));
            g[b].push_back(make_shared<Edge>(a, c));
        }
        vector<int> deg(n + 1, -1);
        deg[n] = 0;
        queue<int> q;
        q.push(n);
        int max_deg = numeric_limits<int>::max();
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (deg[cur] >= max_deg)
                break;
            for (auto edge : g[cur])
                if (deg[edge->u] < 0)
                {
                    deg[edge->u] = deg[cur] + 1;
                    if (edge->u == 1)
                        max_deg = deg[edge->u];
                    q.push(edge->u);
                }
        }
        vector<int> ans;
        vector<int> cur_lv {1};
        for (int lv = max_deg; lv > 0; --lv)
        {
            int min_c = numeric_limits<int>::max();
            for (int cur : cur_lv)
                for (auto edge : g[cur])
                    if (deg[edge->u] == lv - 1)
                        min_c = min(min_c, edge->c);
            ans.push_back(min_c);
            vector<int> next_lv;                        
            for (int cur : cur_lv)
                for (auto edge : g[cur])
                    if (deg[edge->u] == lv - 1 && edge->c == min_c)
                    {
                        next_lv.push_back(edge->u);
                        deg[edge->u] = -1;
                    }
            cur_lv = next_lv;
        }
        cout << max_deg << "\n";
        for_each(ans.begin(), ans.end() - 1, [](int i){ cout << i << " "; });
        cout << ans.back() << "\n";
    }
}
