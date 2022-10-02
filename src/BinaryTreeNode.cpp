/** @file BinaryTreeNode.cpp
 * @brief Implementation of the BinaryTreeNode class used by BinaryTree
 *    pointer/dynamic node based concrete implementations.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Linked Lists
 * @date   June 1, 2021
 *
 * Implementation of BinaryTreeNode class used by BinaryTree
 * pointer/dynamic node based implementations.
 */
#include "BinaryTreeNode.hpp"
#include "Employee.hpp"
#include <string>
using namespace std;

/**
 * @brief Default constructor
 *
 * Construct an empty node, with no key/value pair and both
 * children are nullptr indicating no children present.
 */
template<class Key, class Value>
BinaryTreeNode<Key, Value>::BinaryTreeNode()
{
  this->key = Key();
  this->value = Value();
  this->left = nullptr;
  this->right = nullptr;
}

/**
 * @brief Standard constructor
 *
 * The standard way to construct a node is we know the
 * key/value pair the node will hold.  So initialize those
 * fields of the node, but have left and right children
 * point to nullptr, indicating no inital left or right
 * child.
 */
template<class Key, class Value>
BinaryTreeNode<Key, Value>::BinaryTreeNode(Key key, Value value)
{
  this->key = key;
  this->value = value;
  this->left = nullptr;
  this->right = nullptr;
}

/**
 * @brief Class destructor
 *
 * The destructor for this BinaryTreeNode instance.
 */
template<class Key, class Value>
BinaryTreeNode<Key, Value>::~BinaryTreeNode()
{
  // nothing to do currently
  // cout << "BinaryTreeNode::destructor> entered" << endl
  //     << "   key: " << key << endl
  //     << " value: " << value << endl
  //     << endl;
}

/**
 * @brief Get key
 *
 * Accessor method to return the key of the key/value pair
 * being held by this node.
 *
 * @returns Key returns the key of this nodes key/value pair.
 */
template<class Key, class Value>
Key BinaryTreeNode<Key, Value>::getKey() const
{
  return key;
}

/**
 * @brief Get value
 *
 * Accessor method to return the value of the key/value pair
 * being held by this node.
 *
 * @returns Value returns the value of this nodes key/value pair.
 */
template<class Key, class Value>
Value BinaryTreeNode<Key, Value>::getValue() const
{
  return value;
}

/**
 * @brief Is leaf node
 *
 * Information method returns true if this node is a leaf node,
 * e.g. if both the left and right children are nullptr.  Returns
 * false if this is not a leaf node, when 1 or both children
 * point to a node further down the tree.
 *
 * @returns bool true if this is a leaf node of the tree, false
 *   if this is not a leaf node.
 */
template<class Key, class Value>
bool BinaryTreeNode<Key, Value>::isLeaf() const
{
  // this is a leaf if both left and right children are null
  return ((left == nullptr) and (right == nullptr));
}

/**
 * @brief Set key
 *
 * Mutator method to set the key of the key/value pair
 * being held by this node.
 *
 * @param key The new key to set for this node.
 */
template<class Key, class Value>
void BinaryTreeNode<Key, Value>::setKey(const Key& key)
{
  this->key = key;
}

/**
 * @brief Set value
 * Mutator method to set the value of the key/value pair
 * being held by this node.
 *
 * @param value The new value to set for this node.
 */
template<class Key, class Value>
void BinaryTreeNode<Key, Value>::setValue(const Value& value)
{
  this->value = value;
}

/**
 * @brief Has left child
 *
 * Test and return true if this node has a left child.  Return
 * false if the node does not have a left child.
 *
 * @returns bool true if this node has a left child, false
 *   if this node does not have a left child.
 */
template<class Key, class Value>
bool BinaryTreeNode<Key, Value>::hasLeft() const
{
  return (left != nullptr);
}

/**
 * @brief Get left child
 *
 * Method to get left child of this node for performing
 * tree taversals.
 *
 * @returns BinaryTreeNode<Key, Value>* Returns a
 *   pointer to a BinaryTreeNode.  The pointer will be the
 *   nullptr if no left child is set for this node.
 */
template<class Key, class Value>
BinaryTreeNode<Key, Value>* BinaryTreeNode<Key, Value>::getLeft() const
{
  return left;
}

/**
 * @brief Set left child
 *
 * Method to set left child of this node for performing
 * tree insertions and management.  This method simply deletes
 * any existing left child, so it is unsafe to call if unsure
 * if left child already exists.
 *
 * @param left The new left child node to be assigned to this node.
 */
template<class Key, class Value>
void BinaryTreeNode<Key, Value>::setLeft(BinaryTreeNode<Key, Value>* left)
{
  // now we can set our node to the one just given
  this->left = left;
}

/**
 * @brief Has right child
 *
 * Test and return true if this node has a right child.  Return
 * false if the node does not have a right child.
 *
 * @returns bool true if this node has a right child, false
 *   if this node does not have a right child.
 */
template<class Key, class Value>
bool BinaryTreeNode<Key, Value>::hasRight() const
{
  return (right != nullptr);
}

/**
 * @brief Get right child
 *
 * Method to get right child of this node for performing
 * tree taversals.
 *
 * @returns BinaryTreeNode<Key, Value>* Returns a
 *   pointer to a BinaryTreeNode.  The pointer will be the
 *   nullptr if no right child is set for this node.
 */
template<class Key, class Value>
BinaryTreeNode<Key, Value>* BinaryTreeNode<Key, Value>::getRight() const
{
  return right;
}

/**
 * @brief Set right child
 *
 * Method to set right child of this node for performing
 * tree insertions and management.  This method simply deletes
 * any existing right child, so it is unsafe to call if unsure
 * if right child already exists.
 *
 * @param right The new right child node to be assigned to this node.
 */
template<class Key, class Value>
void BinaryTreeNode<Key, Value>::setRight(BinaryTreeNode<Key, Value>* right)
{
  // now we can set our node to the one just given
  this->right = right;
}

/**
 * @brief Cause specific instance compilations
 *
 * This is a bit of a kludge, but we can use normal make dependencies
 * and separate compilation by declaring template class
 * BinaryTreeNode<needed_key_type, needed_value_type> here of any
 * types we are going to be instantianting with the template.
 *
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 * https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
 */
template class BinaryTreeNode<int, int>;
template class BinaryTreeNode<string, double>;
template class BinaryTreeNode<int, Employee>;
