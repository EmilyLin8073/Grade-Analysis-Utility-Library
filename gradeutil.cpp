/*gradeutil.cpp*/

//
// Emily Lin
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #02: GradeUtil API
// 

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "gradeutil.h"

using namespace std;

void Dept::addCourse(Course course)
{
  // Add course to Courses.
  //Dept dept(course.Dept);
  this->Courses.push_back(course);
}

void College::addDepartment(Dept department)
{
  // Add department to Depts.
  //College college(department.Name);
  this->Depts.push_back(department);
}



//
// API:
//

// 
// ParseCourse:
//
// Parses a CSV (comma-separated values) line into a Course
// object, which is then returned.  The given line must have
// the following format:
//
//   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor
//
// Example:
//   BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Eddington
//
// Note the lack of spaces, except perhaps in the title.
// If the given line does not have this format, the behavior 
// of the function is undefined (it may crash, it may throw
// an exception, it may return).
//
Course ParseCourse(string csvline) //Done
{
  //  Course(string dept, string title, int number, int section, string instructor,
  //         int A, int B, int C, int D, int F, int I, int S, int U, int W, int NR)
  
  Course C;
  stringstream parseLine(csvline);
  string dept, title, number, section, instructor, a, b, c, d, f, i, nr, s, u, w;
  
  //Parse the CSV line
  getline(parseLine, dept, ',');
  getline(parseLine, number, ',');
  getline(parseLine, section, ',');
  getline(parseLine, title, ',');
  getline(parseLine, a, ',');
  getline(parseLine, b, ',');
  getline(parseLine, c, ',');
  getline(parseLine, d, ',');
  getline(parseLine, f, ',');
  getline(parseLine, i, ',');
  getline(parseLine, nr, ',');
  getline(parseLine, s, ',');
  getline(parseLine, u, ',');
  getline(parseLine, w, ',');
  getline(parseLine, instructor);
  
  return Course(dept, title, stoi(number), stoi(section), instructor, stoi(a), stoi(b), stoi(c), 
                stoi(d), stoi(f), stoi(i), stoi(s), stoi(u), stoi(w), stoi(nr));
}


//
// GetDFWRate:
//
// Returns the DFW rate as a percentage for a given course, 
// department, or college.  For a course whose grading type 
// is defined as Course::Letter, the DFW rate is defined as
// 
//   # of D grades + F grades + Withdrawals
//   -------------------------------------- * 100.0
//   # of A, B, C, D, F grades + Withdrawls
//
// The numerator is returned via the reference parameter DFW;
// the denominator is returned via the reference parameter N.
// If the course grading type is not Course::Letter, the DFW
// rate is 0.0, and parameters DFW and N are set to 0.  
//
// When computed for a dept or college, all courses of type 
// Course::Letter are considered in computing an overall DFW 
// rate for the dept or college.  The reference parameters 
// DFW and N are also computed across the dept or college.
//
double GetDFWRate(const Course& c, int& DFW, int& N)
{  
  double percent = 100.0;
  
  if(c.getGradingType() == Course::Letter)
  {
    DFW = c.NumD + c.NumF + c.NumW;
    N = c.NumA + c.NumB + c.NumC + c.NumD + c.NumF + c.NumW;
    return (((DFW) / (double) N ) * percent);
  }
  else
  {
    DFW = 0;
    N = 0; 
  }
    
  return 0.0;
}

double GetDFWRate(const Dept& dept, int& DFW, int& N)
{
  DFW = 0;
  N = 0;
  
  double percent = 100.0;
    
  if(dept.Courses.size() == 0)
  {
      return 0.0;
  }
  else
  {
    for(const Course& c: dept.Courses)
    {   
      if(c.getGradingType() == Course::Letter)
      {
        DFW = DFW + c.NumD + c.NumF + c.NumW;
        N = N + c.NumA + c.NumB + c.NumC + c.NumD + c.NumF + c.NumW;
      }
      else
      {
        DFW = DFW + 0;
        N = N + 0;
      }
    }     
  }
    
  if(N != 0)
  {
    return (((DFW) / (double) N ) * percent);      
  }
  else
  {
    N = 0;
    DFW = 0;       
  }
    
  return 0.0; 
}

double GetDFWRate(const College& college, int& DFW, int& N)
{
  DFW = 0;
  N   = 0;
  
  double percent = 100.0;
   
  if(college.Depts.size() == 0)
  {
      return 0.0;
  }
  else
  {
    for(const Dept& dept: college.Depts)
    {
      for(const Course& c: dept.Courses)
      {
        if(c.getGradingType() == Course::Letter)
        {
          DFW = DFW + c.NumD + c.NumF + c.NumW;
          N = N + c.NumA + c.NumB + c.NumC + c.NumD + c.NumF + c.NumW;
        }
        else
        {
          DFW = DFW + 0;
          N = N + 0;
        }  
      }
    }
  }
  
  if(N != 0)
  {
    return (((DFW) / (double) N ) * percent);      
  }
  else
  {
    N = 0;
    DFW = 0;       
  }
    
  return 0.0; 
}  


