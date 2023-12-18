#pragma once
#include <bits/stdc++.h>
#include "./graph-template.hpp"
/**
 * @brief Dijkstra
 */
template< typename T >
struct Dijkstra : Graph<T> {
  private:
    using P = std::pair<T, int>;
    const T MAX = std::numeric_limits<T>::max() / 2;
    int from;
    std::vector<T> d, prev;
  public:
    using Graph<T>::g;
    Dijkstra(int n) : Graph<T>(n) {}
    void build(int from) {
        this->from = from;
        d.assign(g.size(), MAX);
        prev.assign(g.size(), 0);
        d[from] = 0;
        std::priority_queue<P, std::vector<P>, std::greater<P>> q;
        q.emplace(0, from);
        while(!q.empty()) {
            auto [d_u, u] = q.top(); q.pop();
            if(d[u] < d_u) continue;
            for(auto &e : g[u]) {
                if(d[e] > d[u] + e.cost) {
                    d[e] = d[u] + e.cost;
                    prev[e] = u;
                    q.emplace(d[e], e);
                }
            }
        }
    }
    T dist(int to) {
        assert(0 <= to && to < (int)d.size());
        return d[to];
    }
    std::vector<int> path(int to) {
        assert(0 <= to && to < (int)d.size());
        if(d[to] == MAX) return {};
        std::vector<int> path = {to};
        while(path.back() != from) path.emplace_back(prev[path.back()]);
        reverse(path.begin(), path.end());
        return path;
    }
};