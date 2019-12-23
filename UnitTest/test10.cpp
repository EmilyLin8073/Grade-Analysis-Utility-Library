/*test10cpp*/

//
// Emily Lin
// U. of Illinois, Chicago
// CS 341, Fall 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: vector<Course> FindCourses(const College& college, int courseNumber);
//             => 0 course found, 1 course found, 2 courses found different department
//                2 courses found same department different course number
//                2 courses found same department same course number different section
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


TEST_CASE("Test 10", "[Project01]")
{
  Course C1("BIOE", "Intro to Bioengineering", 101, 01, "Eddington", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  
  Course C2("CS", "Professional Seminar", 499, 01, "Reed", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  Course C3("CS", "Intro to Engineering", 101, 02, "Reynolds", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  
  Course C4("CS", "Professional Seminar", 251, 01, "Lillis", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  Course C5("CS", "Professional Seminar", 251, 02, "Lillis", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  
  Course C6("Art", "Intro to Art ", 101, 01, "Eddington", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  
  Dept dept1("CS");
  dept1.Courses.push_back(C5);
  dept1.Courses.push_back(C4);
  dept1.Courses.push_back(C3);
  dept1.Courses.push_back(C2);
  
  Dept dept2("BIOE");
  dept2.Courses.push_back(C1);
  
  Dept dept3("Art");
  dept3.Courses.push_back(C6);
  
  
  College college1("Art");
  college1.Depts.push_back(dept3);
  
  College college2("Engineering");
  college2.Depts.push_back(dept1);
  college2.Depts.push_back(dept2);
  
  //0 course found
  REQUIRE(FindCourses(college1, 102).size() == 0);
  
  //1 course found
  REQUIRE(FindCourses(college1, 101).size() == 1);
  
  //2 course found, different department
  REQUIRE(FindCourses(college2, 101).size() == 2);
  REQUIRE(FindCourses(college2, 101).front().Dept == "BIOE");
  REQUIRE(FindCourses(college2, 101).back().Dept == "CS");
  
  //2 courses found, same department, different course number
  REQUIRE(FindCourses(college2, 499).size() == 1);
  REQUIRE(FindCourses(college2, 101).size() == 2);
  
  //2 courses found, same department, same course number, different section
  REQUIRE(FindCourses(college2, 251).size() == 2);
  Course C7 = FindCourses(college2, 251)[0];
  REQUIRE(C7.Section == 01);
}