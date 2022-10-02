/** @file BinaryTree.hpp
 * @brief Abstract base class definition of BinaryTree abstract data type.
 *   This header defines the abstraction/interface for concrete
 *   BinaryTree implementations.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment BinaryTrees
 * @date   June 1, 2021
 *
 * Defination of BinaryTree abstraction.  Concrete implementations of
 * this BinaryTree interface must inherit from this abstract base class
 * and implement all defined virtual functions.
 */
#ifndef _BINARYTREE_HPP_
#define _BINARYTREE_HPP_
#include <iostream>
using namespace std;

/** @class BinaryTree
 * @brief The BinaryTree data type abstraction
 *
 * The defined ADT interface for a BinaryTree data type.  This abstraction
 * provides the ability to perform the most common tasks we want to
 * perform with binarytrees, such as insert items and search for items
 * in the tree.
 */
template<class Key, class Value>
class BinaryTree
{
public:
  // accessor and information methods
  int getSize() const;
  bool isEmpty() const;
  virtual string str() const = 0;

  // adding, accessing and removing values from the binarytree
  virtual void clear() = 0;
  virtual void insert(const Key& key, const Value& value) = 0;
  virtual Value remove(const Key& key) = 0;
  virtual Value find(const Key& key) const = 0;

  // friend functions and friend operators
  template<typename K, typename V>
  friend ostream& operator<<(ostream& out, const BinaryTree<K, V>& rhs);

protected: // private to this class and child classes
  /// @brief the current size of the BinaryTree of values, this is
  ///   protected so derived classes can access it
  int size;
};

#endif // _BINARYTREE_HPP_
