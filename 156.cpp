/**
 * AOAPC II Example 5-4 Ananagrams
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, string> trans;
    string s;
    while ((cin >> s) && s[0] != '#') {
        string t = s;
        for (char &c : t)
            c = tolower(c);
        sort(t.begin(), t.end());
        if (trans.find(t) == trans.end())
            trans[t] = s;
        else
            trans[t] = "";
    }
    set<string> ans;
    for (auto p : trans)
        if (p.second != "")
            ans.insert(p.second);
    for (string s : ans)
        cout << s << "\n";
}
