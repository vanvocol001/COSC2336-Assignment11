/** @file test-LBinaryTree.cpp
 * @brief Unit tests for Assignment Trees
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * Tests of the LBinaryTree linked node implementation of the BinaryTree API.
 */
#include "BinaryTreeException.hpp"
#include "catch.hpp"
#include <iostream>
#include <string>
// a testing kludge so we can test some private members you are to implement for tasks
#define private public
#include "LBinaryTree.hpp"
#undef private
#include "Employee.hpp"
using namespace std;

/** Test LBinaryTree construction and basic operations
 */
TEST_CASE("LBinaryTreeNode<int, int> test tree construction <int,int> key/value types", "[task0]")
{
  // test empty tree construction
  LBinaryTree<int, int> empty;
  CHECK(empty.getSize() == 0);
  CHECK(empty.isEmpty());
  CHECK(empty.str() == "<BinaryTree> size: 0 values: [ ]");
}

/** Test LBinaryTree construction and basic operations
 */
TEST_CASE("LBinaryTreeNode<string, double> test tree construction <string,double> key/value types", "[task0]")
{
  // test empty tree construction
  LBinaryTree<string, double> empty;
  CHECK(empty.getSize() == 0);
  CHECK(empty.isEmpty());
  CHECK(empty.str() == "<BinaryTree> size: 0 values: [ ]");
}

/** Task 1: Test LBinaryTree insert member function
 */
