#include "Graf.h"
int Node::lastID = 0;
int main() {
	Graph* g = new Graph(5);
	Node n;
	cout << *g;
	addNode(g);
	addEdge(g, 1, 2);
	addEdge(g, 3, 0);
	cout << endl << endl << *g;
	removeNode(g, 2);
	cout << endl<<endl<< *g;
	eraseGraph(g);
	system("PAUSE");
}