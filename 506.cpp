/**
 * AOAPC II Example 6-21 System Dependencies
 * ICPC WF 1997
 */
#include <bits/stdc++.h>
using namespace std;
struct Info
{
    string name;
    vector<int> depOns, usedIns;
    int status = 0;
    Info(string &name) : name(name) { }
};
map<string, int> name2id;
vector<Info> comps;
list<int> installed;
int id(string &item)
{
    if (name2id.count(item))
        return name2id[item];
    comps.push_back(item);
    return name2id[item] = comps.size() - 1;
}
void install(int id, bool exp)
{
    for (int dep : comps[id].depOns)
        if (!comps[dep].status)
            install(dep, false);
    cout << "   Installing " << comps[id].name << "\n";
    installed.push_back(id);
    comps[id].status = exp ? 1 : 2;
}
void uninstall(int id)
{
    cout << "   Removing " << comps[id].name << "\n"; 
    installed.remove(id);
    comps[id].status = 0;
    for (int dep : comps[id].depOns)
        if (comps[dep].status == 2 && none_of(comps[dep].usedIns.begin(), comps[dep].usedIns.end(), [](int id){ return comps[id].status; }))
            uninstall(dep);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    while (getline(cin, line))
    {
        name2id.clear();
        comps.clear();
        installed.clear();
        while (line != "END")
        {
            cout << line << "\n";
            if (line[0] == 'L')
                for (int i : installed)
                    cout << "   " << comps[i].name << "\n";
            else
            {
                stringstream ss(line);
                string cmd, item;
                ss >> cmd >> item;
                int item_id = id(item);
                if (cmd[0] == 'D')
                {
                    string cur;
                    while (ss >> cur)
                    {
                        int cur_id = id(cur);
                        comps[item_id].depOns.push_back(cur_id);
                        comps[cur_id].usedIns.push_back(item_id);
                    }
                }
                else if (cmd[0] == 'I')
                    if (comps[item_id].status)
                        cout << "   " << item << " is already installed.\n";
                    else
                        install(item_id, true);
                else
                    if (!comps[item_id].status)
                        cout << "   " << item << " is not installed.\n";
                    else if (any_of(comps[item_id].usedIns.begin(), comps[item_id].usedIns.end(), [](int id){ return comps[id].status; }))
                        cout << "   " << item << " is still needed.\n";
                    else
                        uninstall(item_id);
            }
            getline(cin, line);
        }
        cout << "END\n";
    }
}
