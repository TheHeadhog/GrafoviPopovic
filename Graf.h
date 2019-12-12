#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Uzima se da indeksiranje pocinje od 0//

struct Node {
	bool visited = false;
	static int lastID;
	int ID = lastID++;
	void operator=(Node& n2);
	int eIndex;
};
class Graph {
public:
	//Node* getNodes() { return Nodes; }
	int* getEdges() { return Edges; }
	int getSize() { return Size; }
	int geteSize() { return eSize; }
	Graph(int n);
	friend void addEdge(Graph* g, int a, int b);
	friend void removeEdge(Graph* g, int a, int b);
	friend void removeNode(Graph* g, int a);
	friend void addNode(Graph* g);
	friend ostream& operator<<(ostream& os, Graph& g);
	friend void eraseGraph(Graph* g) {
		delete g->Nodes;
		delete g->Edges;
		delete g;
	}
private:
	int* Edges;
	Node* Nodes;
	int Size;
	int eSize;
};