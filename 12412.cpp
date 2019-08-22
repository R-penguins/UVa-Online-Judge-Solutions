/**
 * AOAPC II Example 4-6 A Typical Homework
 */
#include <bits/stdc++.h>
using namespace std;
struct Student {
    string sid, name;
    int cid, tot = 0, psd = 0;
    vector<int> scr;

    bool read() {
        cin >> sid;
        if (sid != "0") {
            cin >> cid >> name;
            scr = vector<int>(4);
            for (int &i : scr) {
                cin >> i;
                tot += i;
                if (i >= 60)
                    ++psd;
            }
            return true;
        }
        return false;
    }
};
void query(list<Student> &data, list<Student>::iterator iter) {
    int rank = 1;
    for (Student stu : data)
        if (stu.tot > iter->tot)
            ++rank;
    cout << rank << " " << iter->sid << " " << iter->cid << " " << iter->name << " ";
    for (int i : iter->scr)
        cout << i << " ";
    cout << iter->tot << " " << iter->tot / 4.0 + 5e-5 << '\n';
}
void stats(list<Student> &data) {
    const static vector<string> classes { "Chinese", "Mathematics", "English", "Programming" };
    cout << "Please enter class ID, 0 for the whole statistics.\n";
    int choice, cnt = 0;
    vector<int> score(4, 0), sub_passed(4, 0), all_passed(5, 0);
    cin >> choice;
    for (Student stu : data)
        if (choice == 0 || stu.cid == choice) {
            ++cnt;
            transform(stu.scr.begin(), stu.scr.end(), score.begin(), score.begin(), plus<int>());
            transform(stu.scr.begin(), stu.scr.end(), sub_passed.begin(), sub_passed.begin(), [](int scor, int su){
                if (scor >= 60)
                    return su + 1;
                return su;
            });
            ++all_passed[stu.psd];
        }
    if (!cnt)
        return;
    for (int id = 0; id < 4; ++id)
        cout << classes[id] << '\n'
             << "Average Score: " << 1.0 * score[id] / cnt + 5e-5 << '\n'
             << "Number of passed students: " << sub_passed[id] << '\n'
             << "Number of failed students: " << cnt - sub_passed[id] << "\n\n";
    int cur_sum = 0;
    cout << "Overall:\n"
         << "Number of students who passed all subjects: " << (cur_sum += all_passed[4]) << '\n'
         << "Number of students who passed 3 or more subjects: " << (cur_sum += all_passed[3]) << '\n'
         << "Number of students who passed 2 or more subjects: " << (cur_sum += all_passed[2]) << '\n'
         << "Number of students who passed 1 or more subjects: " << (cur_sum += all_passed[1]) << '\n'
         << "Number of students who failed all subjects: " << all_passed[0] << "\n\n";
}
int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(2);
    list<Student> data;
    bool cont = true;
    while (cont) {
        cout << "Welcome to Student Performance Management System (SPMS).\n\n"
             << "1 - Add\n"
             << "2 - Remove\n"
             << "3 - Query\n"
             << "4 - Show ranking\n"
             << "5 - Show Statistics\n"
             << "0 - Exit\n\n";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            while (true) {
                cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish.\n";
                Student cur;
                if (cur.read()) {
                    bool ok = true;
                    for (Student stu : data)
                        if (cur.sid == stu.sid) {
                            ok = false;
                            break;
                        }
                    if (ok)
                        data.push_back(cur);
                    else
                        cout << "Duplicated SID.\n";
                }
                else
                    break;
            }
            break;
        case 2:
            while (true) {
                string entry;
                int cnt = 0;
                cout << "Please enter SID or name. Enter 0 to finish.\n";
                cin >> entry;
                if (!isalpha(entry[0])) {
                    if (entry == "0")
                        break;
                    auto iter = data.begin();
                    while (iter != data.end()) {
                        if (iter->sid == entry) {
                            iter = data.erase(iter);
                            ++cnt;
                            break;
                        }
                        else
                            ++iter;
                    }
                }
                else {
                    auto iter = data.begin();
                    while (iter != data.end()) {
                        if (iter->name == entry) {
                            iter = data.erase(iter);
                            ++cnt;
                        }
                        else
                            ++iter;
                    }
                }
                cout << cnt << " student(s) removed.\n";
            }
            break;
        case 3:
            while (true) {
                string entry;
                cout << "Please enter SID or name. Enter 0 to finish.\n";
                cin >> entry;
                if (!isalpha(entry[0])) {
                    if (entry == "0")
                        break;
                    for (auto iter = data.begin(); iter != data.end(); ++iter)
                        if (iter->sid == entry) {
                            query(data, iter);
                            break;
                        }
                }
                else
                    for (auto iter = data.begin(); iter != data.end(); ++iter) 
                        if (iter->name == entry) {
                            query(data, iter);
                        }
            }
            break;
        case 4:
            cout << "Showing the ranklist hurts students' self-esteem. Don't do that.\n";
            break;
        case 5:
            stats(data);
            break;
        case 0:
            cont = false;
        }
    }
}
