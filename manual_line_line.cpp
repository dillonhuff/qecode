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

std::vector<rational> test_points_from_roots(const std::vector<rational>& roots) {
  if (roots.size() == 0) {
    return {};
  }

  vector<rational> sorted_roots = roots;
  sort(begin(sorted_roots), end(sorted_roots));
  rational one(1);
  rational two(2);
  rational neg_inf = sorted_roots.front() - 1;
  rational pos_inf = sorted_roots.back() + 1;

  vector<rational> test_points;

  test_points.push_back(neg_inf);

  for (int i = 0; i < sorted_roots.size(); i++) {
    test_points.push_back(sorted_roots[i]);

    if (i < sorted_roots.size() - 1) {
      rational mid = (sorted_roots[i] + sorted_roots[i + 1]) / two;
      test_points.push_back(mid);
    }
  }

  test_points.push_back(pos_inf);
  
  
  return test_points;
}

bool lines_intersect(const double a,
		     const double b,
		     const double c,
		     const double d) {
  //Build the polynomial and evaluate it at (a, b, c, d)
  polynomial p = line_line_poly();
  cout << "Before substitution" << endl;
  cout << p << endl;
  vector<rational> rs{{a}, {b}, {c}, {d}};
  polynomial p_univariate = evaluate_at(rs, p);

  cout << p_univariate << endl;

  assert(p_univariate.num_vars() == 1);

  rational max_width(0.0001);
  vector<interval> roots = isolate_roots(p_univariate, max_width);
  cout << "# of roots = " << roots.size() << endl;

  // Approximate roots by midpoints of intervals
  vector<rational> points;

  rational two(2);
  for (auto& it : roots) {
    points.push_back((it.start.value + it.end.value) / two);
  }

  cout << "Roots" << endl;
  for (auto& pt : points) {
    cout << pt.to_double() << endl;
  }

  cout << "test points" << endl;
  vector<rational> test_points = test_points_from_roots(points);
  for (auto& pt : test_points) {
    cout << pt.to_double() << endl;
  }

  // Is this the correct handling of the zero root case?
  if (test_points.size() == 0) {
    return formula(a, b, c, d, 0.0);
  }

  for (auto& pt : test_points) {
    double test_x = pt.to_double();
    bool fm_true = formula(a, b, c, d, test_x);
    cout << "At x = " << test_x << " the formula is " << fm_true << endl;
    if (fm_true) {
      return true;
    }
  }

  return false;
}

// Line line intersection without y:
// a*x+b-c*x-d == 0.0
int main() {

  double a = 1.0;
  double b = -3;

  double c = 1.0;
  double d = -3.0;

  bool it = lines_intersect(a, b, c, d);
  cout << "Intersection?" << endl;
  cout << it << endl;
  return 0;
}
