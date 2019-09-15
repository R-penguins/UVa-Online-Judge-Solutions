/**
 * The Dragon of Loowater
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    while ((cin >> n >> m) && n && m)
    {
        vector<int> heads(n), knights(m);
        for (int &i : heads)
            cin >> i;
        for (int &i : knights)
            cin >> i;
        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());
        int h = 0, ans = 0;
        for (int k : knights)
            if (k >= heads[h])
            {
                ans += k;
                if (++h == n)
                    break;
            }
        if (h < n)
            cout << "Loowater is doomed!\n";
        else
            cout << ans << "\n";
    }
}
