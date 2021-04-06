// Pescaru Tudor-Mihai 321CA 2021
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int N, B;
    vector<pair<int, int>> computers;

    void read_input() {
        ifstream in("crypto.in");
        in >> N >> B;

        for (int i = 0; i < N; ++i) {
            int Pi, Ui;
            in >> Pi >> Ui;
            pair<int, int> computer = {Pi, Ui};
            computers.push_back(computer);
        }

        in.close();
    }

    ull upgrade_cost_to_p(ull p) {
        ull upgrade_cost = 0;
        int i = 0;
        while (upgrade_cost <= (ull)B && i < N) {
            if ((ull)computers[i].first < p) {
                upgrade_cost += (p - computers[i].first) * computers[i].second;
            }
            i++;
        }
        return upgrade_cost;
    }

    int get_result() {
        ull start = 1;
        ull end = ULLONG_MAX - 1;

        while (start <= end) {
            ull mid = (start + end) / 2;
            ull upgrade_cost = upgrade_cost_to_p(mid);

            if (upgrade_cost == (ull)B) {
                return mid;
            }
            if (upgrade_cost < (ull)B) {
                start = mid + 1;
            }
            if (upgrade_cost > (ull)B) {
                end = mid - 1;
            }
        }

        return end;
    }

    void print_output(int result) {
        ofstream out("crypto.out");
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
