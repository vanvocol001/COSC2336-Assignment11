/** @file BinaryTree.cpp
 * @brief Implementation of the BinaryTree class used by BinaryTree
 *    pointer/dynamic node based concrete implementations.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Linked Lists
 * @date   June 1, 2021
 *
 * Implementation of the BinaryTree base class concrete member functions
 * and friend functions.
 */
#include "BinaryTree.hpp"
#include "Employee.hpp"
#include <iostream>
using namespace std;

/**
 * @brief Size accessor
 *
 * Accessor method to get the current size of this Binarytree of values.
 *
 * @returns int Returns the current size of the binarytree of values.
 */
template<class Key, class Value>
int BinaryTree<Key, Value>::getSize() const
{
  return size;
}

/**
 * @brief Check if empty binary tree
 *
 * Accessor method to test if the BinaryTree is currently
 * empty or not.
 *
 * @returns bool Returns true if the BinaryTree is currently
 *   empty, or false if it has 1 or more items.
 */
template<class Key, class Value>
bool BinaryTree<Key, Value>::isEmpty() const
{
  // can simply test size, if it is equal to 0, then it is true the
  // binarytree is empty, if it is not equal, then the answer is false
  return size == 0;
}

/**
 * @brief Overload output stream operator for Binarytree type.
 *
 * Overload the output stream operator so that we can display current
 * values of a Binarytree on standard output.  We can define this in the
 * base class because concrete derived classes must implement the
 * actual str() method that is used here to represent the
 * binarytree as a string object output.
 *
 * @param out The output stream we should send the representation
 *   of the current Binarytree to.
 * @param rhs The Binarytree object to create and return a string
 *   representation of on the output stream.
 *
 * @returns ostream& Returns a reference to the originaly provided
 *   output stream, but after we  have inserted current Binarytree
 *   values / representation onto the stream
 */
template<typename K, typename V>
ostream& operator<<(ostream& out, const BinaryTree<K, V>& rhs)
{
  // reuse Binarytree str() method to stream to output stream
  out << rhs.str();

  // return the modified output stream as our result
  return out;
}

/**
 * @brief Cause specific instance compilations
 *
 * This is a bit of a kludge, but we can use normal make dependencies
 * and separate compilation by declaring template class Binarytree<needed_type>
 * here of any types we are going to be instantianting with the
 * template.
 *
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 * https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
 */
template ostream& operator<<<int, int>(ostream&, const BinaryTree<int, int>&);
template ostream& operator<<<string, double>(ostream&, const BinaryTree<string, double>&);

/**
 * @brief Cause specific instance compilations
 *
 * This is a bit of a kludge, but we can use normal make dependencies
 * and separate compilation by declaring template class
 * BinaryTree<needed_key_type, needed_value_type> here of any types we
 * are going to be instantianting with the template.
 *
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 * https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
 */
template class BinaryTree<int, int>;
template class BinaryTree<string, double>;
