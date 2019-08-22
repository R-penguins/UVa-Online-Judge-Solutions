#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int rnd;
    while ((cin >> rnd) && rnd != -1) {
        string key, gus;
        cin >> key >> gus;
        set<char> keys, wrongs;
        for (char c : key)
            keys.insert(c);
        int chance = 7;
        for (char gu : gus)
            if (keys.find(gu) != keys.end()) {
                keys.erase(gu);
                if (keys.empty())
                    break;
            }
            else if (wrongs.find(gu) == wrongs.end()){
                wrongs.insert(gu);
                --chance;
                if (!chance)
                    break;
            }
        cout << "Round " << rnd << '\n';
        if (keys.empty())
            cout << "You win.\n";
        else if (!chance)
            cout << "You lose.\n";
        else
            cout << "You chickened out.\n";
    }
}