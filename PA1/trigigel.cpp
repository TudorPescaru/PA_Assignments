// Pescaru Tudor-Mihai 321CA 2021
#include <bits/stdc++.h>

using namespace std;

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int N;

    void read_input() {
        ifstream in("trigigel.in");
        in >> N;
        in.close();
    }

    int get_result() {
        return 0;
    }

    void print_output(int result) {
        ofstream out("trigigel.out");
        out << result;
        out.close();
    }
};

int main() {
    auto* task = new (nothrow) Task();
    if (!task) {
        cerr << "Error starting task";
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
