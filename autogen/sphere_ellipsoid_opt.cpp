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

bool formula(const double a, const double b, const double c, const double d, const double f, const double g, const double h, const double l, const double m, const double n, const double x ) {
	double p_1 = n;
	double p_2 = m;
	double p_3 = l;
	double p_4 = b;
	double p_5 = ( ( ( ( a * c ) * x ) + ( pow( c, 2.0 ) * h ) ) + ( c * d ) );
	double p_6 = ( ( ( ( a * x ) + ( c * h ) ) - c ) + d );
	double p_7 = ( ( ( ( a * x ) + ( c * h ) ) + c ) + d );
	double p_8 = ( ( ( ( ( ( pow( f, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) - ( ( ( ( 2.0 * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) - ( pow( l, 2.0 ) * pow( m, 2.0 ) ) ) + ( ( pow( m, 2.0 ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - pow( n, 2.0 ) );
	double p_9 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) + ( ( ( ( ( ( 2.0 * a ) * b ) * g ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( 2.0 * a ) * c ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( 2.0 * a ) * d ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( pow( b, 2.0 ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( 2.0 * pow( b, 2.0 ) ) * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( pow( b, 2.0 ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( pow( b, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) + ( ( ( pow( b, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( pow( b, 2.0 ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 2.0 * b ) * c ) * g ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( 2.0 * b ) * d ) * g ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( c, 2.0 ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( 2.0 * c ) * d ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( pow( d, 2.0 ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) );
	double p_10 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 3.0 ) * b ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 3.0 ) ) + ( ( ( ( ( ( 3.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) * g ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( ( ( ( 3.0 * pow( a, 2.0 ) ) * b ) * c ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( ( ( 3.0 * pow( a, 2.0 ) ) * b ) * d ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( a * pow( b, 3.0 ) ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( 2.0 * a ) * pow( b, 3.0 ) ) * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( ( ( 3.0 * a ) * pow( b, 3.0 ) ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( a * pow( b, 3.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * x ) ) - ( ( ( ( a * pow( b, 3.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 3.0 ) ) ) + ( ( ( a * pow( b, 3.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( ( 6.0 * a ) * pow( b, 2.0 ) ) * c ) * g ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( 6.0 * a ) * pow( b, 2.0 ) ) * d ) * g ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( 3.0 * a ) * b ) * pow( c, 2.0 ) ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( ( 6.0 * a ) * b ) * c ) * d ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( 3.0 * a ) * b ) * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) - ( ( ( ( pow( b, 4.0 ) * pow( f, 2.0 ) ) * g ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 2.0 * pow( b, 4.0 ) ) * f ) * g ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( pow( b, 4.0 ) * pow( g, 3.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( b, 4.0 ) * g ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) - ( ( ( ( pow( b, 4.0 ) * g ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( pow( b, 4.0 ) * g ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( pow( b, 3.0 ) * c ) * pow( f, 2.0 ) ) * h ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * pow( b, 3.0 ) ) * c ) * f ) * h ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( 3.0 * pow( b, 3.0 ) ) * c ) * pow( g, 2.0 ) ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( pow( b, 3.0 ) * c ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) - ( ( ( ( ( pow( b, 3.0 ) * c ) * h ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( pow( b, 3.0 ) * c ) * h ) * pow( n, 2.0 ) ) ) - ( ( ( ( pow( b, 3.0 ) * d ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 2.0 * pow( b, 3.0 ) ) * d ) * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( 3.0 * pow( b, 3.0 ) ) * d ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( b, 3.0 ) * d ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) - ( ( ( ( pow( b, 3.0 ) * d ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( pow( b, 3.0 ) * d ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 3.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * g ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( ( 6.0 * pow( b, 2.0 ) ) * c ) * d ) * g ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( 3.0 * pow( b, 2.0 ) ) * pow( d, 2.0 ) ) * g ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( b * pow( c, 3.0 ) ) * pow( h, 3.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 3.0 * b ) * pow( c, 2.0 ) ) * d ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 3.0 * b ) * c ) * pow( d, 2.0 ) ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( b * pow( d, 3.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) );
	double p_11 = ( b * c );
	double p_12 = ( ( ( ( ( a * c ) * x ) + ( ( b * c ) * g ) ) + ( pow( c, 2.0 ) * h ) ) + ( c * d ) );
	double p_13 = ( ( ( ( ( ( ( pow( f, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) - ( ( ( ( 2.0 * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( pow( h, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) - ( pow( l, 2.0 ) * pow( m, 2.0 ) ) ) + ( ( pow( m, 2.0 ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - pow( n, 2.0 ) );
	double p_14 = c;
	double p_15 = ( ( ( ( a * b ) * x ) + ( pow( b, 2.0 ) * g ) ) + ( b * d ) );
	double p_16 = ( ( ( ( ( a * l ) * x ) + ( ( b * g ) * l ) ) - b ) + ( d * l ) );
	double p_17 = ( ( ( ( ( a * l ) * x ) + ( ( b * g ) * l ) ) + b ) + ( d * l ) );
	double p_18 = ( ( a * x ) + d );
	double p_19 = h;
	double p_20 = g;
	double p_21 = ( ( ( ( ( ( ( ( pow( f, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) - ( ( ( ( 2.0 * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( pow( g, 2.0 ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( pow( h, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) - ( pow( l, 2.0 ) * pow( m, 2.0 ) ) ) + ( ( pow( m, 2.0 ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - pow( n, 2.0 ) );
	double p_22 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) + ( ( ( ( ( ( 2.0 * a ) * b ) * g ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( 2.0 * a ) * d ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( pow( b, 2.0 ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( 2.0 * pow( b, 2.0 ) ) * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( pow( b, 2.0 ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( b, 2.0 ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) - ( ( pow( b, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) + ( ( ( pow( b, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( pow( b, 2.0 ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( 2.0 * b ) * d ) * g ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( pow( d, 2.0 ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) );
	double p_23 = ( ( ( ( ( ( a * b ) * pow( m, 2.0 ) ) * x ) + ( ( ( b * c ) * h ) * pow( m, 2.0 ) ) ) + ( ( b * d ) * pow( m, 2.0 ) ) ) - ( ( pow( c, 2.0 ) * g ) * pow( n, 2.0 ) ) );
	double p_24 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( x, 2.0 ) ) + ( ( ( ( ( ( 2.0 * a ) * c ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * x ) ) + ( ( ( ( ( 2.0 * a ) * d ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * x ) ) + ( ( ( pow( c, 2.0 ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( 2.0 * pow( c, 2.0 ) ) * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( pow( c, 2.0 ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( c, 2.0 ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) - ( ( pow( c, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) + ( ( ( pow( c, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( pow( c, 2.0 ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( 2.0 * c ) * d ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) + ( ( pow( d, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) );
	double p_25 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) + ( ( ( ( ( ( ( 2.0 * a ) * b ) * g ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( 2.0 * a ) * c ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( 2.0 * a ) * d ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( pow( b, 2.0 ) * pow( f, 2.0 ) ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( 2.0 * pow( b, 2.0 ) ) * f ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( pow( b, 2.0 ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( pow( b, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 4.0 ) ) ) + ( ( ( pow( b, 2.0 ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( pow( b, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * b ) * c ) * g ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 2.0 * b ) * d ) * g ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( c, 2.0 ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) ) - ( ( ( ( ( 2.0 * pow( c, 2.0 ) ) * f ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) + ( ( ( ( pow( c, 2.0 ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( pow( c, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( c, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) * pow( x, 2.0 ) ) ) - ( pow( c, 2.0 ) * pow( n, 4.0 ) ) ) + ( ( ( ( ( ( 2.0 * c ) * d ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( d, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) );
	double p_26 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( b, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) - ( ( ( ( pow( a, 2.0 ) * pow( c, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * a ) * pow( b, 3.0 ) ) * g ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( ( 2.0 * a ) * pow( b, 2.0 ) ) * c ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( 2.0 * a ) * pow( b, 2.0 ) ) * d ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) - ( ( ( ( ( ( ( 2.0 * a ) * b ) * pow( c, 2.0 ) ) * g ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) - ( ( ( ( ( ( 2.0 * a ) * pow( c, 3.0 ) ) * h ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) - ( ( ( ( ( ( 2.0 * a ) * pow( c, 2.0 ) ) * d ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) + ( ( ( pow( b, 4.0 ) * pow( f, 2.0 ) ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( 2.0 * pow( b, 4.0 ) ) * f ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( pow( b, 4.0 ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( pow( b, 4.0 ) * pow( l, 2.0 ) ) * pow( m, 4.0 ) ) ) + ( ( ( pow( b, 4.0 ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( pow( b, 4.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * pow( b, 3.0 ) ) * c ) * g ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 2.0 * pow( b, 3.0 ) ) * d ) * g ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) ) - ( ( ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * f ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) - ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) * pow( x, 2.0 ) ) ) - ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * pow( b, 2.0 ) ) * c ) * d ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( pow( b, 2.0 ) * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( ( 2.0 * b ) * pow( c, 3.0 ) ) * g ) * h ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) - ( ( ( ( ( ( 2.0 * b ) * pow( c, 2.0 ) ) * d ) * g ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) - ( ( ( pow( c, 4.0 ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) - ( ( ( ( ( 2.0 * pow( c, 3.0 ) ) * d ) * h ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) - ( ( ( pow( c, 2.0 ) * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) );
	double p_27 = ( ( ( ( ( a * b ) * x ) + ( pow( b, 2.0 ) * g ) ) + ( ( b * c ) * h ) ) + ( b * d ) );
	double p_28 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( b, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) + ( ( ( ( pow( a, 2.0 ) * pow( c, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * a ) * pow( b, 3.0 ) ) * g ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( ( 2.0 * a ) * pow( b, 2.0 ) ) * c ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( 2.0 * a ) * pow( b, 2.0 ) ) * d ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( 2.0 * a ) * b ) * pow( c, 2.0 ) ) * g ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) + ( ( ( ( ( ( 2.0 * a ) * pow( c, 3.0 ) ) * h ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) + ( ( ( ( ( ( 2.0 * a ) * pow( c, 2.0 ) ) * d ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) + ( ( ( pow( b, 4.0 ) * pow( f, 2.0 ) ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( 2.0 * pow( b, 4.0 ) ) * f ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( pow( b, 4.0 ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( pow( b, 4.0 ) * pow( l, 2.0 ) ) * pow( m, 4.0 ) ) ) + ( ( ( pow( b, 4.0 ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( pow( b, 4.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * pow( b, 3.0 ) ) * c ) * g ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 2.0 * pow( b, 3.0 ) ) * d ) * g ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) ) - ( ( ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * f ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) + ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) * pow( x, 2.0 ) ) ) - ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * pow( b, 2.0 ) ) * c ) * d ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( pow( b, 2.0 ) * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 2.0 * b ) * pow( c, 3.0 ) ) * g ) * h ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( ( ( ( 2.0 * b ) * pow( c, 2.0 ) ) * d ) * g ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( pow( c, 4.0 ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( ( ( 2.0 * pow( c, 3.0 ) ) * d ) * h ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( pow( c, 2.0 ) * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) );


	return ( ( ( ( ( ( ( ( ( ( ( within_eps( p_1, 0.0 , EPSILON ) && !within_eps( p_2, 0.0 , EPSILON ) ) && !within_eps( p_3, 0.0 , EPSILON ) ) && ( ( ( within_eps( p_4, 0.0 , EPSILON ) && ( ( p_5 < 0.0 ) || within_eps( p_5, 0.0 , EPSILON ) ) ) && ( within_eps( p_6, 0.0 , EPSILON ) || within_eps( p_7, 0.0 , EPSILON ) ) ) || ( ( within_eps( p_4, 0.0 , EPSILON ) && ( ( p_5 > 0.0 ) || within_eps( p_5, 0.0 , EPSILON ) ) ) && ( within_eps( p_6, 0.0 , EPSILON ) || within_eps( p_7, 0.0 , EPSILON ) ) ) ) ) || ( ( ( !within_eps( p_1, 0.0 , EPSILON ) && !within_eps( p_3, 0.0 , EPSILON ) ) && ( ( p_8 < 0.0 ) || within_eps( p_8, 0.0 , EPSILON ) ) ) && ( ( !within_eps( p_2, 0.0 , EPSILON ) && ( ( ( within_eps( p_9, 0.0 , EPSILON ) && ( ( p_10 < 0.0 ) || within_eps( p_10, 0.0 , EPSILON ) ) ) && ( ( ( p_11 < 0.0 ) || within_eps( p_11, 0.0 , EPSILON ) ) || ( ( p_12 < 0.0 ) || within_eps( p_12, 0.0 , EPSILON ) ) ) ) || ( ( within_eps( p_9, 0.0 , EPSILON ) && ( ( p_10 < 0.0 ) || within_eps( p_10, 0.0 , EPSILON ) ) ) && ( ( p_11 > 0.0 ) || ( ( p_12 > 0.0 ) || within_eps( p_12, 0.0 , EPSILON ) ) ) ) ) ) || ( !within_eps( p_2, 0.0 , EPSILON ) && ( ( ( within_eps( p_9, 0.0 , EPSILON ) && ( ( p_10 > 0.0 ) || within_eps( p_10, 0.0 , EPSILON ) ) ) && ( ( p_11 < 0.0 ) || ( ( p_12 > 0.0 ) || within_eps( p_12, 0.0 , EPSILON ) ) ) ) || ( ( within_eps( p_9, 0.0 , EPSILON ) && ( ( p_10 > 0.0 ) || within_eps( p_10, 0.0 , EPSILON ) ) ) && ( ( ( p_11 > 0.0 ) || within_eps( p_11, 0.0 , EPSILON ) ) || ( ( p_12 < 0.0 ) || within_eps( p_12, 0.0 , EPSILON ) ) ) ) ) ) ) ) ) || ( ( ( !within_eps( p_1, 0.0 , EPSILON ) && !within_eps( p_3, 0.0 , EPSILON ) ) && ( ( p_13 < 0.0 ) || within_eps( p_13, 0.0 , EPSILON ) ) ) && ( ( ( ( within_eps( p_2, 0.0 , EPSILON ) && within_eps( p_14, 0.0 , EPSILON ) ) && ( ( p_15 < 0.0 ) || within_eps( p_15, 0.0 , EPSILON ) ) ) && ( within_eps( p_16, 0.0 , EPSILON ) || within_eps( p_17, 0.0 , EPSILON ) ) ) || ( ( ( within_eps( p_2, 0.0 , EPSILON ) && within_eps( p_14, 0.0 , EPSILON ) ) && ( ( p_15 > 0.0 ) || within_eps( p_15, 0.0 , EPSILON ) ) ) && ( within_eps( p_16, 0.0 , EPSILON ) || within_eps( p_17, 0.0 , EPSILON ) ) ) ) ) ) || ( ( ( ( !within_eps( p_2, 0.0 , EPSILON ) && !within_eps( p_3, 0.0 , EPSILON ) ) && !within_eps( p_14, 0.0 , EPSILON ) ) && !within_eps( p_4, 0.0 , EPSILON ) ) && within_eps( p_9, 0.0 , EPSILON ) ) ) || ( ( ( ( within_eps( p_14, 0.0 , EPSILON ) && within_eps( p_4, 0.0 , EPSILON ) ) && within_eps( p_18, 0.0 , EPSILON ) ) && ( within_eps( p_2, 0.0 , EPSILON ) || within_eps( p_3, 0.0 , EPSILON ) ) ) && ( ( ( !within_eps( p_2, 0.0 , EPSILON ) && !within_eps( p_3, 0.0 , EPSILON ) ) && ( p_19 > 0.0 ) ) || ( ( ( within_eps( p_1, 0.0 , EPSILON ) || within_eps( p_3, 0.0 , EPSILON ) ) && ( ( within_eps( p_2, 0.0 , EPSILON ) || within_eps( p_3, 0.0 , EPSILON ) ) || within_eps( p_19, 0.0 , EPSILON ) ) ) && ( ( ( !within_eps( p_1, 0.0 , EPSILON ) && !within_eps( p_3, 0.0 , EPSILON ) ) && ( p_20 > 0.0 ) ) || ( ( ( p_21 < 0.0 ) || within_eps( p_21, 0.0 , EPSILON ) ) && ( ( within_eps( p_1, 0.0 , EPSILON ) || within_eps( p_3, 0.0 , EPSILON ) ) || within_eps( p_20, 0.0 , EPSILON ) ) ) ) ) ) ) ) || ( ( ( within_eps( p_14, 0.0 , EPSILON ) && !within_eps( p_4, 0.0 , EPSILON ) ) && ( within_eps( p_2, 0.0 , EPSILON ) || within_eps( p_3, 0.0 , EPSILON ) ) ) && ( ( ( !within_eps( p_2, 0.0 , EPSILON ) && !within_eps( p_3, 0.0 , EPSILON ) ) && ( p_19 > 0.0 ) ) || ( ( ( p_22 < 0.0 ) || within_eps( p_22, 0.0 , EPSILON ) ) && ( ( within_eps( p_2, 0.0 , EPSILON ) || within_eps( p_3, 0.0 , EPSILON ) ) || within_eps( p_19, 0.0 , EPSILON ) ) ) ) ) ) || ( ( ( !within_eps( p_14, 0.0 , EPSILON ) && ( within_eps( p_1, 0.0 , EPSILON ) || within_eps( p_3, 0.0 , EPSILON ) ) ) && ( ( within_eps( p_2, 0.0 , EPSILON ) || within_eps( p_3, 0.0 , EPSILON ) ) || within_eps( p_4, 0.0 , EPSILON ) ) ) && ( ( !within_eps( p_3, 0.0 , EPSILON ) && ( p_23 < 0.0 ) ) || ( ( ( p_24 < 0.0 ) || within_eps( p_24, 0.0 , EPSILON ) ) && ( within_eps( p_3, 0.0 , EPSILON ) || within_eps( p_23, 0.0 , EPSILON ) ) ) ) ) ) || ( ( !within_eps( p_14, 0.0 , EPSILON ) && ( within_eps( p_3, 0.0 , EPSILON ) || ( ( p_25 < 0.0 ) || within_eps( p_25, 0.0 , EPSILON ) ) ) ) && ( ( !within_eps( p_1, 0.0 , EPSILON ) && !within_eps( p_3, 0.0 , EPSILON ) ) || ( ( !within_eps( p_2, 0.0 , EPSILON ) && !within_eps( p_3, 0.0 , EPSILON ) ) && !within_eps( p_4, 0.0 , EPSILON ) ) ) ) ) || ( ( ( ( within_eps( p_3, 0.0 , EPSILON ) || within_eps( p_14, 0.0 , EPSILON ) ) || ( ( p_25 < 0.0 ) || within_eps( p_25, 0.0 , EPSILON ) ) ) && ( ( ( !within_eps( p_1, 0.0 , EPSILON ) && !within_eps( p_3, 0.0 , EPSILON ) ) && !within_eps( p_14, 0.0 , EPSILON ) ) || ( ( !within_eps( p_2, 0.0 , EPSILON ) && !within_eps( p_3, 0.0 , EPSILON ) ) && !within_eps( p_4, 0.0 , EPSILON ) ) ) ) && ( ( ( ( !within_eps( p_2, 0.0 , EPSILON ) && !within_eps( p_3, 0.0 , EPSILON ) ) && ( ( ( p_26 < 0.0 ) || within_eps( p_26, 0.0 , EPSILON ) ) || ( ( within_eps( p_1, 0.0 , EPSILON ) || ( ( p_27 < 0.0 ) || within_eps( p_27, 0.0 , EPSILON ) ) ) && ( within_eps( p_9, 0.0 , EPSILON ) || ( within_eps( p_4, 0.0 , EPSILON ) && ( within_eps( p_1, 0.0 , EPSILON ) || within_eps( p_14, 0.0 , EPSILON ) ) ) ) ) ) ) && ( ( ( ( ( p_11 > 0.0 ) || within_eps( p_11, 0.0 , EPSILON ) ) && ( within_eps( p_14, 0.0 , EPSILON ) || ( ( p_28 < 0.0 ) || within_eps( p_28, 0.0 , EPSILON ) ) ) ) || ( ( ( ( within_eps( p_1, 0.0 , EPSILON ) || within_eps( p_14, 0.0 , EPSILON ) ) || ( ( p_12 > 0.0 ) || within_eps( p_12, 0.0 , EPSILON ) ) ) || ( ( p_28 < 0.0 ) || within_eps( p_28, 0.0 , EPSILON ) ) ) && ( ( p_11 < 0.0 ) || ( ( within_eps( p_1, 0.0 , EPSILON ) || ( ( p_12 > 0.0 ) || within_eps( p_12, 0.0 , EPSILON ) ) ) && ( within_eps( p_14, 0.0 , EPSILON ) || ( ( p_28 > 0.0 ) || within_eps( p_28, 0.0 , EPSILON ) ) ) ) ) ) ) || ( ( within_eps( p_1, 0.0 , EPSILON ) || ( ( p_12 < 0.0 ) || within_eps( p_12, 0.0 , EPSILON ) ) ) && ( within_eps( p_14, 0.0 , EPSILON ) || ( ( p_28 > 0.0 ) || within_eps( p_28, 0.0 , EPSILON ) ) ) ) ) ) || ( ( ( !within_eps( p_2, 0.0 , EPSILON ) && !within_eps( p_3, 0.0 , EPSILON ) ) && ( ( ( p_26 < 0.0 ) || within_eps( p_26, 0.0 , EPSILON ) ) || ( ( within_eps( p_1, 0.0 , EPSILON ) || ( ( p_27 > 0.0 ) || within_eps( p_27, 0.0 , EPSILON ) ) ) && ( within_eps( p_9, 0.0 , EPSILON ) || ( within_eps( p_4, 0.0 , EPSILON ) && ( within_eps( p_1, 0.0 , EPSILON ) || within_eps( p_14, 0.0 , EPSILON ) ) ) ) ) ) ) && ( ( ( ( ( p_11 < 0.0 ) || within_eps( p_11, 0.0 , EPSILON ) ) && ( within_eps( p_14, 0.0 , EPSILON ) || ( ( p_28 < 0.0 ) || within_eps( p_28, 0.0 , EPSILON ) ) ) ) || ( ( ( ( within_eps( p_1, 0.0 , EPSILON ) || within_eps( p_14, 0.0 , EPSILON ) ) || ( ( p_12 > 0.0 ) || within_eps( p_12, 0.0 , EPSILON ) ) ) || ( ( p_28 < 0.0 ) || within_eps( p_28, 0.0 , EPSILON ) ) ) && ( ( p_11 > 0.0 ) || ( ( within_eps( p_1, 0.0 , EPSILON ) || ( ( p_12 > 0.0 ) || within_eps( p_12, 0.0 , EPSILON ) ) ) && ( within_eps( p_14, 0.0 , EPSILON ) || ( ( p_28 > 0.0 ) || within_eps( p_28, 0.0 , EPSILON ) ) ) ) ) ) ) || ( ( within_eps( p_1, 0.0 , EPSILON ) || ( ( p_12 < 0.0 ) || within_eps( p_12, 0.0 , EPSILON ) ) ) && ( within_eps( p_14, 0.0 , EPSILON ) || ( ( p_28 > 0.0 ) || within_eps( p_28, 0.0 , EPSILON ) ) ) ) ) ) ) ) );
}


polynomial make_polynomial_1() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = n;
	return result_polynomial_21393;
}

polynomial make_polynomial_2() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = m;
	return result_polynomial_21393;
}

polynomial make_polynomial_3() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = l;
	return result_polynomial_21393;
}

polynomial make_polynomial_4() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = b;
	return result_polynomial_21393;
}

polynomial make_polynomial_5() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( a * c ) * x ) + ( pow( c, 2.0 ) * h ) ) + ( c * d ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_6() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( a * x ) + ( c * h ) ) - c ) + d );
	return result_polynomial_21393;
}

polynomial make_polynomial_7() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( a * x ) + ( c * h ) ) + c ) + d );
	return result_polynomial_21393;
}

polynomial make_polynomial_8() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( pow( f, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) - ( ( ( ( 2.0 * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) - ( pow( l, 2.0 ) * pow( m, 2.0 ) ) ) + ( ( pow( m, 2.0 ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - pow( n, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_9() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) + ( ( ( ( ( ( 2.0 * a ) * b ) * g ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( 2.0 * a ) * c ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( 2.0 * a ) * d ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( pow( b, 2.0 ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( 2.0 * pow( b, 2.0 ) ) * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( pow( b, 2.0 ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( pow( b, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) + ( ( ( pow( b, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( pow( b, 2.0 ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 2.0 * b ) * c ) * g ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( 2.0 * b ) * d ) * g ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( c, 2.0 ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( 2.0 * c ) * d ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( pow( d, 2.0 ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_10() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 3.0 ) * b ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 3.0 ) ) + ( ( ( ( ( ( 3.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) * g ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( ( ( ( 3.0 * pow( a, 2.0 ) ) * b ) * c ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( ( ( 3.0 * pow( a, 2.0 ) ) * b ) * d ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( a * pow( b, 3.0 ) ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( 2.0 * a ) * pow( b, 3.0 ) ) * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( ( ( 3.0 * a ) * pow( b, 3.0 ) ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( a * pow( b, 3.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * x ) ) - ( ( ( ( a * pow( b, 3.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 3.0 ) ) ) + ( ( ( a * pow( b, 3.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( ( 6.0 * a ) * pow( b, 2.0 ) ) * c ) * g ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( 6.0 * a ) * pow( b, 2.0 ) ) * d ) * g ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( 3.0 * a ) * b ) * pow( c, 2.0 ) ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( ( 6.0 * a ) * b ) * c ) * d ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( 3.0 * a ) * b ) * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) - ( ( ( ( pow( b, 4.0 ) * pow( f, 2.0 ) ) * g ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 2.0 * pow( b, 4.0 ) ) * f ) * g ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( pow( b, 4.0 ) * pow( g, 3.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( b, 4.0 ) * g ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) - ( ( ( ( pow( b, 4.0 ) * g ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( pow( b, 4.0 ) * g ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( pow( b, 3.0 ) * c ) * pow( f, 2.0 ) ) * h ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * pow( b, 3.0 ) ) * c ) * f ) * h ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( 3.0 * pow( b, 3.0 ) ) * c ) * pow( g, 2.0 ) ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( pow( b, 3.0 ) * c ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) - ( ( ( ( ( pow( b, 3.0 ) * c ) * h ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( pow( b, 3.0 ) * c ) * h ) * pow( n, 2.0 ) ) ) - ( ( ( ( pow( b, 3.0 ) * d ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 2.0 * pow( b, 3.0 ) ) * d ) * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( 3.0 * pow( b, 3.0 ) ) * d ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( b, 3.0 ) * d ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) - ( ( ( ( pow( b, 3.0 ) * d ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( pow( b, 3.0 ) * d ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 3.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * g ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( ( 6.0 * pow( b, 2.0 ) ) * c ) * d ) * g ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( 3.0 * pow( b, 2.0 ) ) * pow( d, 2.0 ) ) * g ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( b * pow( c, 3.0 ) ) * pow( h, 3.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 3.0 * b ) * pow( c, 2.0 ) ) * d ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 3.0 * b ) * c ) * pow( d, 2.0 ) ) * h ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( b * pow( d, 3.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_11() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( b * c );
	return result_polynomial_21393;
}

polynomial make_polynomial_12() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( ( a * c ) * x ) + ( ( b * c ) * g ) ) + ( pow( c, 2.0 ) * h ) ) + ( c * d ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_13() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( pow( f, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) - ( ( ( ( 2.0 * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( pow( h, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) - ( pow( l, 2.0 ) * pow( m, 2.0 ) ) ) + ( ( pow( m, 2.0 ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - pow( n, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_14() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = c;
	return result_polynomial_21393;
}

polynomial make_polynomial_15() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( a * b ) * x ) + ( pow( b, 2.0 ) * g ) ) + ( b * d ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_16() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( ( a * l ) * x ) + ( ( b * g ) * l ) ) - b ) + ( d * l ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_17() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( ( a * l ) * x ) + ( ( b * g ) * l ) ) + b ) + ( d * l ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_18() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( a * x ) + d );
	return result_polynomial_21393;
}

polynomial make_polynomial_19() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = h;
	return result_polynomial_21393;
}

polynomial make_polynomial_20() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = g;
	return result_polynomial_21393;
}

polynomial make_polynomial_21() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( pow( f, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) - ( ( ( ( 2.0 * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( pow( g, 2.0 ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( pow( h, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) - ( pow( l, 2.0 ) * pow( m, 2.0 ) ) ) + ( ( pow( m, 2.0 ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - pow( n, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_22() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) + ( ( ( ( ( ( 2.0 * a ) * b ) * g ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( 2.0 * a ) * d ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( pow( b, 2.0 ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( 2.0 * pow( b, 2.0 ) ) * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( pow( b, 2.0 ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( b, 2.0 ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) - ( ( pow( b, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) + ( ( ( pow( b, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( pow( b, 2.0 ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( 2.0 * b ) * d ) * g ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( pow( d, 2.0 ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_23() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( a * b ) * pow( m, 2.0 ) ) * x ) + ( ( ( b * c ) * h ) * pow( m, 2.0 ) ) ) + ( ( b * d ) * pow( m, 2.0 ) ) ) - ( ( pow( c, 2.0 ) * g ) * pow( n, 2.0 ) ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_24() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( x, 2.0 ) ) + ( ( ( ( ( ( 2.0 * a ) * c ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * x ) ) + ( ( ( ( ( 2.0 * a ) * d ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * x ) ) + ( ( ( pow( c, 2.0 ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( 2.0 * pow( c, 2.0 ) ) * f ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( pow( c, 2.0 ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( c, 2.0 ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) - ( ( pow( c, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) + ( ( ( pow( c, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( pow( c, 2.0 ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( 2.0 * c ) * d ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) ) + ( ( pow( d, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_25() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) + ( ( ( ( ( ( ( 2.0 * a ) * b ) * g ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( 2.0 * a ) * c ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( 2.0 * a ) * d ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( pow( b, 2.0 ) * pow( f, 2.0 ) ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( 2.0 * pow( b, 2.0 ) ) * f ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( pow( b, 2.0 ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( pow( b, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 4.0 ) ) ) + ( ( ( pow( b, 2.0 ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( pow( b, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * b ) * c ) * g ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 2.0 * b ) * d ) * g ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( c, 2.0 ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) ) - ( ( ( ( ( 2.0 * pow( c, 2.0 ) ) * f ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) + ( ( ( ( pow( c, 2.0 ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( pow( c, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( c, 2.0 ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) * pow( x, 2.0 ) ) ) - ( pow( c, 2.0 ) * pow( n, 4.0 ) ) ) + ( ( ( ( ( ( 2.0 * c ) * d ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( pow( d, 2.0 ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_26() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( b, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) - ( ( ( ( pow( a, 2.0 ) * pow( c, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * a ) * pow( b, 3.0 ) ) * g ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( ( 2.0 * a ) * pow( b, 2.0 ) ) * c ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( 2.0 * a ) * pow( b, 2.0 ) ) * d ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) - ( ( ( ( ( ( ( 2.0 * a ) * b ) * pow( c, 2.0 ) ) * g ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) - ( ( ( ( ( ( 2.0 * a ) * pow( c, 3.0 ) ) * h ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) - ( ( ( ( ( ( 2.0 * a ) * pow( c, 2.0 ) ) * d ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) + ( ( ( pow( b, 4.0 ) * pow( f, 2.0 ) ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( 2.0 * pow( b, 4.0 ) ) * f ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( pow( b, 4.0 ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( pow( b, 4.0 ) * pow( l, 2.0 ) ) * pow( m, 4.0 ) ) ) + ( ( ( pow( b, 4.0 ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( pow( b, 4.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * pow( b, 3.0 ) ) * c ) * g ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 2.0 * pow( b, 3.0 ) ) * d ) * g ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) ) - ( ( ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * f ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) - ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) * pow( x, 2.0 ) ) ) - ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * pow( b, 2.0 ) ) * c ) * d ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( pow( b, 2.0 ) * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( ( 2.0 * b ) * pow( c, 3.0 ) ) * g ) * h ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) - ( ( ( ( ( ( 2.0 * b ) * pow( c, 2.0 ) ) * d ) * g ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) - ( ( ( pow( c, 4.0 ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) - ( ( ( ( ( 2.0 * pow( c, 3.0 ) ) * d ) * h ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) - ( ( ( pow( c, 2.0 ) * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_27() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( ( a * b ) * x ) + ( pow( b, 2.0 ) * g ) ) + ( ( b * c ) * h ) ) + ( b * d ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_28() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_d(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_f(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 11);
	monomial m_g(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 11);
	monomial m_h(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 11);
	monomial m_l(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 11);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 11);
	monomial m_n(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 11);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 11);


	polynomial a({m_a}, 11);
	polynomial b({m_b}, 11);
	polynomial c({m_c}, 11);
	polynomial d({m_d}, 11);
	polynomial f({m_f}, 11);
	polynomial g({m_g}, 11);
	polynomial h({m_h}, 11);
	polynomial l({m_l}, 11);
	polynomial m({m_m}, 11);
	polynomial n({m_n}, 11);
	polynomial x({m_x}, 11);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( b, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) + ( ( ( ( pow( a, 2.0 ) * pow( c, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * a ) * pow( b, 3.0 ) ) * g ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( ( 2.0 * a ) * pow( b, 2.0 ) ) * c ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( 2.0 * a ) * pow( b, 2.0 ) ) * d ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( ( ( ( 2.0 * a ) * b ) * pow( c, 2.0 ) ) * g ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) + ( ( ( ( ( ( 2.0 * a ) * pow( c, 3.0 ) ) * h ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) + ( ( ( ( ( ( 2.0 * a ) * pow( c, 2.0 ) ) * d ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) + ( ( ( pow( b, 4.0 ) * pow( f, 2.0 ) ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( ( 2.0 * pow( b, 4.0 ) ) * f ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) * x ) ) + ( ( ( ( pow( b, 4.0 ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( pow( b, 4.0 ) * pow( l, 2.0 ) ) * pow( m, 4.0 ) ) ) + ( ( ( pow( b, 4.0 ) * pow( m, 4.0 ) ) * pow( n, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( pow( b, 4.0 ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * pow( b, 3.0 ) ) * c ) * g ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 2.0 * pow( b, 3.0 ) ) * d ) * g ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( f, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) ) - ( ( ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * f ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) * x ) ) + ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( g, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) - ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 4.0 ) ) * pow( x, 2.0 ) ) ) - ( ( pow( b, 2.0 ) * pow( c, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( ( ( ( ( 2.0 * pow( b, 2.0 ) ) * c ) * d ) * h ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( pow( b, 2.0 ) * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) * pow( m, 2.0 ) ) * pow( n, 2.0 ) ) ) + ( ( ( ( ( ( 2.0 * b ) * pow( c, 3.0 ) ) * g ) * h ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( ( ( ( 2.0 * b ) * pow( c, 2.0 ) ) * d ) * g ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( pow( c, 4.0 ) * pow( h, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( ( ( 2.0 * pow( c, 3.0 ) ) * d ) * h ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) ) + ( ( ( pow( c, 2.0 ) * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) * pow( n, 4.0 ) ) );
	return result_polynomial_21393;
}



double extract_double_from_coeff(const polynomial& x_coeff) {
assert(x_coeff.num_monos() == 1);
monomial xc = x_coeff.monomial(0);
assert(is_constant(xc));
double xcd = xc.coeff().to_double();
return xcd;
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

std::vector<interval> linear_roots(const polynomial& p) {
  //cout << p << endl;
auto ps = coefficients_wrt(p, 0);
assert(ps.size() == 2);
polynomial x_coeff = ps[1];
double xcd = extract_double_from_coeff(x_coeff);
if (within_eps(xcd, 0.0, EPSILON)) {
return {};
}polynomial c = ps[0];
double ccd = extract_double_from_coeff(c);
double root_loc = -ccd / xcd;
rational r(root_loc);
return {{ipt(r), ipt(r)}};
}
std::vector<interval> find_roots(const polynomial& p, const rational& max_width) {
  cout << p << endl;
  if (degree_wrt(0, p) == 0) { return {}; }
  if (degree_wrt(0, p) == 1) {
    return linear_roots(p);
  }
  if (degree_wrt(0, p) == 2) {
    return quadratic_roots(p);
  }

  if (degree_wrt(0, p) == 3) {
    assert(false);
  }
  return isolate_roots(p, max_width);
}

bool test_formula_at_sample_points(const double a, const double b, const double c, const double d, const double f, const double g, const double h, const double l, const double m, const double n , const std::vector<polynomial>& upolys) {
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
		return formula(a, b, c, d, f, g, h, l, m, n , 0.0);
	 }

	for (auto& pt : test_points) { double test_x = pt.to_double();
	 bool fm_true = formula(a, b, c, d, f, g, h, l, m, n , test_x);
	 //cout << "At x = " << test_x << " the formula is " << fm_true << endl;
	 if (fm_true) {
		return true;
	 }
	}
	return false;
	
}

bool sphere_ellipsoid_opt( const double a, const double b, const double c, const double d, const double f, const double g, const double h, const double l, const double m, const double n ) {
	vector<polynomial> polys{make_polynomial_1(), make_polynomial_2(), make_polynomial_3(), make_polynomial_4(), make_polynomial_5(), make_polynomial_6(), make_polynomial_7(), make_polynomial_8(), make_polynomial_9(), make_polynomial_10(), make_polynomial_11(), make_polynomial_12(), make_polynomial_13(), make_polynomial_14(), make_polynomial_15(), make_polynomial_16(), make_polynomial_17(), make_polynomial_18(), make_polynomial_19(), make_polynomial_20(), make_polynomial_21(), make_polynomial_22(), make_polynomial_23(), make_polynomial_24(), make_polynomial_25(), make_polynomial_26(), make_polynomial_27(), make_polynomial_28() };
	vector<rational> rs{{a}, {b}, {c}, {d}, {f}, {g}, {h}, {l}, {m}, {n} };
	vector<polynomial> upolys;
	for (auto& p : polys) {
		polynomial p_univariate = evaluate_at(rs, p);
		upolys.push_back(p_univariate);
	}
	return test_formula_at_sample_points(a, b, c, d, f, g, h, l, m, n , upolys);

}
