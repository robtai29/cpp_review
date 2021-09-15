#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
using namespace std;

class NodateData{

    friend ostream& operator<<(ostream&, const NodeData&);
    public:
    
    NodeData();
    NodeData(const NodeData&);
    NodeData(string&);
    ~NodeData();
    NodeData& operator=(const NodeData&);


    bool operator==(const NodeData&);
    bool operator!=(const NodeData&);
    bool operator==(const NodeData&);
    bool operator==(const NodeData&);
    bool operator==(const NodeData&);


    private:
    string data;





};

#endif