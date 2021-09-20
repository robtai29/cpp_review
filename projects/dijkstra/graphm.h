/*
Robert Tai
9.25.2021

this project is to implement Dijkstra's shortest path algorithm. Descrition of each
node is 50 chars max length. There can be several graphs, each has at most 100 nodes.
Class includes adjacency matrix, number of nodes, TableType array, and array of
NodeData.

specifications and assumptions:
- it's assumed the user will provide a .txt file with the integer n on first line to
tell how many nodes.
- on n following lines, a description of each node.
- on following lines input sources node, space, destination, space, and final cost
- end input with 0 for the first integer
*/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <fstream>

#include "nodedata.h"

using namespace std;

class GraphM{

    static const int MAXNODES = 101;
    public:
        GraphM();
        ~GraphM();
        void buildGraph(string filename);
        void insertEdge(int, int, int);
        void removeEdge(int, int, int);

    
    private:
        struct TableType
        {
            bool visited;                        // where node has been visited
            int dist;                            // shorstest distance from source
            int prev;                            // previous node in path of min distance
        };
        
        NodeData data[MAXNODES];                // data for graph nodes information
        int cost[MAXNODES][MAXNODES];              // cost array, the adjacency matrix
        int size;                               // number of nodes in the graph
        TableType T[MAXNODES][MAXNODES];
        void makeEmpty();







};


#endif