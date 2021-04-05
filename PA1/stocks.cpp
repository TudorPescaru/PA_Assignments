// Pescaru Tudor-Mihai 321CA 2021
#include <bits/stdc++.h>

using namespace std;

int solve(int N, int B, int L, vector<tuple<int, int, int>>& stocks) {
    return 0;
}

int main() {
    ifstream in("stocks.in");
    ofstream out("stocks.out");

    int N, B, L;
    vector<tuple<int, int, int>> stocks;

    in >> N >> B >> L;

    for (int i = 0; i < N; i++) {
        int currentValue, minValue, maxValue;
        in >> currentValue >> minValue >> maxValue;
        tuple<int, int, int> stock = {currentValue, minValue, maxValue};
        stocks.push_back(stock);
    }

    out << solve(N, B, L, stocks);

    in.close();
    out.close();
    return 0;
}
