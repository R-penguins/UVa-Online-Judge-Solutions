/**
 * AOAPC II Exercise 4-3 Othello
 * simulation
 * 107 WA
 * ? AC
 */
#include <bits/stdc++.h>
using namespace std;
struct Pos {
    int x, y;
    Pos(int x, int y) : x(x), y(y) {}
    Pos operator+(const Pos &oth) const {
        return Pos(x + oth.x, y + oth.y);
    }
    bool operator==(const Pos &oth) const {
        return x == oth.x && y == oth.y;
    }
    bool valid() const {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }
};
const vector<Pos> moves { Pos(-1, 0), Pos(-1, 1), Pos(0, 1), Pos(1, 1),
                          Pos(1, 0), Pos(1, -1), Pos(0, -1), Pos(-1, -1) };
vector<string> board;              
char turn;            
char oppo(char a) {
    return a == 'W' ? 'B' : 'W';
}
bool can_put(Pos pos) {
    if (board[pos.x][pos.y] != '-')
        return false;
    for (Pos dir : moves) {
        Pos next = pos + dir;
        if (next.valid() && board[next.x][next.y] != oppo(turn))
            continue;
        while (next.valid()) {
            if (board[next.x][next.y] == '-')
                break;
            else if (board[next.x][next.y] == turn)
                return true;
            next = next + dir;
        }
    }
    return false;
}
void put(Pos pos) {
    board[pos.x][pos.y] = turn;
    for (Pos dir : moves) {
        Pos next = pos + dir;
        if (next.valid() && board[next.x][next.y] != oppo(turn))
            continue;
        while (next.valid()) {
            if (board[next.x][next.y] == '-')
                break;
            else if (board[next.x][next.y] == turn) {
                for (Pos p = pos + dir; !(p == next); p = p + dir)
                    board[p.x][p.y] = turn;
                break;
            }
            next = next + dir;
        }
    }
}
void lis() {
    bool first = true;
    for (int r = 0; r < 8; ++r)
        for (int c = 0; c < 8; ++c)
            if (can_put(Pos(r, c))) {
                if (first)
                    first = false;
                else
                    cout << " ";
                cout << "(" << r + 1 << "," << c + 1<< ")";
            }
    if (first)
        cout << "No legal move.";
    cout << "\n";
}
void move() {
    char ir, ic;
    cin >> ir >> ic;
    int r = ir - '0' - 1, c = ic - '0' - 1;
    if (!can_put(Pos(r, c)))
        turn = oppo(turn);
    put(Pos(r, c));
    turn = oppo(turn);
    int b = 0, w = 0;
    for (string &s : board)
        for (char c : s)
            if (c == 'B')
                ++b;
            else if (c == 'W')
                ++w;
    cout << "Black - " << setw(2) << b << " White - " << setw(2) << w << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int gn;
    cin >> gn;
    for (int g = 0; g < gn; ++g) {
        if (g)
            cout << "\n";
        board = vector<string>(8);
        for (string &s : board)
            cin >> s;
        cin >> turn;
        bool cont = true;
        while (cont) {
            char cmd;
            cin >> cmd;
            switch (cmd) {
                case 'L':
                    lis();
                    break;
                case 'M':
                    move();
                    break;
                case 'Q':
                    cont = false;
                    for (string &s : board)
                        cout << s << "\n";
            }
        }
    }
}
