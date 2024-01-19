#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
#include "data-structure/segment-tree.hpp"

int main(){
    int N,Q;
    std::cin>>N>>Q;
    std::vector<ll> A(N);
    for(int i=0;i<N;++i)std::cin>>A[i];
    SegmentTree<Monoid::Sum<ll>> RSQ(A);
    while(Q--){
        int op,x,y;
        std::cin>>op>>x>>y;
        if(op==1)std::cout<<RSQ.prod(x,y)<<std::endl;
        else RSQ.apply(x,y);
    }
}