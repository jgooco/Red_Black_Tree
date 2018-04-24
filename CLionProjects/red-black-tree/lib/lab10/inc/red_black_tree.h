#ifndef CMPE126S18_LABS_LIB_LAB10_NODE_H
#define CMPE126S18_LABS_LIB_LAB10_NODE_H

namespace lab10 {
    struct Node{
        int data;
        bool  color;
        Node *left, *right, *parent;

        Node(int data){
            this->data =data;
            left = right = parent = nullptr;
        }
    };
}

#endif