#include "Util.h"

// PRIVATE //

bool Util::further(pair<string, double> p1, pair<string, double> p2) {
    return p1.second > p2.second;
}


// PUBLIC //

long long Util::dijkstra(string start, string end, vector<string>& path, double& minDist) {
    //algorithm implemented with help of pseudocode from Graph Algorithms slides

    //time the algorithm
    auto startTime = chrono::high_resolution_clock::now();

    //cool and useful helper structures
    stack<string> helper;
    unordered_set<string> visited;
    unordered_set<string> notVisited;
    unordered_map<string, double> dist;
    unordered_map<string, string> prev;

    //push everything on the graph into the queue (uncomment once carson implements loading into the graph)
    dist[start] = 0;
    visited.insert(start);
    prev[start] = "";

    // for(auto iter = graph.get().begin(); iter != graph.get().end(); iter++) {
    //     if(iter->first != start) {
    //         dist[iter->first] = numeric_limits<double>::max());
    //         notVisited.insert(iter->first);
    //         prev[iter->first] = "";
    //     }
    // }

    while(!notVisited.empty()) {
        //for all u in notVisited, find the smallest dist[u]
        string minKey = 0;
        double min = numeric_limits<double>::max();
        for(string l : notVisited) {
            if(dist[l] < min) {
                min = dist[l];
                minKey = l;
            }
        }

        //Remove u from notVisited, add to visited
        notVisited.erase(minKey);
        visited.insert(minKey);

        //for all v adjacent to u in notVisited, relax

        // for(pair<string, int> p : graph) {
        //     if(notVisited.count(p.first) && dist[p.first] > dist[minKey] + p.second) {
        //         dist[p.first] = dist[minKey] + p.second;
        //         prev[p.first] = minKey;
        //     }
        // }

    }

    //backtracking
    minDist = dist[end];

    string cur = end;
    while(prev[cur] != "") {
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
