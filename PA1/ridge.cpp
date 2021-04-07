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
    int N;
    vector<pair<int, int>> mountains;

    // O(N) space-time complexity
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

    // O(N) space-time complexity
    ull get_result() {
        // Create DP state vector with three states
        vector<vector<ull>> dp(N, vector<ull>(3, 0));

        // Initialise first position of vector
        dp[0][1] = mountains[0].second;
        // If mountain can be excavated twice add cost else infinity
        if (mountains[0].first >= 2) {
            dp[0][2] = 2 * mountains[0].second;
        } else {
            // Set double excavation state as impossible
            dp[0][2] = ULLONG_MAX;
        }

        // Update states going through every mountain comparing to previous
        for (int i = 1; i < N; i++) {
            // Get all possible levels of excavation for previous and current
            int c0 = mountains[i].first;
            int c1 = mountains[i].first - 1;
            int c2 = mountains[i].first - 2;
            int p0 = mountains[i - 1].first;
            int p1 = mountains[i - 1].first - 1;
            int p2 = mountains[i - 1].first - 2;
            // Update state for not excavating curr
            // Compare unexcavated curr with unexcavated prev
            if (c0 != p0) {
                // Compare unexcavated curr with prev excavated once
                if (c0 != p1) {
                    // Compare unexcavated curr with prev excavated twice
                    if (c0 != p2) {
                        dp[i][0] = min(dp[i - 1][0],
                                        min(dp[i - 1][1], dp[i - 1][2]));
                    } else {
                        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
                    }
                } else {
                    // Compare unexcavated curr with prev excavated twice
                    if (c0 != p2) {
                        dp[i][0] = min(dp[i - 1][0], dp[i - 1][2]);
                    } else {
                        dp[i][0] = dp[i - 1][0];
                    }
                }
            } else {
                // Compare unexcavated curr with prev excavated once
                if (c0 != p1) {
                    // Compare unexcavated curr with prev excavated twice
                    if (c0 != p2) {
                        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
                    } else {
                        dp[i][0] = dp[i - 1][1];
                    }
                }
            }
            // Update state for excavating curr once
            // Compare curr excavated once with unexcavated prev
            if (c1 != p0) {
                // Compare curr excavated once with prev excavated once
                if (c1 != p1) {
                    // Compare curr excavated once with prev excavated twice
                    if (c1 != p2) {
                        dp[i][1] = min(dp[i - 1][0],
                                        min(dp[i - 1][1], dp[i - 1][2]))
                                        + mountains[i].second;
                    } else {
                        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1])
                                    + mountains[i].second;
                    }
                } else {
                    // Compare curr excavated once with prev excavated twice
                    if (c1 != p2) {
                        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2])
                                    + mountains[i].second;
                    } else {
                        dp[i][1] = dp[i - 1][0] + mountains[i].second;
                    }
                }
            } else {
                // Compare curr excavated once with prev excavated once
                if (c1 != p1) {
                    // Compare curr excavated once with prev excavated twice
                    if (c1 != p2) {
                        dp[i][1] = min(dp[i - 1][1], dp[i - 1][2])
                                    + mountains[i].second;
                    } else {
                        dp[i][1] = dp[i - 1][1] + mountains[i].second;
                    }
                }
            }
            // Check if curr can be excavated twice
            if (c2 >= 0) {
                // Update state for excavating curr twice
                // Compare curr excavated twice with unexcavated prev
                if (c2 != p0) {
                    // Compare curr excavated twice with prev excavated once
                    if (c2 != p1) {
                        // Compare cur excavated twice with prev excavated twice
                        if (c2 != p2) {
                            dp[i][2] = min(dp[i - 1][0],
                                            min(dp[i - 1][1], dp[i - 1][2]))
                                            + 2 * mountains[i].second;
                        } else {
                            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1])
                                        + 2 * mountains[i].second;
                        }
                    } else {
                        // Compare curr excavated once with prev excavated twice
                        if (c2 != p2) {
                            dp[i][2] = min(dp[i - 1][0], dp[i - 1][2])
                                        + 2 * mountains[i].second;
                        } else {
                            dp[i][2] = dp[i - 1][0] + 2 * mountains[i].second;
                        }
                    }
                } else {
                    // Compare curr excavated twice with prev excavated once
                    if (c2 != p1) {
                        // Compare curr excavated once with prev excavated twice
                        if (c2 != p2) {
                            dp[i][2] = min(dp[i - 1][1], dp[i - 1][2])
                                        + 2 * mountains[i].second;
                        } else {
                            dp[i][2] = dp[i - 1][1] + 2 * mountains[i].second;
                        }
                    }
                }
            } else {
                // Set double excavation state as impossible
                dp[i][2] = ULLONG_MAX;
            }
        }

        return min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
    }

    void print_output(ull result) {
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