/*
   TEST_CASE("LBinaryTreeNode<int, int> test insert member implementation",
          "[task1]")
   {
   // initially tree is empty
   LBinaryTree<int, int> tree;
   CHECK( tree.getSize() == 0 );
   CHECK( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 0 values: [ ]" );

   // first inserted becomes root
   tree.insert(10, 10);
   CHECK( tree.getSize() == 1 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 1 values: [ 10 ]" );

   // next node should be left child
   tree.insert(5, 5);
   CHECK( tree.getSize() == 2 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 2 values: [ 5 10 ]" );

   // fill up a few more nodes
   tree.insert(15, 15);
   tree.insert(3, 3);
   tree.insert(1, 1);
   tree.insert(12, 12);
   tree.insert(11, 11);
   tree.insert(18, 18);
   CHECK( tree.getSize() == 8 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 8 values: [ 1 3 5 10 11 12 15 18 ]" );

   // cleared tree should be empty again
   tree.clear();
   CHECK( tree.getSize() == 0 );
   CHECK( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 0 values: [ ]" );
   }
 
*/
/** Task 1: Test LBinaryTree insert member function
 */

   TEST_CASE("LBinaryTreeNode<string, double> test insert member implementation",
          "[task1]")
   {
   // initially tree is empty
   LBinaryTree<string, double> tree;
   CHECK( tree.getSize() == 0 );
   CHECK( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 0 values: [ ]" );

   // first inserted becomes root
   string key = "juliet";
   tree.insert(key, 10.10);
   CHECK( tree.getSize() == 1 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 1 values: [ 10.1 ]" );

   // next node should be left child
   key = "echo";
   tree.insert(key, 5.5);
   CHECK( tree.getSize() == 2 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 2 values: [ 5.5 10.1 ]" );

   // fill up a few more nodes
   key = "oscar";
   tree.insert(key, 15.15);
   key = "charlie";
   tree.insert(key, 3.3);
   key = "alpha";
   tree.insert(key, 1.1);
   key = "lima";
   tree.insert(key, 12.12);
   key = "kilo";
   tree.insert(key, 11.11);
   key = "romeo";
   tree.insert(key, 18.18);
   CHECK( tree.getSize() == 8 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 8 values: [ 1.1 3.3 5.5 10.1 11.11 12.12 15.15 18.18 ]" );

   // cleared tree should be empty again
   tree.clear();
   CHECK( tree.getSize() == 0 );
   CHECK( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 0 values: [ ]" );
   }
 

/** Task 0: Test LBinaryTree construction and basic operations
 */

   TEST_CASE("LBinaryTreeNode<int, int> test tree construction <int,int> using array based constructor",
          "[task0]")
   {
   // test array based constructor, keys inserted in order from index 0 up to max,
   // so 10 becomes the root of this tree
   int keys[]   = {10, 5, 15, 12, 11, 3, 2, 1};
   int values[] = {10, 5, 15, 12, 11, 3, 2, 1};
   int size = 8;
   LBinaryTree<int, int> tree(size, keys, values);

   CHECK( tree.getSize() == 8 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK(tree.str() == "<BinaryTree> size: 8 values: [ 1 2 3 5 10 11 12 15 ]" );

   }
 

/** Task 0 Test LBinaryTree construction and basic operations
 */

   TEST_CASE("LBinaryTreeNode<string, double> test tree construction <string,double> using array based constructor",
          "[task0]")
   {
   // test array based constructor, keys inserted in order from index 0 up to max,
   // so 10 becomes the root of this tree
   string keys[]   = {"juliet", "echo", "oscar", "lima", "kilo", "charlie", "bravo", "alpha"};
   double values[] = {10.10, 5.5, 15.15, 12.12, 11.11, 3.3, 2.2, 1.1};
   int size = 8;
   LBinaryTree<string, double> tree(size, keys, values);

   CHECK( tree.getSize() == 8 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK(tree.str() == "<BinaryTree> size: 8 values: [ 1.1 2.2 3.3 5.5 10.1 11.11 12.12 15.15 ]" );

   }
 

/** Task 2: Test LBinaryTree find member function
 */

   TEST_CASE("LBinaryTreeNode<int, int> test search with find member implementation",
          "[task2]")
   {
   int keys[]   = {10, 5, 15, 12, 11, 3, 2, 1};
   int values[] = {10, 5, 15, 12, 11, 3, 2, 1};
   int size = 8;
   LBinaryTree<int, int> tree(size, keys, values);

   CHECK( tree.getSize() == 8 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK(tree.str() == "<BinaryTree> size: 8 values: [ 1 2 3 5 10 11 12 15 ]" );

   // test find the root node
   CHECK( tree.find(10) == 10 );

   // test intermediate nodes, 15 and 5
   CHECK( tree.find(15) == 15 );
   CHECK( tree.find(5) == 5 );

   // test some leaf nodes
   CHECK( tree.find(11) == 11 );
   CHECK( tree.find(1) == 1 );

   // test we get expected exception if try and find key not in the tree
   CHECK_THROWS_AS( tree.find(42), BinaryTreeKeyNotFoundException );
   }
 

/** Task 2: Test LBinaryTree find member function
 */

   TEST_CASE("LBinaryTreeNode<string, double> test search with find member implementation",
          "[task2]")
   {
   // test array based constructor, keys inserted in order from index 0 up to max,
   // so 10 becomes the root of this tree
   string keys[]   = {"juliet", "echo", "oscar", "lima", "kilo", "charlie", "bravo", "alpha"};
   double values[] = {10.10, 5.5, 15.15, 12.12, 11.11, 3.3, 2.2, 1.1};
   int size = 8;
   LBinaryTree<string, double> tree(size, keys, values);

   CHECK( tree.getSize() == 8 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK(tree.str() == "<BinaryTree> size: 8 values: [ 1.1 2.2 3.3 5.5 10.1 11.11 12.12 15.15 ]" );

   // test find the root node
   CHECK( tree.find("juliet") == Approx(10.1) );

   // test intermediate nodes, 15 and 5
   CHECK( tree.find("oscar") == Approx(15.15) );
   CHECK( tree.find("echo") == Approx(5.5) );

   // test some leaf nodes
   CHECK( tree.find("kilo") == Approx(11.11) );
   CHECK( tree.find("alpha") == Approx(1.1) );

   // test we get expected exception if try and find key not in the tree
   CHECK_THROWS_AS( tree.find("thanks-for-the-fish"), BinaryTreeKeyNotFoundException );
   }
 

/** Task 3: Test private LBinaryTree getMinimum member function
 */

   TEST_CASE("LBinaryTreeNode<int, int> test private getMinimum member implementation",
          "[task3]")
   {
   int keys[]   = {10, 5, 15, 12, 11, 3, 2, 1, 8, 9, 18, 16, 20};
   int values[] = {10, 5, 15, 12, 11, 3, 2, 1, 8, 9, 18, 16, 20};
   int size = 13;
   LBinaryTree<int, int> tree(size, keys, values);

   CHECK( tree.getSize() == 13 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK(tree.str() == "<BinaryTree> size: 13 values: [ 1 2 3 5 8 9 10 11 12 15 16 18 20 ]" );

   // pointers for our tests
   BinaryTreeNode<int, int>* subtree;
   BinaryTreeNode<int, int>* node;

   // minimum of a leaf node should just return itself
   // 1 is a leaf node
   subtree = tree.root->left->left->left->left;
   node = tree.getMinimum(subtree);
   CHECK( node->getKey() == 1 );
   CHECK( node->getValue() == 1 );

   // 11 is a leaf node
   subtree = tree.root->right->left->left;
   node = tree.getMinimum(subtree);
   CHECK( node->getKey() == 11 );
   CHECK( node->getValue() == 11 );

   // 20 is a leaf node
   subtree = tree.root->right->right->right;
   node = tree.getMinimum(subtree);
   CHECK( node->getKey() == 20 );
   CHECK( node->getValue() == 20 );

   // minimum of node with only right subtree should return itself
   // 8 has only a right subtree
   subtree = tree.root->left->right;
   node = tree.getMinimum(subtree);
   CHECK( node->getKey() == 8 );
   CHECK( node->getValue() == 8 );

   // minimum of node with only left subtree should return the minimum
   // value in the left subtree.
   // 3 has only a left subtree
   subtree = tree.root->left->left;
   node = tree.getMinimum(subtree);
   CHECK( node->getKey() == 1 );
   CHECK( node->getValue() == 1 );

   // minimum of node with bothy left and right children should return minimum
   // in left subtree
   // 15 has left and right children
   subtree = tree.root->right;
   node = tree.getMinimum(subtree);
   CHECK( node->getKey() == 11 );
   CHECK( node->getValue() == 11 );

   // minimum from root is value 1
   node = tree.getMinimum(tree.root);
   CHECK( node->getKey() == 1 );
   CHECK( node->getValue() == 1 );
   }
 

/** Task 3: Test private LBinaryTree getMinimum member function
 */

   TEST_CASE("LBinaryTreeNode<string, double> test private getMinimum member implementation",
          "[task3]")
   {
   string keys[]   = {"juliet", "echo", "oscar", "lima", "kilo", "charlie", "bravo", "alpha", "hotel", "india", "romeo", "papa", "tango"};
   double values[] = {10.10, 5.5, 15.15, 12.12, 11.11, 3.3, 2.2, 1.1, 8.8, 9.9, 18.18, 16.16, 20.20};
   int size = 13;
   LBinaryTree<string, double> tree(size, keys, values);

   CHECK( tree.getSize() == 13 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK(tree.str() == "<BinaryTree> size: 13 values: [ 1.1 2.2 3.3 5.5 8.8 9.9 10.1 11.11 12.12 15.15 16.16 18.18 20.2 ]" );

   // pointers for our tests
   BinaryTreeNode<string, double>* subtree;
   BinaryTreeNode<string, double>* node;

   // minimum of a leaf node should just return itself
   // 1 "alpha" is a leaf node
   subtree = tree.root->left->left->left->left;
   node = tree.getMinimum(subtree);
   CHECK( node->getKey() == "alpha" );
   CHECK( node->getValue() == Approx(1.1) );

   // 11 "kilo" is a leaf node
   subtree = tree.root->right->left->left;
   node = tree.getMinimum(subtree);
   CHECK( node->getKey() == "kilo" );
   CHECK( node->getValue() == Approx(11.11) );

   // 20 "tango" is a leaf node
   subtree = tree.root->right->right->right;
   node = tree.getMinimum(subtree);
   CHECK( node->getKey() == "tango" );
   CHECK( node->getValue() == Approx(20.20) );

   // minimum of node with only right subtree should return itself
   // 8 "hotel" has only a right subtree
   subtree = tree.root->left->right;
   node = tree.getMinimum(subtree);
   CHECK( node->getKey() == "hotel" );
   CHECK( node->getValue() == Approx(8.8) );

   // minimum of node with only left subtree should return the minimum
   // value in the left subtree.
   // 3 "charlie" has only a left subtree
   subtree = tree.root->left->left;
   node = tree.getMinimum(subtree);
   CHECK( node->getKey() == "alpha" );
   CHECK( node->getValue() == Approx(1.1) );

   // minimum of node with bothy left and right children should return minimum
   // in left subtree
   // 15 "oscar" has left and right children
   subtree = tree.root->right;
   node = tree.getMinimum(subtree);
   CHECK( node->getKey() == "kilo" );
   CHECK( node->getValue() == Approx(11.11) );

   // minimum from root is value 1
   node = tree.getMinimum(tree.root);
   CHECK( node->getKey() == "alpha" );
   CHECK( node->getValue() == Approx(1.1) );
   }
 

/** Task 4: Test private LBinaryTree deleteMinimum member function
 */

   TEST_CASE("LBinaryTreeNode<int, int> test private deleteMinimum member implementation",
          "[task4]")
   {
   int keys[]   = {10, 5, 15, 12, 11, 3, 2, 1, 8, 9, 18, 16, 20};
   int values[] = {10, 5, 15, 12, 11, 3, 2, 1, 8, 9, 18, 16, 20};
   int size = 13;
   LBinaryTree<int, int> tree(size, keys, values);

   CHECK( tree.getSize() == 13 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK(tree.str() == "<BinaryTree> size: 13 values: [ 1 2 3 5 8 9 10 11 12 15 16 18 20 ]" );

   // pointers for our tests
   BinaryTreeNode<int, int>* subtree;
   BinaryTreeNode<int, int>* node;

   // delete minimum of a node with a left child should just delete it
   // 12 has only left child 11
   subtree = tree.root->right->left;
   node = tree.deleteMinimum(subtree);
   // deleteMinimum cannot update size, it is a recursive function, but we
   // can check the value was removed from the tree
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 1 2 3 5 8 9 10 12 15 16 18 20 ]" );


   // Another test of node with only a left subtree, though this node has a subtree, not
   // just a single node.  3 has a left subtree with 2 and 1 in it
   subtree = tree.root->left->left;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 2 3 5 8 9 10 12 15 16 18 20 ]" );

   // 18 has left and right subtrees, should end up deleteing node 16
   subtree = tree.root->right->right;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 2 3 5 8 9 10 12 15 18 20 ]" );

   // now 18 has only a right subtree, so it should end up returning itself for deletion.
   // because of how deleteMin is supposed to work, this will only return the new
   // minimum node, it will not actually change the tree
   subtree = tree.root->right->right;
   CHECK( subtree->getKey() == 18 );
   CHECK( subtree->getValue() == 18 );
   node = tree.deleteMinimum(subtree);
   // did not update left node of the node 18 we started from
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 2 3 5 8 9 10 12 15 18 20 ]" );
   // but node 20 should be returned, which would cause this node 18 to be deleted if we called
   // this on a parent tree of 18
   CHECK( node->getKey() == 20 );
   CHECK( node->getValue() == 20 );

   // test delete from root, 2 should be current minimum from root
   subtree = tree.root;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 3 5 8 9 10 12 15 18 20 ]" );

   // test delete from root again, 3 should be current minimum from root
   subtree = tree.root;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 5 8 9 10 12 15 18 20 ]" );

   // 5 is minimum but it has right subtrees.  5 should be removed
   subtree = tree.root;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 8 9 10 12 15 18 20 ]" );

   // 15 has left and right subtrees, 12 is its left subtree which whould be removed
   subtree = tree.root->right;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 8 9 10 15 18 20 ]" );

   // now tree root has left and right subtrees, but again left subtree has a right
   // subtree, but 8 should be removed if delete from root
   subtree = tree.root;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 9 10 15 18 20 ]" );

   // deleteing from root again leaves tree with no left subtree from root, only
   // right
   subtree = tree.root;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 10 15 18 20 ]" );

   // 10 is the root of the tree, but no left subtree so 10 is the smallest.
   // deleting from root should return the node with a value of 15 as the new
   // node that would replace the root.  We will simulate what the
   // remove() function would do with this here by replacing the root value
   // with what is returned
   subtree = tree.root;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 10 15 18 20 ]" );
   CHECK( node->getKey() == 15 );
   CHECK( node->getValue() == 15);
   tree.root = node;  // something like this should happen in the remove() function
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 15 18 20 ]" );
   }
 

