/** @file Employee.hpp
 * @brief Basic example user defined class to hold Employee record.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * @description Simple example of an Employee record/class
 *   we can use to demonstrate  key/value pair
 *   management.
 */
#include <iostream>
#include <string>
using namespace std;

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

// This should really be a class constant, however this
// global constant represents a flag that is used to
// indicate empty slots and/or failed search.
const int EMPTY_EMPLOYEE_ID = 0;

/** @class Employee
 * @brief A simple example Employee record
 *
 * A simple Employee class/record to demonstrate/test our hashing
 * dictionary assignment.  NOTE: we are using 0 as a flag to represent
 * an unused slot or an invalid/empty employee.  This is used/assumed
 * by our dictionary class to determine if a slot is empty and/or to
 * give a failure result for a failed search.
 */
class Employee
{
public:
  // constructors
  Employee();
  Employee(int id, string name, string address, float salary);

  // accessor methods
  int getId() const;
  string getName() const;
  string str() const;

  // class operators
  friend ostream& operator<<(ostream& out, Employee& employee);

private:
  int id;
  string name;
  string address;
  float salary;
};

#endif // EMPLOYEE_HPP
