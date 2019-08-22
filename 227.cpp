/**
 * AOAPC II 3-5 Puzzle
 * ICPC WF 1993
 * I/O, simulation
 * 60 WA
 * +10 AC
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> t(5);
    int cnt = 0;
    while (getline(cin, t[0]) && t[0][0] != 'Z') {
        if (cnt > 0)
            cout << '\n';
        cout << "Puzzle #" << ++cnt << ":\n";
        int x, y;
        for (int row = 0; row < 5; ++row) {
            if (row > 0)
                getline(cin, t[row]);
            if (t[row].size() < 5)
                t[row] += " ";
            int pos;
            if ((pos = t[row].find(' ')) != string::npos) {
                x = row;
                y = pos;
            }
        }
        string ops, temp;
        getline(cin, temp);
        ops.append(temp);
        while (temp.back() != '0') {
            getline(cin, temp);
            ops.append(temp);
        }
        bool ok = true;
        for (char op : ops) {
            int r = x, c = y;
            switch (op) {
            case 'A':
                --r;
                break;
            case 'B':
                ++r;
                break;
            case 'L':
                --c;
                break;
            case 'R':
                ++c;
                break;
            }
            if (r < 0 || r > 4 || c < 0 || c > 4) {
                ok = false;
                break;
            }
            swap(t[x][y], t[r][c]);
            x = r;
            y = c;
        }
        if (ok)
            for (string row : t) {
                auto iter = row.begin();
                cout << *iter++;
                for (; iter < row.end(); ++iter)
                    cout << " " << *iter;
                cout << '\n';
            }
        else
            cout << "This puzzle has no final configuration.\n";
    } 
}