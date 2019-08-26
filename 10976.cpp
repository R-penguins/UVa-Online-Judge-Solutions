/**
 * Fractions Again?!
 * AOAPC II Example 7-3
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    while (cin >> k)
    {
        vector<int> ys, xs;
        for (int y = k + 1; y <= 2 * k; ++y)
            if (k * y % (y - k) == 0)
            {
                ys.push_back(y);
                xs.push_back(k * y / (y - k));
            }
        cout << ys.size() << "\n";
        for (int i = 0; i < ys.size(); ++i)
            cout << "1/" << k << " = 1/" << xs[i] << " + 1/" << ys[i] << "\n";
    }
}
