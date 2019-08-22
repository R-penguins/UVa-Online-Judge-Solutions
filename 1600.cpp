/**
 * AOAPC II Exercise 6-5 Patrol Robot
 * ICPC Hanoi 2006
 * 60 AC;
 */
#include <bits/stdc++.h>
using namespace std;
struct Pt
{
    int x, y, dep = 0, cnt = 0;
    Pt(int x, int y) : x(x), y(y) { }
    Pt step(const Pt &dir)
    {
        Pt next(x + dir.x, y + dir.y);
        next.dep = dep + 1;
        return next;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const vector<Pt> DIRS {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    int kase;
    cin >> kase;
    while (kase--)
    {
        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<int>> obs(m, vector<int>(n));
        for (auto &row : obs)
            for (int &pos : row)
                cin >> pos;
        bool found = false;
        int ans = -1;
        queue<Pt> q;
        q.push({0, 0});
        while (!q.empty() && ans == -1)
        {
            Pt cur = q.front();
            q.pop();
            for (const Pt &dir : DIRS)
            {
                Pt next = cur.step(dir);
                if (0 <= next.x && next.x < m && 0 <= next.y && next.y < n)
                {
                    int &status = obs[next.x][next.y];
                    if (status == -1)
                        continue;
                    else if (status == 0)
                    {
                        status = -1;
                        next.cnt = 0;
                    }
                    else
                        next.cnt = cur.cnt + 1;
                    if (next.cnt > k)
                        continue;
                    if (next.x == m - 1 && next.y == n - 1)
                    {
                        ans = next.dep;
                        break;
                    }
                    q.push(next);
                }
            }
        }
        cout << ans << "\n";
    }
}
