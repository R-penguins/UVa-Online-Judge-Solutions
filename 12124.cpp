/**
 * Assemble
 * 2007 NWERC
 * LA 3971
 */
#include <bits/stdc++.h>
using namespace std;
struct Comp
{
    int p, q;
    Comp(int p, int q) : p(p), q(q) { }
};
map<string, vector<Comp>> types;
int b;
bool ok(int q)
{
    int s = 0;
    for (const auto &type : types)
    {
        int minP = 2e6;
        for (auto &comp : type.second)
            if (comp.q >= q)
                minP = min(minP, comp.p);
        if (minP == 2e6 || (s += minP) > b)
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >>t;
    while (t--)
    {
        int n;
        cin >> n >> b;
        types.clear();
        // vector<int> qs;
        int maxQ = 0;
        while (n--)
        {
            string type, name;
            int p, q;
            cin >> type >> name >> p >> q;
            types[type].push_back({p, q});
            // qs.push_back(q);
            maxQ = max(maxQ, q);
        }
        // sort(qs.begin(), qs.end());
        // qs.erase(unique(qs.begin(), qs.end()), qs.end());
        // int l = 0, r = qs.size() - 1;
        int l = 0, r = maxQ;
        while (l < r)
        {
            int m = l + (r - l + 1) / 2; // ?? (l + r) / 2
            // if (ok(qs[m]))
            if (ok(m))
                l = m;
            else
                r = m - 1;
        }
        // cout << qs[l] << "\n";
        cout << l << "\n";
    }
}