/** Task 4: Test private LBinaryTree deleteMinimum member function
 */

   TEST_CASE("LBinaryTreeNode<string, double> test private deleteMinimum member implementation",
          "[task4]")
   {
   string keys[]   = {"juliet", "echo", "oscar", "lima", "kilo", "charlie", "bravo", "alpha", "hotel", "india", "romeo", "papa", "tango"};
   double values[] = {10.10, 5.5, 15.15, 12.12, 11.11, 3.3, 2.2, 1.1, 8.8, 9.9, 18.18, 16.16, 20.20};
   int size = 13;
   LBinaryTree<string, double> tree(size, keys, values);

   CHECK( tree.getSize() == 13 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK(tree.str() == "<BinaryTree> size: 13 values: [ 1.1 2.2 3.3 5.5 8.8 9.9 10.1 11.11 12.12 15.15 16.16 18.18 20.2 ]" );

   // pointers for our tests
   BinaryTreeNode<string, double>* subtree;
   BinaryTreeNode<string, double>* node;

   // delete minimum of a node with a left child should just delete it
   // 12 "lima" has only left child 11 "kilo"
   subtree = tree.root->right->left;
   node = tree.deleteMinimum(subtree);
   // deleteMinimum cannot update size, it is a recursive function, but we
   // can check the value was removed from the tree
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 1.1 2.2 3.3 5.5 8.8 9.9 10.1 12.12 15.15 16.16 18.18 20.2 ]" );


   // Another test of node with only a left subtree, though this node has a subtree, not
   // just a single node.  3 "charlie" has a left subtree with 2 "bravo" and 1 "alpha" in it
   subtree = tree.root->left->left;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 2.2 3.3 5.5 8.8 9.9 10.1 12.12 15.15 16.16 18.18 20.2 ]" );

   // 18 "romeo" has left and right subtrees, should end up deleteing node 16 "papa"
   subtree = tree.root->right->right;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 2.2 3.3 5.5 8.8 9.9 10.1 12.12 15.15 18.18 20.2 ]" );

   // now 18 "romeo" has only a right subtree, so it should end up returning itself for deletion.
   // because of how deleteMin is supposed to work, this will only return the new
   // minimum node, it will not actually change the tree
   subtree = tree.root->right->right;
   CHECK( subtree->getKey() == "romeo" );
   CHECK( subtree->getValue() == Approx(18.18) );
   node = tree.deleteMinimum(subtree);
   // did not update left node of the node 18 we started from
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 2.2 3.3 5.5 8.8 9.9 10.1 12.12 15.15 18.18 20.2 ]" );
   // but node 20 should be returned, which would cause this node 18 to be deleted if we called
   // this on a parent tree of 18
   CHECK( node->getKey() == "tango" );
   CHECK( node->getValue() == Approx(20.20) );

   // test delete from root, 2 "bravo" should be current minimum from root
   subtree = tree.root;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 3.3 5.5 8.8 9.9 10.1 12.12 15.15 18.18 20.2 ]" );

   // test delete from root again, 3 "charlie" should be current minimum from root
   subtree = tree.root;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 5.5 8.8 9.9 10.1 12.12 15.15 18.18 20.2 ]" );

   // 5 "echo" is minimum but it has right subtrees.  5 "echo" should be removed
   subtree = tree.root;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 8.8 9.9 10.1 12.12 15.15 18.18 20.2 ]" );

   // 15 "oscar" has left and right subtrees, 12 "lima" is its left subtree which whould be removed
   subtree = tree.root->right;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 8.8 9.9 10.1 15.15 18.18 20.2 ]" );

   // now tree root has left and right subtrees, but again left subtree has a right
   // subtree, but 8 "hotel" should be removed if delete from root
   subtree = tree.root;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 9.9 10.1 15.15 18.18 20.2 ]" );

   // deleteing from root again leaves tree with no left subtree from root, only
   // right
   subtree = tree.root;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 10.1 15.15 18.18 20.2 ]" );

   // 10 "juliet" is the root of the tree, but no left subtree so 10 "juliet" is the smallest.
   // deleting from root should return the node with a value of 15 "oscar" as the new
   // node that would replace the root.  We will simulate what the
   // remove() function would do with this here by replacing the root value
   // with what is returned
   subtree = tree.root;
   node = tree.deleteMinimum(subtree);
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 10.1 15.15 18.18 20.2 ]" );
   CHECK( node->getKey() == "oscar" );
   CHECK( node->getValue() == Approx(15.15) );
   tree.root = node;  // something like this should happen in the remove() function
   CHECK( tree.str() == "<BinaryTree> size: 13 values: [ 15.15 18.18 20.2 ]" );
   }
 

