/*
 * Variable.cpp
 *
 *  Created on: 22-Sep-2019
 *      Author: Raj
 */

#include "Variable.hpp"

namespace MultiThread {

unsigned int Variable::i = 1;
unsigned int Variable::MaxNo;
bool Variable::isMaxReached = false;

std::mutex Variable::mutexLock;
std::condition_variable Variable::conditionalNotification;

} /* namespace MultiThread */
