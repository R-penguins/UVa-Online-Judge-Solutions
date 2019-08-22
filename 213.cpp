/**
 * AOAPC II Example 4-4 Message Encoding
 */
#include <bits/stdc++.h>
using namespace std;
int read_int(int len) {
    int ans = 0;
    char cur;
    while (len--) {
        cin >> cur;
        ans = ans * 2 + cur - '0';
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string header;
    while (getline(cin, header)) {
        // Make map
        vector<string> dec(8, string(1 << 8, ' '));
        int len = 1, pos = 0;
        for (char c : header) {
            dec[len][pos++] = c;
            if (pos >= (1 << len) - 1) {
                ++len;
                pos = 0;
            }
        }
        // Decode
        while (len = read_int(3)) {
            int val;
            while ((val = read_int(len)) < (1 << len) - 1) {
                char c = dec[len][val];
                cout << dec[len][val];
            }
        }
        cout << '\n';
        getline(cin, header);
    }
}
