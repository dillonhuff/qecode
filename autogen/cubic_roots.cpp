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

  if (p < 0) {

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
  } else if (p > 0) {

    cout << "sqrt(p / 3.0) = " << sqrt(p / 3.0) << endl;

    double A = 2*sqrt(p/3.0);

    cout << "A = " << A << endl;
    double phi = asinh((3.0*q) / (A*p));
    cout << "phi = " << phi << endl;
    double r1 = -A * sinh((phi / 3.0));

    cout << "r1 = " << r1 << endl;
    //double B = -b / (3.0*a);

    return {r1};
    
  } else {
    assert(false);
  }

  
}

double evaluate_cubic(const double a,
		      const double b,
		      const double c,
		      const double d,
		      const double x) {
  assert(!within_eps(a, 0.0));

  return a*pow(x, 3.0) + b*pow(x, 2.0) + c*pow(x, 1.0) + d;
}

TEST_CASE("x^3 - 6x^2 + 11x - 6, 3 roots") {
  double a = 1;
  double b = -6;
  double c = 11;
  double d = -6;

  auto roots = cubic_roots(a, b, c, d);
  double r = roots[0];

  cout << "value at root = " << evaluate_cubic(a, b, c, d, r) << endl;
  
  REQUIRE(roots.size() == 3);
}

TEST_CASE("15x^3 + 0x^2 + 1x - 1, 1 real") {
  double a = 15;
  double b = 0.1;
  double c = 10;
  double d = -1;

  auto roots = cubic_roots(a, b, c, d);
  double r = roots[0];

  cout << "value at root = " << evaluate_cubic(a, b, c, d, r) << endl;

  REQUIRE(roots.size() == 1);
}

TEST_CASE("x^3 - 3x^2 + 3x - 1, 1 coincident") {
  double a = 1;
  double b = -3;
  double c = 3;
  double d = -1;

  //REQUIRE(cubic_roots(a, b, c, d).size() == 1);
}
