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
#include "Employee.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/**
 * @brief Default constructor
 *
 * Default constructor for our Employee record/class.  Construct an
 * empty employee record
 */
Employee::Employee()
{
  this->id = EMPTY_EMPLOYEE_ID;
  this->name = "";
  this->address = "";
  this->salary = 0.0;
}

/**
 * @brief Standard constructor
 *
 * Basic constructor for our Employee record/class.
 */
Employee::Employee(int id, string name, string address, float salary)
{
  this->id = id;
  this->name = name;
  this->address = address;
  this->salary = salary;
}

/**
 * @brief id accessor
 *
 * Accessor method to get the employee id.
 *
 * @returns int Returns the integer employee id value.
 */
int Employee::getId() const
{
  return id;
}

/**
 * @brief name accessor
 *
 * Accessor method to get the employee name.
 *
 * @returns string Returns the string containing the full
 *   employee name for this record.
 */
string Employee::getName() const
{
  return name;
}

/**
 * @brief Employee to string
 *
 * Create and return a string representation of this Employee record.
 *
 * @returns string Returns a string representation of the information in
 *   this Employee record.
 */
string Employee::str() const
{
  ostringstream out;

  out << "( id: " << id << ", " << name << ", " << address << ", " << fixed << setprecision(2) << salary << " )";

  return out.str();
}

/**
 * @brief overload output streaming operator
 *
 * Friend function to ouput representation of Employee to an
 * output stream.
 *
 * @param out A reference to an output stream to which we should
 *   send the representation of an employee record for display.
 * @param employee The reference to the employee record to be displayed.
 *
 * @returns ostream& Returns a reference to the original output
 *   stream, but now the employee information should have been
 *   inserted into the stream for display.
 */
ostream& operator<<(ostream& out, Employee& employee)
{
  // out << "( id: " << employee.id << ", "
  //    << employee.name << ", "
  //    << employee.address << ", "
  //    << fixed << setprecision(2) << employee.salary << " )" << endl;
  out << employee.str();

  return out;
}
