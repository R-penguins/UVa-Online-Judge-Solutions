/**
 * AOAPC II Example 6-5 Boxes in a Lines
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> L, R;
void link(int l, int r)
{
    R[l] = r;
    L[r] = l;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, T = 1;
    while (cin >> n >> m)
    {
        L.clear();
        R.clear();
        for (int i = 0; i <= n; ++i)
        {
            L.push_back(i - 1);
            R.push_back(i + 1);
        }
        L[0] = n;
        R[n] = 0;
        bool inv = false;
        while (m--)
        {
            int op;
            cin >> op;
            if (op == 4)
            {
                inv = !inv;
                continue;
            }
            int x, y;
            cin >> x >> y;
            if (op == 3 && R[y] == x)
                swap(x, y);
            int lx = L[x], rx = R[x], ly = L[y], ry = R[y];
            if (op == 3)
            {
                if (rx == y)
                {
                    link(lx, y);
                    link(y, x);
                    link(x, ry);
                }
                else
                {
                    link(lx, y);
                    link(y, rx);
                    link(ly, x);
                    link(x, ry);
                }
                continue;
            }
            if (inv)
                op = 3 - op;
            if (op == 1 && ly == x || op == 2 && ry == x)
                continue;
            link(lx, rx);
            if (op == 1)    
            {
                link(ly, x);
                link(x, y);
            }
            else
            {
                link(y, x);
                link(x, ry);
            }
        }
        long long ans = 0;
        for (int i = 1, cur = R[0]; i <= n; ++i, cur = R[cur])
            if (i % 2)
                ans += cur;
        if (inv && n % 2 == 0)
            ans = (long long) n * (n + 1) / 2 - ans;
        cout << "Case " << T++ << ": " << ans << "\n";
    }
}
