#ifndef CMPE126S18_LABS_LIB_LAB10_NODE_H
#define CMPE126S18_LABS_LIB_LAB10_NODE_H

namespace lab10 {
    struct Node{
        int data;
        bool  color;
        int  size = 0;
        Node *left, *right, *parent;

        Node(int data){
            this->data =data;
            left = right = parent = nullptr;
        }
    };

    class redblacktree{
    private:
        Node *root;
    protected:
        void rotateleft(Node *&, Node *&);
        void rotateright(Node *&, Node *&);
        void fixviolations(Node *&, Node *&);
    public:
        redblacktree();
        void insert(Node *top, int value);
        void inorder();
        void levelorder();
        void remove(Node x);
    };
}
//dhnkghnuisrhnuitbkldnklk

#endif