#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#include <bits/stdc++.h>
#include "data-structure/union-find.hpp"

int main() {
    int N,Q;
    std::cin>>N>>Q;
    UnionFind uni(N);
    while(Q--){
        int op,x,y;
        std::cin>>op>>x>>y;
        if(op==0)uni.unite(x,y);
        else std::cout<<uni.same(x,y)<<std::endl;
    }
}