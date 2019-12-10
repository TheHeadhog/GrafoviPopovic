#include "Graf.h"

Graph::Graph(int n)
{
	Nodes = new Node[n + 1];
	//Edges = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		Nodes[i].eIndex = 0;
	}
	//Dodat je cvor koji sluzi kao provera poslednje ivice
	//Edges[n] = -1;
	Size = n + 1;
}


void Node::operator=(Node& n2)
{
	ID = n2.ID;
	eIndex = n2.eIndex;
	visited = n2.visited;
}

void addEdge(Graph* g, int a, int b)
{
	if (a > b) swap(a, b);
	int ind1 = g->Nodes[a + 1].eIndex;
	int ind2 = g->Nodes[b + 1].eIndex;
	int* newEdge = new int[g->eSize + 2];
	int i = 0;
	while (i < ind1)
	{
		newEdge[i] = g->Edges[i];
		i++;
	}
	newEdge[i] = b;
	i++;
	while (i < ind2+1)
	{
		newEdge[i] = g->Edges[i - 1];
		i++;
	}
	newEdge[i] = a;
	i++;
	while (i < g->eSize + 2)
	{
		newEdge[i] = g->Edges[i - 2];
		i++;
	}
	g->Edges = newEdge;
	g->eSize = g->eSize + 2;
	for (int j = 0; j < g->Size; j++)
	{
		if (j > a) g->Nodes[j].eIndex++;
		if (j > b)g->Nodes[j].eIndex++;
	}
}

void removeEdge(Graph* g, int a, int b)
{
	if (a > b) swap(a, b);
	int ind1 = g->Nodes[a].eIndex;
	int ind2 = g->Nodes[b].eIndex;
	int* newEdge = new int[g->eSize -2];
	int i = 0;
	while (i < ind1)
	{
		newEdge[i] = g->Edges[i];
		i++;
	}
	while (1)
	{
		if (g->Edges[i] == a) { break; }
		else {
			newEdge[i] = g->Edges[i];
			i++;
		}
	}
	while (i < ind2 -1)
	{
		newEdge[i] = g->Edges[i + 1];
		i++;
	}
	while (1)
	{
		if (g->Edges[i] == a) { break; }
		else {
			newEdge[i] = g->Edges[i+1];
			i++;
		}
	}
	while (i < g->eSize - 2)
	{
		newEdge[i] = g->Edges[i + 2];
		i++;
	}
	g->Edges = newEdge;
	g->eSize = g->eSize - 2;
	for (int j = 0; j < g->Size; j++)
	{
		if (j > a) g->Nodes[j].eIndex--;
		if (j > b)g->Nodes[j].eIndex--;
	}
}

void removeNode(Graph* g, int a)
{
	int offset = g->Nodes[a + 1].eIndex - g->Nodes[a].eIndex;
	int start = g->Nodes[a].eIndex;
	int mini = 0;
	Node* newNode = new Node[g->Size - 1];
	for (int i = 0; i < g->Size - 1; i++) {
		if (i < a) newNode[i] = g->Nodes[i];
		else {
			newNode[i] = g->Nodes[i + 1];
			newNode[i].eIndex -= offset;
		}
	}
	int* newEdge = new int[g->eSize - offset];
	for (int i = 0; i < g->eSize - 1; i++) {
		if (g->Edges[i] == a) { mini++; }
		if (i < a) newEdge[i] = g->Edges[mini+i];
		else newEdge[i] = g->Edges[mini + i + offset];
	}
	g->Edges = newEdge;
	g->Nodes = newNode;
	g->eSize = g->eSize - offset-mini;
	g->Size = g->Size - 1;
}

void addNode(Graph* g)
{
	Node* newNode = new Node[g->Size +1];
	for (int i = 0; i < g->Size ; i++) {
		newNode[i] = g->Nodes[i]; 
		Node::lastID--;
	}
	newNode[g->Size].ID = Node::lastID;
	newNode[g->Size-1].eIndex = newNode[g->Size - 2].eIndex;
	g->Nodes = newNode;
	g->Size++;
}

ostream& operator<<(ostream& os, Graph& g)
{
	for (int i = 0; i < g.Size-1; i++)
	{
		os << "Cvor " << g.Nodes[i].ID << " | Susedi: ";
		int j = 0;
		for (j; j < g.Nodes[i+1].eIndex-g.Nodes[i].eIndex; j++)
		{
			os << " " << g.Edges[g.Nodes[i].eIndex+j];
		}
		os << endl;
	}
	return os;
}
