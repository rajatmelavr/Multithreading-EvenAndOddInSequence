/*
 * Variable.hpp
 *
 *  Created on: 22-Sep-2019
 *      Author: Raj
 */

#ifndef VARIABLE_HPP_
#define VARIABLE_HPP_

#include <mutex>
#include <condition_variable>

namespace MultiThread {

class Variable {
 public: // For Mutex
  static std::mutex mutexLock;
  static std::condition_variable conditionalNotification;
  static bool isMaxReached;
 public: // For normal member Variable
  static unsigned int i;
  static unsigned int MaxNo;
 public: // For member function
  Variable() = delete;
  Variable(const Variable&) = delete;
  Variable& operator=(const Variable&) = delete;
  Variable(Variable&&) = delete;
  Variable& operator=(Variable&&) = delete;
};

} /* namespace MultiThread */

#endif /* VARIABLE_HPP_ */
