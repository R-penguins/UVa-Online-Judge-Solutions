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
        vector<int> ys;
        for (int y = k + 1; y <= 2 * k; ++y)
            if (k * y % (y - k) == 0)
                ys.push_back(y);
        cout << ys.size() << "\n";
        for (int i = 0; i < ys.size(); ++i)
        {
            int y = ys[i], x = k * y / (y - k);
            cout << "1/" << k << " = 1/" << x << " + 1/" << y << "\n";
        }
    }
}
