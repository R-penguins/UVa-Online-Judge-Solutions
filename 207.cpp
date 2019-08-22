/**
 * AOAPC II Example 5-10 PGA Tour Prize Money
 * ICPC WF 1990
 */
#include <bits/stdc++.h>
using namespace std;
struct Player {
    string name;
    vector<int> rd;
    int s36, rank, stot;
    bool dq = false;
    Player(string &name, vector<int> &rd) : name(name), rd(rd) {
        s36 = rd[0] + rd[1];
        if (rd.size() < 4)
            dq = true;
        stot = s36 + accumulate(rd.begin() + 2, rd.end(), 0);
    }
};
int main() {
    cin.tie(nullptr);
    const int CUT = 70;
    cout << fixed << setprecision(2);
    int kase;
    cin >> kase;
    for (int k = 0; k < kase; ++k) {
        double purse;
        cin >> purse;
        vector<double> perc(CUT);
        for (double &d : perc)
            cin >> d;
        vector<Player> players;
        // Read players
        int np;
        cin >> np;
        while (np--) {
            string na = "", junk;
            vector<int> src;
            getline(cin, junk);
            for (int i = 0; i < 20; ++i)
                na += getchar();
            while (na.back() == ' ')
                na.pop_back();
            bool valid = true;
            for (int i = 0; i < 4; ++i) {
                string s = "";
                for (int j = 0; j < 3; ++j)
                    s += getchar();
                if (isalpha(s[0]) || isalpha(s[1])) {
                    if (i < 2)
                        valid = false;
                    break;
                }
                src.push_back(stoi(s));
            }
            if (valid)
                players.push_back(Player(na, src));
        }
        // First 36 holes
        sort(players.begin(), players.end(), [](Player &a, Player &b){
            return a.s36 < b.s36;
        });
        int pos = -1, scr = 0;
        auto cut = players.begin();
        for (; cut != players.end(); ++cut) {
            ++pos;
            if (cut->s36 > scr) {
                scr = cut->s36;
                if (pos >= CUT)
                    break;
            }
        }
        players.erase(cut, players.end());
        // Final rounds
        sort(players.begin(), players.end(), [](Player &a, Player &b){
            if (a.rd.size() != b.rd.size())
                return a.rd.size() > b.rd.size();
            if (a.stot != b.stot)
                return a.stot < b.stot;
            return a.name < b.name;
        });
        // Ranking
        map<int, int> num;
        map<int, double> totScr;
        pos = -1, scr = 0;
        int cnt = 0, rk = 0, last_prize = 0;
        for (Player &p : players) {
            if (p.dq)
                break;
            ++pos;
            if (p.stot > scr) {
                rk = pos;
                scr = p.stot;
            }
            p.rank = rk;
            if (p.name.back() != '*') {
                if (cnt < CUT) {
                    last_prize = p.rank;
                    totScr[p.rank] += perc[cnt];
                }
                ++num[p.rank];
                ++cnt;
            }
        }
        // Output
        if (k)
            cout << "\n";
        cout << left << setw(21) << "Player Name" << setw(10) << "Place" << setw(5) << "RD1" << setw(5) << "RD2" << setw(5) << "RD3" << setw(5) << "RD4" << setw(10) << "TOTAL" << "Money Won\n";
        cout << string(71, '-') << "\n";
        for (Player &p : players) {
            if (!p.dq) {
                cout << left << setw(21) << p.name;
                cout << setw(10) << ((num[p.rank] > 1 && p.name.back() != '*' && p.rank <= last_prize) ? to_string(p.rank + 1) + "T" : to_string(p.rank + 1));
                for (int i : p.rd)
                    cout << setw(5) << i;
                cout << setw(3) << p.stot;
                if (p.name.back() != '*' && p.rank <= last_prize) {
                    cout << string(7, ' ');
                    cout << "$" << right << setw(9) << purse * (totScr[p.rank] / 100) / num[p.rank];
                }
            }
            else {
                cout << left << setw(31) << p.name;
                for (int i = 0; i < 4; ++i)
                    if (i < p.rd.size())
                        cout << setw(5) << p.rd[i];
                    else
                        cout << string(5, ' ');
                cout << "DQ";
            }
            cout << "\n";
        }
    }
}
