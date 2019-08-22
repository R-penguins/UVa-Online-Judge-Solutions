/**
 * AOAPC II Exercise 5-5 Compound Words
 * 8 TLE 20 AC // sliding words is faster than a huge set
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<string> dict;
    string s;
    while (cin >> s)
        dict.insert(s);
    for (const string &s : dict)
        for (int sz = 1; sz < s.size(); ++sz)
            if (dict.count(s.substr(0, sz)) && dict.count(s.substr(sz)))
            {
                cout << s << "\n";
                break;
            }
}
