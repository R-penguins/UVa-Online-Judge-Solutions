/**
 * Commando War
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, T = 0;
    while ((cin >> n) && n)
    {
        vector<pair<int, int>> jbs(n);
        for (auto &jb : jbs)
            cin >> jb.second >> jb.first;
        sort(jbs.rbegin(), jbs.rend());
        int b = 0, ans = 0;
        for (auto jb : jbs)
        {
            b += jb.second;
            ans = max(ans, b + jb.first);
        }
        cout << "Case " << ++T << ": " << ans << "\n";
    }
}
