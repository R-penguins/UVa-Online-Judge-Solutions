/**
 * AOAPC II Example 5-1 Where's the Marble
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, kase = 0;
    while ((cin >> n >> q) && n && q) {
        cout << "CASE# " << ++kase << ":\n";
        vector<int> mar(n);
        for (int &i : mar)
            cin >> i;
        sort(mar.begin(), mar.end());
        while (q--) {
            int x;
            cin >> x;
            auto pos = lower_bound(mar.begin(), mar.end(), x);
            if (pos != mar.end() && *pos == x)
                cout << x << " found at " << pos - mar.begin() + 1 << "\n";
            else
                cout << x << " not found\n";
        }
    }
}