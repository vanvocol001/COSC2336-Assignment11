/** @file test-BinaryTreeNode.cpp
 * @brief Unit tests for Assignment Trees
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * Tests of the BinaryTreeNode class and member functions
 */
#include "BinaryTreeNode.hpp"
#include "Employee.hpp"
#include "catch.hpp"
#include <iostream>
#include <string>
using namespace std;

/** Test BinaryTreeNode construction and basic operations
 */
TEST_CASE("BinaryTreeNode<int, int> test of construction and basic operations", "[task0]")
{
  // empty node, no key/value pair initialized, default construciton of int
  // type results in 0 value always?
  BinaryTreeNode<int, int> empty;
  CHECK(empty.isLeaf());
  CHECK(empty.getKey() == 0);
  CHECK(empty.getValue() == 0);
  CHECK_FALSE(empty.hasLeft());
  CHECK_FALSE(empty.hasRight());
  CHECK(empty.getLeft() == nullptr);
  CHECK(empty.getRight() == nullptr);

  // node with int key and int value
  BinaryTreeNode<int, int> node1(5, 42);
  CHECK(node1.isLeaf());
  CHECK(node1.getKey() == 5);
  CHECK(node1.getValue() == 42);
  CHECK_FALSE(node1.hasLeft());
  CHECK_FALSE(node1.hasRight());
  CHECK(node1.getLeft() == nullptr);
  CHECK(node1.getRight() == nullptr);

  // construct a small tree
  BinaryTreeNode<int, int> node2(3, 3);
  CHECK(node2.isLeaf());
  node1.setLeft(&node2);

  // node1 is not a leaf anymore, but node 2 should be
  CHECK_FALSE(node1.isLeaf());
  CHECK(node2.isLeaf());
  CHECK(node1.hasLeft());

  // we can traverse the tree from node1 root
  BinaryTreeNode<int, int>* tmp;
  tmp = node1.getLeft();
  CHECK(tmp->getKey() == 3);
  CHECK(tmp->getValue() == 3);

  // test right child
  BinaryTreeNode<int, int> node3(8, 8);
  CHECK(node3.isLeaf());
  node1.setRight(&node3);

  // node1 still not a leaf, but node 3 should still be
  CHECK_FALSE(node1.isLeaf());
  CHECK(node3.isLeaf());
  CHECK(node1.hasRight());

  // we can traverse the tree from node1 root
  tmp = node1.getRight();
  CHECK(tmp->getKey() == 8);
  CHECK(tmp->getValue() == 8);
}

TEST_CASE("BinaryTreeNode<string, double> test of construction and basic operations", "[task0]")
{
  // empty node, no key/value pair initialized, default construciton of
  // string is empty string "" and of a double is 0.0?
  BinaryTreeNode<string, double> empty;
  CHECK(empty.isLeaf());
  CHECK(empty.getKey() == "");
  CHECK(empty.getValue() == 0.0);
  CHECK_FALSE(empty.hasLeft());
  CHECK_FALSE(empty.hasRight());
  CHECK(empty.getLeft() == nullptr);
  CHECK(empty.getRight() == nullptr);

  // node with string key and string value
  BinaryTreeNode<string, double> node1("alex", 34.56);
  CHECK(node1.isLeaf());
  CHECK(node1.getKey() == "alex");
  CHECK(node1.getValue() == 34.56);
  CHECK_FALSE(node1.hasLeft());
  CHECK_FALSE(node1.hasRight());
  CHECK(node1.getLeft() == nullptr);
  CHECK(node1.getRight() == nullptr);

  // construct a small tree
  BinaryTreeNode<string, double> node2("bobby", 13.13);
  CHECK(node2.isLeaf());
  node1.setLeft(&node2);

  // node1 is not a leaf anymore, but node 2 should be
  CHECK_FALSE(node1.isLeaf());
  CHECK(node2.isLeaf());
  CHECK(node1.hasLeft());

  // we can traverse the tree from node1 root
  BinaryTreeNode<string, double>* tmp;
  tmp = node1.getLeft();
  CHECK(tmp->getKey() == "bobby");
  CHECK(tmp->getValue() == 13.13);

  // test right child
  BinaryTreeNode<string, double> node3("holden", 42.42);
  CHECK(node3.isLeaf());
  node1.setRight(&node3);

  // node1 still not a leaf, but node 3 should still be
  CHECK_FALSE(node1.isLeaf());
  CHECK(node3.isLeaf());
  CHECK(node1.hasRight());

  // we can traverse the tree from node1 root
  tmp = node1.getRight();
  CHECK(tmp->getKey() == "holden");
  CHECK(tmp->getValue() == 42.42);
}

/** Test BinaryTreeNode construction and basic operations with a user defined
 *    type.
 */
TEST_CASE("BinaryTreeNode<int, Employee> test of construction and basic operations", "[task0]")
{
  // empty node, no key/value pair initialized, default construciton of int
  // type results in 0 value always?
  BinaryTreeNode<int, Employee> empty;
  CHECK(empty.isLeaf());
  CHECK(empty.getKey() == 0);
  CHECK(empty.getValue().str() == "( id: 0, , , 0.00 )");
  CHECK_FALSE(empty.hasLeft());
  CHECK_FALSE(empty.hasRight());
  CHECK(empty.getLeft() == nullptr);
  CHECK(empty.getRight() == nullptr);

  // node with int key and int value
  Employee holden(42, "James Holden", "Rocinante", 500.00);
  BinaryTreeNode<int, Employee> node1(holden.getId(), holden);
  CHECK(node1.isLeaf());
  CHECK(node1.getKey() == 42);
  CHECK(node1.getValue().str() == "( id: 42, James Holden, Rocinante, 500.00 )");
  CHECK_FALSE(node1.hasLeft());
  CHECK_FALSE(node1.hasRight());
  CHECK(node1.getLeft() == nullptr);
  CHECK(node1.getRight() == nullptr);

  // construct a small tree
  Employee amos(38, "Amos Burton", "Rocinante", 250.00);
  BinaryTreeNode<int, Employee> node2(amos.getId(), amos);
  CHECK(node2.isLeaf());
  node1.setLeft(&node2);

  // node1 is not a leaf anymore, but node 2 should be
  CHECK_FALSE(node1.isLeaf());
  CHECK(node2.isLeaf());
  CHECK(node1.hasLeft());

  // we can traverse the tree from node1 root
  BinaryTreeNode<int, Employee>* tmp;
  tmp = node1.getLeft();
  CHECK(tmp->getKey() == 38);
  CHECK(tmp->getValue().str() == "( id: 38, Amos Burton, Rocinante, 250.00 )");

  // test right child
  Employee naomi(57, "Naomi Nagata", "Rocinante", 525.00);
  BinaryTreeNode<int, Employee> node3(naomi.getId(), naomi);
  CHECK(node3.isLeaf());
  node1.setRight(&node3);

  // node1 still not a leaf, but node 3 should still be
  CHECK_FALSE(node1.isLeaf());
  CHECK(node3.isLeaf());
  CHECK(node1.hasRight());

  // we can traverse the tree from node1 root
  tmp = node1.getRight();
  CHECK(tmp->getKey() == 57);
  CHECK(tmp->getValue().str() == "( id: 57, Naomi Nagata, Rocinante, 525.00 )");
}