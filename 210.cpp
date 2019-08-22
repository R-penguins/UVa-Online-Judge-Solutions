/**
 * AOAPC II Example 6-1 Concurrency Simulator
 * ICPC WF 1991
 */
#include <bits/stdc++.h>
using namespace std;
int n, ta, to, tb, te, ts, t;
vector<string> progs;
vector<int> line_nums, vars;
deque<int> readyQ;
queue<int> blockedQ;
bool locked;
void run(int id)
{
    int timer = t;
    while (timer > 0)
    {
        string &line = progs[line_nums[id]];
        switch(line[2])
        {
        case '=':
            vars[line[0] - 'a'] = stoi(line.substr(4));
            timer -= ta;
            break;
        case 'i': // print
            cout << id + 1 << ": " << vars[line[6] - 'a'] << "\n";
            timer -= to;
            break;
        case 'c': // lock
            if (locked)
            {
                blockedQ.push(id);
                return;
            }
            locked = true;
            timer -= tb;
            break;
        case 'l': // unlock
            locked = false;
            if (!blockedQ.empty())
            {
                readyQ.push_front(blockedQ.front());
                blockedQ.pop();
            }
            timer -= te;
            break;
        case 'd': // stop
            return;
        }
        ++line_nums[id];
    }
    readyQ.push_back(id);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> ta >> to >> tb >> te >> ts >> t;
        progs.clear();
        line_nums = vector<int>(n);
        vars = vector<int>(26, 0);
        locked = false;
        string line;
        int line_num = 0;
        getline(cin, line);
        for (int i = 0; i < n; ++i)
        {
            line_nums[i] = line_num;
            while (true)
            {
                getline(cin, line);
                progs.push_back(line);
                ++line_num;
                if (line == "end")
                    break;
            }
            readyQ.push_back(i);
        }
        while (!readyQ.empty())
        {
            int cur_id = readyQ.front();
            readyQ.pop_front();
            run(cur_id);
        }
        if (T)
            cout << "\n";
    }
}
