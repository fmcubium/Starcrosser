#pragma once

#include <vector>
#include <map>
#include <string>

using namespace std;

class Graph {
	//These maps will make up our graph
	map<string, vector<pair<string, double>>> data;

	static Graph* instance;
	//Private constructor
	Graph();

public:

	//Calculate distance in galactic coordinates
	static float distGalactic(string s1, string s2);

	static void create();

	static Graph* getInstance();

	//Get adjacent stars based on ID
	vector<pair<string, double>> getAdjacent(string id);

	//Get the data from the graph
	map<string, vector<pair<string, double>>> getData();

	//destroy the instance
	static void finalize();

};