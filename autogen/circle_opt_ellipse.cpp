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

bool formula(const double a, const double b, const double c, const double d, const double h, const double k, const double r, const double x ) {
	double p_1 = c;
	double p_2 = d;
	double p_3 = ( ( ( pow( c, 2.0 ) - pow( h, 2.0 ) ) + ( ( 2.0 * h ) * x ) ) - pow( x, 2.0 ) );
	double p_4 = ( b - k );
	double p_5 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 4.0 ) * pow( c, 4.0 ) ) - ( ( ( 4.0 * pow( a, 3.0 ) ) * pow( c, 4.0 ) ) * x ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) ) - ( ( ( ( 4.0 * pow( a, 2.0 ) ) * b ) * pow( c, 4.0 ) ) * k ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 6.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( ( 4.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * x ) ) - ( ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( 4.0 * a ) * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * x ) ) + ( ( ( ( ( 8.0 * a ) * b ) * pow( c, 4.0 ) ) * k ) * x ) ) - ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * x ) ) - ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) * x ) ) - ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( x, 3.0 ) ) ) + ( ( ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * x ) ) - ( ( ( ( ( 8.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( x, 2.0 ) ) ) + ( ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 3.0 ) ) ) + ( pow( b, 4.0 ) * pow( c, 4.0 ) ) ) - ( ( ( 4.0 * pow( b, 3.0 ) ) * pow( c, 4.0 ) ) * k ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) ) + ( ( ( 6.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) - ( ( ( ( ( 4.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * x ) ) + ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * k ) ) - ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * pow( k, 3.0 ) ) ) + ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * k ) * pow( r, 2.0 ) ) ) - ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * k ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * k ) ) + ( ( ( ( ( ( 8.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * k ) * x ) ) - ( ( ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * k ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( d, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( k, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( r, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( x, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * h ) * x ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( k, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( r, 2.0 ) ) ) - ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( k, 2.0 ) ) * x ) ) - ( ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( r, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( x, 3.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( k, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 4.0 ) ) ) + ( pow( d, 4.0 ) * pow( h, 4.0 ) ) ) - ( ( ( 4.0 * pow( d, 4.0 ) ) * pow( h, 3.0 ) ) * x ) ) + ( ( ( 6.0 * pow( d, 4.0 ) ) * pow( h, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * pow( d, 4.0 ) ) * h ) * pow( x, 3.0 ) ) ) + ( pow( d, 4.0 ) * pow( x, 4.0 ) ) );
	double p_6 = ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( c, 2.0 ) ) - ( ( ( 2.0 * a ) * pow( c, 2.0 ) ) * x ) ) + ( pow( b, 2.0 ) * pow( c, 2.0 ) ) ) - ( ( ( 2.0 * b ) * pow( c, 2.0 ) ) * k ) ) + ( pow( c, 2.0 ) * pow( d, 2.0 ) ) ) + ( pow( c, 2.0 ) * pow( k, 2.0 ) ) ) - ( pow( c, 2.0 ) * pow( r, 2.0 ) ) ) + ( pow( c, 2.0 ) * pow( x, 2.0 ) ) ) - ( pow( d, 2.0 ) * pow( h, 2.0 ) ) ) + ( ( ( 2.0 * pow( d, 2.0 ) ) * h ) * x ) ) - ( pow( d, 2.0 ) * pow( x, 2.0 ) ) );
	double p_7 = ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	double p_8 = ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( c, 2.0 ) ) - ( ( ( 2.0 * a ) * pow( c, 2.0 ) ) * x ) ) - ( pow( b, 2.0 ) * pow( c, 2.0 ) ) ) + ( ( ( 2.0 * b ) * pow( c, 2.0 ) ) * k ) ) + ( pow( c, 2.0 ) * pow( d, 2.0 ) ) ) - ( pow( c, 2.0 ) * pow( k, 2.0 ) ) ) - ( pow( c, 2.0 ) * pow( r, 2.0 ) ) ) + ( pow( c, 2.0 ) * pow( x, 2.0 ) ) ) - ( pow( d, 2.0 ) * pow( h, 2.0 ) ) ) + ( ( ( 2.0 * pow( d, 2.0 ) ) * h ) * x ) ) - ( pow( d, 2.0 ) * pow( x, 2.0 ) ) );


	return ( ( ( !within_eps( p_1, 0.0 , EPSILON ) && ( within_eps( p_2, 0.0 , EPSILON ) || ( ( p_3 > 0.0 ) || within_eps( p_3, 0.0 , EPSILON ) ) ) ) && ( ( ( ( ( p_4 < 0.0 ) || within_eps( p_4, 0.0 , EPSILON ) ) && ( ( p_5 < 0.0 ) || within_eps( p_5, 0.0 , EPSILON ) ) ) || ( ( ( p_4 > 0.0 ) || within_eps( p_4, 0.0 , EPSILON ) ) && ( ( p_5 < 0.0 ) || within_eps( p_5, 0.0 , EPSILON ) ) ) ) || ( ( ( p_6 < 0.0 ) || within_eps( p_6, 0.0 , EPSILON ) ) && ( ( p_5 > 0.0 ) || within_eps( p_5, 0.0 , EPSILON ) ) ) ) ) || ( ( ( p_7 < 0.0 ) || within_eps( p_7, 0.0 , EPSILON ) ) && ( ( ( ( ( p_8 > 0.0 ) || within_eps( p_8, 0.0 , EPSILON ) ) || ( ( p_5 < 0.0 ) || within_eps( p_5, 0.0 , EPSILON ) ) ) && ( ( !within_eps( p_1, 0.0 , EPSILON ) && ( p_4 < 0.0 ) ) || ( ( ( p_8 > 0.0 ) || within_eps( p_8, 0.0 , EPSILON ) ) && ( ( p_5 > 0.0 ) || within_eps( p_5, 0.0 , EPSILON ) ) ) ) ) || ( ( ( ( p_8 > 0.0 ) || within_eps( p_8, 0.0 , EPSILON ) ) || ( ( p_5 < 0.0 ) || within_eps( p_5, 0.0 , EPSILON ) ) ) && ( ( !within_eps( p_1, 0.0 , EPSILON ) && ( p_4 > 0.0 ) ) || ( ( ( p_8 > 0.0 ) || within_eps( p_8, 0.0 , EPSILON ) ) && ( ( p_5 > 0.0 ) || within_eps( p_5, 0.0 , EPSILON ) ) ) ) ) ) ) );
}


