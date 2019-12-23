/*test11cpp*/

//
// Emily Lin
// U. of Illinois, Chicago
// CS 341, Fall 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: vector<Course> FindCourses(const College& college, string instructorPrefix);
//             => 0 prefix found, 1 prefix found, 2 prefix found different department
//                2 prefix found same department different course number
//                2 prefix found same department same course number different section
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


TEST_CASE("Test 11", "[Project01]")
{
  Course C1("BIOE", "Intro to Bioengineering", 101, 01, "Max", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  Course C2("CS", "Intro to Python", 102, 01, "Matthew", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  
  Course C3("CS", "Professional Seminar", 499, 01, "Reed", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  Course C4("CS", "Intro to Engineering", 101, 02, "Reynolds", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  
  Course C5("CS", "Professional Seminar", 251, 01, "Lillis", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  Course C6("CS", "Professional Seminar", 251, 02, "Lillis", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  
  Course C7("Art", "Intro to Art ", 101, 01, "Mark", 
            0, 0, 0, 0, 0, 
            0, 20, 20, 0, 20);
  
  Dept dept1("CS");
  dept1.Courses.push_back(C6);
  dept1.Courses.push_back(C5);
  dept1.Courses.push_back(C4);
  dept1.Courses.push_back(C3);
  dept1.Courses.push_back(C2);
  
  Dept dept2("BIOE");
  dept2.Courses.push_back(C1);
  
  Dept dept3("Art");
  dept3.Courses.push_back(C7);
  
  
  College college1("Art");
  college1.Depts.push_back(dept3);
  
  College college2("Engineering");
  college2.Depts.push_back(dept1);
  college2.Depts.push_back(dept2);
  
  
  //0 course found
  REQUIRE(FindCourses(college1, "Em").size() == 0);
  REQUIRE(FindCourses(college2, "Em").size() == 0);
  
  //1 course found
  REQUIRE(FindCourses(college1, "Ma").size() == 1);
  
  //2 courses found, different department
  REQUIRE(FindCourses(college2, "Ma").size() == 2);
  REQUIRE(FindCourses(college2, "Ma").front().Dept == "BIOE");
  
  //2 courses found, same department, different course number
  REQUIRE(FindCourses(college2, "Re").size() == 2);
  REQUIRE(FindCourses(college2, "Re").front().Number == 101);
  
  //2 course found, same department, same course number, different section
  REQUIRE(FindCourses(college2, "Li").size() == 2);
  REQUIRE(FindCourses(college2, "Li").front().Section == 01);
  
  //Empty string should return all the course in vector
  REQUIRE(FindCourses(college1, "").size() == 1);
  REQUIRE(FindCourses(college1, "").front().Instructor == "Mark");
  REQUIRE(FindCourses(college1, "").front().Dept == "Art");
  REQUIRE(FindCourses(college1, "").front().Number == 101);
  REQUIRE(FindCourses(college1, "").front().Section == 01);
  
  REQUIRE(FindCourses(college2, "").size() == 6);
  REQUIRE(FindCourses(college2, "").front().Instructor == "Max");
  REQUIRE(FindCourses(college2, "").front().Dept == "BIOE");
  REQUIRE(FindCourses(college2, "").front().Number == 101);
  REQUIRE(FindCourses(college2, "").front().Section == 01);
 
  
  //Input more than two characters
  REQUIRE(FindCourses(college1, "Mar").size() == 1);
  REQUIRE(FindCourses(college2, "Ree").size() == 1);
  REQUIRE(FindCourses(college2, "Reed").size() == 1);
  
  //Input less than two characters
  REQUIRE(FindCourses(college2, "R").size() == 2);
  
  //Input with all lower cases
  REQUIRE(FindCourses(college2, "re").size() == 0);
}