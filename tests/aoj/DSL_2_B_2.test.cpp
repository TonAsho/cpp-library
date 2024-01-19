#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include <bits/stdc++.h>
#include "data-structure/segment-tree.hpp"

int main(){
    int N,Q;
    std::cin>>N>>Q;
    SegmentTree<Monoid::Sum<ll>> RSQ(N);
    while(Q--){
        int op,x,y;
        std::cin>>op>>x>>y;
        if(op==1)std::cout<<RSQ.prod(x,y+1)<<std::endl;
        else RSQ.apply(x,y); }
}