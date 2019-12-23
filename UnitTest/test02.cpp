/*test02.cpp*/

//
// Emily Lin
// U. of Illinois, Chicago
// CS 341, Fall 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: Course ParseCourse(string csvline);
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


TEST_CASE("Test 02", "[Project01]")
{ 
  string csvline = "BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Eddington";
  
  REQUIRE(ParseCourse(csvline).Dept == "BIOE");
  REQUIRE(ParseCourse(csvline).Number == 101);
  REQUIRE(ParseCourse(csvline).Section == 01);
  REQUIRE(ParseCourse(csvline).Title == "Intro to Bioengineering");
  
  REQUIRE(ParseCourse(csvline).NumA == 22);
  REQUIRE(ParseCourse(csvline).NumB == 8);           
  REQUIRE(ParseCourse(csvline).NumC == 2);
  REQUIRE(ParseCourse(csvline).NumD == 1);
  REQUIRE(ParseCourse(csvline).NumF == 0);
  
  REQUIRE(ParseCourse(csvline).NumI == 1);
  REQUIRE(ParseCourse(csvline).NumNR == 0);
  REQUIRE(ParseCourse(csvline).NumS == 0);           
  REQUIRE(ParseCourse(csvline).NumU == 0);
  REQUIRE(ParseCourse(csvline).NumW == 5);
   
  REQUIRE(ParseCourse(csvline).Instructor == "Eddington");
}