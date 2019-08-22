/**
 * AOAPC II Example 4-1 Ancient Cypher
 * stats
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    while (cin >> a >> b) {
        vector<int> freqA(26), freqB(26);
        for (char c : a)
            ++freqA[c - 'A'];
        for (char c : b)
            ++freqB[c - 'A'];
        sort(freqA.begin(), freqA.end());
        sort(freqB.begin(), freqB.end());
        if (equal(freqA.begin(), freqA.end(), freqB.begin()))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}