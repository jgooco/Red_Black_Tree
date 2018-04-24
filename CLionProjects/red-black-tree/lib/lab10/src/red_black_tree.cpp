#include "red_black_tree.h"

namespace lab10{
    void rotateleft(Node *&a, Node *&b){
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
}