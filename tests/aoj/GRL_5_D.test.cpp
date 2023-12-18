#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D"
#include <bits/stdc++.h>
#include "../../graph/euler-tour.hpp"
#include "../../data-structure/binary-indexed-tree.hpp"

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int N, Q;
    std::cin >> N;
    EulerTour<long long> G(N);
    for(int i = 0; i < N; ++i) {
        int k; std::cin >> k;
        for(int j = 0; j < k; ++j) {
            int p; std::cin >> p;
            G.add_edge(p, i); 
        }
    }
    G.build(0);
    BinaryIndexedTree<long long> bit(2 * N);
    std::cin >> Q;
    while(Q--) {
        int op;
        std::cin >> op;
        if(op == 0) {
            int p, x;
            std::cin >> p >> x;
            bit.add(G.get_idx(p).first, x);
            bit.add(G.get_idx(p).second, -x);
        } else {
            int u;
            std::cin >> u;
            long long ans = 0;
            G.each_edge(0, u, [&](int l, int r) { ans += bit.sum(l, r); });
            std::cout << ans << '\n';
        }
    }
}