/** Task 5: Test LBinaryTree remove member function
 */

   TEST_CASE("LBinaryTreeNode<int, int> test remove member implementation",
          "[task5]")
   {
   int keys[]   = {10, 5, 15, 12, 11, 3, 2, 1, 4, 8, 13};
   int values[] = {10, 5, 15, 12, 11, 3, 2, 1, 4, 8, 13};
   int size = 11;
   LBinaryTree<int, int> tree(size, keys, values);

   // easy case, remove a leaf node
   tree.remove(1);
   CHECK( tree.getSize() == 10 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 10 values: [ 2 3 4 5 8 10 11 12 13 15 ]" );

   // easy case, another leaf node removal
   tree.remove(2);
   CHECK( tree.getSize() == 9 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 9 values: [ 3 4 5 8 10 11 12 13 15 ]" );

   // node 3 currently only has a right node 4, remove it
   tree.remove(3);
   CHECK( tree.getSize() == 8 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 8 values: [ 4 5 8 10 11 12 13 15 ]" );

   // node 8 is a leaf, remove it so that 5 has only a left node 4
   tree.remove(8);
   CHECK( tree.getSize() == 7 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 7 values: [ 4 5 10 11 12 13 15 ]" );

   // test we get exception if try and remove key not in tree
   CHECK_THROWS_AS( tree.remove(16), BinaryTreeKeyNotFoundException );

   // node 5 has only left subtree 4 now, test remove node with only left subtree
   tree.remove(5);
   CHECK( tree.getSize() == 6 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 6 values: [ 4 10 11 12 13 15 ]" );

   // most difficult case, node 12 has both subtrees, 11 and 13 to left and righ
   // respectively, try removing it
   tree.remove(12);
   CHECK( tree.getSize() == 5 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 5 values: [ 4 10 11 13 15 ]" );

   // test removing root of tree.  Root has 2 subtrees, 4 and 15 to the
   // left and right respectively.
   tree.remove(10);
   CHECK( tree.getSize() == 4 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 4 values: [ 4 11 13 15 ]" );

   // remove node 4, leaving 11 at root with only a right subtree
   tree.remove(4);
   CHECK( tree.getSize() == 3 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 3 values: [ 11 13 15 ]" );

   // remove node root 11 wich only has right subtree
   tree.remove(11);
   CHECK( tree.getSize() == 2 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 2 values: [ 13 15 ]" );

   // 13 is root, remove it bringing tree down to single remaining node
   tree.remove(13);
   CHECK( tree.getSize() == 1 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 1 values: [ 15 ]" );

   // test we get exception if try and remove key not in tree when tree
   // mostly gone and try a key that was in the tree just before
   CHECK_THROWS_AS( tree.remove(13), BinaryTreeKeyNotFoundException );

   // remove the last node, tree should now be empty
   tree.remove(15);
   CHECK( tree.getSize() == 0 );
   CHECK( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 0 values: [ ]" );
   }
 

/** Task 5: Test LBinaryTree remove member function
 */

   TEST_CASE("LBinaryTreeNode<string, double> test remove member implementation",
          "[task5]")
   {
   // test array based constructor, keys inserted in order from index 0 up to max,
   // so 10 becomes the root of this tree
   string keys[]   = {"juliet", "echo", "oscar", "lima", "kilo", "charlie", "bravo", "alpha", "delta", "hotel", "mike"};
   double values[] = {10.10, 5.5, 15.15, 12.12, 11.11, 3.3, 2.2, 1.1, 4.4, 8.8, 13.13};
   int size = 11;
   LBinaryTree<string, double> tree(size, keys, values);

   // easy case, remove a leaf node
   tree.remove("alpha");
   CHECK( tree.getSize() == 10 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 10 values: [ 2.2 3.3 4.4 5.5 8.8 10.1 11.11 12.12 13.13 15.15 ]" );

   // easy case, another leaf node removal
   tree.remove("bravo");
   CHECK( tree.getSize() == 9 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 9 values: [ 3.3 4.4 5.5 8.8 10.1 11.11 12.12 13.13 15.15 ]" );

   // node 3 "charlie" currently only has a right node 4 "delta", remove it
   tree.remove("charlie");
   CHECK( tree.getSize() == 8 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 8 values: [ 4.4 5.5 8.8 10.1 11.11 12.12 13.13 15.15 ]" );

   // node 8 "hotel" is a leaf, remove it so that 5 "echo" has only a left node 4 "delta"
   tree.remove("hotel");
   CHECK( tree.getSize() == 7 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 7 values: [ 4.4 5.5 10.1 11.11 12.12 13.13 15.15 ]" );

   // test we get exception if try and remove key not in tree
   CHECK_THROWS_AS( tree.remove("papa"), BinaryTreeKeyNotFoundException );

   // node 5 "echo" has only left subtree 4 "delta" now, test remove node with only left subtree
   tree.remove("echo");
   CHECK( tree.getSize() == 6 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 6 values: [ 4.4 10.1 11.11 12.12 13.13 15.15 ]" );

   // most difficult case, node 12 "lima" has both subtrees, 11 "kilo" and 13 "mike" to left and right
   // respectively, try removing it
   tree.remove("lima");
   CHECK( tree.getSize() == 5 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 5 values: [ 4.4 10.1 11.11 13.13 15.15 ]" );

   // test removing root of tree "juliett".  Root has 2 subtrees, 4 "delta" and 15 "oscar" to the
   // left and right respectively.
   tree.remove("juliet");
   CHECK( tree.getSize() == 4 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 4 values: [ 4.4 11.11 13.13 15.15 ]" );

   // remove node 4 "delta", leaving 11 "kilo" at root with only a right subtree
   tree.remove("delta");
   CHECK( tree.getSize() == 3 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 3 values: [ 11.11 13.13 15.15 ]" );

   // remove node root 11 "kilo" wich only has right subtree
   tree.remove("kilo");
   CHECK( tree.getSize() == 2 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 2 values: [ 13.13 15.15 ]" );

   // 13 "mike" is root, remove it bringing tree down to single remaining node
   tree.remove("mike");
   CHECK( tree.getSize() == 1 );
   CHECK_FALSE( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 1 values: [ 15.15 ]" );

   // test we get exception if try and remove key not in tree when tree
   // mostly gone and try a key that was in the tree just before
   CHECK_THROWS_AS( tree.remove("mike"), BinaryTreeKeyNotFoundException );

   // remove the last node, tree should now be empty
   tree.remove("oscar");
   CHECK( tree.getSize() == 0 );
   CHECK( tree.isEmpty() );
   CHECK( tree.str() == "<BinaryTree> size: 0 values: [ ]" );
   }
 
