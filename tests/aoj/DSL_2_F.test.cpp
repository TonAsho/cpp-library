#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F"
#include <bits/stdc++.h>
#include "data-structure/lazy-segment-tree.hpp"

int main(){
    int N,Q;
    std::cin>>N>>Q;
    LazySegmentTree<Monoid::AssignMin<ll,(1ll<<31)-1>> RMQ(N);
    while(Q--){
        int op,x,y,val;
        std::cin>>op>>x>>y;
        if(op==0){
            std::cin>>val;
            RMQ.apply(x,y+1,val);
        }else{
            std::cout<<RMQ.prod(x,y+1)<<std::endl;
        }
    }
}