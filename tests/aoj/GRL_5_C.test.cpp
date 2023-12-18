#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C"
#include <bits/stdc++.h>
#include "../../graph/euler-tour.hpp"

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int N, Q;
    std::cin >> N;
    EulerTour<long long> G(N);
    for(int i = 0; i < N; ++i) {
        int k; std::cin >> k;
        for(int j = 0; j < k; ++j) {
            int c; std::cin >> c;
            G.add_edge(i, c);
        }
    }
    G.build(0);
    std::cin >> Q;
    while(Q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << G.lca(u, v) << std::endl;
    }
}