polynomial make_polynomial_1() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0 }, 8);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0 }, 8);
	monomial m_h(1, {0, 0, 0, 0, 1, 0, 0, 0 }, 8);
	monomial m_k(1, {0, 0, 0, 0, 0, 1, 0, 0 }, 8);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 1, 0 }, 8);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 1 }, 8);


	polynomial a({m_a}, 8);
	polynomial b({m_b}, 8);
	polynomial c({m_c}, 8);
	polynomial d({m_d}, 8);
	polynomial h({m_h}, 8);
	polynomial k({m_k}, 8);
	polynomial r({m_r}, 8);
	polynomial x({m_x}, 8);


	polynomial result_polynomial_21393 = c;
	return result_polynomial_21393;
}

polynomial make_polynomial_2() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0 }, 8);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0 }, 8);
	monomial m_h(1, {0, 0, 0, 0, 1, 0, 0, 0 }, 8);
	monomial m_k(1, {0, 0, 0, 0, 0, 1, 0, 0 }, 8);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 1, 0 }, 8);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 1 }, 8);


	polynomial a({m_a}, 8);
	polynomial b({m_b}, 8);
	polynomial c({m_c}, 8);
	polynomial d({m_d}, 8);
	polynomial h({m_h}, 8);
	polynomial k({m_k}, 8);
	polynomial r({m_r}, 8);
	polynomial x({m_x}, 8);


	polynomial result_polynomial_21393 = d;
	return result_polynomial_21393;
}