//
// GetGradeDistribution
//
// Returns an object containing the grade distribution for a given
// course, dept or college.  For a course whose grading type is
// defined as Course::Letter, the grade distribution is defined by
// the following values:
//
//   N: the # of A, B, C, D, F grades
//   NumA, NumB, NumC, NumD, NumF: # of A, B, C, D, F grades
//   PercentA, PercentB, PercentC, PercentD, PercentF: % of A, B, 
//     C, D, F grades.  Example: PercentA = NumA / N * 100.0
//
// If the course grading type is not Course::Letter, all values
// are 0.  When computed for a dept or college, all courses of
// type Course::Letter are considered in computing an overall 
// grade distribution for the dept or college.
//
GradeStats GetGradeDistribution(const Course& c)
{
  //	GradeStats(int n, int numA, int numB, int numC, int numD, int numF,
  //	           double percentA, double percentB, double percentC, double percentD, double percentF)
  int n = 0;
  int numA = 0;
  int numB = 0;
  int numC = 0;
  int numD = 0;
  int numF = 0;
  
  double percentA = 0.0;
  double percentB = 0.0;
  double percentC = 0.0;   
  double percentD = 0.0;
  double percentF = 0.0;
  
  double percent = 100.0;
  
  if(c.getGradingType() == Course::Letter)
  {
    n = c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;
    numA = c.NumA;
    numB = c.NumB;
    numC = c.NumC;
    numD = c.NumD;
    numF = c.NumF;
    
    percentA = ((numA / (double)n)) * percent;
    percentB = ((numB / (double)n)) * percent;
    percentC = ((numC / (double)n)) * percent;
    percentD = ((numD / (double)n)) * percent;
    percentF = ((numF / (double)n)) * percent;
  }
  if(n == 0)
  {
    numA = 0;
    numB = 0;
    numC = 0;
    numD = 0;
    numF = 0;
    
    percentA = 0.0;
    percentB = 0.0;
    percentC = 0.0;
    percentD = 0.0;
    percentF = 0.0;

  }
  
  return GradeStats(n, numA, numB, numC, numD, numF, percentA, percentB, percentC, percentD, percentF); 
}

GradeStats GetGradeDistribution(const Dept& dept)
{
  int n = 0;
  int numA = 0;
  int numB = 0;
  int numC = 0;
  int numD = 0;
  int numF = 0;
  
  double percentA = 0.0;
  double percentB = 0.0;
  double percentC = 0.0;   
  double percentD = 0.0;
  double percentF = 0.0;
  
  double percent = 100.0;
  
  for(const Course& c: dept.Courses)
  {
    if(c.getGradingType() == Course::Letter)
    {
      n = n + c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;
      numA = numA + c.NumA;
      numB = numB + c.NumB;
      numC = numC + c.NumC;
      numD = numD + c.NumD;
      numF = numF + c.NumF;
    
      percentA = ((numA / (double)n)) * percent;
      percentB = ((numB / (double)n)) * percent;
      percentC = ((numC / (double)n)) * percent;
      percentD = ((numD / (double)n)) * percent;
      percentF = ((numF / (double)n)) * percent;
    }
    else
    {
      n += 0;
      numA += 0;
      numB += 0;
      numC += 0;
      numD += 0;
      numF += 0;
    
      percentA = ((numA / (double)n)) * percent;
      percentB = ((numB / (double)n)) * percent;
      percentC = ((numC / (double)n)) * percent;
      percentD = ((numD / (double)n)) * percent;
      percentF = ((numF / (double)n)) * percent;
    }
  }
  
  if(n == 0)
  {
    numA = 0;
    numB = 0;
    numC = 0;
    numD = 0;
    numF = 0;
    
    percentA = 0.0;
    percentB = 0.0;
    percentC = 0.0;
    percentD = 0.0;
    percentF = 0.0;
  }
  
  return GradeStats(n, numA, numB, numC, numD, numF, percentA, percentB, percentC, percentD, percentF);
}

GradeStats GetGradeDistribution(const College& college)
{
  int n = 0;
  int numA = 0;
  int numB = 0;
  int numC = 0;
  int numD = 0;
  int numF = 0;
  
  double percentA = 0.0;
  double percentB = 0.0;
  double percentC = 0.0;   
  double percentD = 0.0;
  double percentF = 0.0;
  
  double percent = 100.0;
  
  for(const Dept& dept: college.Depts)
  {
    for(const Course& c: dept.Courses)
    {
      if(c.getGradingType() == Course::Letter)
      {
        n = n + c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;
        numA = numA + c.NumA;
        numB = numB + c.NumB;
        numC = numC + c.NumC;
        numD = numD + c.NumD;
        numF = numF + c.NumF;
    
        percentA = ((numA / (double)n)) * percent;
        percentB = ((numB / (double)n)) * percent;
        percentC = ((numC / (double)n)) * percent;
        percentD = ((numD / (double)n)) * percent;
        percentF = ((numF / (double)n)) * percent;
      }
      else
      {
        n += 0;
        numA += 0;
        numB += 0;
        numC += 0;
        numD += 0;
        numF += 0;
    
        percentA = ((numA / (double)n)) * percent;
        percentB = ((numB / (double)n)) * percent;
        percentC = ((numC / (double)n)) * percent;
        percentD = ((numD / (double)n)) * percent;
        percentF = ((numF / (double)n)) * percent;
      }
    }
  }
  
  if(n == 0)
  {
    numA = 0;
    numB = 0;
    numC = 0;
    numD = 0;
    numF = 0;
    
    percentA = 0.0;
    percentB = 0.0;
    percentC = 0.0;
    percentD = 0.0;
    percentF = 0.0;
   }
  
  return GradeStats(n, numA, numB, numC, numD, numF, percentA, percentB, percentC, percentD, percentF);
}


