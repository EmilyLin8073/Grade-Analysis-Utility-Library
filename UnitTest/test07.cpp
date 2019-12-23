/*test07cpp*/

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
//             GradeStats GetGradeDistribution(const College& college);
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


TEST_CASE("Test 07", "[Project01]")
{ 
//   int numA = 59;
//   int numB = 44;
//   int numC = 37;
//   int numD = 85;
//   int numF = 3;
  
  double epsilon = 0.001;
  double expectValueA = 25.877;
  double expectValueB = 19.298;
  double expectValueC = 16.228;
  double expectValueD = 37.281;
  double expectValueF = 1.316;
    
  Course C1("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/59, 44, 37, 85, 3, 
           /*I,S,U,W,NR*/0, 0, 0, 0, 0);
  
  Course C2("CS", "Intro to Engineering", 101, 01, "Reed", 
            /*A-F*/0, 0, 0, 0, 0, 
            /*I,S,U,W,NR*/6, 9, 44, 15, 8);
  
  Course C3("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/11, 35, 22, 57, 18, 
           /*I,S,U,W,NR*/0, 0, 0, 0, 0);
  
  Dept dept1("CS");
  dept1.Courses.push_back(C1);
  dept1.Courses.push_back(C2);
  dept1.Courses.push_back(C3);
  
  Dept dept2("Art");
  
  College college("Engineering");
  college.Depts.push_back(dept1);
  
  GradeStats gradeStats = GetGradeDistribution(dept1);
  GradeStats gradeStats2 = GetGradeDistribution(dept2);
  
  REQUIRE(C1.getGradingType() == Course::Letter);
  
  REQUIRE(GetGradeDistribution(C1).N == 228);
  REQUIRE(GetGradeDistribution(C2).N == 0);
  REQUIRE(GetGradeDistribution(C3).N == 143);
  REQUIRE(gradeStats.N == 228 + 143);
  REQUIRE(gradeStats2.N == 0);
  REQUIRE(GetGradeDistribution(college).N == 228 + 143);
  
  REQUIRE(gradeStats.NumA == 59 + 11);
  REQUIRE(gradeStats.NumB == 44 + 35);
  REQUIRE(gradeStats.NumC == 37 + 22);
  REQUIRE(gradeStats.NumD == 85 + 57);
  REQUIRE(gradeStats.NumF == 3 + 18);
  
  REQUIRE(gradeStats2.NumA == 0);
  REQUIRE(gradeStats2.NumB == 0);
  REQUIRE(gradeStats2.NumC == 0);
  REQUIRE(gradeStats2.NumD == 0);
  REQUIRE(gradeStats2.NumF == 0);

  REQUIRE(abs(GetGradeDistribution(C1).PercentA - expectValueA) < epsilon);
  REQUIRE(abs(GetGradeDistribution(C1).PercentB - expectValueB) < epsilon);
  REQUIRE(abs(GetGradeDistribution(C1).PercentC - expectValueC) < epsilon);
  REQUIRE(abs(GetGradeDistribution(C1).PercentD - expectValueD) < epsilon);
  REQUIRE(abs(GetGradeDistribution(C1).PercentF - expectValueF) < epsilon);
  
  REQUIRE(abs(GetGradeDistribution(dept1).PercentA - 18.868) < epsilon);
  REQUIRE(abs(GetGradeDistribution(dept1).PercentB - 21.294) < epsilon);
  REQUIRE(abs(GetGradeDistribution(dept1).PercentC - 15.903) < epsilon);
  REQUIRE(abs(GetGradeDistribution(dept1).PercentD - 38.275) < epsilon);
  REQUIRE(abs(GetGradeDistribution(dept1).PercentF - 5.660) < epsilon);
  
  REQUIRE(abs(GetGradeDistribution(college).PercentA - 18.868) < epsilon);
  REQUIRE(abs(GetGradeDistribution(college).PercentB - 21.294) < epsilon);
  REQUIRE(abs(GetGradeDistribution(college).PercentC - 15.903) < epsilon);
  REQUIRE(abs(GetGradeDistribution(college).PercentD - 38.275) < epsilon);
  REQUIRE(abs(GetGradeDistribution(college).PercentF - 5.660) < epsilon);  
}