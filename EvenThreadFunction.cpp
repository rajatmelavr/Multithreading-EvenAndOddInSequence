/*
 * EvenThreadFunction.cpp
 *
 *  Created on: 22-Sep-2019
 *      Author: Raj
 */

#include "EvenThreadFunction.hpp"

namespace MultiThread {
std::once_flag EvenThreadFunction::once;
std::unique_ptr<EvenThreadFunction> EvenThreadFunction::instance;
} /* namespace MultiThread */
