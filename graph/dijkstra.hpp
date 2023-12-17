#pragma once
#include <bits/stdc++.h>
#include "../template/alias.hpp"
#include "./graph-template.hpp"
/**
 * @brief Dijkstra
 */
template<typename T>
struct ShortestPath {
    std::vector<T> dist;
    std::vector<int> from, id;
};
template< typename T >
ShortestPath< T > dijkstra(const Graph< T > &g, int s) {
    std::vector< T > dist(g.size(), INF<T>);
    std::vector< int > from(g.size(), -1), id(g.size(), -1);
    using Pi = pair< T, int >;
    priority_queue< Pi, std::vector< Pi >, greater<> > que;
    dist[s] = 0;
    que.emplace(dist[s], s);
    while(!que.empty()) {
        T cost;
        int idx;
        tie(cost, idx) = que.top();
        que.pop();
        if(dist[idx] < cost) continue;
        for(auto &e : g[idx]) {
            auto next_cost = cost + e.cost;
            if(dist[e.to] <= next_cost) continue;
            dist[e.to] = next_cost;
            from[e.to] = idx;
            id[e.to] = e.idx;
            que.emplace(dist[e.to], e.to);
        }
    }
    return {dist, from, id};
}