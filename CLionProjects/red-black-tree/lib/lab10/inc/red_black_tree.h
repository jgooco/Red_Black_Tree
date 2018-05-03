#ifndef CMPE126S18_LABS_LIB_LAB10_NODE_H
#define CMPE126S18_LABS_LIB_LAB10_NODE_H
#define RED true;
#define BLACK false;

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
        Node *root;

        void rotateleft(Node *&a, Node *&b);

        void rotateright(Node *&a, Node *&b);
        void fixviolations(Node *&, Node *&);

    public:
        redblacktree();
        bool color_is(Node* src);
        void insert(int value);
        void remove(Node* target);

        int size();

        void fixviolations(Node *root, Node *ptr);
    };
}

#endif