/**
 * AOAPC II Example 5-11 The Letter Carrier's Rounds
 * ICPC WF 1999
 */
#include <bits/stdc++.h>
using namespace std;
string get_mta(string &ori) {
    return ori.substr(ori.find('@') + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<string> adds;
    string s;
    while ((cin >> s) && s[0] != '*') {
        string mta;
        int num;
        cin >> mta >> num;
        while (num--) {
            string name;
            cin >> name;
            adds.insert(name + "@" + mta);
        }
    }
    string s_add;
    while ((cin >> s_add) && s_add[0] != '*') {
        string s_mta = get_mta(s_add), r_add;
        vector<string> r_mtas;
        set<string> r_mtas_in;
        map<string, vector<string>> r_adds;
        set<string> r_users;
        while ((cin >> r_add) && r_add[0] != '*')
            if (r_users.find(r_add) == r_users.end()) {
                r_users.insert(r_add);
                string cur_mta = get_mta(r_add);
                if (r_mtas_in.find(cur_mta) == r_mtas_in.end()) {
                    r_mtas.push_back(cur_mta);
                    r_mtas_in.insert(cur_mta);
                }
                r_adds[cur_mta].push_back(r_add);
            }
        string data = "", temp;
        getline(cin, temp);
        while (getline(cin, temp) && temp[0] != '*')
            data += "     " + temp + "\n";
        for (string &r_mta : r_mtas) {
            cout << "Connection between " << s_mta << " and " << r_mta << "\n"
                 << "     HELO " << s_mta << "\n"
                 << "     250\n"
                 << "     MAIL FROM:<" << s_add << ">\n"
                 << "     250\n";
            bool ok = false;
            for (string &r_add : r_adds[r_mta]) {
                cout << "     RCPT TO:<" << r_add << ">\n"
                     << "     ";
                if (adds.find(r_add) != adds.end()) {
                    cout << "250\n";
                    ok = true;
                }
                else
                    cout << "550\n";
            }
            if (ok)
                cout << "     DATA\n"
                     << "     354\n"
                     << data
                     << "     .\n"
                     << "     250\n";
            cout << "     QUIT\n"
                 << "     221\n";
        }
    }
}
