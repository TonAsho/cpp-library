#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <bits/stdc++.h>
#include "../../graph/euler-tour.hpp"

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int N, Q;
    std::cin >> N >> Q;
    EulerTour<long long> G(N);
    for(int i = 1; i < N; ++i) {
        int p; std::cin >> p;
        G.add_edge(i, p);
    }
    G.build(0);
    while(Q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << G.lca(u, v) << std::endl;
    }
}