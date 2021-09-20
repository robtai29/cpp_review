#include "graphm.h"

GraphM::GraphM(){
    size = 0;
    for (int row = 0; row < MAXNODES; row++){
        for (int col = 0; col < MAXNODES; col++){
            T[row][col]= {false, INT_MAX, -1};
            cost[row][col] = INT_MAX;
        }

    }

}

GraphM::~GraphM(){
    makeEmpty();
}

GraphM::makeEmpty(){
    for (int i = 0; i < size; i++){
        data[i] = nodeData();
    }
    for (int i = 0; i < MAXNODES; i++){
        for (int j =0; j < MAXNODES; j++){
            cost[i][j] = INT_MAX;
            T[i][j] = {false, INT_MAX, -1};
        }
    }
    size = 0;
}

void insertEdge(int to, int from, int cost_){
    if (to <= 0 || from <= 0 || to > size || from > size){
        throw invalid_argument("invalid number for the edge");
    }
    cost[to][from] = cost_;
}

void removeEdge(int to, int from){
    if (to <= 0 || from <= 0 || to > size || from > size){
        throw invalid_argument("invalid number for the edge");
    }

    costo[to][from] = INT_MAX;
}

void GraphM::buildGraph(string filename){
    ifstream input(filename);
    if (!input){
        cout << "error in opening";
    }

    // input >> size;

    // string str;
    // int count = 0;
    // while(getline(cin, str)){
    //     // if (count < size){
    //     //     data[count] = NodeData(str);
    //     //     count++;
    //     // }

    // }

}

        // NodeData data[MAXNODES];
        // int C[MAXNODES][MAXNODES];
        // int size;
        // TableType T[MAXNODES][MAXNODES];

        // struct TableType{
        //     bool visited;
        //     int dist;
        //     int path
        // };