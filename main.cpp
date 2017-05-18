#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include <cassert>
#include <iostream>

#include "intersection.h"

using namespace std;

struct square {
  double x, y, l;
};

struct circle {
  double x, y, r;
};

bool in_circle(const double x, const double y, const circle circ) {
  return pow( circ.x - x, 2 ) + pow( circ.y - y, 2 ) <= pow( circ.r, 2 );
}

bool in_square(const double x, const double y, const square sq) {
  return (sq.x <= x && x <= (sq.x + sq.l)) &&
    (sq.y <= y && y <= (sq.y + sq.l));
}

bool overlap(const square sq, const circle circ) {
  return test(circ.r, sq.l, sq.y, circ.y, circ.x, sq.x);
}

TEST_CASE("circle and square do overlap") {
  square s{0.0, 0.0, 1.0};
  circle c{0.0, 0.0, 1.0};

  REQUIRE(overlap(s, c));
}

TEST_CASE("circle and square do not overlap") {
  square s{0.0, 0.0, 1.0};
  circle c{5.0, 0.0, 1.0};

  REQUIRE(!overlap(s, c));
}

TEST_CASE("circle and square do not overlap, more complex") {
  square s{0.0, -1.6, 2.0};
  circle c{0.7, 0.1, 1.0};

  REQUIRE(!overlap(s, c));
}

TEST_CASE("circle contains square") {
  square s{0.65, 0.11, 0.1};
  circle c{0.7, 0.1, 3.0};

  REQUIRE(overlap(s, c));
}

TEST_CASE("Overlap with circle outside square") {
  square s{0.0, 0.0, 100};
  circle c{101.0, 1.01, 1.1};

  double test_x = 101 - 1.1;
  double test_y = 1.01;

  cout << "Test point in square = " << in_square(test_x, test_y, s) << endl;
  cout << "Test point in circle = " << in_circle(test_x, test_y, c) << endl;

  REQUIRE(overlap(s, c));
}


