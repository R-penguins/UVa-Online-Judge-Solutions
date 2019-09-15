/**
 * Age Sort
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while ((cin >> n) && n)
    {
        array<int, 100> ages {0};
        while (n--)
        {
            int age;
            cin >> age;
            ++ages[age];
        }
        bool first = true;
        for (int i = 1; i < 100; ++i)
            for (int cnt = 0; cnt < ages[i]; ++cnt)
            {
                if (first)
                    first = false;
                else
                    cout << " ";
                cout << i;
            }
        cout << "\n";
    }
}
