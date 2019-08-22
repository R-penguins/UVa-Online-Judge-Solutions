/**
 * AOAPC II Exercise 4-2 Squares
 * Solution 2 (Inspired by CHEN Feng)
 * Counts the max length of horizontal and vertical line segments starting
 * at each dot.
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, pn = 0;
    while (cin >> n >> m) {
        vector<vector<bool>> conH(n + 1, vector<bool>(n + 1, false)),
                             conV(n + 1, vector<bool>(n + 1, false));
        while (m--) {
            char ori;
            int i, j;
            cin >> ori >> i >> j;
            ori == 'H' ? conH[i][j] = true : conV[j][i] = true;
        }
        vector<vector<int>> lenH(n + 2, vector<int>(n + 2, 0)),
                            lenV(n + 2, vector<int>(n + 2, 0));
        for (int r = n; r >= 1; --r)
            for (int c = n; c >= 1; --c) {
                if (conH[r][c])
                    lenH[r][c] = lenH[r][c + 1] + 1;
                if (conV[r][c])
                    lenV[r][c] = lenV[r + 1][c] + 1;
            }
        vector<int> sz(n + 1, 0);
        for (int r = 1; r <= n; ++r)
            for (int c = 1; c <= n; ++c)
                for (int s = 1; s <= min(lenH[r][c], lenV[r][c]); ++s)
                    if (lenH[r + s][c] >= s && lenV[r][c + s] >= s)
                        ++sz[s];                            
        if (pn)
            cout << "\n**********************************\n\n";
        cout << "Problem #" << ++pn << "\n\n";
        bool no = true;
        for (int size = 1; size <= n; ++size)
            if (sz[size]) {
                cout << sz[size] << " square (s) of size " << size << "\n";
                no = false;
            }
        if (no)
            cout << "No completed squares can be found.\n";
    }
}
