/*test06.cpp*/

//
// Emily Lin
// U. of Illinois, Chicago
// CS 341, Fall 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: GradeStats GetGradeDistribution(const Course& c); 
//             GradeStats GetGradeDistribution(const Dept& dept);
//             GradeStats GetGradeDistribution(const College& college); => corner case
// should fail 8(stat)
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


TEST_CASE("Test 06", "[Project01]")
{ 
  int numA = 0;
  int numB = 0;
  int numC = 0;
  int numD = 0;
  int numF = 0;
  
  
  Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/numA, numB, numC,numD, numF, 
           /*I,S,U,W,NR*/24, 20, 20, 33, 16);
  
  Dept dept("CS");
  dept.Courses.push_back(C);
  
  College college("Engineering");
  college.Depts.push_back(dept);
    
  REQUIRE(C.getGradingType() != Course::Letter);
  
  REQUIRE(GetGradeDistribution(C).N == 0);
  REQUIRE(GetGradeDistribution(C).NumA == 0);
  REQUIRE(GetGradeDistribution(C).NumB == 0);
  REQUIRE(GetGradeDistribution(C).NumC == 0);
  REQUIRE(GetGradeDistribution(C).NumD == 0);
  REQUIRE(GetGradeDistribution(C).NumF == 0);
    
  REQUIRE(GetGradeDistribution(C).PercentA == 0.0);
  REQUIRE(GetGradeDistribution(C).PercentB == 0.0);
  REQUIRE(GetGradeDistribution(C).PercentC == 0.0);
  REQUIRE(GetGradeDistribution(C).PercentD == 0.0);
  REQUIRE(GetGradeDistribution(C).PercentF == 0.0);
  
  REQUIRE(GetGradeDistribution(dept).N == 0);
  REQUIRE(GetGradeDistribution(dept).NumA == 0);
  REQUIRE(GetGradeDistribution(dept).NumB == 0);
  REQUIRE(GetGradeDistribution(dept).NumC == 0);
  REQUIRE(GetGradeDistribution(dept).NumD == 0);
  REQUIRE(GetGradeDistribution(dept).NumF == 0);
    
  REQUIRE(GetGradeDistribution(dept).PercentA == 0.0);
  REQUIRE(GetGradeDistribution(dept).PercentB == 0.0);
  REQUIRE(GetGradeDistribution(dept).PercentC == 0.0);
  REQUIRE(GetGradeDistribution(dept).PercentD == 0.0);
  REQUIRE(GetGradeDistribution(dept).PercentF == 0.0);
  
  REQUIRE(GetGradeDistribution(college).N == 0);
  REQUIRE(GetGradeDistribution(college).NumA == 0);
  REQUIRE(GetGradeDistribution(college).NumB == 0);
  REQUIRE(GetGradeDistribution(college).NumC == 0);
  REQUIRE(GetGradeDistribution(college).NumD == 0);
  REQUIRE(GetGradeDistribution(college).NumF == 0);
    
  REQUIRE(GetGradeDistribution(college).PercentA == 0.0);
  REQUIRE(GetGradeDistribution(college).PercentB == 0.0);
  REQUIRE(GetGradeDistribution(college).PercentC == 0.0);
  REQUIRE(GetGradeDistribution(college).PercentD == 0.0);
  REQUIRE(GetGradeDistribution(college).PercentF == 0.0);
}