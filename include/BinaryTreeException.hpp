/** @file BinaryTreeException.hpp
 * @brief Declare Exceptions that can be thrown by BinaryTree instances.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment BinaryTrees
 * @date   June 1, 2021
 *
 * Declare all exceptions that can be generated and thrown by BinaryTree
 * instances.
 */
#ifndef _BINARYTREE_EXCEPTION_HPP_
#define _BINARYTREE_EXCEPTION_HPP_
#include <string>
using namespace std;

/** @class BinaryTreeKeyNotFoundException
 * @brief BinaryTree Key Not Found Exception for the Binarytree class.
 *
 * Exception to be thrown by our BinaryTree class if attempt to find
 * or remove a Key from the tree and that key is not present in the
 * tree.
 *
 */
class BinaryTreeKeyNotFoundException : public exception
{
public:
  explicit BinaryTreeKeyNotFoundException(const string& message);
  ~BinaryTreeKeyNotFoundException();
  virtual const char* what() const throw();

private:
  /// Stores the particular message describing what caused the exception.
  string message;
};

#endif // _BINARYTREE_EXCEPTION_HPP_