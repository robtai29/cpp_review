#ifndef INTSEARCHBINARYTREE_H
#define INTSEARCHBINARYTREE_H

class IntSearchBinaryTree{

    public:
        IntSearchBinaryTree() : root(nullptr) {}

        // Copy Constructor
        IntSearchBinaryTree(IntSearchBinaryTree*);
        
        // Destructor
        ~IntSearchBinaryTree();

        //Assignment Operator Overload
        IntSearchBinaryTree& operator=(const IntSearchBinaryTree&);

        void insert(int);

        bool search(int);

        void remove(int);


    private:
        struct TreeNode{
            int val;
            TreeNode* left;
            TreeNode* right;
        };

        TreeNode* root;

        void destroyTree(TreeNode* node);

        void copySubTree(TreeNode*&, TreeNode*&);

        void insert(TreeNode*&, int);

        bool search(TreeNode*, int);




};

#endif