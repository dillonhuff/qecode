#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#define EPSILON 1.0e-4

using namespace std;

bool within_eps(const double a, const double b, const double eps) {
  return fabs(a - b) < eps;
}

bool within_eps(const double a, const double b) {
  return within_eps(a, b, EPSILON);
}

vector<double> linear_roots(const double a,
			    const double b) {
  if (within_eps(a, 0.0)) { return {}; }

  return {-b / a};
}

vector<double> quadratic_roots(const double a,
			       const double b,
			       const double c) {
  return {};
}

vector<double> cubic_roots(const double a,
			   const double b,
			   const double c,
			   const double d) {
  return {};
}

double evaluate_cubic(const double a,
		      const double b,
		      const double c,
		      const double d,
		      const double x) {
  assert(!within_eps(a, 0.0));

  return 0.0;
}

TEST_CASE("x^3 - 6x^2 + 11x - 6") {
  double a = 1;
  double b = -6;
  double c = 11;
  double d = -6;

  REQUIRE(cubic_roots(a, b, c, d).size() == 3);

}
