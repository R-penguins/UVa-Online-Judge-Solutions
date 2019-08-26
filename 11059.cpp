/**
 * Maximum product
 * AOAPC II Example 7-2
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, T = 1;
    while (cin >> n)
    {
        long long cur = 0, neg_cur = 0, ans = 0;
        while (n--)
        {
            int i;
            cin >> i;
            if (i)
            {
                cur = cur ? cur * i : i;
                neg_cur *= i;
                if (i < 0)
                    swap(neg_cur, cur);
                ans = max(ans, cur);
            }
            else
            {
                cur = 0;
                neg_cur = 0;
            }
        }
        cout << "Case #" << T++ << ": The maximum product is " << ans << ".\n\n";
    }
}
