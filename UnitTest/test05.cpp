/*test05.cpp*/

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
//             double GetDFWRate(const College& college, int& DFW, int& N); => corner case
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


TEST_CASE("Test 05", "[Project01]")
{
  int DFW;
  int N;
  
  Course C("BIOE", "Intro to Bioengineering", 101, 01, "Eddington", 
           /*A-F*/0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/38, 27, 21, 33, 29);
  
  Dept dept1("CS");
  dept1.Courses.push_back(C);
  
  Dept dept2("ART");
  
  College college1("Art");
  
  College college2("Engineering");
  college2.Depts.push_back(dept1);

  REQUIRE(dept1.Courses.size() == 1);
  REQUIRE(college2.Depts.size() == 1);
  REQUIRE(college1.Depts.size() == 0);
  REQUIRE(GetDFWRate(dept2, DFW, N) == 0.0);
  REQUIRE(GetDFWRate(college1, DFW, N) == 0.0);
}