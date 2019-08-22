/**
 * AOAPC II Example 5-5 The SetStack Computer
 * ICPC NWERC 2006
 */
#include <bits/stdc++.h>
using namespace std;
map<set<int>, int> IDs;
vector<set<int>> Sets;
int ID(set<int> st) {
    if (IDs.find(st) != IDs.end())
        return IDs[st];
    Sets.push_back(st);
    return IDs[st] = Sets.size() - 1;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        IDs.clear();
        Sets.clear();
        stack<int> stk;
        int n;
        cin >> n;
        string op;
        while (n--) {
            cin >> op;
            if (op[0] == 'P')
                stk.push(ID(set<int>()));
            else if (op[0] == 'D')
                stk.push(stk.top());
            else {
                auto x1 = Sets[stk.top()];
                stk.pop();
                set<int> x2 = Sets[stk.top()], x;
                stk.pop();
                switch (op[0]) {
                case 'U':
                    set_union(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
                    break;
                case 'I':
                    set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
                    break;
                case 'A':
                    x = x2;
                    x.insert(ID(x1));
                }
                stk.push(ID(x));
            }
            cout << Sets[stk.top()].size() << "\n";
        }
        cout << "***\n";
    }
}
