#include "red_black_tree.h"
#include "iostream"

namespace lab10{
//test
    // AUXILIARY FUNCTION
    void inOrder_traversal(Node *top);// recurse function that will level order tranversal;

    void insert_recurse(Node *top, int value);

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
        a = b->left;
        b->left = a->right;
        a->right = b;
        a->red = a->right->red;
        a->right->red;

    }

    void redblacktree::fixviolations(Node *&a, Node *&b) // fixes any violation from insert
    {

    }

    void redblacktree::insert(int value)//inserts a node into red black tree
    {
        if (root == nullptr) {
            root = new Node(value);
        } else {
            insert_recurse(root, value);
        }

    }

    void insert_recurse(Node *top, int value) {
        if (value > top->data) {
            if (top->right == nullptr) top->right = new Node(value);
            else insert_recurse(top->right, value);
        } else if (value < top->data) {
            if (top->left == nullptr) top->left = new Node(value);
            else insert_recurse(top->left, value);
        } else if (value == top->data) top->size++;
    }

    void redblacktree::remove(Node x){

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