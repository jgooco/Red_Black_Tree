#ifndef CMPE126S18_LABS_LIB_LAB10_NODE_H
#define CMPE126S18_LABS_LIB_LAB10_NODE_H

#define RED true;
#define BLACK false;
namespace lab10 {
    struct Node{
        int data;
        bool  color;
        Node *left, *right, *parent;
        int size = 0;

        Node(int data){
            this->data =data;
            left = right = parent = nullptr;
        }
    };

    class redblacktree{
        Node *root;
        int _size;
    protected:
        void rotateleft(Node *&);
        void rotateright(Node *&);

        void fixInsert(Node *&);

    public:
        redblacktree();
        bool color_is(Node* src);
        void insert(int value);

        void color_to_black(Node *newNode);

        void color_to_red(Node *newNode);

        Node *find_key(int key);
        void remove(int key);
        void inOrder();
        void levelOrder();
        int size();
    };
}

#endif