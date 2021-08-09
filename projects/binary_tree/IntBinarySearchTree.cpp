#include "IntBinarySearchTree"

void IntBinarySearchTree: copySubTree(TreeNode*& root, TreeNode*& rhsNode){
    if (rhsNode == nullptr){
        return;
    }

    root = new TreeNode;
    root-> val = rhsNode -> val;
    copySubTree(root-> left, rhsNode-> left);
    copySubTree(root-> right, rhsNode-> right);

}

void IntBinarySearchTree::~BinarySearchTree(){
    destroySubTree(root);
}

void IntBinarySearchTree::destroySubTree(TreeNode* node){
    if (node == nullptr){
        return;
    }

    destroySubTree(node-> left);
    destroySubTree(node-> right);
    delete node;
}

void IntBinarySearchTree::insert(int val){
    search(root, val);

}

void IntBinarySearchTree::insert(TreeNode*& node, int val){
    if (node == nullptr){
        node = new TreeNode{val, nullptr, nullptr};
    }else if (val > node -> val){
        insert(node -> right, val);
    }else if (val < node -> val){
        insert(node -> left, val);
    }
}

bool IntBinarySearchTree::search(int val){
    return search(root, val);
}

bool IntBinarySearchTree::search(TreeNode* node, int val){
    if (node == nullptr){
        return false;
    }

    if (node-> val == val){
        return true;
    }else if (val > node -> val){
        return search(node -> right, val);
    }else{
        return search(node -> left, val);
    }
}

