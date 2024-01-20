#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B"
#include <bits/stdc++.h>
#include "graph/topological-sort.hpp"

int main(){
    int N,M;
    std::cin>>N>>M;
    Graph<int> G(N);
    G.read(M,0,false,true);
    std::vector<int> ans=std::move(TopologicalSort<int>(G).get());
    for(int i = 0; i < ans.size(); ++i) std::cout<<ans[i]<<'\n';
}