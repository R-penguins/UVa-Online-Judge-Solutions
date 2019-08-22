/**
 * AOAPC II Exercise 6-8 Spatial Structures
 * ICPC WF 1998
 * 83 AC;
 */
#include <bits/stdc++.h>
using namespace std;
vector<string> g;
set<int> ans;
void trans(int r, int c, int len, int path, int dep)
{
    bool black = true;
    for (int rr = r; black && rr < r + len; ++rr)
        for (int cc = c; cc < c + len; ++cc)
            if (g[rr][cc] != '1')
            {
                black = false;
                break;
            }
    if (black)
        ans.insert(path);
    else if (len > 1)
    {
        int new_len = len / 2, new_dep = dep + 1;
        trans(r, c, new_len, path + 1 * pow(5, dep), new_dep);
        trans(r, c + new_len, new_len, path + 2 * pow(5, dep), new_dep);
        trans(r + new_len, c, new_len, path + 3 * pow(5, dep), new_dep);
        trans(r + new_len, c + new_len, new_len, path + 4 * pow(5, dep), new_dep);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, kase = 0;
    while (cin >> n && n)
    {
        if (kase)
            cout << "\n";
        cout << "Image " << ++kase << "\n";
        if (n > 0)
        {
            g = vector<string>(n);
            for (string &row : g)
                cin >> row;
            ans.clear();
            trans(0, 0, n, 0, 0);
            int cnt = 0;
            for (int i : ans)
            {
                if (cnt && cnt % 12 == 0)
                    cout << "\n";
                else if (cnt)
                    cout << " ";
                cout << i;
                ++cnt;
            }
            if (cnt)
                cout << "\n";
            cout << "Total number of black nodes = " << cnt << "\n";
        }
        else
        {
            n = -1 * n;
            int node;
            g = vector<string>(n, string(n, '.'));
            while (cin >> node && node != -1)
            {
                int len = n, r = 0, c = 0, dir;
                while (dir = node % 5)
                {
                    len /= 2;
                    if (dir == 2 || dir == 4)
                        c += len;
                    if (dir == 3 || dir == 4)
                        r += len;
                    node = (node - dir) / 5;
                }
                for (int rr = r; rr < r + len; ++rr)
                    for (int cc = c; cc < c + len; ++cc)
                        g[rr][cc] = '*';
            }
            for (string &row : g)
                cout << row << "\n";
        }
    }
}
