/*
 * OddThreadFunction.hpp
 *
 *  Created on: 22-Sep-2019
 *      Author: Raj
 */

#ifndef ODDTHREADFUNCTION_HPP_
#define ODDTHREADFUNCTION_HPP_
#include <iostream>
#include <memory>
#include "Variable.hpp"

namespace MultiThread {

class OddThreadFunction {
 private:
  static std::once_flag once;
  static std::unique_ptr<OddThreadFunction> instance;
 public:  // For default constructor
  OddThreadFunction() = default;
 public:  // For restricting use of any other functions
  OddThreadFunction(const OddThreadFunction&) = delete;
  OddThreadFunction& operator=(const OddThreadFunction&) = delete;
  OddThreadFunction(OddThreadFunction&&) = delete;
  OddThreadFunction& operator=(OddThreadFunction&&) = delete;
 public:  // Overloading "()" operator
  void operator()() {
    while (!Variable::isMaxReached) {
      std::unique_lock<std::mutex> locker(Variable::mutexLock);
      Variable::conditionalNotification.wait(locker, []() {
        return (Variable::i % 2 != 0);
      });
      std::cout << "Odd  :    " << Variable::i << std::endl;
      if (++Variable::i >= Variable::MaxNo) {
        Variable::isMaxReached = true;
      }
      locker.unlock();
      Variable::conditionalNotification.notify_all();
    }
  }
  static OddThreadFunction& getInstance() {
    std::call_once(once, []() {
      instance.reset(new OddThreadFunction);
    });
    return *instance.get();
  }
};

} /* namespace MultiThread */

#endif /* ODDTHREADFUNCTION_HPP_ */
