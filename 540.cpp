/**
 * AOAPC II Example 5-6 Team Queue
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, ts = 0;
    while ((cin >> t) && t) {
        cout << "Scenario #" << ++ts << "\n";
        map<int, int> team;
        int n;
        for (int tn = 0; tn < t; ++tn) {
            cin >> n;
            while (n--) {
                int mem;
                cin >> mem;
                team[mem] = tn;
            }
        }
        queue<int> team_q;
        vector<queue<int>> mem_q(t); 
        string cmd;
        while ((cin >> cmd) && cmd[0] != 'S') {
            if (cmd[0] == 'E') {
                int cur;
                cin >> cur;
                int tm = team[cur];
                if (mem_q[tm].empty())
                    team_q.push(tm);
                mem_q[tm].push(cur);
            }
            else {
                auto &q = mem_q[team_q.front()];
                cout << q.front() << "\n";
                q.pop();
                if (q.empty())
                    team_q.pop();
            }
        }
        cout << "\n";
    }
}
