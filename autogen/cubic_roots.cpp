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
  assert(false);
  return {};
}

vector<double> cubic_roots(const double a,
			   const double b,
			   const double c,
			   const double d) {
  double p = (3*a*c - b*b) / (3*a*a);
  double q = (2*b*b*b - 9*a*b*c + 27*a*a*d) / (27*a*a*a);

  cout << "p = " << p << endl;

  assert(p < 0);

  double A = 2.0*sqrt(-p / 3.0);

  double phi = acos((3.0*q) / (A*p));

  double B = -b / (3.0*a);

  double r1 = A*cos((1/3.0)*phi) + B;
  double r2 = A*cos((1/3.0)*(phi + 2*M_PI)) + B;
  double r3 = A*cos((1/3.0)*(phi + 4*M_PI)) + B;

  cout << "r1 = " << r1 << endl;
  cout << "r2 = " << r2 << endl;
  cout << "r3 = " << r3 << endl;
  
  return {r1, r2, r3};
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
