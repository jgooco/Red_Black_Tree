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
        if(a->left == nullptr){
            //do nothing. Nothing to rotate with.
        }
        else{   //if there is a left node to rotate with
            b = a->left;        //set *b to be the node left of a. (we are rotating a to the right.

            if(b->right != nullptr){     //need to move the b->right to the left of a
                a->left = b->right;     //moved to left of a
                b->right->parent = a;       //b->right's new parent is now a
            }
            else if (b->right == nullptr){      //nothing to move
                a->left = nullptr;          //dont think I need... (maybe just do nothing)
            }
            if(a->parent != nullptr){       //if the parent of a exists, we need to change it to be b's parent instead
                b->parent = a->parent;      //b's parent is now a's parent
            }
            if(a->parent == nullptr){       //if a had no parent then that meant a was root
                b = root;               // after rotating right, b is now the new root
            }
            a->parent = b;              //a's new parent is now b since a rotated right
            b->right = a;               //b's right is now a
        }

    }

    void redblacktree::fixviolations(Node *&a, Node *&b) // fixes any violation from insert
    {

    }

    int redblacktree::size() {
        return root->size;
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