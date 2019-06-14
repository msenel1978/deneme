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

	// call function getAverage to calculate the average grade
	cout << "\nClass average is " << setprecision( 2 ) << fixed << 
		getAverage() << endl;

	// call functions getMinimum and getMaximum
	cout << "Lowest grade is " << getMinimum() << "\nHighest grade is "
		<< getMaximum() << endl;

	// call function outputBarChart to print grade distribution chart
	outputBarChart();
}

void GradeBook::outputGrades() {

	int student = 0;

	cout << "\nThe Grades are:\n";

	for (student = 0; student < students; student++) {
		cout << "Student " << setw(2) << student + 1 << ": "
			<< setw(3) << grades[student] << endl;
	}

}

double GradeBook::getAverage() {

	int total = 0, student = 0;

	for (student = 0; student < students; student++)
		total += grades[student][test];

	return static_cast <double> (total) / students;
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

	int student, count, stars;
	const int frequencySize = 11;
	int frequency[frequencySize] = {};

	for (student = 0; student < students; student++) {
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