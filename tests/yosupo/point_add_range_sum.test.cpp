#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
#include "../../data-structure/binary-indexed-tree.hpp"

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int N, Q;
    std::cin >> N >> Q;
    std::vector<long long> A(N);
    for(int i = 0; i < N; ++i) std::cin >> A[i];
    BinaryIndexedTree<long long> bit(A);
    while(Q--) {
        int t, x, y;
        std::cin >> t >> x >> y;
        if(t == 0) {
            bit.add(x, y);
        } else {
            std::cout << bit.sum(x, y) << std::endl;
        }
    }
}