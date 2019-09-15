/**
 * Open Credit System
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = numeric_limits<int>::min(), curMax = ans;
        for (int i = 0; i < n; ++i)
        {
            int cur;
            cin >> cur;
            if (i)
                ans = max(ans, curMax - cur);
            curMax = max(curMax, cur);
        }
        cout << ans << "\n";
    }
}
