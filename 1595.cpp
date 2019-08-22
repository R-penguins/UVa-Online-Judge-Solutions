/**
 * AOAPC II Exercise 5-6 Symmetry
 * ICPC Seoul 2004
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        set<pair<double, int>> pts;
        double sum = 0;
        for (int i = 0; i < n; ++i)
        {
            int x, y;
            cin >> x >> y;
            pts.insert({ x, y });
            sum += x;
        }
        double mid = sum / n;
        bool sym = true;
        for (auto &pt : pts)
            if (pt.first < mid && !pts.count({ mid + mid - pt.first, pt.second }))
            {
                sym = false;
                break;
            }
        cout << (sym ? "YES" : "NO") << "\n";
    }
}
