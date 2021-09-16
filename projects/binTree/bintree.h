/******************************************************************************

Robert Tai
9.15.2021
Practice Project from UWB CSS 342

to create a binary search tree class called BinTree along with some additional
functions terms

*******************************************************************************/


#ifdef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <nodedata.h>

using namespace std;

class BinTree{
    
    // Overloaded << operator
    friend ostream& operator<<(ostream&, const BinTree&);
    
    private:
       struct Node{
           NodeData* data_;
           Node* left;
           Node* right;
       }
       
       Node* root;
       void sideways(Node*, int) const; // displaySideways() helper
    
    void makeEmpty();                   // make the tree empty so the isEmpty returns true
    void makeEmptyHelper(Node *&);
    bool equalHelper(const BinTree& rhs) const;
    int getHeightHelper(const Node* node, const NodeData & toFind) const;
    void recursiveAssign(Node *&, Node*) const;
    void recursiveAssignHelper(const BinTree &);
    
    string inOrderTraversal(Node* node);
    int height(const Node* node)
    
    
    public:

    BinTree();                    // default constructor
    BinTree(const BinTree &);     // copy constructor
    ~BinTree();                   // destructor
    
    bool isEmpty() const;         // true if the tree is empty, otherwise is false

    BinTree& operator=(const BinTree&);
    bool operator==(const BinTree& rhs);
    bool operator!=(const BinTree& rhs);
    
    int getHeight(const NodeData & toFind) const;
    

    
    bool retrieve(const NodeData &, NodeData *&);    // look for the input, store in the right hand
    void retrieveHelper(Node*, const NodeData&, NodeData *&, bool &);
    
    void bstreeToArray(Node* []);
    



};

#endif