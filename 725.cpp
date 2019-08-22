/**
 * Division
 * AOAPC II Example 7-1
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setfill('0');
    int n;
    bool first = true;
    while (cin >> n && n)
    {
        if (first)
            first = false;
        else
            cout << "\n";
        bool found = false;
        for (long long abcde = 10234; abcde <= 98765; ++abcde)
        {
            if (abcde % n)
                continue;
            int fghij = abcde / n;
            string str = to_string(abcde * 100000 + fghij);
            sort(str.begin(), str.end());
            bool ok = true;
            for (int i = 0; i < 10; ++i)
                if (str[i] != '0' + i)
                {
                    ok = false;
                    break;
                }
            if (ok)
            {
                cout << abcde << " / " << setw(5) << fghij << " = " << n << "\n";
                found = true;
            }
        }
        if (!found)
            cout << "There are no solutions for " << n << ".\n";
    }
}