polynomial make_polynomial_3() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0 }, 8);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0 }, 8);
	monomial m_h(1, {0, 0, 0, 0, 1, 0, 0, 0 }, 8);
	monomial m_k(1, {0, 0, 0, 0, 0, 1, 0, 0 }, 8);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 1, 0 }, 8);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 1 }, 8);


	polynomial a({m_a}, 8);
	polynomial b({m_b}, 8);
	polynomial c({m_c}, 8);
	polynomial d({m_d}, 8);
	polynomial h({m_h}, 8);
	polynomial k({m_k}, 8);
	polynomial r({m_r}, 8);
	polynomial x({m_x}, 8);


	polynomial result_polynomial_21393 = ( ( ( pow( c, 2.0 ) - pow( h, 2.0 ) ) + ( ( 2.0 * h ) * x ) ) - pow( x, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_4() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0 }, 8);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0 }, 8);
	monomial m_h(1, {0, 0, 0, 0, 1, 0, 0, 0 }, 8);
	monomial m_k(1, {0, 0, 0, 0, 0, 1, 0, 0 }, 8);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 1, 0 }, 8);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 1 }, 8);


	polynomial a({m_a}, 8);
	polynomial b({m_b}, 8);
	polynomial c({m_c}, 8);
	polynomial d({m_d}, 8);
	polynomial h({m_h}, 8);
	polynomial k({m_k}, 8);
	polynomial r({m_r}, 8);
	polynomial x({m_x}, 8);


	polynomial result_polynomial_21393 = ( b - k );
	return result_polynomial_21393;
}

