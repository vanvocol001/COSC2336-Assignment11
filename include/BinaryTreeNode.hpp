/** @file BinaryTreeNode.hpp
 * @brief Definition of the BinaryTreeNode class used by BinaryTree
 *    pointer/dynamic node based concrete implementations.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Linked Lists
 * @date   June 1, 2021
 *
 * Definition of BinaryTreeNode class used by BinaryTree
 * pointer/dynamic node based implementations.
 */
#ifndef _BINARYTREENODE_HPP_
#define _BINARYTREENODE_HPP_

/** @class BinaryTreeNode
 * @brief A simple BinaryTreeNode for BinaryTrees.

 * This node type is used to hold values in our pointer/ dynamic
 * linked node implemented of the BinaryTree ADT.  This node has
 * some defined member functions, like constructors and
 * isLeaf() accessor method to make it safer and easier for
 * pointer based binary trees to create and use the nodes.
 *
 */
template<class Key, class Value>
class BinaryTreeNode
{
public:
  // constructors and destructors
  BinaryTreeNode();
  BinaryTreeNode(Key key, Value value);
  ~BinaryTreeNode();

  // accessor method
  Key getKey() const;
  Value getValue() const;
  bool isLeaf() const;

  // mutators, needed for tree deletion because we
  // copy key/values of minimum right subtree into node being removed
  void setKey(const Key& key);
  void setValue(const Value& value);

  // function to set and return children
  bool hasLeft() const;
  BinaryTreeNode<Key, Value>* getLeft() const;
  void setLeft(BinaryTreeNode<Key, Value>* left);
  bool hasRight() const;
  BinaryTreeNode<Key, Value>* getRight() const;
  void setRight(BinaryTreeNode<Key, Value>* right);

private:
  /// @brief the node's key, what is used to actually organize the binary
  ///    search tree, and forms a key/value pair with the nodes value.
  Key key;

  /// @brief the actual date value being stored by this node
  Value value;

  /// @brief A pointer to the left child of this current node.
  ///    This can be a nullptr to indicate no left child.  For
  ///    a binary search tree, the key value of the left child
  ///    must be ordered before the key value of this node.
  BinaryTreeNode<Key, Value>* left;

  /// @brief A pointer to the right child of this current node.
  ///    This can be a nullptr to indicate no right child.  For
  ///    a binary search tree, the key value of the right child
  ///    must be ordered after the key value of this node.
  BinaryTreeNode<Key, Value>* right;
};

#endif // define _BINARYTREENODE_HPP_
