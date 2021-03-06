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

bool formula(const double a, const double b, const double c, const double d, const double l, const double r, const double x ) {
	return ( ( ( ( ( l >= 0.0 ) && ( ( ( ( ( ( ( ( ( ( pow( b, 2.0 ) - ( ( 2.0 * b ) * d ) ) + ( ( 2.0 * b ) * l ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * x ) ) + pow( d, 2.0 ) ) - ( ( 2.0 * d ) * l ) ) + pow( l, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) && ( ( a - x ) <= 0.0 ) ) && ( ( ( a + l ) - x ) >= 0.0 ) ) || ( ( ( ( ( pow( c, 2.0 ) - ( ( 2.0 * c ) * x ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) && ( ( ( ( ( ( ( b - d ) <= 0.0 ) && ( ( ( ( ( ( ( pow( b, 2.0 ) - ( ( 2.0 * b ) * d ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * x ) ) + pow( d, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( a - x ) <= 0.0 ) ) && ( ( ( a + l ) - x ) >= 0.0 ) ) && ( ( ( ( b - d ) + l ) >= 0.0 ) || ( ( ( ( ( ( ( ( ( ( pow( b, 2.0 ) - ( ( 2.0 * b ) * d ) ) + ( ( 2.0 * b ) * l ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * x ) ) + pow( d, 2.0 ) ) - ( ( 2.0 * d ) * l ) ) + pow( l, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) || ( ( ( ( ( ( ( b - d ) + l ) >= 0.0 ) && ( ( ( ( ( ( ( ( ( ( pow( b, 2.0 ) - ( ( 2.0 * b ) * d ) ) + ( ( 2.0 * b ) * l ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * x ) ) + pow( d, 2.0 ) ) - ( ( 2.0 * d ) * l ) ) + pow( l, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( a - x ) <= 0.0 ) ) && ( ( ( a + l ) - x ) >= 0.0 ) ) && ( ( ( b - d ) <= 0.0 ) || ( ( ( ( ( ( ( pow( b, 2.0 ) - ( ( 2.0 * b ) * d ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * x ) ) + pow( d, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) ) ) );
}


polynomial make_polynomial_1() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0 }, 7);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0 }, 7);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0 }, 7);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0 }, 7);
	monomial m_l(1, {0, 0, 0, 0, 1, 0, 0 }, 7);
	monomial m_r(1, {0, 0, 0, 0, 0, 1, 0 }, 7);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 1 }, 7);


	polynomial a({m_a}, 7);
	polynomial b({m_b}, 7);
	polynomial c({m_c}, 7);
	polynomial d({m_d}, 7);
	polynomial l({m_l}, 7);
	polynomial r({m_r}, 7);
	polynomial x({m_x}, 7);


	polynomial result_polynomial_21393 = l;
	return result_polynomial_21393;
}

polynomial make_polynomial_2() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0 }, 7);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0 }, 7);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0 }, 7);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0 }, 7);
	monomial m_l(1, {0, 0, 0, 0, 1, 0, 0 }, 7);
	monomial m_r(1, {0, 0, 0, 0, 0, 1, 0 }, 7);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 1 }, 7);


	polynomial a({m_a}, 7);
	polynomial b({m_b}, 7);
	polynomial c({m_c}, 7);
	polynomial d({m_d}, 7);
	polynomial l({m_l}, 7);
	polynomial r({m_r}, 7);
	polynomial x({m_x}, 7);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( pow( b, 2.0 ) - ( ( 2.0 * b ) * d ) ) + ( ( 2.0 * b ) * l ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * x ) ) + pow( d, 2.0 ) ) - ( ( 2.0 * d ) * l ) ) + pow( l, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_3() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0 }, 7);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0 }, 7);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0 }, 7);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0 }, 7);
	monomial m_l(1, {0, 0, 0, 0, 1, 0, 0 }, 7);
	monomial m_r(1, {0, 0, 0, 0, 0, 1, 0 }, 7);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 1 }, 7);


	polynomial a({m_a}, 7);
	polynomial b({m_b}, 7);
	polynomial c({m_c}, 7);
	polynomial d({m_d}, 7);
	polynomial l({m_l}, 7);
	polynomial r({m_r}, 7);
	polynomial x({m_x}, 7);


	polynomial result_polynomial_21393 = ( a - x );
	return result_polynomial_21393;
}

polynomial make_polynomial_4() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0 }, 7);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0 }, 7);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0 }, 7);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0 }, 7);
	monomial m_l(1, {0, 0, 0, 0, 1, 0, 0 }, 7);
	monomial m_r(1, {0, 0, 0, 0, 0, 1, 0 }, 7);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 1 }, 7);


	polynomial a({m_a}, 7);
	polynomial b({m_b}, 7);
	polynomial c({m_c}, 7);
	polynomial d({m_d}, 7);
	polynomial l({m_l}, 7);
	polynomial r({m_r}, 7);
	polynomial x({m_x}, 7);


	polynomial result_polynomial_21393 = ( ( a + l ) - x );
	return result_polynomial_21393;
}

