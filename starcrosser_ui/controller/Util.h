#pragma once

#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <chrono>
#include <limits>

#include "../model/Graph.h"

using namespace std;

class Util {
    //Make class non-instantiable
    Util() {}
    static bool further(pair<string, double> p1, pair<string, double> p2);

public:

    //Runs Dijkstra's Algorithm, putting the path in order in the vector and returning the time it took to run
    static long long dijkstra(string start, string end, vector<string>& path, double& minDist);

    //Runs the A* Algorithm, putting the path in order in the vector and returning the time it took to run
    static long long aStar(string start, string end, vector<string>& path, double& minDist);
};

