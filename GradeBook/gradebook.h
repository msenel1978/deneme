#ifndef gradebook_h
#define gradebook_h

#include <string>
using std::string;

class GradeBook {

public:
	// constant -- number of students who took the test
   const static int students = 10;	// note public data
   const static int tests = 3; 		// number of tests

   // constructor initializes course name and array of grades
   GradeBook(string, const int [][tests]);

   void setCourseName(string);					// function to set the course name
   string getCourseName();						// function to retrieve the course name
   void displayMessage();						// display a welcome message
   double getAverage(const int [], const int);	// determine the average grade for the test
   int getMinimum();							// find the minimum grade for the test
   int getMaximum();							// find the maximum grade for the test
   void processGrades();						// perform various operations on the grade data
   void outputBarChart();						// output bar chart of grade distribution
   void outputGrades();							// output the contents of the grades array


private:
   string courseName; // course name for this grade book
   int grades[students][tests]; // array of student grades
};

#endif