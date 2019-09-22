/*
 * OddThreadFunction.cpp
 *
 *  Created on: 22-Sep-2019
 *      Author: Raj
 */

#include "OddThreadFunction.hpp"

namespace MultiThread {

std::once_flag OddThreadFunction::once;
std::unique_ptr<OddThreadFunction> OddThreadFunction::instance;
} /* namespace MultiThread */
