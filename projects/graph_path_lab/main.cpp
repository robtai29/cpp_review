#include "graph.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	graph<int> graph1;
	cout << "hello world" << endl;
	graph1.add_vertex(0);
	graph1.add_vertex(1);
	graph1.add_vertex(2);
	graph1.add_vertex(3);
	graph1.add_vertex(4);
	graph1.add_vertex(5);

	graph1.add_edge(0, 1);
	graph1.add_edge(1, 2);
	graph1.add_edge(2, 3);
	graph1.add_edge(2, 4);
	graph1.add_edge(4, 5);
	graph1.add_edge(5, 0);
	graph1.add_edge(3, 1);

	graph1.printPaths(0);
}