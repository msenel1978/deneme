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
using std::fixed;

#include <string>
using std::string;
using std::getline;

#include <iomanip>
using std::setprecision;
using std::setw;

#include "gradebook.h"

// constructor initializes courseName and grades array
GradeBook::GradeBook( string name, const int gradesArray[][tests] )
{
	int student, test;

	setCourseName(name); // initialize courseName

	// copy grades from gradeArray to grades data member
	for (student = 0; student < students; student++) {

		for (test = 0; test < tests; test++)
			grades[student][test] = gradesArray[student][test];
	}
} // end GradeBook constructor

// function to set the course name
void GradeBook::setCourseName( string name )
{
   courseName = name; // store the course name
} // end function setCourseName

// function to retrieve the course name
string GradeBook::getCourseName() {

	return courseName;
}

void GradeBook::displayMessage() {

	cout << "Welcome to the GradeBook for \n" << getCourseName() << "!" << endl; 
}

void GradeBook::processGrades() {

	outputGrades();

	// call functions getMinimum and getMaximum
	cout << "Lowest grade is " << getMinimum() << "\nHighest grade is "
		<< getMaximum() << endl;

	// call function outputBarChart to print grade distribution chart
	outputBarChart();
}

void GradeBook::outputGrades() {

	int student = 0, test;
	double average;

	cout << "\nThe Grades are:\n\n";
	cout << "            "; // align column heads

	for (test = 0; test < tests; test++)
		cout << "Test " << test + 1 << " ";

	cout << "Average" <<endl;

	for (student = 0; student < students; student++) {
		cout << "Student " << setw(2) << student + 1;

		for (test = 0; test < tests; test++)
			cout << setw(8) << grades[student][test];

		average = getAverage(grades[student], tests);
		cout << setw(9) << setprecision(2) << fixed << average << endl;
	}

}

double GradeBook::getAverage(const int setOfGrades[], const int grades) {

	int total = 0, grade = 0;

	for (grade = 0; grade < grades; grade++)
		total += setOfGrades[grade];

	return static_cast <double> (total) / grades;
}

int GradeBook::getMinimum() {

	int minimum = 100, student, test;

	for (student = 0; student < students; student++) {
		for (test = 0; test < tests; test++)
			if (grades[student][test] < minimum)
				minimum = grades[student][test];
	}

	return minimum;
}

int GradeBook::getMaximum() {

	int maximum = 0, student, test;

	for (student = 0; student < students; student++) {
		for (test = 0; test < tests; test++) {
			if (grades[student][test] > maximum)
				maximum = grades[student][test];
		}
	}

	return maximum;
}

void GradeBook::outputBarChart() {

	int student, test, count, stars;
	const int frequencySize = 11;
	int frequency[frequencySize] = {};

	for (student = 0; student < students; student++) {
		for (test = 0; test < tests; test++)
			frequency[grades[student][test] / 10 ]++;
	}

	cout << "\nGrade distribution:" << endl;

	for (count = 0; count < frequencySize; count++) {
		if (count == 0)
			cout << "  0-9: ";
		else if (count == 10)
			cout << "  100:";
		else
			cout << count * 10 << "-" << (count * 10) + 9 << ":";

		for (stars = 0; stars < frequency[count]; stars++)
			cout << '*';

		cout << endl;
	}

}