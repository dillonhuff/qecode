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
	return ( ( ( ( ( ( pow( c, 2.0 ) - ( ( 2.0 * c ) * x ) ) - pow( l, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) && ( ( ( ( ( b - d ) <= 0.0 ) && ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 4.0 ) - ( ( 4.0 * pow( a, 3.0 ) ) * x ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) ) - ( ( ( 4.0 * pow( a, 2.0 ) ) * b ) * d ) ) - ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) ) + ( ( ( 4.0 * pow( a, 2.0 ) ) * c ) * x ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( d, 2.0 ) ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( a, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( a, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * a ) * pow( b, 2.0 ) ) * x ) ) + ( ( ( ( 8.0 * a ) * b ) * d ) * x ) ) + ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * x ) ) - ( ( ( 8.0 * a ) * c ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * a ) * pow( d, 2.0 ) ) * x ) ) - ( ( ( 4.0 * a ) * pow( l, 2.0 ) ) * x ) ) + ( ( ( 4.0 * a ) * pow( r, 2.0 ) ) * x ) ) + pow( b, 4.0 ) ) - ( ( 4.0 * pow( b, 3.0 ) ) * d ) ) + ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) ) - ( ( ( 4.0 * pow( b, 2.0 ) ) * c ) * x ) ) + ( ( 6.0 * pow( b, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( 2.0 * pow( b, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( b, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( b, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * d ) ) + ( ( ( ( 8.0 * b ) * c ) * d ) * x ) ) - ( ( 4.0 * b ) * pow( d, 3.0 ) ) ) + ( ( ( 4.0 * b ) * d ) * pow( l, 2.0 ) ) ) + ( ( ( 4.0 * b ) * d ) * pow( r, 2.0 ) ) ) - ( ( ( 8.0 * b ) * d ) * pow( x, 2.0 ) ) ) + pow( c, 4.0 ) ) - ( ( 4.0 * pow( c, 3.0 ) ) * x ) ) + ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( 2.0 * pow( c, 2.0 ) ) * pow( l, 2.0 ) ) ) + ( ( 2.0 * pow( c, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( c, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * c ) * pow( d, 2.0 ) ) * x ) ) + ( ( ( 4.0 * c ) * pow( l, 2.0 ) ) * x ) ) - ( ( ( 4.0 * c ) * pow( r, 2.0 ) ) * x ) ) + pow( d, 4.0 ) ) - ( ( 2.0 * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + pow( l, 4.0 ) ) - ( ( 2.0 * pow( l, 2.0 ) ) * pow( r, 2.0 ) ) ) + pow( r, 4.0 ) ) <= 0.0 ) ) || ( ( ( b - d ) >= 0.0 ) && ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 4.0 ) - ( ( 4.0 * pow( a, 3.0 ) ) * x ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) ) - ( ( ( 4.0 * pow( a, 2.0 ) ) * b ) * d ) ) - ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) ) + ( ( ( 4.0 * pow( a, 2.0 ) ) * c ) * x ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( d, 2.0 ) ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( a, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( a, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * a ) * pow( b, 2.0 ) ) * x ) ) + ( ( ( ( 8.0 * a ) * b ) * d ) * x ) ) + ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * x ) ) - ( ( ( 8.0 * a ) * c ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * a ) * pow( d, 2.0 ) ) * x ) ) - ( ( ( 4.0 * a ) * pow( l, 2.0 ) ) * x ) ) + ( ( ( 4.0 * a ) * pow( r, 2.0 ) ) * x ) ) + pow( b, 4.0 ) ) - ( ( 4.0 * pow( b, 3.0 ) ) * d ) ) + ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) ) - ( ( ( 4.0 * pow( b, 2.0 ) ) * c ) * x ) ) + ( ( 6.0 * pow( b, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( 2.0 * pow( b, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( b, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( b, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * d ) ) + ( ( ( ( 8.0 * b ) * c ) * d ) * x ) ) - ( ( 4.0 * b ) * pow( d, 3.0 ) ) ) + ( ( ( 4.0 * b ) * d ) * pow( l, 2.0 ) ) ) + ( ( ( 4.0 * b ) * d ) * pow( r, 2.0 ) ) ) - ( ( ( 8.0 * b ) * d ) * pow( x, 2.0 ) ) ) + pow( c, 4.0 ) ) - ( ( 4.0 * pow( c, 3.0 ) ) * x ) ) + ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( 2.0 * pow( c, 2.0 ) ) * pow( l, 2.0 ) ) ) + ( ( 2.0 * pow( c, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( c, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * c ) * pow( d, 2.0 ) ) * x ) ) + ( ( ( 4.0 * c ) * pow( l, 2.0 ) ) * x ) ) - ( ( ( 4.0 * c ) * pow( r, 2.0 ) ) * x ) ) + pow( d, 4.0 ) ) - ( ( 2.0 * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + pow( l, 4.0 ) ) - ( ( 2.0 * pow( l, 2.0 ) ) * pow( r, 2.0 ) ) ) + pow( r, 4.0 ) ) <= 0.0 ) ) ) || ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * d ) ) - pow( c, 2.0 ) ) + ( ( 2.0 * c ) * x ) ) + pow( d, 2.0 ) ) + pow( l, 2.0 ) ) - pow( r, 2.0 ) ) <= 0.0 ) && ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 4.0 ) - ( ( 4.0 * pow( a, 3.0 ) ) * x ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) ) - ( ( ( 4.0 * pow( a, 2.0 ) ) * b ) * d ) ) - ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) ) + ( ( ( 4.0 * pow( a, 2.0 ) ) * c ) * x ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( d, 2.0 ) ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( a, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( a, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * a ) * pow( b, 2.0 ) ) * x ) ) + ( ( ( ( 8.0 * a ) * b ) * d ) * x ) ) + ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * x ) ) - ( ( ( 8.0 * a ) * c ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * a ) * pow( d, 2.0 ) ) * x ) ) - ( ( ( 4.0 * a ) * pow( l, 2.0 ) ) * x ) ) + ( ( ( 4.0 * a ) * pow( r, 2.0 ) ) * x ) ) + pow( b, 4.0 ) ) - ( ( 4.0 * pow( b, 3.0 ) ) * d ) ) + ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) ) - ( ( ( 4.0 * pow( b, 2.0 ) ) * c ) * x ) ) + ( ( 6.0 * pow( b, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( 2.0 * pow( b, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( b, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( b, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * d ) ) + ( ( ( ( 8.0 * b ) * c ) * d ) * x ) ) - ( ( 4.0 * b ) * pow( d, 3.0 ) ) ) + ( ( ( 4.0 * b ) * d ) * pow( l, 2.0 ) ) ) + ( ( ( 4.0 * b ) * d ) * pow( r, 2.0 ) ) ) - ( ( ( 8.0 * b ) * d ) * pow( x, 2.0 ) ) ) + pow( c, 4.0 ) ) - ( ( 4.0 * pow( c, 3.0 ) ) * x ) ) + ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( 2.0 * pow( c, 2.0 ) ) * pow( l, 2.0 ) ) ) + ( ( 2.0 * pow( c, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( c, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * c ) * pow( d, 2.0 ) ) * x ) ) + ( ( ( 4.0 * c ) * pow( l, 2.0 ) ) * x ) ) - ( ( ( 4.0 * c ) * pow( r, 2.0 ) ) * x ) ) + pow( d, 4.0 ) ) - ( ( 2.0 * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + pow( l, 4.0 ) ) - ( ( 2.0 * pow( l, 2.0 ) ) * pow( r, 2.0 ) ) ) + pow( r, 4.0 ) ) >= 0.0 ) ) ) ) || ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) && ( ( ( ( ( b - d ) <= 0.0 ) && ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 4.0 ) - ( ( 4.0 * pow( a, 3.0 ) ) * x ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) ) - ( ( ( 4.0 * pow( a, 2.0 ) ) * b ) * d ) ) - ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) ) + ( ( ( 4.0 * pow( a, 2.0 ) ) * c ) * x ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( d, 2.0 ) ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( a, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( a, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * a ) * pow( b, 2.0 ) ) * x ) ) + ( ( ( ( 8.0 * a ) * b ) * d ) * x ) ) + ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * x ) ) - ( ( ( 8.0 * a ) * c ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * a ) * pow( d, 2.0 ) ) * x ) ) - ( ( ( 4.0 * a ) * pow( l, 2.0 ) ) * x ) ) + ( ( ( 4.0 * a ) * pow( r, 2.0 ) ) * x ) ) + pow( b, 4.0 ) ) - ( ( 4.0 * pow( b, 3.0 ) ) * d ) ) + ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) ) - ( ( ( 4.0 * pow( b, 2.0 ) ) * c ) * x ) ) + ( ( 6.0 * pow( b, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( 2.0 * pow( b, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( b, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( b, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * d ) ) + ( ( ( ( 8.0 * b ) * c ) * d ) * x ) ) - ( ( 4.0 * b ) * pow( d, 3.0 ) ) ) + ( ( ( 4.0 * b ) * d ) * pow( l, 2.0 ) ) ) + ( ( ( 4.0 * b ) * d ) * pow( r, 2.0 ) ) ) - ( ( ( 8.0 * b ) * d ) * pow( x, 2.0 ) ) ) + pow( c, 4.0 ) ) - ( ( 4.0 * pow( c, 3.0 ) ) * x ) ) + ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( 2.0 * pow( c, 2.0 ) ) * pow( l, 2.0 ) ) ) + ( ( 2.0 * pow( c, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( c, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * c ) * pow( d, 2.0 ) ) * x ) ) + ( ( ( 4.0 * c ) * pow( l, 2.0 ) ) * x ) ) - ( ( ( 4.0 * c ) * pow( r, 2.0 ) ) * x ) ) + pow( d, 4.0 ) ) - ( ( 2.0 * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + pow( l, 4.0 ) ) - ( ( 2.0 * pow( l, 2.0 ) ) * pow( r, 2.0 ) ) ) + pow( r, 4.0 ) ) <= 0.0 ) ) || ( ( ( b - d ) >= 0.0 ) && ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 4.0 ) - ( ( 4.0 * pow( a, 3.0 ) ) * x ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) ) - ( ( ( 4.0 * pow( a, 2.0 ) ) * b ) * d ) ) - ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) ) + ( ( ( 4.0 * pow( a, 2.0 ) ) * c ) * x ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( d, 2.0 ) ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( a, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( a, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * a ) * pow( b, 2.0 ) ) * x ) ) + ( ( ( ( 8.0 * a ) * b ) * d ) * x ) ) + ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * x ) ) - ( ( ( 8.0 * a ) * c ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * a ) * pow( d, 2.0 ) ) * x ) ) - ( ( ( 4.0 * a ) * pow( l, 2.0 ) ) * x ) ) + ( ( ( 4.0 * a ) * pow( r, 2.0 ) ) * x ) ) + pow( b, 4.0 ) ) - ( ( 4.0 * pow( b, 3.0 ) ) * d ) ) + ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) ) - ( ( ( 4.0 * pow( b, 2.0 ) ) * c ) * x ) ) + ( ( 6.0 * pow( b, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( 2.0 * pow( b, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( b, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( b, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * d ) ) + ( ( ( ( 8.0 * b ) * c ) * d ) * x ) ) - ( ( 4.0 * b ) * pow( d, 3.0 ) ) ) + ( ( ( 4.0 * b ) * d ) * pow( l, 2.0 ) ) ) + ( ( ( 4.0 * b ) * d ) * pow( r, 2.0 ) ) ) - ( ( ( 8.0 * b ) * d ) * pow( x, 2.0 ) ) ) + pow( c, 4.0 ) ) - ( ( 4.0 * pow( c, 3.0 ) ) * x ) ) + ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( 2.0 * pow( c, 2.0 ) ) * pow( l, 2.0 ) ) ) + ( ( 2.0 * pow( c, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( c, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * c ) * pow( d, 2.0 ) ) * x ) ) + ( ( ( 4.0 * c ) * pow( l, 2.0 ) ) * x ) ) - ( ( ( 4.0 * c ) * pow( r, 2.0 ) ) * x ) ) + pow( d, 4.0 ) ) - ( ( 2.0 * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + pow( l, 4.0 ) ) - ( ( 2.0 * pow( l, 2.0 ) ) * pow( r, 2.0 ) ) ) + pow( r, 4.0 ) ) <= 0.0 ) ) ) || ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) - pow( b, 2.0 ) ) + ( ( 2.0 * b ) * d ) ) - pow( c, 2.0 ) ) + ( ( 2.0 * c ) * x ) ) - pow( d, 2.0 ) ) + pow( l, 2.0 ) ) - pow( r, 2.0 ) ) >= 0.0 ) && ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 4.0 ) - ( ( 4.0 * pow( a, 3.0 ) ) * x ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) ) - ( ( ( 4.0 * pow( a, 2.0 ) ) * b ) * d ) ) - ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) ) + ( ( ( 4.0 * pow( a, 2.0 ) ) * c ) * x ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( d, 2.0 ) ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( a, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( a, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * a ) * pow( b, 2.0 ) ) * x ) ) + ( ( ( ( 8.0 * a ) * b ) * d ) * x ) ) + ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * x ) ) - ( ( ( 8.0 * a ) * c ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * a ) * pow( d, 2.0 ) ) * x ) ) - ( ( ( 4.0 * a ) * pow( l, 2.0 ) ) * x ) ) + ( ( ( 4.0 * a ) * pow( r, 2.0 ) ) * x ) ) + pow( b, 4.0 ) ) - ( ( 4.0 * pow( b, 3.0 ) ) * d ) ) + ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) ) - ( ( ( 4.0 * pow( b, 2.0 ) ) * c ) * x ) ) + ( ( 6.0 * pow( b, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( 2.0 * pow( b, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( b, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( b, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * d ) ) + ( ( ( ( 8.0 * b ) * c ) * d ) * x ) ) - ( ( 4.0 * b ) * pow( d, 3.0 ) ) ) + ( ( ( 4.0 * b ) * d ) * pow( l, 2.0 ) ) ) + ( ( ( 4.0 * b ) * d ) * pow( r, 2.0 ) ) ) - ( ( ( 8.0 * b ) * d ) * pow( x, 2.0 ) ) ) + pow( c, 4.0 ) ) - ( ( 4.0 * pow( c, 3.0 ) ) * x ) ) + ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( 2.0 * pow( c, 2.0 ) ) * pow( l, 2.0 ) ) ) + ( ( 2.0 * pow( c, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( c, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * c ) * pow( d, 2.0 ) ) * x ) ) + ( ( ( 4.0 * c ) * pow( l, 2.0 ) ) * x ) ) - ( ( ( 4.0 * c ) * pow( r, 2.0 ) ) * x ) ) + pow( d, 4.0 ) ) - ( ( 2.0 * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + pow( l, 4.0 ) ) - ( ( 2.0 * pow( l, 2.0 ) ) * pow( r, 2.0 ) ) ) + pow( r, 4.0 ) ) >= 0.0 ) ) ) ) );
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


	polynomial result_polynomial_21393 = ( ( ( pow( c, 2.0 ) - ( ( 2.0 * c ) * x ) ) - pow( l, 2.0 ) ) + pow( x, 2.0 ) );
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


	polynomial result_polynomial_21393 = ( b - d );
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


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 4.0 ) - ( ( 4.0 * pow( a, 3.0 ) ) * x ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) ) - ( ( ( 4.0 * pow( a, 2.0 ) ) * b ) * d ) ) - ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) ) + ( ( ( 4.0 * pow( a, 2.0 ) ) * c ) * x ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( d, 2.0 ) ) ) + ( ( 2.0 * pow( a, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( a, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( a, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * a ) * pow( b, 2.0 ) ) * x ) ) + ( ( ( ( 8.0 * a ) * b ) * d ) * x ) ) + ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * x ) ) - ( ( ( 8.0 * a ) * c ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * a ) * pow( d, 2.0 ) ) * x ) ) - ( ( ( 4.0 * a ) * pow( l, 2.0 ) ) * x ) ) + ( ( ( 4.0 * a ) * pow( r, 2.0 ) ) * x ) ) + pow( b, 4.0 ) ) - ( ( 4.0 * pow( b, 3.0 ) ) * d ) ) + ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) ) - ( ( ( 4.0 * pow( b, 2.0 ) ) * c ) * x ) ) + ( ( 6.0 * pow( b, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( 2.0 * pow( b, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( b, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( b, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * d ) ) + ( ( ( ( 8.0 * b ) * c ) * d ) * x ) ) - ( ( 4.0 * b ) * pow( d, 3.0 ) ) ) + ( ( ( 4.0 * b ) * d ) * pow( l, 2.0 ) ) ) + ( ( ( 4.0 * b ) * d ) * pow( r, 2.0 ) ) ) - ( ( ( 8.0 * b ) * d ) * pow( x, 2.0 ) ) ) + pow( c, 4.0 ) ) - ( ( 4.0 * pow( c, 3.0 ) ) * x ) ) + ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( 2.0 * pow( c, 2.0 ) ) * pow( l, 2.0 ) ) ) + ( ( 2.0 * pow( c, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( c, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * c ) * pow( d, 2.0 ) ) * x ) ) + ( ( ( 4.0 * c ) * pow( l, 2.0 ) ) * x ) ) - ( ( ( 4.0 * c ) * pow( r, 2.0 ) ) * x ) ) + pow( d, 4.0 ) ) - ( ( 2.0 * pow( d, 2.0 ) ) * pow( l, 2.0 ) ) ) - ( ( 2.0 * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( 4.0 * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + pow( l, 4.0 ) ) - ( ( 2.0 * pow( l, 2.0 ) ) * pow( r, 2.0 ) ) ) + pow( r, 4.0 ) );
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


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * d ) ) - pow( c, 2.0 ) ) + ( ( 2.0 * c ) * x ) ) + pow( d, 2.0 ) ) + pow( l, 2.0 ) ) - pow( r, 2.0 ) );
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


	polynomial result_polynomial_21393 = ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
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


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) - pow( b, 2.0 ) ) + ( ( 2.0 * b ) * d ) ) - pow( c, 2.0 ) ) + ( ( 2.0 * c ) * x ) ) - pow( d, 2.0 ) ) + pow( l, 2.0 ) ) - pow( r, 2.0 ) );
	return result_polynomial_21393;
}



