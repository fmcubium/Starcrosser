#include "Graph.h"
#include "Data/load.h"

// constructor impl

Graph::Graph() {
	//load up all the vertices from the data
	loadGraph(data);
	parseAttributes(attributes);
}

double Graph::distGalactic(string s1, string s2) {
	vector<double> p1 = Graph::getInstance()->getAttributes()[s1];
	vector<double> p2 = Graph::getInstance()->getAttributes()[s2];

	/*
	  l (galactic longitude) = p1[0]
	  b (galactic latitude) = p1[1]
	  r_dist (spectro distance) = p1[2]
	*/
	double dist = sqrt(p1[2]*p1[2] + p2[2]*p2[2] - 2*p1[2]*p2[2]*cos(p1[1]-p2[1])
		- 2*p1[2]*p2[2]*sin(p1[1]-p2[1])*(cos(p1[0]-p2[0])-1));
	return dist;
}

void Graph::create() {
	if(instance == nullptr)
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


map<string, vector<double>> Graph::getAttributes(){
	return attributes;	
}


void Graph::finalize() {
	delete instance;
}
