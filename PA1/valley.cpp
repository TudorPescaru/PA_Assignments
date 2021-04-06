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
    int N, global_min, start_pos, end_pos;
    vector<int> heights;

    void read_input() {
        ifstream in("valley.in");
        in >> N;
        global_min = INT_MAX;
        start_pos = 0;
        end_pos = 0;

        for (int i = 0; i < N; i++) {
            int hi;
            in >> hi;
            heights.push_back(hi);
            if (hi < global_min) {
                global_min = hi;
                start_pos = i;
                end_pos = i;
            } else if (hi == global_min) {
                end_pos = i;
            }
        }
        in.close();
    }

    ull get_result() {
        ull excavate = 0;
        if (end_pos == 0) {
            excavate += heights[1] - global_min;
            heights[1] = global_min;
        }
        if (start_pos == N - 1) {
            excavate += heights[N - 2] - global_min;
            heights[N - 2] = global_min;
        }
        for (int i = start_pos; i <= end_pos; ++i) {
            excavate += heights[i] - global_min;
            heights[i] = global_min;
        }
        for (int i = 0; i < start_pos; ++i) {
            if (heights[i] < heights[i + 1]) {
                excavate += heights[i + 1] - heights[i];
                heights[i + 1] = heights[i];
            }
        }
        for (int i = N - 1; i > end_pos; --i) {
            if (heights[i] < heights[i - 1]) {
                excavate += heights[i - 1] - heights[i];
                heights[i - 1] = heights[i];
            }
        }
        return excavate;
    }

    void print_output(ull result) {
        ofstream out("valley.out");
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
