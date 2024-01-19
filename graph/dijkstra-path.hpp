#pragma once
#include <bits/stdc++.h>
#include "./graph-template.hpp"
/**
 * @brief Dijkstra Path
 */
template<typename T>
std::pair<T, std::vector<int>> dijkstra_path(const Graph<T> &g, int s, int t) {
    const int n = g.size();
    std::vector<T> d(n, INF<T>);
    d[s] = 0;
    std::vector<int> prev(n);
    std::priority_queue<std::pair<T,int>, std::vector<std::pair<T,int>>, std::greater<std::pair<T,int>>> q;
    q.emplace(0, s);
    while(!q.empty()){
        auto [d_u, u] = q.top(); q.pop();
        if(d[u] < d_u)continue;
        for(auto &e : g[u]){
            if(d[e] > d[u] + e.cost){
                d[e] = d[u] + e.cost;
                prev[e] = u;
                q.emplace(d[e], e);
            }
        }
    }
    if(d[t] == INF<T>)return {-1,{}};
    std::vector<int> path;
    path.emplace_back(t);
    while(path.back() != s) path.emplace_back(prev[path.back()]);
    reverse(path.begin(), path.end());
    return {d[t],path};
}