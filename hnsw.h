#ifndef HNSW_H
#define HNSW_H

#include <random>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct Item {
	Item(vector<double> _values):values(_values) {}
	vector<double> values;
	// Assume L2 distance
	double dist(Item& other) {
		double result = 0.0;
		for (int i = 0; i < values.size(); i++) result += (values[i] - other.values[i]) * (values[i] - other.values[i]);
		return result;
	}
};

struct HNSWGraph {
	HNSWGraph(int _M, int _MMax, int _MMax0, int _efConstruction, int _ml):M(_M),MMax(_MMax),MMax0(_MMax0),efConstruction(_efConstruction),ml(_ml){
		layerEdgeLists.push_back(unordered_map<int, vector<int>>());
	}
	
	// Number of neighbors
	int M;
	// Max number of neighbors in layers >= 1
	int MMax;
	// Max number of neighbors in layers 0
	int MMax0;
	// Search numbers in construction
	int efConstruction;
	// Max number of layers
	int ml;

	// number of items
	int itemNum;
	// actual vector of the items
	vector<Item> items;
	// adjacent edge lists in each layer
	vector<unordered_map<int, vector<int>>> layerEdgeLists;
	// enter node id
	int enterNode;

	default_random_engine generator;

	// methods
	void addEdge(int st, int ed, int lc);
	vector<int> searchLayer(Item& q, int ep, int ef, int lc);
	void Insert(Item& q);
	vector<int> KNNSearch(Item& q, int K);

	void printGraph() {
		for (int l = 0; l < layerEdgeLists.size(); l++) {
			cout << "Layer:" << l << endl;
			for (auto it = layerEdgeLists[l].begin(); it != layerEdgeLists[l].end(); ++it) {
				cout << it->first << ":";
				for (auto ed: it->second) cout << ed << " ";
				cout << endl;
			}
		}
	}
};

#endif