/**
 * AOAPC II Exercise 6-2 S-Trees
 * 45 AC;
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, kase = 0;
    while (cin >> n && n)
    {
        cout << "S-Tree #" << ++kase << ":\n";
        string ordering, terminals;
        getline(cin, ordering);
        getline(cin, ordering);
        cin >> terminals;
        vector<int> ord;
        for (int i = 1; i < 3 * n; i += 3)
            ord.push_back(ordering[i] - '1');
        int m;
        cin >> m;
        while (m--)
        {
            string vva;
            cin >> vva;
            int pos = 0;
            for (int i = 0; i < n; ++i)
                pos += (1 << n - 1 - i) * (vva[ord[i]] - '0');
            cout << terminals[pos];
        }
        cout << "\n\n";
    }
}
