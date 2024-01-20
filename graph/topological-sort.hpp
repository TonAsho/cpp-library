#pragma once
#include <bits/stdc++.h>
#include "./graph-template.hpp"
/**
 * @brief Topological Sort
 */
template<typename T>
struct TopologicalSort {
  private:
    int n;
    const Graph<T> &g;
    std::vector<int> ord;
    std::vector<bool> seen;
    void dfs(int v) {
        seen[v] = true;
        for(auto &e : g[v]) if(!seen[e]) dfs(e);
        ord.push_back(v);
    }
    void init() {
        n = g.size();
        seen.assign(n, false);
        ord.reserve(n);
        for(int i = 0; i < n; ++i) if(!seen[i]) dfs(i);
        std::reverse(ord.begin(),ord.end());
    }
  public:
    TopologicalSort(const Graph<T> &g) : g(g) { init(); }
    const std::vector<int> &get() const & { return ord; }
};