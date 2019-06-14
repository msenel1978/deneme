/*
 * =====================================================================================
 *
 *       Filename:  gradebook.cpp
 *
 *    Description:  Sample Program to try classes and objects
 *
 *        Version:  1.0
 *        Created:  02/27/2019 21:38:26
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Murat Senel (msenel@gmail.com)
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::getline;

#include "gradebook.h"

//int main(int argc, char const *argv[]) {
int main(void) {
  // array of student grades
  int gradesArray[GradeBook::students][GradeBook::tests] = {
    {87, 96, 70},
    {68, 87, 90},
    {94, 100, 90},
    {100, 81, 82},
    {83, 65, 65},
    {78, 87, 65},
    {85, 75, 83},
    {91, 94, 100},
    {76, 72, 84},
    {87, 93, 73}};

  GradeBook myGradeBook ("CS101 Introduction to C++ Programming", gradesArray);

  myGradeBook.displayMessage();
  myGradeBook.processGrades();

  return 0;
}
