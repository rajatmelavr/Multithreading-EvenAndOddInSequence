# Makefile for Multithreading-EvenAndOddInSequence-master
# Author: Raj Prajapati
# Date: 25 Sept 2019
#------------------------------------------------
#Description : This Makefile is creating the individual objects and after that
# its creating the executable
 
#Flags
CXXFLAGS= -Wall -Wextra -Werror -std=c++11 -g3 -fmessage-length=0
 
#Compiler
CXX= g++
 
#Creation of object files
EvenThreadFunction.o:EvenThreadFunction.cpp EvenThreadFunction.hpp
	${CXX} ${CXXFLAGS} -c EvenThreadFunction.cpp
 
#Creation of object files
OddThreadFunction.o:OddThreadFunction.cpp OddThreadFunction.hpp
	${CXX} ${CXXFLAGS} -c OddThreadFunction.cpp
 
#Creation of object files
Variable.o:Variable.cpp Variable.hpp
	${CXX} ${CXXFLAGS} -c Variable.cpp
 
#Creation of object files
PrintingEvenOddMultithreading.o:EvenThreadFunction.hpp OddThreadFunction.hpp Variable.hpp
	${CXX} ${CXXFLAGS} -c PrintingEvenOddMultithreading.cpp
 
#Creation of Executable, Don not forget to give the dependencies
all:PrintingEvenOddMultithreading.o Variable.o OddThreadFunction.o EvenThreadFunction.o
	${CXX} ${CXXFLAGS} PrintingEvenOddMultithreading.o Variable.o OddThreadFunction.o EvenThreadFunction.o -o EvenOddMultithreading -L/usr/local/lib/ -lpthread
clean:
	rm -rf *.o EvenOddMultithreading