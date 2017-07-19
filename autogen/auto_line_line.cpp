#include <ralg/root_counting.h>

using namespace std;
using namespace ralg;

#define EPSILON 1.0e-4

bool within_eps(const double a, const double b, const double eps) {
	return fabs(a - b) < eps;
}

std::vector<rational> test_points_from_roots(const std::vector<rational>& roots) {
if (roots.size() == 0) { return {};
 } vector<rational> sorted_roots = roots;
 sort(begin(sorted_roots), end(sorted_roots));
 rational one(1);
 rational two(2);
 rational neg_inf = sorted_roots.front() - 1;
 rational pos_inf = sorted_roots.back() + 1;
 vector<rational> test_points;
 test_points.push_back(neg_inf);
 for (int i = 0; i < sorted_roots.size(); i++) {
test_points.push_back(sorted_roots[i]);
 if (i < sorted_roots.size() - 1) { rational mid = (sorted_roots[i] + sorted_roots[i + 1]) / two;
 test_points.push_back(mid);
 } } test_points.push_back(pos_inf);
 return test_points;
 }

bool formula(const double a, const double b, const double c, const double d, const double f, const double x ) {
	return ( within_eps( ( x * ( a - f ) ), 0.0 , EPSILON ) || within_eps( ( ( ( ( a * x ) + b ) - ( c * x ) ) - d ), 0.0 , EPSILON ) );
}


polynomial make_polynomial_1() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0 }, 6);
	monomial m_b(1, {0, 1, 0, 0, 0, 0 }, 6);
	monomial m_c(1, {0, 0, 1, 0, 0, 0 }, 6);
	monomial m_d(1, {0, 0, 0, 1, 0, 0 }, 6);
	monomial m_f(1, {0, 0, 0, 0, 1, 0 }, 6);
	monomial m_x(1, {0, 0, 0, 0, 0, 1 }, 6);


	polynomial a({m_a}, 6);
	polynomial b({m_b}, 6);
	polynomial c({m_c}, 6);
	polynomial d({m_d}, 6);
	polynomial f({m_f}, 6);
	polynomial x({m_x}, 6);


	polynomial result_polynomial_21393 = ( x * ( a - f ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_2() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0 }, 6);
	monomial m_b(1, {0, 1, 0, 0, 0, 0 }, 6);
	monomial m_c(1, {0, 0, 1, 0, 0, 0 }, 6);
	monomial m_d(1, {0, 0, 0, 1, 0, 0 }, 6);
	monomial m_f(1, {0, 0, 0, 0, 1, 0 }, 6);
	monomial m_x(1, {0, 0, 0, 0, 0, 1 }, 6);


	polynomial a({m_a}, 6);
	polynomial b({m_b}, 6);
	polynomial c({m_c}, 6);
	polynomial d({m_d}, 6);
	polynomial f({m_f}, 6);
	polynomial x({m_x}, 6);


	polynomial result_polynomial_21393 = ( ( ( ( a * x ) + b ) - ( c * x ) ) - d );
	return result_polynomial_21393;
}



bool test_formula_at_sample_points(const double a, const double b, const double c, const double d, const double f , const std::vector<polynomial>& upolys) {
	rational max_width(0.0001);
	vector<interval> roots;
	for (auto& p_univariate : upolys) {
		concat(roots, isolate_roots(p_univariate));
	}
	vector<rational> points;
	rational two(2);
	 for (auto& it : roots) {
		 points.push_back((it.start.value + it.end.value) / two);
	 }

	 vector<rational> test_points = test_points_from_roots(points);
	if (test_points.size() == 0) {
		return formula(a, b, c, d, f , 0.0);
	 }

	for (auto& pt : test_points) { double test_x = pt.to_double();
	 bool fm_true = formula(a, b, c, d, f , test_x);
	 cout << "At x = " << test_x << " the formula is " << fm_true << endl;
	 if (fm_true) {
		return true;
	 }
	}
	return false;
	
}

bool shapes_intersect( const double a, const double b, const double c, const double d, const double f ) {
	vector<polynomial> polys{make_polynomial_1(), make_polynomial_2() };
	vector<rational> rs{{a}, {b}, {c}, {d}, {f} };
	vector<polynomial> upolys;
	for (auto& p : polys) {
		polynomial p_univariate = evaluate_at(rs, p);
		upolys.push_back(p_univariate);
	}
	return test_formula_at_sample_points(a, b, c, d, f , upolys);

}

int main() {
  
}
