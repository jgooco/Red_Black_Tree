#include "gtest/gtest.h"
#include "red_black_tree.h"


TEST(red_black_tree, constructorTest)
{
    lab10::redblacktree tree0;
    EXPECT_EQ(0, tree0.size());
}

TEST(red_black_tree, insertTest)
{
    lab10::redblacktree tree1;
    tree1.insert(10);
    tree1.insert(20);
    tree1.insert(30);
    tree1.insert(15);
    tree1.insert(1);

    EXPECT_EQ(5, tree1.size());
    //EXPECT_EQ("1 10 15 20 30", tree1.inOrder()); // indicates nodes are in the right place
    //EXPECT_EQ("20 10 30 1 15", tree1.levelOrder()); // indicates rbt
}

TEST(red_black_tree, removeTest) {
    lab10::redblacktree tree2;
    tree2.insert(10);
    tree2.insert(20);
    tree2.insert(30);
    tree2.insert(15);
    tree2.insert(1);

    EXPECT_EQ(5, tree2.size());
    //EXPECT_EQ("1 10 15 20 30", tree2.inOrder()); // indicates nodes are in the right place

    tree2.remove(10);
    tree2.remove(30);
    EXPECT_EQ(3, tree2.size());

    //EXPECT_EQ("10 1 20 15", tree2.levelOrder()); // indicates rbt
}