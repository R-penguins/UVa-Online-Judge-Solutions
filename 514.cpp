/**
 * AOAPC II Example 5-2 Rails
 * ICPC CERC 1997
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while ((cin >> n) && n)
    {
        int cur;
        while ((cin >> cur) && cur)
        {
            vector<int> tar(n);
            tar[0] = cur;
            for (int i = 1; i < n; ++i)
                cin >> tar[i];
            stack<int> s;
            int a = 1, b = 0;
            bool ok = true;
            while (b < n)
                if (a == tar[b])
                {
                    ++a;
                    ++b;
                }
                else if (!s.empty() && s.top() == tar[b])
                {
                    s.pop();
                    ++b;
                }
                else if (a <= n)
                    s.push(a++);
                else
                {
                    ok = false;
                    break;
                }
            cout << (ok ? "Yes" : "No") << "\n";
        }
        cout << "\n";
    }
}
