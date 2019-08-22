/**
 * AOAPC II Exercise 5-3 Throwing Cards Away I
 * 10 RE 15 AC // Boundaries!
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
        queue<int> cards;
        for (int i = 1; i <= n; ++i)
            cards.push(i);
        cout << "Discarded cards:";
        bool first = true;
        while (cards.size() >= 2)
        {
            if (first)
                first = false;
            else
                cout << ",";
            cout << " " << cards.front();
            cards.pop();
            cards.push(cards.front());
            cards.pop();
        }
        cout << "\n"
             << "Remaining card: " << cards.front() << "\n";
    }
}
