#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>
#include "data-structure/union-find.hpp"

int main(){
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