polynomial make_polynomial_5() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0 }, 7);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0 }, 7);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0 }, 7);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0 }, 7);
	monomial m_l(1, {0, 0, 0, 0, 1, 0, 0 }, 7);
	monomial m_r(1, {0, 0, 0, 0, 0, 1, 0 }, 7);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 1 }, 7);


	polynomial a({m_a}, 7);
	polynomial b({m_b}, 7);
	polynomial c({m_c}, 7);
	polynomial d({m_d}, 7);
	polynomial l({m_l}, 7);
	polynomial r({m_r}, 7);
	polynomial x({m_x}, 7);


	polynomial result_polynomial_21393 = ( ( ( pow( c, 2.0 ) - ( ( 2.0 * c ) * x ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_6() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0 }, 7);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0 }, 7);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0 }, 7);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0 }, 7);
	monomial m_l(1, {0, 0, 0, 0, 1, 0, 0 }, 7);
	monomial m_r(1, {0, 0, 0, 0, 0, 1, 0 }, 7);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 1 }, 7);


	polynomial a({m_a}, 7);
	polynomial b({m_b}, 7);
	polynomial c({m_c}, 7);
	polynomial d({m_d}, 7);
	polynomial l({m_l}, 7);
	polynomial r({m_r}, 7);
	polynomial x({m_x}, 7);


	polynomial result_polynomial_21393 = ( b - d );
	return result_polynomial_21393;
}

polynomial make_polynomial_7() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0 }, 7);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0 }, 7);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0 }, 7);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0 }, 7);
	monomial m_l(1, {0, 0, 0, 0, 1, 0, 0 }, 7);
	monomial m_r(1, {0, 0, 0, 0, 0, 1, 0 }, 7);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 1 }, 7);


	polynomial a({m_a}, 7);
	polynomial b({m_b}, 7);
	polynomial c({m_c}, 7);
	polynomial d({m_d}, 7);
	polynomial l({m_l}, 7);
	polynomial r({m_r}, 7);
	polynomial x({m_x}, 7);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( pow( b, 2.0 ) - ( ( 2.0 * b ) * d ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * x ) ) + pow( d, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_8() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0 }, 7);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0 }, 7);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0 }, 7);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0 }, 7);
	monomial m_l(1, {0, 0, 0, 0, 1, 0, 0 }, 7);
	monomial m_r(1, {0, 0, 0, 0, 0, 1, 0 }, 7);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 1 }, 7);


	polynomial a({m_a}, 7);
	polynomial b({m_b}, 7);
	polynomial c({m_c}, 7);
	polynomial d({m_d}, 7);
	polynomial l({m_l}, 7);
	polynomial r({m_r}, 7);
	polynomial x({m_x}, 7);


	polynomial result_polynomial_21393 = ( ( b - d ) + l );
	return result_polynomial_21393;
}



bool test_formula_at_sample_points(const double a, const double b, const double c, const double d, const double l, const double r , const std::vector<polynomial>& upolys) {
	rational max_width(0.0001);
	vector<interval> roots;
	for (auto& p_univariate : upolys) {
		concat(roots, isolate_roots(p_univariate, max_width));
	}
	vector<rational> points;
	rational two(2);
	 for (auto& it : roots) {
		 points.push_back((it.start.value + it.end.value) / two);
	 }

	 vector<rational> test_points = test_points_from_roots(points);
	if (test_points.size() == 0) {
		return formula(a, b, c, d, l, r , 0.0);
	 }

	for (auto& pt : test_points) { double test_x = pt.to_double();
	 bool fm_true = formula(a, b, c, d, l, r , test_x);
	 cout << "At x = " << test_x << " the formula is " << fm_true << endl;
	 if (fm_true) {
		return true;
	 }
	}
	return false;
	
}

bool shapes_intersect( const double a, const double b, const double c, const double d, const double l, const double r ) {
	vector<polynomial> polys{make_polynomial_1(), make_polynomial_2(), make_polynomial_3(), make_polynomial_4(), make_polynomial_5(), make_polynomial_6(), make_polynomial_7(), make_polynomial_8() };
	vector<rational> rs{{a}, {b}, {c}, {d}, {l}, {r} };
	vector<polynomial> upolys;
	for (auto& p : polys) {
		polynomial p_univariate = evaluate_at(rs, p);
		upolys.push_back(p_univariate);
	}
	return test_formula_at_sample_points(a, b, c, d, l, r , upolys);

}