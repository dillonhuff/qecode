#include "line_rectangle.h"

#define CATCH_CONFIG_MAIN

#include "catch.hpp"


TEST_CASE("Line rectangle pure") {
  double line_slope = -1.0;
  double line_intercept = 0.0;

  double rectangle_x_min = 0.0;//-0.0000001;
  double rectangle_y_min = 0.0; //-0.0000001;

  double rectangle_x_max = 1.0;
  double rectangle_y_max = 1.0;

  bool it = line_rectangle(line_slope,
			   line_intercept,
			   rectangle_x_min,
			   rectangle_y_min,
			   rectangle_x_max,
			   rectangle_y_max);

  REQUIRE(it);

}
