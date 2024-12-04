#include "Graph.h"
#include "Data/load.h"

// constructor impl

Graph::Graph() {
	//load up all the vertices from the data
	loadGraph(data);
}

float Graph::distGalactic(string s1, string s2) {

}

void Graph::create() {
	instance = new Graph();
}

Graph *Graph::getInstance() {
	if(instance == nullptr)
		return nullptr;
	return instance;
}

vector<pair<string, double>> Graph::getAdjacent(string id) {
	if(data.find(id) == data.end())
		return {};

	return data[id];
}

map<string, vector<pair<string, double>>> Graph::getData() {
	return data;
}

void Graph::finalize() {
	delete instance;
}