polynomial make_polynomial_5() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0 }, 8);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0 }, 8);
	monomial m_h(1, {0, 0, 0, 0, 1, 0, 0, 0 }, 8);
	monomial m_k(1, {0, 0, 0, 0, 0, 1, 0, 0 }, 8);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 1, 0 }, 8);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 1 }, 8);


	polynomial a({m_a}, 8);
	polynomial b({m_b}, 8);
	polynomial c({m_c}, 8);
	polynomial d({m_d}, 8);
	polynomial h({m_h}, 8);
	polynomial k({m_k}, 8);
	polynomial r({m_r}, 8);
	polynomial x({m_x}, 8);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 4.0 ) * pow( c, 4.0 ) ) - ( ( ( 4.0 * pow( a, 3.0 ) ) * pow( c, 4.0 ) ) * x ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) ) - ( ( ( ( 4.0 * pow( a, 2.0 ) ) * b ) * pow( c, 4.0 ) ) * k ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 6.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( ( 4.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * x ) ) - ( ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( 4.0 * a ) * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * x ) ) + ( ( ( ( ( 8.0 * a ) * b ) * pow( c, 4.0 ) ) * k ) * x ) ) - ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * x ) ) - ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) * x ) ) - ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( x, 3.0 ) ) ) + ( ( ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * x ) ) - ( ( ( ( ( 8.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( x, 2.0 ) ) ) + ( ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 3.0 ) ) ) + ( pow( b, 4.0 ) * pow( c, 4.0 ) ) ) - ( ( ( 4.0 * pow( b, 3.0 ) ) * pow( c, 4.0 ) ) * k ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) ) + ( ( ( 6.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) - ( ( ( ( ( 4.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * x ) ) + ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * k ) ) - ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * pow( k, 3.0 ) ) ) + ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * k ) * pow( r, 2.0 ) ) ) - ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * k ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * k ) ) + ( ( ( ( ( ( 8.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * k ) * x ) ) - ( ( ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * k ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( d, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( k, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( r, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( x, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * h ) * x ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( k, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( r, 2.0 ) ) ) - ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( k, 2.0 ) ) * x ) ) - ( ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( r, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( x, 3.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( k, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 4.0 ) ) ) + ( pow( d, 4.0 ) * pow( h, 4.0 ) ) ) - ( ( ( 4.0 * pow( d, 4.0 ) ) * pow( h, 3.0 ) ) * x ) ) + ( ( ( 6.0 * pow( d, 4.0 ) ) * pow( h, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * pow( d, 4.0 ) ) * h ) * pow( x, 3.0 ) ) ) + ( pow( d, 4.0 ) * pow( x, 4.0 ) ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_6() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0 }, 8);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0 }, 8);
	monomial m_h(1, {0, 0, 0, 0, 1, 0, 0, 0 }, 8);
	monomial m_k(1, {0, 0, 0, 0, 0, 1, 0, 0 }, 8);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 1, 0 }, 8);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 1 }, 8);


	polynomial a({m_a}, 8);
	polynomial b({m_b}, 8);
	polynomial c({m_c}, 8);
	polynomial d({m_d}, 8);
	polynomial h({m_h}, 8);
	polynomial k({m_k}, 8);
	polynomial r({m_r}, 8);
	polynomial x({m_x}, 8);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( c, 2.0 ) ) - ( ( ( 2.0 * a ) * pow( c, 2.0 ) ) * x ) ) + ( pow( b, 2.0 ) * pow( c, 2.0 ) ) ) - ( ( ( 2.0 * b ) * pow( c, 2.0 ) ) * k ) ) + ( pow( c, 2.0 ) * pow( d, 2.0 ) ) ) + ( pow( c, 2.0 ) * pow( k, 2.0 ) ) ) - ( pow( c, 2.0 ) * pow( r, 2.0 ) ) ) + ( pow( c, 2.0 ) * pow( x, 2.0 ) ) ) - ( pow( d, 2.0 ) * pow( h, 2.0 ) ) ) + ( ( ( 2.0 * pow( d, 2.0 ) ) * h ) * x ) ) - ( pow( d, 2.0 ) * pow( x, 2.0 ) ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_7() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0 }, 8);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0 }, 8);
	monomial m_h(1, {0, 0, 0, 0, 1, 0, 0, 0 }, 8);
	monomial m_k(1, {0, 0, 0, 0, 0, 1, 0, 0 }, 8);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 1, 0 }, 8);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 1 }, 8);


	polynomial a({m_a}, 8);
	polynomial b({m_b}, 8);
	polynomial c({m_c}, 8);
	polynomial d({m_d}, 8);
	polynomial h({m_h}, 8);
	polynomial k({m_k}, 8);
	polynomial r({m_r}, 8);
	polynomial x({m_x}, 8);


	polynomial result_polynomial_21393 = ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_8() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0 }, 8);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0 }, 8);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0 }, 8);
	monomial m_h(1, {0, 0, 0, 0, 1, 0, 0, 0 }, 8);
	monomial m_k(1, {0, 0, 0, 0, 0, 1, 0, 0 }, 8);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 1, 0 }, 8);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 1 }, 8);


	polynomial a({m_a}, 8);
	polynomial b({m_b}, 8);
	polynomial c({m_c}, 8);
	polynomial d({m_d}, 8);
	polynomial h({m_h}, 8);
	polynomial k({m_k}, 8);
	polynomial r({m_r}, 8);
	polynomial x({m_x}, 8);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( c, 2.0 ) ) - ( ( ( 2.0 * a ) * pow( c, 2.0 ) ) * x ) ) - ( pow( b, 2.0 ) * pow( c, 2.0 ) ) ) + ( ( ( 2.0 * b ) * pow( c, 2.0 ) ) * k ) ) + ( pow( c, 2.0 ) * pow( d, 2.0 ) ) ) - ( pow( c, 2.0 ) * pow( k, 2.0 ) ) ) - ( pow( c, 2.0 ) * pow( r, 2.0 ) ) ) + ( pow( c, 2.0 ) * pow( x, 2.0 ) ) ) - ( pow( d, 2.0 ) * pow( h, 2.0 ) ) ) + ( ( ( 2.0 * pow( d, 2.0 ) ) * h ) * x ) ) - ( pow( d, 2.0 ) * pow( x, 2.0 ) ) );
	return result_polynomial_21393;
}



