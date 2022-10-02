/** @file LBinaryTree.hpp
 * @brief Concrete link listed based implementation of BinaryTree ADT.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment BinaryTrees
 * @date   June 1, 2021
 *
 * Implement the BinaryTree abstraction using a pointer based set of
 * nodes of dynamically allocated node items.  The dynamic node based
 * implementation creates new nodes dynamically when items are inserted
 * into the tree, and deletes these nodes when the key/value pair is deleted
 * from the tree.  We use a binary search tree.  We support nodes with
 * key/value pairs.  The binary tree is organized by key values.  The
 * general rule is that keys must have an order defined by operator<().
 * When a key/value pair is inserted in tree, it will go to the left subtree
 * of any existing node where the key is less than ordering, and will got
 * to the right subtree where the key is greater than ordering.  Because
 * of the tree structure, assuming the tree does not become too balanced,
 * all operations such as search, insertion and removal should be O(n log_2 n)
 * in performance.
 */
#ifndef _LBINARYTREE_HPP_
#define _LBINARYTREE_HPP_
#include "BinaryTree.hpp"
#include "BinaryTreeNode.hpp"
#include <string>
using namespace std;

/** @class LBinaryTree
 * @brief The LBinaryTree data type abstraction
 *
 * The defined ADT interface for a LBinaryTree data type.  This abstraction
 * provides the ability to perform the most common tasks we want to
 * perform with binarytrees, such as insert items and search for items
 * in the tree.
 */
template<class Key, class Value>
class LBinaryTree : public BinaryTree<Key, Value>
{
public:
  // constructors and destructors
  LBinaryTree(); // default constructor

  // construct from a list/array of key/value pairs
  LBinaryTree(int size, const Key keys[], const Value values[]);

  ~LBinaryTree(); // destructor

  // accessor and information methods
  string str() const;

  // adding, accessing and removing values from the binarytree
  void clear();
  void insert(const Key& key, const Value& value);
  Value find(const Key& key) const;
  Value remove(const Key& key);

private:
  /// @brief The root of this binary tree.  When tree is empty then
  ///   root should be nullptr and size should be 0
  BinaryTreeNode<Key, Value>* root;
  
  
  // private member functions.  These are overloaded recursive functions
  // that do most of the real work of the public interface.  The public
  // interface simply calls the private recursive methods on the root
  // node to perform the operation.
  string str(BinaryTreeNode<Key, Value>* node) const;
  void clear(BinaryTreeNode<Key, Value>* node);
  BinaryTreeNode<Key, Value>* insert(BinaryTreeNode<Key, Value>* node, const Key& key, const Value& value);
  Value find(BinaryTreeNode<Key, Value>* node, const Key& key) const;
  BinaryTreeNode<Key, Value>* getMinimum(BinaryTreeNode<Key, Value>* node);
  BinaryTreeNode<Key, Value>* deleteMinimum(BinaryTreeNode<Key, Value>* node);
  BinaryTreeNode<Key, Value>* remove(BinaryTreeNode<Key, Value>* node, const Key& key);
  
    
};

#endif // define _LBINARYTREE_HPP_
