/**
 * AOAPC II 3-8 Repeating decimals
 * ICPC WF 1990
 * math, simulation
 * 67 WA, 84 PE, 90 AC
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    while (cin >> a >> b) {
        map<int, int> remPos;
        string s = "";
        int rem = a % b, n = rem * 10, dig = n / b;
        int pos = 0;
        while (remPos.find(rem) == remPos.end()) {
            s.append(to_string(dig));
            remPos[rem] = pos++;
            rem = n % b;
            n = rem * 10;
            dig = n / b;
        }
        int beg = remPos[rem];
        cout << a << "/" << b << " = " << a / b << "." << string(s.begin(), s.begin() + beg) << "(";
        if (s.size() <= 50)
            cout << string(s.begin() + beg, s.end());
        else
            cout << string(s.begin() + beg, s.begin() + 50) << "...";
        cout << ")\n";
        cout << "   " << s.size() - beg << " = number of digits in repeating cycle\n\n";
    }
}