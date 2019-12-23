/*test08cpp*/

//
// Emily Lin
// U. of Illinois, Chicago
// CS 341, Fall 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: vector<Course> FindCourses(const Dept& dept, int courseNumber); 
//             => 0 course found, 1 course found, 2 course found with same course number
// 
// *****************************************************************


#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;


TEST_CASE("Test 08", "[Project01]")
{
  Course C1("CS", "Professional Seminar", 499, 01, "Hummel", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  Course C2("CS", "Professional Seminar", 499, 02, "Hummel", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  
  Course C3("CS", "Professional Seminar", 141, 01, "Reed", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  
  Dept dept("CS");
  dept.Courses.push_back(C3);
  dept.Courses.push_back(C2);
  dept.Courses.push_back(C1);
  
  REQUIRE(FindCourses(dept, 151).empty() == true);
  REQUIRE(FindCourses(dept, 141).size() == 1);
  REQUIRE(FindCourses(dept, 499).size() == 2);
  REQUIRE(FindCourses(dept, 499).front().Section == 01);
}