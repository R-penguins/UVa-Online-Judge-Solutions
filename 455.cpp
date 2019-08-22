/**
 * AOAPC II 3-4 Periodic Strings
 * String
 * 15 AC
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    bool first = true;
    while (N--) {
        string s;
        cin >> s;
        int ans = 1;
        for (; ans <= s.size() / 2; ++ans) {
            if (s.size() % ans) // !
                continue;
            auto end = s.begin() + ans, iter = end;
            for (; iter < s.end(); iter += ans)
                if (!equal(s.begin(), end, iter))
                    break;
            if (iter >= s.end())
                break;
        }
        if (first)
            first = false;
        else
            cout << '\n';
        cout << (ans <= s.size() / 2 ? ans : s.size()) << '\n';
    }
}