//
// FindCourses(dept, courseNumber)
//
// Searches the courses in the department for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, and returned in
// ascending order by section number.
//
vector<Course> FindCourses(const Dept& dept, int courseNumber)
{
  vector<Course>  courses;
    
//   for(const Course& c: dept.Courses)
//   {
//     auto it = find_if(dept.Courses.begin(), dept.Courses.end(), 
//                      [=] (const Course& c)
//                       {
//                           if(c.Number == courseNumber)
//                               return true;
//                           else
//                               return false;
//                       });
    
//     if(it == dept.Courses.end())
//     {
//         //courses.size() = 0;
//     }
//     else
//     {
//        courses.push_back(&it); 
//     }
//   }
//

    
  if(dept.Courses.size() == 0)
  {
      courses.clear();
      return courses;
  }

  for(const Course& c: dept.Courses)
  {
    if(c.Number == courseNumber)
    {
        courses.push_back(c);
    }
  }
  
  sort(courses.begin(), courses.end(),
       [](const Course& c1, const Course& c2)
       {
         if(c1.Section < c2.Section)
             return true;
         else
             return false;
       });
    
  return courses;
}


//
// FindCourses(dept, instructorPrefix)
//
// Searches the courses in the department for those whose 
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".
//
// If none are found, then the returned vector is empty.  If 
// one or more courses are found, copies of the course objects
// are returned in a vector, with the courses appearing in 
// ascending order by course number.  If two courses have the 
// same course number, they are given in ascending order by 
// section number.  Note that courses are NOT sorted by instructor
// name.
//
vector<Course> FindCourses(const Dept& dept, string instructorPrefix)
{
  vector<Course>  courses;
    
  if(dept.Courses.size() == 0)
  {
      courses.clear();
      return courses;
  }
    
  for(const Course& c: dept.Courses)
  {
    if(c.Instructor.find(instructorPrefix) == 0)
    {
        courses.push_back(c);
    }
  }
  
  sort(courses.begin(), courses.end(),
       [](const Course& c1, const Course& c2)
       {
         if(c1.Number < c2.Number)
             return true;
         else if(c1.Number > c2.Number)
             return false;
         else
             if(c1.Section < c2.Section)
                 return true;
             else
                 return false;
       });

  return courses;
}


//
// FindCourses(college, courseNumber)
//
// Searches for all courses in the college for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by department, then course number,
// and then section number.
//
vector<Course> FindCourses(const College& college, int courseNumber)
{
  vector<Course>  courses;
   
  if(college.Depts.size() == 0)
  {
      return courses;
  }
 
  
  for(const Dept& dept: college.Depts)
  {
    for(const Course& c: dept.Courses)
    {
      if(c.Number == courseNumber)
      {
        courses.push_back(c);
      }
    }
  }
    
  sort(courses.begin(), courses.end(),
       [](const Course& c1, const Course& c2)
       {
         if(c1.Dept < c2.Dept)
             return true;
         else if(c1.Dept > c2.Dept)
             return false;
         else
             if(c1.Number < c2.Number)
                 return true;
             else if(c1.Number > c2.Number)
                 return false;
             else
                 if(c1.Section < c2.Section)
                     return true;
                 else
                     return false;
       });
  
  return courses;
}


//
// FindCourses(college, instructorPrefix)
//
// Searches all the courses in the college for those whose 
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by instructor, then course number,
// and then section number.
//
vector<Course> FindCourses(const College& college, string instructorPrefix)
{
  vector<Course>  courses;
    
  if(college.Depts.size() == 0)
  {
    return courses;
  }
    
  for(const Dept& dept: college.Depts)
  {
    for(const Course& c: dept.Courses)
    {
      if(c.Instructor.find(instructorPrefix) == 0)
      {
        courses.push_back(c);
      }
    }
  }
    
  sort(courses.begin(), courses.end(),
       [](const Course& c1, const Course& c2)
       {
//          if(c1.Instructor < c2.Instructor)
//              return true;
//          else if(c1.Instructor > c2.Instructor)
//              return false;
//          else 
             if(c1.Dept < c2.Dept)
                 return true;
             else if(c1.Dept > c2.Dept)
                 return false;
             else 
                 if(c1.Number < c2.Number)
                     return true;
                 else if(c1.Number > c2.Number)
                     return false;
                 else
                     if(c1.Section < c2.Section)
                         return true;
                     else
                         return false;
       });
    
  return courses;
}

