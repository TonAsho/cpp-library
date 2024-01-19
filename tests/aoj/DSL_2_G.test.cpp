#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G"
#include <bits/stdc++.h>
#include "data-structure/lazy-segment-tree.hpp"

int main(){
    int N,Q;
    std::cin>>N>>Q;
    LazySegmentTree<Monoid::AddSum<ll>> RMQ(N);
    while(Q--){
        int op,x,y,val;
        std::cin>>op>>x>>y;
        if(op==0){
            std::cin>>val;
            RMQ.apply(x-1,y,val);
        }else{
            std::cout<<RMQ.prod(x-1,y)<<std::endl;
        }
    }
}