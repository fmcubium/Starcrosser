#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

// Func to clean and extract the star ID and distance
bool parseStarEntry(const string& entry, string& star_id, double& star_dist) {
    // find commma 
    int comma_pos = entry.find(',');
    if (comma_pos == string::npos) return false;

    // get star id
    star_id = entry.substr(0, comma_pos);

    // remove quotes 
    if (!star_id.empty() && star_id.front() == '"') {
        star_id.erase(star_id.begin()); 
    }
    if (!star_id.empty() && star_id.back() == '"') {
        star_id.erase(star_id.end() - 1);
    }

    try {
        star_dist = stod(entry.substr(comma_pos + 1));  //Convert distance to double
    } catch (...) {
        cerr << "Unable to convert distance to double! " << endl;
        return false;  
    }

    return true;
}


void parseStarConnections(const string& filename, map<string, vector<pair<string, double>>>& data) {
    // Open the CSV file
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file " << filename << endl;
    }

    // Read the entire file contents into a string
    stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    // Split the contents by newline to get each line
    string line;
    istringstream line_stream(buffer.str());

    // Skip the first line (header)
    getline(line_stream, line);

    // Process each remaining line
    while (getline(line_stream, line)) {

        istringstream ss(line); // <-- Add entire csv row to stringstream
        string source_id_str, adj_stars; 

        if (getline(ss, source_id_str, ',') && getline(ss, adj_stars)) {
            string source_id = source_id_str;

            // Remove the surrounding braces from the adjacency list
            adj_stars.erase(remove(adj_stars.begin(), adj_stars.end(), '{'), adj_stars.end());
            adj_stars.erase(remove(adj_stars.begin(), adj_stars.end(), '}'), adj_stars.end());

            istringstream ss(adj_stars); // list of adj_stars get added to stream
            string star_entry;
            vector<pair<string, double>> connections;
            connections.reserve(10); // to optimize and save performance so we don't need reallocation

            while (getline(ss, star_entry, '|')) { // read up to "|"
                string star_id;
                double star_value;

                if (parseStarEntry(star_entry, star_id, star_value)) { // <--- parse func
                    connections.push_back({star_id, star_value});
                }
            }
            // Add the source_ID and adj_list to graph
            data[source_id] = move(connections); // move(); helps prevent unecessary copying from connections.
        }
    }
}

// Call Func
void loadGraph(map<string, vector<pair<string, double>>>& graph) {
    try {
        parseStarConnections("starcrosser_ui\\model\\Data\\closest_stars.csv", graph);
    } catch (...) {
        cerr << "Error: Unable to open CSV." << endl;
    }
}

// Main/Test function
/*
int main() {
    map<string, vector<pair<string, double>>> graph;
    loadGraph(graph);
    cout << "Map Size: " << graph.size() << endl;


    return 0;
}
*/
