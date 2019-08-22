/**
 * AOAPC II Example 4-3 The Dole Queue
 * simulation
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, m;
    while ((cin >> n >> k >> m) && n) {
        vector<int> dole(n);
        iota(dole.begin(), dole.end(), 1);
        int left = n, kpos = 0, mpos = n - 1;
        while (left) {
            int curK = k, knum, curM = m, mnum;
            while (curK) {
                if (knum = dole[kpos])
                    --curK;
                kpos = (kpos + 1) % n;
            }
            while (curM) {
                if (mnum = dole[mpos])
                    --curM;
                mpos = (mpos - 1 + n) % n;
            }
            dole[(kpos - 1 + n) % n] = 0;
            --left;
            cout << setw(3) << knum;
            if (mnum != knum) {
                cout << setw(3) << mnum;
                dole[(mnum - 1 + n) % n] = 0;
                --left;
            }
            if (left)
                cout << ",";
        }
        cout << '\n';
    }
}