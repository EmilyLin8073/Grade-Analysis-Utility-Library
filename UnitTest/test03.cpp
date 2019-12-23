/*test03.cpp*/

//
// Emily Lin
// U. of Illinois, Chicago
// CS 341, Fall 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: double GetDFWRate(const Course& c, int& DFW, int& N); => corner case
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


TEST_CASE("Test 03", "[Project01]")
{
  int DFW;
  int N;
  
  Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/38, 27, 21, 33, 29);
  
  Course C1("CS", "Professional Seminar", 499, 02, "Hummel", 
           /*A-F*/0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/0, 0, 0, 33, 29);
  
  Dept dept("CS");
  dept.Courses.push_back(C);
  dept.Courses.push_back(C1);
  
  College college("Engineering");
  college.Depts.push_back(dept);
  
  REQUIRE(C.getGradingType() == Course::Satisfactory);
  REQUIRE(C1.getGradingType() == Course::Unknown);
  
  REQUIRE(GetDFWRate(C, DFW, N) == 0.0);
  REQUIRE(GetDFWRate(dept, DFW, N) == 0.0);
  REQUIRE(GetDFWRate(college, DFW, N) == 0.0);
  
  REQUIRE(GetDFWRate(C1, DFW, N) == 0.0);
  
  REQUIRE(N == 0);
  REQUIRE(DFW == 0);
}