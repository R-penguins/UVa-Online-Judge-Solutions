/**
 * AOAPC II Example 6-19 Self-Assembly
 * ICPC WF 2013
 */
#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> g;
vector<int> vis;
bool dfs(int i)
{
    vis[i] = -1;
    for (int j = 0; j < 52; ++j)
        if (g[i][j] && (vis[j] == -1 || !vis[j] && dfs(j)))
            return true;
    vis[i] = 1;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n)
    {
        g = vector<vector<bool>>(52, vector<bool>(52, false));
        while (n--)
        {
            string mol;
            cin >> mol;
            for (int i = 0; i < 8; i += 2)
            {
                if (mol[i] == '0')
                    continue;
                int posInv = (mol[i] - 'A') * 2 + (mol[i + 1] == '+' ? 0 : 1);
                for (int j = 0; j < 8; j += 2)
                {
                    if (mol[j] == '0' || i == j)
                        continue;
                    int posJ = (mol[j] - 'A') * 2 + (mol[j + 1] == '+' ? 1 : 0);
                    g[posInv][posJ] = true;
                }
            }
        }
        bool cycle = false;
        vis = vector<int>(52, 0);
        for (int i = 0; i < 52; ++i)
            if (!vis[i] && dfs(i))
            {
                cycle = true;
                break;
            }
        cout << (cycle ? "unbounded" : "bounded") << "\n";
    }
}
