/**
 * AOAPC II Example 5-3 Andy's First Dictionary
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<string> dict;
    string line;
    while (getline(cin, line)) {
        for (char &c : line)
            c = isalpha(c) ? tolower(c) : ' ';
        stringstream ss(line);
        string word;
        while (ss >> word)
            dict.insert(word);
    }
    for (string s : dict)
        cout << s << "\n";
}
