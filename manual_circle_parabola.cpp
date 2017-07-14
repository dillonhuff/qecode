#include <ralg/root_counting.h>

using namespace ralg;

// Circle parabola without y formula:
// ( a**2-2.0*a*x+b**2-2.0*b*c*x**2-2.0*b*d*x-2.0*b*l+c**2*x**4+2.0*c*d*x**3+2.0*c*l*x**2+d**2*x**2+2.0*d*l*x+l**2-r**2+x**2 <= 0.0 )
int main() {
  // Variable numbering:  a, b, c, d, l, r, x
  monomial a(1, {1, 0, 0, 0, 0, 0, 0}, 7);
  monomial b(1, {0, 1, 0, 0, 0, 0, 0}, 7);
  monomial c(1, {0, 0, 1, 0, 0, 0, 0}, 7);
  monomial d(1, {0, 0, 0, 1, 0, 0, 0}, 7);
  monomial l(1, {0, 0, 0, 0, 1, 0, 0}, 7);
  monomial r(1, {0, 0, 0, 0, 0, 1, 0}, 7);
  monomial x(1, {0, 0, 0, 0, 0, 0, 1}, 7);

  return 0;
}
