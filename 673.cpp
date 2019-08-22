/**
 * AOAPC II Exercise 6-1 Parenthesis Balance
 * 12 WA; 13 AC;
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int kase;
    cin >> kase;
    string junk;
    getline(cin, junk);
    while (kase--)
    {
        string line;
        getline(cin, line);
        stack<char> stk;
        bool ok = true;
        for (char c : line)
            if (c == '(' || c == '[')
                stk.push(c);
            else
            {
                if (stk.empty())
                {
                    ok = false;
                    break;
                }
                char prev = stk.top();
                stk.pop();
                if (prev == '(' && c != ')' || prev == '[' && c != ']')
                {
                    ok = false;
                    break;
                }
            }
        if (!stk.empty())
            ok = false;
        cout << (ok ? "Yes" : "No") << "\n";
    }
}