double extract_double_from_coeff(const polynomial& x_coeff) {
  assert(x_coeff.num_monos() == 1);
  monomial xc = x_coeff.monomial(0);
  assert(is_constant(xc));
  double xcd = xc.coeff().to_double();
  return xcd;
}

std::vector<interval> linear_roots(const polynomial& p) {
  cout << p << endl;
  auto ps = coefficients_wrt(p, 0);
  assert(ps.size() == 2);
  polynomial x_coeff = ps[1];
  double xcd = extract_double_from_coeff(x_coeff);
  if (within_eps(xcd, 0.0, EPSILON)) {
    return {};
  }
  polynomial c = ps[0];
  double ccd = extract_double_from_coeff(c);
  double root_loc = -ccd / xcd;
  rational r(root_loc);
  return {{ipt(r), ipt(r)}};
}

std::vector<interval> quadratic_roots(const polynomial& p) {
  auto ps = coefficients_wrt(p, 0);

  double a = extract_double_from_coeff(ps[2]);
  double b = extract_double_from_coeff(ps[1]);
  double c = extract_double_from_coeff(ps[0]);

  double disc = b*b - 4*a*c;
  double rld = -b / (2*a);

  if (within_eps(disc, 0.0, EPSILON)) {
    rational rl(rld);
    return {{ipt(rl), ipt(rl)}};
  }

  if (disc < 0) {
    return {};
  }

  double r1d = rld - (sqrt(disc) / (2*a));
  double r2d = rld + (sqrt(disc) / (2*a));

  rational r1(r1d);
  rational r2(r2d);

  return {{ipt(r1), ipt(r1)}, {ipt(r2), ipt(r2)}};
}

std::vector<interval> find_roots(const polynomial& p, const rational& max_width) {
  if (degree_wrt(0, p) == 1) {
    return linear_roots(p);
  }

  if (degree_wrt(0, p) == 2) {
    return quadratic_roots(p);
  }

  return isolate_roots(p, max_width);
}

bool test_formula_at_sample_points(const double a, const double b, const double c, const double d, const double h, const double k, const double r , const std::vector<polynomial>& upolys) {
	rational max_width(0.0001);
	vector<interval> roots;
	for (auto& p_univariate : upolys) {
		concat(roots, find_roots(p_univariate, max_width));
	}
	vector<rational> points;
	rational two(2);
	 for (auto& it : roots) {
		 points.push_back((it.start.value + it.end.value) / two);
	 }

	 vector<rational> test_points = test_points_from_roots(points);
	if (test_points.size() == 0) {
		return formula(a, b, c, d, h, k, r , 0.0);
	 }

	for (auto& pt : test_points) { double test_x = pt.to_double();
	 bool fm_true = formula(a, b, c, d, h, k, r , test_x);
	 cout << "At x = " << test_x << " the formula is " << fm_true << endl;
	 if (fm_true) {
		return true;
	 }
	}
	return false;
	
}

bool circle_opt_ellipse( const double a, const double b, const double c, const double d, const double h, const double k, const double r ) {
	vector<polynomial> polys{make_polynomial_1(), make_polynomial_2(), make_polynomial_3(), make_polynomial_4(), make_polynomial_5(), make_polynomial_6(), make_polynomial_7(), make_polynomial_8() };
	vector<rational> rs{{a}, {b}, {c}, {d}, {h}, {k}, {r} };
	vector<polynomial> upolys;
	for (auto& p : polys) {
		polynomial p_univariate = evaluate_at(rs, p);
		upolys.push_back(p_univariate);
	}
	return test_formula_at_sample_points(a, b, c, d, h, k, r , upolys);

}
