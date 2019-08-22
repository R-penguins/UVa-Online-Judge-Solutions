/**
 * AOAPC II Example 6-12 Oil Deposits
 */
#include <bits/stdc++.h>
using namespace std;
vector<string> grid;
int m, n, cnt;
void dfs(int r, int c)
{
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;
    if (grid[r][c] != '@')
        return;
    grid[r][c] = '-';
    for (int dr = -1; dr <= 1; ++dr)
        for (int dc = -1; dc <= 1; ++dc)
            if (dr || dc)
                dfs(r + dr, c + dc);
}
int main()
{
    while ((cin >> m >> n) && m)
    {
        grid = vector<string>(m);
        for (string &line : grid)
            cin >> line;
        cnt = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '@')
                {
                    ++cnt;
                    dfs(i, j);
                }
        cout << cnt << "\n";
    }
}
