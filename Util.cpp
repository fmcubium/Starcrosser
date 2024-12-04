#include "Util.h"

// PRIVATE //

bool Util::further(pair<unsigned long, double> p1, pair<unsigned long, double> p2) {
    return p1.second > p2.second;
}


// PUBLIC //

long long Util::dijkstra(unsigned long start, unsigned long end, vector<unsigned long>& path, double& minDist) {
    //algorithm implemented with help of pseudocode from Graph Algorithms slides

    //time the algorithm
    auto startTime = chrono::high_resolution_clock::now();

    //cool and useful helper structures
    stack<unsigned long> helper;
    unordered_set<unsigned long> visited;
    unordered_set<unsigned long> notVisited;
    unordered_map<unsigned long, double> dist;
    unordered_map<unsigned long, unsigned long> prev;

    //push everything on the graph into the queue (uncomment once carson implements loading into the graph)
    dist[start] = 0;
    visited.insert(start);
    prev[start] = -1;

    // for(auto iter = graph.get().begin(); iter != graph.get().end(); iter++) {
    //     if(iter->first != start) {
    //         dist[iter->first] = numeric_limits<unsigned long>::max());
    //         notVisited.insert(iter->first);
    //         prev[iter->first] = -1;
    //     }
    // }

    while(!notVisited.empty()) {
        //for all u in notVisited, find the smallest dist[u]
        unsigned long minKey = 0;
        double min = numeric_limits<double>::max();
        for(unsigned long l : notVisited) {
            if(dist[l] < min) {
                min = dist[l];
                minKey = l;
            }
        }

        //Remove u from notVisited, add to visited
        notVisited.erase(minKey);
        visited.insert(minKey);

        //for all v adjacent to u in notVisited, relax

        // for(pair<unsigned long, int> p : graph) {
        //     if(notVisited.count(p.first) && dist[p.first] > dist[minKey] + p.second) {
        //         dist[p.first] = dist[minKey] + p.second;
        //         prev[p.first] = minKey;
        //     }
        // }

    }

    //backtracking
    minDist = dist[end];

    unsigned long cur = end;
    while(prev[cur] != -1) {
        helper.push(cur);
        cur = prev[cur];
    }
    while(!helper.empty()) {
        path.push_back(helper.top());
        helper.pop();
    }

    auto endTime = chrono::high_resolution_clock::now();
    return endTime.time_since_epoch().count() - startTime.time_since_epoch().count();
}
