/** @file BinaryTreeException.cpp
 * @brief Implement Exceptions that can be thrown by BinaryTree instances.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * Implement all exception methods that can be generated and thrown by BinaryTree
 * instances.
 */
#include "BinaryTreeException.hpp"
#include <string>
using namespace std;

/**
 * @brief BinaryTreeKeyNotFoundException constructor
 *
 * Constructor for exceptions used for our
 * BinaryTree class.
 *
 * @param message The exception message thrown when an error occurs.
 */
BinaryTreeKeyNotFoundException::BinaryTreeKeyNotFoundException(const string& message)
{
  this->message = message;
}

/**
 * @brief BinaryTreeKeyNotFoundException destructor
 *
 * Destructor for exceptions used for our BinaryTreeKeyNotFoundException
 * class.
 */
BinaryTreeKeyNotFoundException::~BinaryTreeKeyNotFoundException() {}

/**
 * @brief BinaryTreeKeyNotFoundException message
 *
 * Accessor method to access/return message given when an exception occurs.
 *
 * @returns char* Returns a const old style c character array message for
 *   display/use by the process that catches this exception.
 */
const char* BinaryTreeKeyNotFoundException::what() const throw()
{
  // what expects old style array of characters, so convert to that
  return message.c_str();
}