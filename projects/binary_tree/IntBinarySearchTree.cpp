#include "IntBinarySearchTree.h"

// Copy Constructor
IntBinarySearchTree::IntBinarySearchTree(IntBinarySearchTree& rhs){

    root = new TreeNode;
    copySubTree(root, rhs.root);
}

void IntBinarySearchTree::copySubTree(TreeNode*& root, TreeNode*& rhsNode){
    if (rhsNode == nullptr){
        return;
    }

   root = new TreeNode{rhsNode-> val, nullptr, nullptr};
    
    copySubTree(root-> left, rhsNode-> left);
    copySubTree(root-> right, rhsNode-> right);

}

 IntBinarySearchTree::~IntBinarySearchTree(){
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
    insert(root, val);

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

void IntBinarySearchTree::remove(int val){
    remove(root, val);
}

void IntBinarySearchTree::remove(TreeNode*& node, int val){
    if (node == nullptr){
        return;
    }

    if (val > node-> val){
        remove(node-> right, val);
    }else if (val < node -> val){
        remove(node-> left, val);
    }else{
        //case 1 no children;
        if (isLeaf(node)){
            node = nullptr;
        }else if (node->left == nullptr || node-> right == nullptr ){
            TreeNode* temp = node;
            node = node-> left == nullptr ? node-> right : node -> left;
            delete temp;
        }else{
            //both children are present
            int max = getMax(node-> left);
            node-> val = max;
            remove(node-> left, max);
        }
    }
}

        int IntBinarySearchTree::getMax(TreeNode* node){
            if (node == nullptr){
                throw invalid_argument("Issue with logic in the code");
            }
            int val = node -> val;
            while(node != nullptr){
                val = node -> val;
                node = node -> right;
            }

            return val;

        }

        void IntBinarySearchTree::displayInorder(){
            displayInorder(root);
        }

        void IntBinarySearchTree::displayInorder(TreeNode* node){
            if (node == nullptr){
                return;
            }

            displayInorder(node-> left);
            
            cout << node -> val << " ";

            displayInorder(node -> right);

        }

        void IntBinarySearchTree::displayPreorder(){
            displayPreorder(root);
            
        }

        void IntBinarySearchTree::displayPreorder(TreeNode* node){
            if (node == nullptr){
                return;
            }
            cout << node -> val << " ";
            displayPreorder(node-> left);
            displayPreorder(node -> right);

        }

        void IntBinarySearchTree::displayPostorder(){
            displayPostorder(root);
        }

        void IntBinarySearchTree::displayPostorder(TreeNode* node){
            if (node == nullptr){
                return;
            }
            
            displayPostorder(node-> left);
            displayPostorder(node -> right);
            cout << node -> val << " ";
        }

bool IntBinarySearchTree::isLeaf(TreeNode* node){
    if (node == nullptr){
        return false;
    }

    return node-> left == nullptr && node -> right == nullptr;
}

void IntBinarySearchTree::displaySideways(){
    displaySideways(root);
}

void IntBinarySearchTree::displaySideways(TreeNode* node, string indent){
    if (node == nullptr){
        return;
    }
    
    displaySideways(node -> right, indent + "   ");
    cout << indent << node -> val << '\n';
    displaySideways(node -> left, indent + "   ");
}




int main(){
    IntBinarySearchTree* t1 = new IntBinarySearchTree;
    t1->insert(5);
t1 ->insert(6);
t1 ->insert(3);
t1 -> insert(0);


IntBinarySearchTree t2(*t1);
cout << t2.search(10);
   cout << t2.search(0); 
}