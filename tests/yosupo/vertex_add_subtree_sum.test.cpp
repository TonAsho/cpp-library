#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include <bits/stdc++.h>
#include "../../graph/euler-tour.hpp"
#include "../../data-structure/binary-indexed-tree.hpp"

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int N, Q;
    std::cin >> N >> Q;
    std::vector<long long> A(N);
    for(int i = 0; i < N; ++i) std:: cin >> A[i];
    EulerTour<long long> G(N);
    for(int i = 1; i < N; ++i) {
        int p;
        std::cin >> p;
        G.add_edge(p, i);
    }
    G.build(0);
    BinaryIndexedTree<long long> bit(2 * N);
    for(int i = 0; i < N; ++i) {
        bit.add(G.get_idx(i).first, A[i]);
    }
    while(Q--) {
        int op;
        std::cin >> op;
        if(op == 0) {
            int p, x;
            std::cin >> p >> x;
            bit.add(G.get_idx(p).first, x);
        } else {
            int u;
            std::cin >> u;
            long long ans = 0;
            G.each_vertex_subtree(u, [&](int l, int r) { ans += bit.sum(l, r); });
            std::cout << ans << '\n';
        }
    }
}