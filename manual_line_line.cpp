#include <ralg/root_counting.h>

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

bool lines_intersect(const double a,
		     const double b,
		     const double c,
		     const double d) {
  return false;
}

// Line line intersection without y:
// a*x+b-c*x-d == 0.0
int main() {
  // Variable numbering:  a, b, c, d, l, r, x
  monomial a(1, {1, 0, 0, 0, 0}, 5);
  monomial b(1, {0, 1, 0, 0, 0}, 5);
  monomial c(1, {0, 0, 1, 0, 0}, 5);
  monomial d(1, {0, 0, 0, 1, 0}, 5);
  monomial x(1, {0, 0, 0, 0, 1}, 5);

  monomial ax = a*x;
  monomial cx = c*x;

  polynomial p({ax, b, -cx, -d}, 5);

  cout << p << endl;

  return 0;
}