bool test_formula_at_sample_points(const double a, const double b, const double c, const double d, const double l, const double r , const std::vector<polynomial>& upolys) {
	rational max_width(0.0001);
	vector<interval> roots;
	for (auto& p_univariate : upolys) {
	  cout << "Isolating roots for " << p_univariate << endl;
	  concat(roots, isolate_roots(p_univariate, max_width));
	  cout << "Done roots for " << p_univariate << endl;
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
	vector<polynomial> polys{make_polynomial_1(), make_polynomial_2(), make_polynomial_3(), make_polynomial_4(), make_polynomial_5(), make_polynomial_6() };
	vector<rational> rs{{a}, {b}, {c}, {d}, {l}, {r} };
	vector<polynomial> upolys;
	for (auto& p : polys) {
		polynomial p_univariate = evaluate_at(rs, p);
		upolys.push_back(p_univariate);
	}
	return test_formula_at_sample_points(a, b, c, d, l, r , upolys);

}

bool point_in_circle(const double x,
		     const double y,
		     const double a,
		     const double b,
		     const double r) {
  return pow(x - a, 2) + pow(y - b, 2) <= r*r;
}

void fuzz_test_circles(const double a,
		       const double b,
		       const double r,
		       const double c,
		       const double d,
		       const double l) {
  double min_x = min(a, c) - 10;
  double max_x = max(a, c) + 10;

  double min_y = min(b, d) - 10;
  double max_y = max(b, d) + 10;

  for (double x = min_x; x <= max_x; x += 0.1) {
    for (double y = min_y; y <= max_y; y += 1) {
      bool in_c1 = point_in_circle(x, y, a, b, r);
      bool in_c2 = point_in_circle(x, y, c, d, l);
      if (in_c1 && in_c2) {
	cout << "Circles overlap" << endl;
      }
    }
  }

}

int main() {

  double a = 0;
  double b = 0;
  double r = 1;

  double c = 2;
  double d = 0;
  double l = 1.00001;

  bool i = shapes_intersect(a, b, c, d, l, r);
  cout << "Intersect ? " << i << endl;

  fuzz_test_circles(a, b, r, c, d, l);
}
