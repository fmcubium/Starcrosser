#pragma once

#include <vector>
#include <map>

using namespace std;

class Graph {
	//These maps will make up our graph
	map<unsigned long, vector<pair<unsigned long, int>>> data;


public:

	//Calculate distance in galactic coordinates
	static float distGalactic(unsigned long s1, unsigned long s2);

	//Default constructor
	Graph();

	//Get adjacent stars based on ID
	vector<unsigned long> getAdjacent(unsigned long id);



};