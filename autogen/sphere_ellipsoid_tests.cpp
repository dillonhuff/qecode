#include "sphere_ellipsoid.h"

#define CATCH_CONFIG_MAIN

#include "catch.hpp"

TEST_CASE("X-Y plane and ellipsoid") {
  // Plane variables
  double a = 0;
  double b = 0;
  double c = 1;
  double d = 0;

  //Ellipsoid variables

  // Offsets
  double f = 0;
  double g = 0;
  double h = 0;

  // Major axis lengths
  double l = 3; // x
  double m = 2; // y
  double n = 1; // z

  bool intersect = sphere_ellipsoid(  a,  b,  c,  d,  f,  g,  h,  l,  m,  n );
  
  REQUIRE(intersect);

}

TEST_CASE("X-Y plane and above ellipsoid") {
  // Plane variables
  double a = 0;
  double b = 0;
  double c = 1;
  double d = 7;

  //Ellipsoid variables

  // Offsets
  double f = 0;
  double g = 0;
  double h = 0;

  // Major axis lengths
  double l = 3; // x
  double m = 2; // y
  double n = 1; // z

  bool intersect = sphere_ellipsoid(  a,  b,  c,  d,  f,  g,  h,  l,  m,  n );
  
  REQUIRE(!intersect);

}

TEST_CASE("X-Y plane and just below ellipsoid") {
  // Plane variables
  double a = 0;
  double b = 0;
  double c = 1;
  double d = 0.9;

  //Ellipsoid variables

  // Offsets
  double f = 0;
  double g = 0;
  double h = 0;

  // Major axis lengths
  double l = 3; // x
  double m = 2; // y
  double n = 1; // z

  bool intersect = sphere_ellipsoid(  a,  b,  c,  d,  f,  g,  h,  l,  m,  n );
  
  REQUIRE(intersect);

}

TEST_CASE("X-Y plane on ellipsoid") {
  // Plane variables
  double a = 0;
  double b = 0;
  double c = 1;
  double d = 1.0;

  //Ellipsoid variables

  // Offsets
  double f = 0;
  double g = 0;
  double h = 0;

  // Major axis lengths
  double l = 3; // x
  double m = 2; // y
  double n = 1; // z

  bool intersect = sphere_ellipsoid(  a,  b,  c,  d,  f,  g,  h,  l,  m,  n );
  
  REQUIRE(intersect);

}

TEST_CASE("X-Y plane just above ellipsoid") {
  // Plane variables
  double a = 0;
  double b = 0;
  double c = 1;
  double d = 1.01;

  //Ellipsoid variables

  // Offsets
  double f = 0;
  double g = 0;
  double h = 0;

  // Major axis lengths
  double l = 3; // x
  double m = 2; // y
  double n = 1; // z

  bool intersect = sphere_ellipsoid(  a,  b,  c,  d,  f,  g,  h,  l,  m,  n );
  
  REQUIRE(!intersect);

}

TEST_CASE("X-Y plane 0.1 above ellipsoid") {
  // Plane variables
  double a = 0;
  double b = 0;
  double c = 1;
  double d = 1.1;

  //Ellipsoid variables

  // Offsets
  double f = 0;
  double g = 0;
  double h = 0;

  // Major axis lengths
  double l = 3; // x
  double m = 2; // y
  double n = 1; // z

  bool intersect = sphere_ellipsoid(  a,  b,  c,  d,  f,  g,  h,  l,  m,  n );
  
  REQUIRE(!intersect);

}
