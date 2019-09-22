/*
 * EvenThreadFunction.hpp
 *
 *  Created on: 22-Sep-2019
 *      Author: Raj
 */

#ifndef EVENTHREADFUNCTION_HPP_
#define EVENTHREADFUNCTION_HPP_
#include <iostream>
#include "Variable.hpp"
#include <memory>

namespace MultiThread {

class EvenThreadFunction {
 private:
  static std::unique_ptr<EvenThreadFunction> instance;
  static std::once_flag once;
 public:  // For default constructor
  EvenThreadFunction() = default;
 public:  // For restricting use of any other functions
  EvenThreadFunction(const EvenThreadFunction&) = delete;
  EvenThreadFunction& operator=(const EvenThreadFunction&) = delete;
  EvenThreadFunction(EvenThreadFunction&&) = delete;
  EvenThreadFunction& operator=(EvenThreadFunction&&) = delete;
 public:  // Overloading "()" operator
  void operator()(void) {
    while (!Variable::isMaxReached) {
      std::unique_lock<std::mutex> locker(Variable::mutexLock);
      Variable::conditionalNotification.wait(locker, []() {
        return (Variable::i % 2 == 0);
      });
      std::cout << "Even :    " << Variable::i << std::endl;
      if (++Variable::i >= Variable::MaxNo)
      {
        Variable::isMaxReached = true;
      }
      locker.unlock();
      Variable::conditionalNotification.notify_all();
    }
  }
  static EvenThreadFunction& getInstance() {
    std::call_once(once, []() {
      instance.reset(new EvenThreadFunction);
    });
    return *instance.get();
  }
};

} /* namespace MultiThread */

#endif /* EVENTHREADFUNCTION_HPP_ */
