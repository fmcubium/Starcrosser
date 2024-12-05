#include "Util.h"

// PRIVATE //

bool Util::further(pair<string, double> p1, pair<string, double> p2) {
    return p1.second > p2.second;
}

// PUBLIC //

long long Util::dijkstra(string start, string end, Graph* graph, vector<string>& path, double& minDist) {
    //algorithm implemented with help of pseudocode from Graph Algorithms slides

    //time the algorithm
    auto startTime = chrono::high_resolution_clock::now();

    //cool and useful helper structures
    stack<string> helper;
    unordered_set<string> visited;
    unordered_set<string> notVisited;
    unordered_map<string, double> dist;
    unordered_map<string, string> prev;

    //push everything on the graph into the queue
    dist[start] = 0;
    notVisited.insert(start);
    prev[start] = "";

    for(auto iter = graph->getData().begin(); iter != graph->getData().end(); ++iter) {
        if(iter->first != start) {
            dist[iter->first] = numeric_limits<double>::max();
            notVisited.insert(iter->first);
            prev[iter->first] = "";
        }
    }

    while(!notVisited.empty()) {
        //for all u in notVisited, find the smallest dist[u]
        string minKey = "";
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

        for(pair<string, double>& p : graph->getData()[minKey]) {
            if(notVisited.count(p.first) && dist[p.first] > dist[minKey] + p.second) {
                dist[p.first] = dist[minKey] + p.second;
                prev[p.first] = minKey;
            }
        }

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

long long Util::aStar(string start, string end, Graph* graph, vector<string>& path, double& minDist) {
    //A* algorithm is implemented using pseudocode from https://brilliant.org/wiki/a-star-search/

    //Time the algorithm
    auto startTime = chrono::high_resolution_clock::now();

    //cool helper data structures
    stack<string> helper;
    unordered_map<string, double> gVals;
    unordered_map<string, string> prev;
    unordered_set<string> open;
    unordered_set<string> closed;

    //initialize lists and search - we are guaranteed that each string is unique
    gVals[start] = 0;
    prev[start] = "";
    bool found = false;
    open.insert(start);

    for(auto iter = graph->getData().begin(); iter != graph->getData().end(); ++iter) {
        if(iter->first != start) {
            gVals[iter->first] = numeric_limits<double>::max();
            prev[iter->first] = "";
        }
    }

    while(!(found || open.empty())) {
        //find star w smallest f(n)
        string minKey = "";
        double min = numeric_limits<double>::max();
        for(pair<string, double> p : gVals) {
            if(p.second + graph->distGalactic(p.first, end) < min) {
                min = p.second + graph->distGalactic(p.first, end);
                minKey = p.first;
            }
        }

        if(minKey == end)
            found = true;
        else {
            closed.insert(minKey);
            vector<pair<string, double>> neighbors = graph->getData()[minKey];

            //perform checks
            for(pair<string, double>& neighbor : neighbors) {
                //if a neighbor in closed has a lower g(n) value
                if(gVals[neighbor.first] > gVals[minKey] + neighbor.second && closed.find(neighbor.first) == closed.end()) {
                    gVals[neighbor.first] = gVals[minKey] + neighbor.second;
                    prev[neighbor.first] = minKey;
                    open.insert(neighbor.first);
                }
            }
            open.erase(minKey);
        }
    }

    minDist = gVals[end];

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