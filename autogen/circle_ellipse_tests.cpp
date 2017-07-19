#include "ellipse_circle.h"

#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;


void overlap_case_1() {
  double a = -1;
  double b = -1;
  double r = 1000000;

  double c = 3;
  double d = 1;

  double h = 2;
  double k = 4;

  bool i = shapes_intersect(a, b, c, d, h, k, r);
  cout << "Intersect ? " << i << endl;
  REQUIRE(i);

}


void no_overlap_case_1() {
  double a = -100;
  double b = -100;
  double r = 0.1;

  double c = 3;
  double d = 1;

  double h = 2;
  double k = 4;

  bool i = shapes_intersect(a, b, c, d, h, k, r);
  cout << "Intersect ? " << i << endl;
  REQUIRE(!i);

}

// (x - 3)^2 + (y + 4)^2 = root(5)^2 and (x - 7)^2 / 3 + y^2 / 2 = 1
void no_overlap_case_2() {
  double a = 3;
  double b = -4;
  double r = sqrt(5);

  double c = 3;
  double d = 2;

  double h = 7;
  double k = 0;

  bool i = shapes_intersect(a, b, c, d, h, k, r);
  cout << "Intersect ? " << i << endl;
  REQUIRE(!i);
}

// (x - 3.5)^2 + (y + 4.5)^2 = sqrt(5)^2 and (x - 7)^2 / 3 + (y + 4)^2 / 2 = 1
void overlap_case_2() {
  double a = 3.5;
  double b = -4.5;
  double r = sqrt(5);

  double c = 3;
  double d = 2;

  double h = 7;
  double k = -4;

  bool i = shapes_intersect(a, b, c, d, h, k, r);
  cout << "Intersect ? " << i << endl;
  REQUIRE(i);

}

// Circle contains the ellipse
// (x - 3.5)^2 + (y + 4.5)^2 = sqrt(5)^2 and (x - 3.3)^2 / 3 + (y + 4)^2 / 2 = 1
void overlap_case_3() {
  double a = 3.5;
  double b = -4.5;
  double r = sqrt(5);

  double c = 3;
  double d = 2;

  double h = 3.3;
  double k = -4;

  bool i = shapes_intersect(a, b, c, d, h, k, r);
  cout << "Intersect ? " << i << endl;
  REQUIRE(i);
}

// Horizontal major ellipse contains circle
// (x - 3.5)^2 + (y + 4.5)^2 = sqrt(5)^2 and (x - 3.3)^2 / 23 + (y + 4.15)^2 /7 = 1
void overlap_case_5() {
  double a = 3.5;
  double b = -4.5;
  double r = sqrt(5);

  double c = 23;
  double d = 7;

  double h = 3.3;
  double k = -4.15;

  bool i = shapes_intersect(a, b, c, d, h, k, r);
  cout << "Intersect ? " << i << endl;
  REQUIRE(i);

}

// Ellipse completely contains circle
// (x - 3.5)^2 + (y + 4.5)^2 = sqrt(5)^2 and (x - 3.3)^2 / 7 + (y + 4)^2 / 23 = 1
void overlap_case_4() {
  double a = 3.5;
  double b = -4.5;
  double r = sqrt(5);

  double c = 7;
  double d = 23;

  double h = 3.3;
  double k = -4;

  bool i = shapes_intersect(a, b, c, d, h, k, r);
  cout << "Intersect ? " << i << endl;
  REQUIRE(i);

}

TEST_CASE() {
  overlap_case_1();
  overlap_case_2();
  overlap_case_3();
  overlap_case_5();
  overlap_case_4();

  no_overlap_case_1();
  no_overlap_case_2();
  
}

