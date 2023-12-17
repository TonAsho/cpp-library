#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
#include <bits/stdc++.h>
#include "../../data-structure/binary-indexed-tree.hpp"

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int N, Q;
    std::cin >> N >> Q;
    BinaryIndexedTree<long long> bit(N + 1);
    while(Q--) {
        int t, x, y;
        std::cin >> t >> x >> y;
        if(t == 0) {
            bit.add(x, y);
        } else {
            std::cout << bit.sum(x, y + 1) << std::endl;
        }
    }
}