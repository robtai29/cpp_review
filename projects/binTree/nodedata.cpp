#include "nodedata.h"

NodeData::NodeData() : data("") {}

NodeData::NodeData(string str) : data(str) {}

NodeData::NodeData(const NodeData& rhs){
    (*this) = rhs;
}

NodeData::~NodeData() {};

bool NodeData::setData(istream& infile){
    getline(infile, data);
    
    return infile.eof != true;
}

NodeData& NodeData::operator=(const NodeData& rhs){  // need to check for self assignment
    if (this != &rhs){
        data = rhs.data;
    }
    
    return *this;
}

bool NodeData::operator==(const NodeData& rhs) const{
    return data == rhs.data;
}

bool NodeData::operator!=(const NodeData& rhs) const{
    return !((*this) == rhs);
}

bool NodeData::operator>=(const NodeData& rhs) const{
    return data >= rhs.data;
}

bool NodeData::operator>(const NodeData& rhs) const{
    return data > rhs.data;
}

bool NodeData::operator<=(const NodeData& rhs) const{
    return data <= rhs.data;
}

bool NodeData::operator<(const NodeData& rhs) const{
    return data < rhs.data;
}