#include <ralg/root_counting.h>
#include <ralg/polynomial.h>

using namespace std;
using namespace ralg;

bool within_eps(const double a, const double b, const double eps) {
  return fabs(a - b) < eps;
}

bool formula(const double a,
	     const double b,
	     const double c,
	     const double d,
	     const double x) {
  return within_eps(a*x + b - c*x - d, 0.0, 0.0001);
}

polynomial line_line_poly() {
  // Variable numbering:  a, b, c, d, l, r, x
  monomial a(1, {1, 0, 0, 0, 0}, 5);
  monomial b(1, {0, 1, 0, 0, 0}, 5);
  monomial c(1, {0, 0, 1, 0, 0}, 5);
  monomial d(1, {0, 0, 0, 1, 0}, 5);
  monomial x(1, {0, 0, 0, 0, 1}, 5);

  monomial ax = a*x;
  monomial cx = c*x;

  polynomial p({ax, b, -cx, -d}, 5);

  return p;
}

// TODO: Add line polynomial, root queue, and formula evaluation
bool lines_intersect(const double a,
		     const double b,
		     const double c,
		     const double d) {
  //Build the polynomial and evaluate it at (a, b, c, d)
  polynomial p = line_line_poly();
  cout << "Before substitution" << endl;
  cout << p << endl;
  vector<rational> rs{{d}, {c}, {b}, {a}};
  polynomial p_univariate = evaluate_at(rs, p);

  cout << p_univariate << endl;
  return false;
}

// Line line intersection without y:
// a*x+b-c*x-d == 0.0
int main() {

  double a = 1.0;
  double b = -3;

  double c = -1.0;
  double d = 5.0;

  cout << "Intersection?" << endl;
  cout << lines_intersect(a, b, c, d) << endl;
  return 0;
}
