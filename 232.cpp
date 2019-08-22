/**
 * AOAPC II 3-6 Puzzle
 * ICPC WF 1994
 * I/O
 * 47 AC
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c, ds = 0;
    while ((cin >> r) && r) {
        cin >> c;
        vector<string> puz(r);
        for (string &row : puz)
            cin >> row;
        vector<vector<int>> num(r, vector<int>(c, 0));
        int n = 0;
        for (int row = 0; row < r; ++row)
            for (int col = 0; col < c; ++col)
                if (puz[row][col] != '*' && (!row || !col || puz[row - 1][col] == '*' || puz[row][col - 1] == '*'))
                    num[row][col] = ++n;
        if (ds)
            cout << '\n';
        cout << "puzzle #" << ++ds << ":\n";
        cout << "Across\n";
        for (int row = 0; row < r; ++row)
            for (int col = 0; col < c; ++col) {
                if (puz[row][col] == '*')
                    continue;
                cout << setw(3) << num[row][col] << "." << puz[row][col];
                while (++col < c && puz[row][col] != '*')
                    cout << puz[row][col];
                cout << '\n';
            }
        cout << "Down\n";
        for (int row = 0; row < r; ++row)
            for (int col = 0; col < c; ++col) {
                if (puz[row][col] == '*')
                    continue;
                cout << setw(3) << num[row][col] << "." << puz[row][col];
                puz[row][col] = '*';
                int rr = row;
                while (++rr < r && puz[rr][col] != '*') {
                    cout << puz[rr][col];
                    puz[rr][col] = '*';
                }
                cout << '\n';
            }
    }
}