// Pescaru Tudor-Mihai 321CA 2021
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// O(N) space-time complexity
class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int N, global_min, start_pos, end_pos;
    vector<int> heights;

    // O(N) space-time complexity
    void read_input() {
        ifstream in("valley.in");
        in >> N;
        // Initialise global min, start and end postions
        global_min = INT_MAX;
        start_pos = 0;
        end_pos = 0;

        for (int i = 0; i < N; i++) {
            int hi;
            in >> hi;
            heights.push_back(hi);
            // Determine if read height is lower than min
            if (hi < global_min) {
                // Update global min and postions
                global_min = hi;
                start_pos = i;
                end_pos = i;
            } else if (hi == global_min) {
                // Update end postion if equal to global min
                end_pos = i;
            }
        }

        in.close();
    }

    // O(N) time complexity
    ull get_result() {
        ull excavate = 0;
        // If minimum is first element excavate second element to ensure prefix
        if (end_pos == 0) {
            excavate += heights[1] - global_min;
            heights[1] = global_min;
        }
        // If minimum is last element excavate second to last to ensure suffix
        if (start_pos == N - 1) {
            excavate += heights[N - 2] - global_min;
            heights[N - 2] = global_min;
        }

        // From start to first position of minimum excavate to ensure decrease
        for (int i = 0; i < start_pos; ++i) {
            if (heights[i] < heights[i + 1]) {
                excavate += heights[i + 1] - heights[i];
                heights[i + 1] = heights[i];
            }
        }
        // Between first and last positions of min excavate to min
        for (int i = start_pos; i <= end_pos; ++i) {
            excavate += heights[i] - global_min;
            heights[i] = global_min;
        }
        // From end to last position of minimum excavate to ensure increase
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
