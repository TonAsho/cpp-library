#pragma once
#include <bits/stdc++.h>
#include "./graph-template.hpp"
/**
 * @brief Dijkstra
 */
template<typename T>
std::vector<T> dijkstra(const Graph<T> &g, int s) {
    const int n = g.size();
    std::vector<T> d(n, INF<T>);
    d[s] = 0;
    std::priority_queue<std::pair<T,int>, std::vector<std::pair<T,int>>, std::greater<std::pair<T,int>>> q;
    q.emplace(0, s);
    while(!q.empty()){
        auto [d_u, u] = q.top(); q.pop();
        if(d[u] < d_u)continue;
        for(auto &e : g[u]){
            if(d[e] > d[u] + e.cost){
                d[e] = d[u] + e.cost;
                q.emplace(d[e], e);
            }
        }
    }
    return d;
}