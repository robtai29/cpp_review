#include "bintree.h"

// ------------------------------------------------------------------------------------
// prints the tree using inorder traversal
// ------------------------------------------------------------------------------------
ostream & operator << (ostream & output,
    const BinTree & tree) {
}

BinTree::BinTree(): root(nullptr) {}
BinTree::BinTree(const BinTree & rhs) {
    ( * this) = rhs;
}

BinTree::~BinTree() {
    makeEmpty(root);
};

void BinTree::makeEmpty() {
    makeEmptyHelper(root);
}

void BinTree::makeEmptyHelper(Node * & node) {
    if (node == nullptr) {
        return;
    }

    makeEmptyHelper(node -> left);
    makeEmptyHelper(node -> right);

    delete node -> data_;
    node -> data_ = nullptr;

    delete node;
    node = nullptr;
}

BinTree & BinTree::operator = (const BinTree & rhs) {
    if (this == & rhs) {
        return *this;
    }

    makeEmpty();
    recursiveAssignHelper(rhs);
    return *this;
}

void BinTree::recursiveAssignHelper(const BinTree & rhs) {
    recursiveAssign(root, rhs.root);
}

void BinTree::recursiveAssign(Node * & node,
    const Node * rNode) {
    if (rNode == nullptr) {
        node = nullptr;
        return;
    }

    node = new Node {
        new NodeData {
            rNode -> data
        }, nullptr, nullptr
    };
    recursiveAssign(node -> left, rNode -> left);
    recursiveAssign(node -> right, rNode -> right);
}

bool BinTree::isEmpty() const {
    return root == nullptr;
}

bool BinTree::operator == (const BinTree & rhs) const {

    return equalHelper(root, rhs.root);

}

bool BinTree::equalHelper(Node * node, Node * rNode) const {
    if (node == nullptr && rNode == nullptr) {
        return true;
    }

    if (node == nullptr || rNode == nullptr || node -> data_ != rNode -> data_) {
        return false;
    }

    return equalHelper(node -> left, rNode -> left) && equalHelper(node -> right, rNode -> right);
}

bool BinTree::operator != (const BinTree & rhs) {
    return !( * this == rhs);
}

int BinTree::getHeight(const NodeData & toFind) {

    return getHeightHelper(root, toFind);
}

int getHeightHelper(const Node * node,
    const NodeData & toFind) {

    if (node == nullptr) {
        return 0;
    }

    if ( * node -> data_ == toFind) {
        return height(node);
    }

    int left = getHeightHelper(node -> left, toFind);
    int right = getHeightHelper(node -> right, toFind);

    return max(left, right);
}

int height(const Node * node) {
    if (node == nullptr) {
        return 0;
    }

    return 1 + max(height(node -> left), height(node -> right));

}

// --------------------- retrieve -----------------------------------------
// Checks whether or not a NodeData is in a BSTree
// If found returns a pointer to that node
// Uses helper function retrieveHelper
// -----------------------------------------------------------------------

    bool BinTree::retrieve(const NodeData & target, NodeData *& found){
       
       return retrieveHelper(root, target, found);
    }
// --------------------- retrieveHelper -----------------------------------------
// Helper function to retrieve
// ------------------------------------------------------------------------------

    
    bool BinTree::retrieveHelper(Node* node, const NodeData& target, NodeData *& found){

        
        if (node == nullptr){
            found = nullptr;
            return false;
        }
        
        if (*node -> data_ < target){
            
            return retrieveHelper(node -> right, target, found);
            
        }else if (*node -> data_ > target){
            return retrieveHelper(node -> left, target, found);
        }else{
            found = node -> data_;
            return true;
            
        }
        
    }
    
    
    void bstreeToArray(Node* []){
        
        
    }

// BinTree();
// BinTree(const BinTree& rhs);
// ~BinTree();

// void operator=(const BinTree& rhs);
// bool operator==(const BinTree& rhs);
// bool operator!=(const BinTree& rhs);
// bool operator>(const BinTree& rhs);
// bool operator>= (const BinTree& rhs);
// bool operator<= (const BinTree& rhs);
// bool operator< (const BinTree& rhs);

// private:
//     NodeData root;