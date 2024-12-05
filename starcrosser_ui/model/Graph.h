#pragma once

#include <vector>
#include <map>
#include <string>
#include <cmath>

using namespace std;

class Graph {
	//These maps will make up our graph
	map<string, vector<pair<string, double>>> data;
	map<string, vector<double>> attributes;

	static Graph* instance;
	//Private constructor
	Graph();

public:

	//Calculate distance in galactic coordinates
	static double distGalactic(string s1, string s2);

	static void create();

	static Graph* getInstance();

	//Get adjacent stars based on ID
	vector<pair<string, double>> getAdjacent(string id);

	//Get the data from the graph
	map<string, vector<pair<string, double>>> getData();

	//Get Star Attributes
	map<string, vector<double>> getAttributes();

	//destroy the instance
	static void finalize();

};