/**
 * AOAPC II Example 4-5 Spreadsheet tracking
 */
#include <bits/stdc++.h>
using namespace std;
struct Cmd {
    string op;
    vector<int> pos;

    void read() {
        cin >> op;
        int cur;
        if (op[0] == 'E')
            for (int i = 0; i < 4; ++i) {
                cin >> cur;
                pos.push_back(cur);
            }
        else {
            int cnt;
            cin >> cnt;
            while (cnt--) {
                cin >> cur;
                pos.push_back(cur);
            }
        }
    }
};
bool simulate(vector<Cmd> &cmds, int &r, int &c) {
    for (Cmd &cmd : cmds) {
        if (cmd.op[0] == 'E') {
            if (r == cmd.pos[0] && c == cmd.pos[1]) {
                r = cmd.pos[2]; c = cmd.pos[3];
            }
            else if (r == cmd.pos[2] && c == cmd.pos[3]) {
                r = cmd.pos[0]; c = cmd.pos[1];
            }
        }
        else if (cmd.op[0] == 'D') {
            int &oi = (cmd.op[1] == 'R' ? r : c), fi = oi;
            for (int po : cmd.pos)
                if (po == oi)
                    return false;
                else if (po < oi)
                    --fi;
            oi = fi;
        }
        else {
            int &oi = (cmd.op[1] == 'R' ? r : c), fi = oi;
            for (int po : cmd.pos)
                if (po <= oi)
                    ++fi;
            oi = fi;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c, n, ds = 0;
    while ((cin >> r >> c >> n) && r) {
        vector<Cmd> cmds(n);
        for (Cmd &c : cmds)
            c.read();
        if (ds)
            cout << '\n';
        cout << "Spreadsheet #" << ++ds << '\n';
        int q, r, c;
        cin >> q;
        while (q--) {
            cin >> r >> c;
            cout << "Cell data in (" << r << "," << c << ") ";
            if (simulate(cmds, r, c))
                cout << "moved to (" << r << "," << c << ")\n";
            else
                cout << "GONE\n";
        }
    }
}
