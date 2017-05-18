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

bool overlap(const square sq, const circle circ) {
  return test(circ.r, sq.l, sq.y, circ.y, circ.x, sq.x);
}

TEST_CASE("circle and square do overlap") {
  square s{0.0, 0.0, 1.0};
  circle c{0.0, 0.0, 1.0};

  REQUIRE(overlap(s, c));
}
