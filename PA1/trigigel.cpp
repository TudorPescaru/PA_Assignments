// Pescaru Tudor-Mihai 321CA 2021
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007
#define KMAX 4

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    ll N;

    void read_input() {
        ifstream in("trigigel.in");
        in >> N;
        in.close();
    }

    // Multiply two matrices
    void multiply_matrix(ll A[KMAX][KMAX], ll B[KMAX][KMAX],
                        ll C[KMAX][KMAX]) {
        ll tmp[KMAX][KMAX];

        for (int i = 0; i < KMAX; ++i) {
            for (int j = 0; j < KMAX; ++j) {
                ll sum = 0;

                for (int k = 0; k < KMAX; ++k) {
                    sum += 1LL * A[i][k] * B[k][j];
                }

                // Perform modulo correctly for negative numbers
                tmp[i][j] = (-((-sum) % MOD) + MOD) % MOD;
            }
        }

        memcpy(C, tmp, sizeof(tmp));
    }

    // Raise a matrix to a given power
    void power_matrix(ll C[KMAX][KMAX], ll p, ll R[KMAX][KMAX]) {
        ll tmp[KMAX][KMAX];
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

    ll get_result() {
        // Return values for base cases
        if (N == 1) {
            return 1;
        }
        if (N == 2) {
            return 3;
        }
        if (N == 3) {
            return 6;
        }
        if (N == 4) {
            return 10;
        }
        // Declare initial constant matrix
        ll C[KMAX][KMAX] = {{0, 0, 0, -1},
                            {1, 0, 0, 1},
                            {0, 1, 0, -1},
                            {0, 0, 1, 2}};
        // Raise matrix to power N - KMAX
        power_matrix(C, N - 4, C);
        // Compute final element
        ll sol = 1 * C[0][3] + 3 * C[1][3] + 6 * C[2][3] + 10 * C[3][3];
        return sol % MOD;
    }

    void print_output(ll result) {
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
