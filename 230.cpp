/**
 * AOAPC II Exercise 5-8 Borrowers
 * 40 AC
 */
#include <bits/stdc++.h>
using namespace std;
map<string, string> auth;
struct Book
{
    string name;
    Book(string name) : name(name) { }
    bool operator<(const Book &rhs) const
    {
        if (auth[name] != auth[rhs.name])
            return auth[name] < auth[rhs.name];
        return name < rhs.name;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    set<Book> books;
    while (getline(cin, line) && line[0] != 'E')
    {
        auto pos = line.find('"', 1);
        string name = line.substr(0, pos + 1), author = line.substr(pos + 5);
        auth[name] = author;
        books.insert(name);
    }
    set<Book> rets;
    string cmd;
    while (cin >> cmd && cmd[0] != 'E')
        if (cmd[0] == 'S')
        {
            for (const Book &ret : rets)
            {
                auto pos = books.insert(ret).first;
                cout << "Put " << ret.name << " ";
                if (pos == books.begin())
                    cout << "first";
                else
                {
                    --pos;
                    cout << "after " << pos->name;
                }
                cout << "\n";
            }
            cout << "END\n";
            rets.clear();
        }
        else
        {
            getline(cin, line);
            string bk = line.substr(line.find('"'));
            if (cmd[0] == 'B')
                books.erase(bk);
            else if (cmd[0] == 'R')
                rets.insert(bk);
        }
}
