// Pescaru Tudor-Mihai 321CA 2021
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

#define MOD 1000000007
#define KMAX 4

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    ull N;

    void read_input() {
        ifstream in("trigigel.in");
        in >> N;
        in.close();
    }

    void multiply_matrix(ull A[KMAX][KMAX], ull B[KMAX][KMAX],
                        ull C[KMAX][KMAX]) {
        ull tmp[KMAX][KMAX];

        for (int i = 0; i < KMAX; ++i) {
            for (int j = 0; j < KMAX; ++j) {
                ull sum = 0;

                for (ull k = 0; k < KMAX; ++k) {
                    sum += 1LL * A[i][k] * B[k][j];
                }

                tmp[i][j] = sum % MOD;
            }
        }

        memcpy(C, tmp, sizeof(tmp));
    }

    void power_matrix(ull C[KMAX][KMAX], ull p, ull R[KMAX][KMAX]) {
        ull tmp[KMAX][KMAX];
        for (int i = 0; i < KMAX; ++i) {
            for (int j = 0; j < KMAX; ++j) {
                tmp[i][j] = (i == j) ? 1 : 0;
            }
        }

        while (p != 1) {
            if  (p % 2 == 0) {
                multiply_matrix(C, C, C);
                p /= 2;
            } else {
                multiply_matrix(tmp, C, tmp);
                --p;
            }
        }

        multiply_matrix(C, tmp, R);
    }

    ull get_result() {
        if (N == 1) {
            return 1;
        }
        if (N == 2) {
            return 3;
        }
        if (N == 3) {
            return 6;
        }
        ull C[KMAX][KMAX] = {{1, 0, 0, 1},
                             {0, 0, 0, 1},
                             {0, 1, 0, 0},
                             {0, 0, 1, 1}};
        power_matrix(C, N - 3, C);
        ull sol = 3 * C[0][3] + 1 * C[1][3] + 3 * C[2][3] + 6 * C[3][3];
        return sol % MOD;
    }

    void print_output(ull result) {
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
