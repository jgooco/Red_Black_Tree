#include "red_black_tree.h"
#include "iostream"

namespace lab10{

    // AUXILIARY FUNCTION
    void inOrder_traversal(Node *top){};// recurse function that will level order tranversal;

    void rotateleft(Node *&a, Node *&b){//rotates nodes to the left when "uncle" node is black
        Node *b_right = b->right;
        b->right = b_right->left;
        if(b_right != nullptr)
            b->right->parent = b;
        b_right->parent = b->parent;
        if(b->parent == nullptr)
            a = b_right;
        else if(b == b->parent->left)
            b->parent->left = b_right;
        else
            b->parent->right = b_right;
        b_right->left = b;
        b->parent= b_right;
    }

    void rotateright(Node *&a, Node *&b)//rotates nodes to the right when "uncle" node is black
    {

    }

    void redblacktree::fixviolations(Node *&a, Node *&b)
    {

    }

    void redblacktree::insert(const int &n)//inserts a node into red black tree
    {

    }

    // default constructor
    redblacktree::redblacktree()
    {
        root = nullptr;
    }

    // prints tree elements by traversing inorder(?)
    void redblacktree::inorder()
    {
        inOrder_traversal(root); // calls aux function
    }

    // AUXILIARY FUNCTION
    void inOrder_traversal(Node *top)
    {
        if (top == nullptr)
        {
            return;
        }
        inOrder_traversal(top->left);
        std::cout << top->data << std::endl;
        inOrder_traversal(top->right);
    }

}