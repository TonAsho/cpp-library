#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include <bits/stdc++.h>
#include "data-structure/segment-tree.hpp"

int main(){
    int N,Q;
    std::cin>>N>>Q;
    SegmentTree<Monoid::Min<ll,(1ll<<31)-1>> RMQ(N);
    while(Q--){
        int op,x,y;
        std::cin>>op>>x>>y;
        if(op==1)std::cout<<RMQ.prod(x,y+1)<<std::endl;
        else RMQ.set(x,y); }
}