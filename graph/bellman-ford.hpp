#pragma once
#include <bits/stdc++.h>
#include "../template/alias.hpp"
#include "./graph-template.hpp"
/**
 * @brief Bellman-Ford
 */
template< typename T >
std::vector<T> bellman_ford(const Edges< T > &edges, int V, int s) {
    std::vector< T > dist(V, INF<T>);
    dist[s] = 0;
    for(int i = 0; i < V - 1; i++) {
        for(auto &e : edges) {
        if(dist[e.from] == INF) continue;
            dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
        }
    }
    for(auto &e : edges) {
        if(dist[e.from] == INF) continue;
        if(dist[e.from] + e.cost < dist[e.to]) return std::vector<T>();
    }
    return dist;
}