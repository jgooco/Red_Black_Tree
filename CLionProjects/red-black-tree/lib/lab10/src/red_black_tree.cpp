#include "red_black_tree.h"
#include <iostream>


namespace lab10{

    // AUXILIARY FUNCTION
    void inOrder_traversal(Node *top);// recurse function that will level order tranversal;

    void insert_recurse(Node *top, int value);


    void redblacktree::rotateleft(Node *&a, Node *&b){
        if(a->right == nullptr){
            //do nothing because you cant rotate with nothing.
        }
        else{
            b = a->right;      //there is something to the left to rotate with

            if(b->left != nullptr){    //a node exists left of b
                a->right = b->left;    //so we make that node to be the right of a
                b->left->parent = a;   //and that b->left node's new parent is now a
            }
            else if (b->left == nullptr){      //if there is no node left of b
                a->right = nullptr;            //then right of a will be empty
            }
            if(a->parent != nullptr){           //if a parent of a exists
                if(a == a->parent->right) {      //if a was to the left of that parent
                    a->parent->right = b;       //b will be to the right of that parent
                }
                else{       //not to the right of that parent, so must be left
                    a->parent->left = b;        //left of that parent will now be b
                }
                b->parent = a->parent;          //and the new parent to b will be a's parent
            }
            if(a->parent == nullptr){      //is a does not have a parent, then that means a is the root
                b = root;                   //therefore after rotating left, b will be the new root
            }
            a->parent = b;         //after rotating, set a's new parent to be b
            b->left = a;           //and b's left is now a
        }
    }

    void redblacktree::rotateright(Node *&a, Node *&b)
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
                a->left = nullptr;          //don't think I need... (maybe just do nothing)
            }
            if(a->parent != nullptr){       //if the parent of a exists, we need to change it to be b's parent instead
                if(a == a->parent->right) {      //if a was to the left of that parent
                    a->parent->right = b;       //b will be to the right of that parent
                }
                else{       //not to the right of that parent, so must be left
                    a->parent->left = b;        //left of that parent will now be b
                }
                b->parent = a->parent;          //and the new parent to b will be a's parent
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
        Node *temp = new Node(value);       //temp is the node we are inserting with the value in it
        temp->color = RED;                  //always inserting new node as red

        if (root == nullptr)        //tree is empty
        {
            root = temp;            //so the new node we are inserting will be the root
        }
        else                        //if tree is not empty
        {
            insert_recurse(root, value);        //recursion to insert node at appropriate place
            Node *grandparent = temp->parent->parent;       //set grandparent node of temp

            if(temp->parent != nullptr && temp->parent->color == 'RED')     //only go through this if-statement if parent of temp is red
            {
                Node *uncle;                            //set uncle node to temp
                if(grandparent->left == temp->parent)   //if temp's parent is to the left of temp's grandparent
                {
                    uncle = grandparent->right;         //uncle has to be to the right of the grandparent
                    if(uncle != nullptr)                //if uncle exists
                    {
                        grandparent->color = RED;       //grandparent is red b/c temp is red and in RB-tree, the red and black alternate. Meaning grandparent and grandchild are always the same color
                        temp->parent = BLACK;           //set the parent of temp to black since there cannot be two adjacent red node (b/c temp is red)
                        uncle->color = temp->parent->color;     //uncle is always the same color are temp's parent
                    }
                }
                else if(grandparent->right == temp->parent)     //if temp's parent was to the right of grandparent instead
                {
                    uncle = grandparent->left;      //uncle has to be the other side of parent, meaning left of grandparent in this case
                    if(uncle != nullptr)            //if uncle exists
                    {
                        grandparent->color = RED;       //grandparent is same color as temp b/c colors in tree is suppose to alternate
                        temp->parent = BLACK;           //cannot have two adjacent red nodes, and temp is red, so parent needs to change to black
                        uncle->color = temp->parent->color;     //uncle is same color as parent
                    }
                }
                else            //if there is no grandparent
                {
                    temp->parent = root;            //parent is root if there is no parent to the parent
                }
            }
        }
        root->color = BLACK;            //ROOT MUST ALWAYS BE BLACK
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
        if(target->right!=NULL&&target->left!=NULL){//two children
            Node* tmp=target->right;
            while(tmp->left!=NULL){
                tmp=tmp->left;
            }//tmp is the successor
            target->data=tmp->data;
            target=tmp;
        }
        //target is leaf node or a node with one child


        if(color_is(target)){//if target is red,and only have one or no child
            target->color=BLACK;
            if(target->right!=NULL){
                Node* tmp=target->right;
                target->data=tmp->data;
                target->left=tmp->left;
                target->right=tmp->right;
                target=tmp;
            }else if(target->left!=NULL){
                Node* tmp=target->left;
                target->data=tmp->data;
                target->left=tmp->left;
                target->right=tmp->right;
                target=tmp;
            }else if(target->parent!=NULL){//no child but have parent
                if(target->parent->left==target){
                    target->parent->left=NULL;
                }else if(target->parent->right==target){
                    target->parent->right=NULL;
                }else{
                    throw "Structure error: cant find child in parent pointer";
                }
            }
        }else{//target is black
            if(color_is(target->left)||color_is(target->right)){// target have a red child
                if(target->right!=NULL){
                    Node* tmp=target->right;
                    target->data=tmp->data;
                    target->left=tmp->left;
                    target->right=tmp->right;
                    target=tmp;
                }else if(target->left!=NULL){
                    Node* tmp=target->left;
                    target->data=tmp->data;
                    target->left=tmp->left;
                    target->right=tmp->right;
                    target=tmp;
                }
            }else{//target have a black child or have no child: double black
                if(target->parent!=NULL){//target is not root
                    if(target==target->parent->right){//sibling at left
                        if(target->left==NULL)
                            throw "Structure error: double black node don't have sibling";
                        if(!target->left->color) {//sibling is black
                        }
                    }else if(target==target->parent->left){//sibling at right
                        if(target->parent->right==NULL)
                            throw "Structure error: double black node don't have sibling";
                        if(!target->parent->right->color){//sibling is black
                            if(color_is(target->parent->right->right)){//rr case:do rotation
                                target->data=target->parent->data;
                                target->parent->data=target->parent->right->data;
                                if(target->right!=NULL)
                                    target->left = target->right;
                                target->right=target->parent->right->left;
                                target->right->parent=target;
                                target=target->parent->right;//delete target at the very end
                                target->parent->right=target->parent->right->right;
                                target->parent->right->parent=target->parent;
                            }else if(color_is(target->parent->right->left)){//rl case

                            }
                        }
                    }else
                        throw "Structure error: cant find child in parent pointer";
                }
            }
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