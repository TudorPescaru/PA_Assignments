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
    vector<pair<int, int>> mountains;

    void read_input() {
        ifstream in("ridge.in");
        in >> N;

        for (int i = 0; i < N; i++) {
            int Hi, Ci;
            in >> Hi >> Ci;
            pair<int, int> mountain = {Hi, Ci};
            mountains.push_back(mountain);
        }
        in.close();
    }

    int get_result() {
        return 0;
    }

    void print_output(int result) {
        ofstream out("ridge.out");
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
