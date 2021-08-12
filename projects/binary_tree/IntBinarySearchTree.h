#ifndef INTSEARCHBINARYTREE_H
#define INTSEARCHBINARYTREE_H
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class IntBinarySearchTree{

    public:
        IntBinarySearchTree() : root(nullptr) {}

        // Copy Constructor
        IntBinarySearchTree(IntBinarySearchTree&);
        
        // Destructor
        ~IntBinarySearchTree();


        //Assignment Operator Overload
        IntBinarySearchTree& operator=(const IntBinarySearchTree&);

        void insert(int);

        bool search(int);

        void displayInorder();

        void displayPreorder();

        void displayPostorder();

        void remove(int);

        void displaySideways();



    private:
        struct TreeNode{
            int val;
            TreeNode* left;
            TreeNode* right;
        };

        TreeNode* root;

        void destroySubTree(TreeNode* node);

        void copySubTree(TreeNode*&, TreeNode*&);

        void insert(TreeNode*&, int);

        bool search(TreeNode*, int);

       void remove(TreeNode*&, int);

        bool isLeaf(TreeNode*);


        void displayInorder(TreeNode*);

        void displayPreorder(TreeNode*);

        void displayPostorder(TreeNode*);

        int getMax(TreeNode*);

        void displaySideways(TreeNode*, string = "");

};

#endif