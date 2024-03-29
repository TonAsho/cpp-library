#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H"
#include <bits/stdc++.h>
#include "data-structure/lazy-segment-tree.hpp"

int main(){
    int N,Q;
    std::cin>>N>>Q;
    LazySegmentTree<Monoid::AddMin<ll>> seg(N,0);
    while(Q--){
        int op,x,y,val;
        std::cin>>op>>x>>y;
        if(op==0){
            std::cin>>val;
            seg.apply(x,y+1,val);
        }else{
            std::cout<<seg.prod(x,y+1)<<std::endl;
        }
    }
}