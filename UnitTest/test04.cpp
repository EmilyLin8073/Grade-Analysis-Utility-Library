/*test04.cpp*/

//
// Emily Lin
// U. of Illinois, Chicago
// CS 341, Fall 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: double GetDFWRate(const Course& c, int& DFW, int& N); 
//             double GetDFWRate(const Dept& dept, int& DFW, int& N);
//             double GetDFWRate(const College& college, int& DFW, int& N); => general case
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


TEST_CASE("Test 04", "[Project01]")
{
  int DFW = 232;
  int N = 372;
  double epsilon = 0.001;
  double expectValue = 62.366;
  
  Course C1("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/59, 44, 37, 85, 3, 
           /*I,S,U,W,NR*/4, 9, 15, 144, 2);
  
  Course C2("CS", "Intro to Engineering", 101, 01, "Reed", 
            /*A-F*/0, 0, 0, 0, 0, 
            /*I,S,U,W,NR*/14, 22, 27, 0, 39);
  
  Dept dept("CS");
  dept.Courses.push_back(C1);
  dept.Courses.push_back(C2);
  
  College college("Engineering");
  college.Depts.push_back(dept);
  
  REQUIRE(abs(GetDFWRate(C1, DFW, N) - expectValue) < epsilon);
  REQUIRE(abs(GetDFWRate(dept, DFW, N) - expectValue) < epsilon);
  REQUIRE(abs(GetDFWRate(college, DFW, N) - expectValue) < epsilon);
  
  REQUIRE(C1.getGradingType() == Course::Letter);
}