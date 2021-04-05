// Pescaru Tudor-Mihai 321CA 2021
#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<int>& heights) {
    return 0;
}

int main() {
    ifstream in("valley.in");
    ofstream out("valley.out");

    int N;
    vector<int> heights;

    in >> N;

    for (int i = 0; i < N; i++) {
        int height;
        in >> height;
        heights.push_back(height);
    }

    out << solve(N, heights);

    in.close();
    out.close();
    return 0;
}
