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
    int N, B, L;
    vector<tuple<int, int, int>> stocks;

    void read_input() {
        ifstream in("stocks.in");
        in >> N >> B >> L;

        for (int i = 0; i < N; ++i) {
            int currentValue, minValue, maxValue;
            in >> currentValue >> minValue >> maxValue;
            tuple<int, int, int> stock = {currentValue, minValue, maxValue};
            stocks.push_back(stock);
        }
        in.close();
    }

    int get_result() {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(B + 1,
                                                 vector<int>(L + 1, 0)));
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= B; ++j) {
                for (int k = 0; k <= L; ++k) {
                    auto[x, y, z] = stocks[i - 1];
                    if (i == 0 || j == 0 || k == 0) {
                        dp[i][j][k] = 0;
                    } else if (x <= j && (x - y) <= k) {
                        int to_add = z - x;
                        int aux = to_add + dp[i - 1][j - x][k - (x - y)];
                        dp[i][j][k] = max(aux, dp[i - 1][j][k]);
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
        return dp[N][B][L];
    }

    void print_output(int result) {
        ofstream out("stocks.out");
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
