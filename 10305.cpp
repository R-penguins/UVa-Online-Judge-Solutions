/**
 * AOAPC II Example 6-15 Ordering Tasks
 */
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> vis;
vector<int> ans;
void topo(int i)
{
    vis[i] = true;
    for (int j : graph[i])
        if (!vis[j])
            topo(j);
    ans.push_back(i); // in reverse order
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while ((cin >> n >> m) && n)
    {
        graph = vector<vector<int>>(n + 1);
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b); // may be duplicates
        }
        vis = vector<bool>(n + 1, false);
        ans.clear();
        for (int i = 1; i <= n; ++i)
            if (!vis[i])
                topo(i);
        cout << ans.back();
        for_each(ans.rbegin() + 1, ans.rend(), [](int i){ cout << " " << i; });
        cout << "\n";
    }
}
