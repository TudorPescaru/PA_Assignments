// Pescaru Tudor-Mihai 321CA 2021
#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<pair<int, int>>& mountains) {
    return 0;
}

int main() {
    ifstream in("ridge.in");
    ofstream out("ridge.out");

    int N;
    vector<pair<int, int>> mountains;

    in >> N;

    for (int i = 0; i < N; i++) {
        int Hi, Ci;
        in >> Hi >> Ci;
        pair<int, int> mountain = {Hi, Ci};
        mountains.push_back(mountain);
    }

    out << solve(N, mountains);

    in.close();
    out.close();
    return 0;
}
