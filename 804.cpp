/**
 * AOAPC II Exercise 6-7 Petri Net Simulation
 * ICPC WF 1998
 * 53 CE; 55 AC;
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int np, T = 1;
    while (cin >> np && np)
    {
        vector<int> nps(np);
        for (int &i : nps)
            cin >> i;
        int nt;
        cin >> nt;
        vector<vector<int>> outs(nt);
        vector<map<int, int>> ins(nt);
        for (int i = 0; i < nt; ++i)
        {
            int cur;
            while (cin >> cur && cur)
                if (cur < 0)
                    ++ins[i][-1 * cur - 1];
                else
                    outs[i].push_back(cur - 1);
        }
        int nf;
        cin >> nf;
        bool live = true;
        int cnt = 0;
        while (live && ++cnt <= nf)
        {
            live = false;
            for (int t = 0; t < nt; ++t)
                if (all_of(ins[t].begin(), ins[t].end(), [&](map<int, int>::value_type i){ return nps[i.first] >= i.second; }))
                {
                    for (auto &i : ins[t])
                        nps[i.first] -= i.second;
                    for (int i : outs[t])
                        nps[i] += 1;
                    live = true;
                    break;
                }
        }
        cout << "Case " << T++ << ": " << (live ? "still live" : "dead") << " after " << cnt - 1 << " transitions\n"
             << "Places with tokens:";
        for (int i = 0; i < np; ++i)
            if (nps[i])
                cout << " " << i + 1 << " (" << nps[i] << ")";
        cout << "\n\n";
    }
}
