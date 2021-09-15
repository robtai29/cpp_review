#ifdef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <nodedata.h>

using namespace std;

class BinTree{
    public:

    BinTree();
    BinTree(const BinTree& rhs);
    ~BinTree();

    void operator=(const BinTree& rhs);
    bool operator==(const BinTree& rhs);
    bool operator!=(const BinTree& rhs);


    private:
        NodeData root;




};

#endif