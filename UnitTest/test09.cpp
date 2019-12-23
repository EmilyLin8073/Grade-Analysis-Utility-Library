/*test09cpp*/

//
// Emily Lin
// U. of Illinois, Chicago
// CS 341, Fall 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: vector<Course> FindCourses(const Dept& dept, string instructorPrefix); 
//             => 0 prefix found, 1 prefix found, 2 prefix found different course number, 
//                2 prefix found same course number
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


TEST_CASE("Test 09", "[Project01]")
{
  Course C1("CS", "Professional Seminar", 141, 01, "Hummel", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  Course C2("CS", "Professional Seminar", 499, 01, "Reed", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  Course C3("CS", "Professional Seminar", 151, 02, "Reynolds", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  
  Course C4("CS", "Professional Seminar", 251, 01, "Lillis", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  Course C5("CS", "Professional Seminar", 251, 02, "Lillis", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  
  Dept dept("CS");
  dept.Courses.push_back(C5);
  dept.Courses.push_back(C4);
  dept.Courses.push_back(C3);
  dept.Courses.push_back(C2);
  dept.Courses.push_back(C1);
  
  REQUIRE(FindCourses(dept, "Em").size() == 0);
  REQUIRE(FindCourses(dept, "Hu").size() == 1);
  
  //Same prefix, different course number
  REQUIRE(FindCourses(dept, "Re").size() == 2);
  REQUIRE(FindCourses(dept, "Re").front().Number == 151);
  
  //Same prefix, same course number
  REQUIRE(FindCourses(dept, "Li").size() == 2);
  REQUIRE(FindCourses(dept, "Li").front().Section == 01);
}