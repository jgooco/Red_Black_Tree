#include "red_black_tree.h"
#include <iostream>


namespace lab10{

    // AUXILIARY FUNCTION
    void inOrder_traversal(Node *top);// recurse function that will level order tranversal;

    void insert_recurse(Node *top, int value);


    void redblacktree::rotateleft(Node *&a){

        /*       //rotates nodes to the left when "uncle" node is black
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
     */

        Node *b;
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

    void redblacktree::rotateright(Node *&a)
    {
        Node *b;
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
                    if(uncle->color == 'RED'){
                        temp->parent->color = BLACK;           //set the parent of temp to black since there cannot be two adjacent red node (b/c temp is red)
                        uncle->color = temp->parent->color;     //uncle is always the same color are temp's parent
                        grandparent->color = RED;       //grandparent is red b/c temp is red and in RB-tree, the red and black alternate. Meaning grandparent and grandchild are always the same color
                    }
                    else{       //if uncle is black
                        if(temp->parent->right = temp){
                            rotateleft(temp->parent);
                        }
                        temp->parent->color = BLACK;           //set the parent of temp to black since there cannot be two adjacent red node (b/c temp is red)
                        grandparent->color = RED;       //grandparent is red b/c temp is red and in RB-tree, the red and black alternate. Meaning grandparent and grandchild are always the same color
                        rotateright(grandparent);
                    }
                }
                else if(grandparent->right == temp->parent)     //if temp's parent was to the right of grandparent instead
                {
                    uncle = grandparent->left;      //uncle has to be the other side of parent, meaning left of grandparent in this case
                    if(uncle->color == 'RED'){
                        temp->parent->color = BLACK;           //set the parent of temp to black since there cannot be two adjacent red node (b/c temp is red)
                        uncle->color = temp->parent->color;     //uncle is always the same color are temp's parent
                        grandparent->color = RED;       //grandparent is red b/c temp is red and in RB-tree, the red and black alternate. Meaning grandparent and grandchild are always the same color
                    }
                    else{       //if uncle is black
                        if(temp->parent->left = temp){
                            rotateright(temp->parent);
                        }
                        temp->parent->color = BLACK;           //set the parent of temp to black since there cannot be two adjacent red node (b/c temp is red)
                        grandparent->color = RED;       //grandparent is red b/c temp is red and in RB-tree, the red and black alternate. Meaning grandparent and grandchild are always the same color
                        rotateleft(grandparent);
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

    Node* LL_rotation(Node * target){//auxiliary function
        target->data=target->parent->data;
        target->parent->data=target->parent->left->data;
        if(target->left!=NULL)
            target->right = target->left;
        target->left=target->parent->left->right;
        if(target->left!=NULL)
            target->left->parent=target;
        target=target->parent->left;//delete target at the very end
        target->parent->left=target->left;
        target->left->parent=target->parent;
        target->left->color=BLACK;
        return target;
    }
    Node* LR_rotation(Node * target) {//auxiliary function
        //first rotation: to a ll case
        Node* LR=target->parent->left->right;
        target->parent->left->right=LR->left;
        LR->left=target->parent->left;
        LR->left->parent=LR;
        target->parent->left=LR;
        LR->parent=target->parent;

        //Second rotation
        return LL_rotation(target);
    }
    Node* RR_rotation(Node * target) {//auxiliary function
        target->data=target->parent->data;
        target->parent->data=target->parent->right->data;
        if(target->right!=NULL)
            target->left = target->right;
        target->right=target->parent->right->left;
        if(target->right!=NULL)
            target->right->parent=target;
        target=target->parent->right;//delete target at the very end
        target->parent->right=target->right;
        target->right->parent=target->parent;
        target->right->color=BLACK;
        return target;
    }
    Node* RL_rotation(Node * target) {//auxiliary function
        //first rotation: to a rr case
        Node* RL=target->parent->right->left;
        target->parent->right->left=RL->right;
        RL->right=target->parent->right;
        RL->right->parent=RL;
        target->parent->right=RL;
        RL->parent=target->parent;

        //Second rotation
        return RR_rotation(target);
    }
    void _Bsibling_Bchildren(Node *double_black){//recursive auxiliary function
        if(double_black->parent!=NULL){
            if(!double_black->parent->color){//parent is black
                _Bsibling_Bchildren(double_black->parent);
            }else{//parent is red
                double_black->parent->color=BLACK;
            }
            //make sibling red
            if(double_black->parent->left==double_black){//sibling at right
                double_black->parent->right->color=RED;
            }else if(double_black->parent->right==double_black){//sibling at left
                double_black->parent->left->color=RED;
            }else
                throw "Structure error: cant find child in parent pointer";
        }
    }
    Node* redblacktree::find_key(int key){
        Node* RT=root;
        while(RT!=NULL){
            if(key<RT->data){
                RT=RT->left;
            }else if(key>RT->data){
                RT=RT->right;
            } else
                return RT;
        }
        return NULL;
    }
    void redblacktree::remove(int key){
        Node* target=find_key(key);
        if(target==NULL)
            throw "Key not found";
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
                        if(target->parent->left->color){//sibling is red: convert to case b or a
                            target->parent->left->parent=target->parent->parent;
                            if(target->parent->parent!=NULL){
                                if(target->parent->parent->left==target->parent)
                                    target->parent->parent->left=target->parent->left;
                                else if(target->parent->parent->right==target->parent)
                                    target->parent->parent->right=target->parent->left;
                                else
                                    throw "Structure error: cant find child in parent pointer";
                            }
                            target->parent->parent=target->parent->left;
                            target->parent->left=target->parent->left->right;
                            target->parent->left->parent=target->parent;
                            target->parent->parent->right=target->parent;
                        }
                        if(!target->parent->left->color) {//sibling is black
                            if(color_is(target->parent->left->left)){//ll case:do rotation
                                target=LL_rotation(target);
                            }else if(color_is(target->parent->left->right)){//lr case
                                target=LR_rotation(target);
                            }else{//black sibling at left and have both black children
                                _Bsibling_Bchildren(target);
                                if(target->right!=NULL) {
                                    target->parent->right = target->right;
                                    target->right->parent=target->parent;
                                }
                                else if(target->left!=NULL) {
                                    target->parent->right = target->left;
                                    target->left->parent=target->parent;
                                } else
                                    target->parent->right=NULL;
                            }
                        }else
                            throw "Unexpected red sibling";
                    }else if(target==target->parent->left){//sibling at right
                        if(target->parent->right==NULL)
                            throw "Structure error: double black node don't have sibling";
                        if(target->parent->right->color){//sibling is red: convert to case b or a
                            target->parent->right->parent=target->parent->parent;
                            if(target->parent->parent!=NULL){
                                if(target->parent->parent->left==target->parent)
                                    target->parent->parent->left=target->parent->right;
                                else if(target->parent->parent->right==target->parent)
                                    target->parent->parent->right=target->parent->right;
                                else
                                    throw "Structure error: cant find child in parent pointer";
                            }
                            target->parent->parent=target->parent->right;
                            target->parent->right=target->parent->right->left;
                            target->parent->right->parent=target->parent;
                            target->parent->parent->left=target->parent;
                            target->parent->color=RED;
                            target->parent->parent=BLACK
                        }
                        if(!target->parent->right->color){//sibling is black
                            if(color_is(target->parent->right->right)){//rr case:do rotation
                                target=RR_rotation(target);
                            }else if(color_is(target->parent->right->left)){//rl case
                                target=RL_rotation(target);
                            }
                            else{//black sibling at right and have both black children
                                _Bsibling_Bchildren(target);
                                if(target->right!=NULL) {
                                    target->parent->left = target->right;
                                    target->right->parent=target->parent;
                                }
                                else if(target->left!=NULL) {
                                    target->parent->left = target->left;
                                    target->left->parent=target->parent;
                                } else
                                    target->parent->left=NULL;
                            }
                        }else
                            throw "Unexpected red sibling";
                    }else
                        throw "Structure error: cant find child in parent pointer";
                }else{//target is root
                    if(target->left!=NULL){
                        root=target->left;
                    }else if(target->right=NULL){
                        root=target->right;
                    }else
                        root=NULL;
                }
            }
        }
        delete target;
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

    // used to print data in tree inOrder (least to greatest)
    void redblacktree::inOrder()
    {
        inOrder_traversal(root);
    }

    // used to indicate recoloring/rotating done in insert and remove
    void redblacktree::levelOrder()
    {

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