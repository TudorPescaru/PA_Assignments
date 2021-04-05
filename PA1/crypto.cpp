// Pescaru Tudor-Mihai 321CA 2021
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull upgrade_cost_to_p(int N, int B,
 vector<pair<int, int>>& computers, ull p) {
    ull upgrade_cost = 0;
    int i = 0;
    while (upgrade_cost <= B && i < N) {
        if (computers[i].first < p) {
            upgrade_cost += (p - computers[i].first) * computers[i].second;
        }
        i++;
    }
    return upgrade_cost;
}

int solve(int N, int B, vector<pair<int, int>>& computers) {
    ull start = 1;
    ull end = ULLONG_MAX - 1;

    while (start <= end) {
        ull mid = (start + end) / 2;
        ull upgrade_cost = upgrade_cost_to_p(N, B, computers, mid);

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

int main() {
    ifstream in("crypto.in");
    ofstream out("crypto.out");

    int N, B;
    vector<pair<int, int>> computers;

    in >> N >> B;

    for (int i = 0; i < N; ++i) {
        int Pi, Ui;
        in >> Pi >> Ui;
        pair<int, int> computer = {Pi, Ui};
        computers.push_back(computer);
    }

    out << solve(N, B, computers);

    in.close();
    out.close();
    return 0;
}
