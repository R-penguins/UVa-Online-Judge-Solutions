/**
 * AOAPC II Exercise 6-6 Equilibrium Mobile
 * ICPC NWERC 2008
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        string line;
        cin >> line;
        int dep = 0, cnt = 0;
        long long cur = 0;
        map<long long, int> tot_weights;
        for (char c : line)
            switch (c)
            {
            case '[':
                ++dep;
                break;
            case ']':
                if (cur)
                {
                    ++tot_weights[cur << dep];
                    ++cnt;
                    cur = 0;
                }
                --dep;
                break;
            case ',':
                if (cur)
                {
                    ++tot_weights[cur << dep];
                    ++cnt;
                    cur = 0;
                }
                break;
            default:
                cur = cur * 10 + c - '0';
            }
        if (cur)
            cout << "0\n";
        else
        {
            int ans = -1;
            for (auto &w : tot_weights)
                ans = max(ans, w.second);
            cout << cnt - ans << "\n";
        }
    }
}
