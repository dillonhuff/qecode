#include "triangle_circle.h"

#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include <iostream>

using namespace std;

TEST_CASE("Overlap case 1") {

  double a = 0.1;
  double b = 0.3;
  double r = 3;;

  double v1x = -0.2;
  double v1y = -0.1;

  double v2x = 1.0;
  double v2y = 1.0;

  double v3x = 1.0;
  double v3y = 0.2;

  bool intersect = triangle_circle(  a,  b,  r,  v1x,  v1y,  v2x,  v2y,  v3x, v3y );

  cout << "Intersect = " << intersect << endl;

  
}
