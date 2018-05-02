#include "red_black_tree.h"
#include <iostream>


namespace lab10{

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

    void redblacktree::remove(Node* target){
        if(target->right!=NULL&&target->left==NULL){//has only right child
            Node* tmp=target->right;
            target->data=tmp->data;
            target->left=tmp->left;
            target->right=tmp->right;
            target=tmp;
        }else if(target->right==NULL&&target->left!=NULL){//has only right child
            Node* tmp=target->left;
            target->data=tmp->data;
            target->left=tmp->left;
            target->right=tmp->right;
            target=tmp;
        }else if(target->right!=NULL&&target->left!=NULL){//two children
            Node* tmp=target->right;
            while(tmp->left!=NULL){
                tmp=tmp->left;
            }
            target->data=tmp->data;
            target=tmp;
        }
        //target is leaf node or a node with one child
        if(color_is(target)){//if target is red
            if(target)
        }

    }

    // default constructor
    redblacktree::redblacktree()
    {
        root = nullptr;
    }

    bool redblacktree::color_is(Node *src) {
        if(src!=NULL){
            return src->color;
        }else{
            return BLACK;  //NULL as black
        }

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