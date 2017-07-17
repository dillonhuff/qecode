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
	return ( ( ( !within_eps( c, 0.0 , EPSILON ) && ( within_eps( d, 0.0 , EPSILON ) || within_eps( ( ( ( pow( c, 2.0 ) - pow( h, 2.0 ) ) + ( ( 2.0 * h ) * x ) ) - pow( x, 2.0 ) ), 0.0 , EPSILON ) ) ) && ( ( ( within_eps( ( b - k ), 0.0 , EPSILON ) && within_eps( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 4.0 ) * pow( c, 4.0 ) ) - ( ( ( 4.0 * pow( a, 3.0 ) ) * pow( c, 4.0 ) ) * x ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) ) - ( ( ( ( 4.0 * pow( a, 2.0 ) ) * b ) * pow( c, 4.0 ) ) * k ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 6.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( ( 4.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * x ) ) - ( ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( 4.0 * a ) * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * x ) ) + ( ( ( ( ( 8.0 * a ) * b ) * pow( c, 4.0 ) ) * k ) * x ) ) - ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * x ) ) - ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) * x ) ) - ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( x, 3.0 ) ) ) + ( ( ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * x ) ) - ( ( ( ( ( 8.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( x, 2.0 ) ) ) + ( ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 3.0 ) ) ) + ( pow( b, 4.0 ) * pow( c, 4.0 ) ) ) - ( ( ( 4.0 * pow( b, 3.0 ) ) * pow( c, 4.0 ) ) * k ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) ) + ( ( ( 6.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) - ( ( ( ( ( 4.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * x ) ) + ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * k ) ) - ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * pow( k, 3.0 ) ) ) + ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * k ) * pow( r, 2.0 ) ) ) - ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * k ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * k ) ) + ( ( ( ( ( ( 8.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * k ) * x ) ) - ( ( ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * k ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( d, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( k, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( r, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( x, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * h ) * x ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( k, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( r, 2.0 ) ) ) - ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( k, 2.0 ) ) * x ) ) - ( ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( r, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( x, 3.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( k, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 4.0 ) ) ) + ( pow( d, 4.0 ) * pow( h, 4.0 ) ) ) - ( ( ( 4.0 * pow( d, 4.0 ) ) * pow( h, 3.0 ) ) * x ) ) + ( ( ( 6.0 * pow( d, 4.0 ) ) * pow( h, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * pow( d, 4.0 ) ) * h ) * pow( x, 3.0 ) ) ) + ( pow( d, 4.0 ) * pow( x, 4.0 ) ) ), 0.0 , EPSILON ) ) || ( within_eps( ( b - k ), 0.0 , EPSILON ) && within_eps( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 4.0 ) * pow( c, 4.0 ) ) - ( ( ( 4.0 * pow( a, 3.0 ) ) * pow( c, 4.0 ) ) * x ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) ) - ( ( ( ( 4.0 * pow( a, 2.0 ) ) * b ) * pow( c, 4.0 ) ) * k ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 6.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( ( 4.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * x ) ) - ( ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( 4.0 * a ) * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * x ) ) + ( ( ( ( ( 8.0 * a ) * b ) * pow( c, 4.0 ) ) * k ) * x ) ) - ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * x ) ) - ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) * x ) ) - ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( x, 3.0 ) ) ) + ( ( ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * x ) ) - ( ( ( ( ( 8.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( x, 2.0 ) ) ) + ( ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 3.0 ) ) ) + ( pow( b, 4.0 ) * pow( c, 4.0 ) ) ) - ( ( ( 4.0 * pow( b, 3.0 ) ) * pow( c, 4.0 ) ) * k ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) ) + ( ( ( 6.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) - ( ( ( ( ( 4.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * x ) ) + ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * k ) ) - ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * pow( k, 3.0 ) ) ) + ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * k ) * pow( r, 2.0 ) ) ) - ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * k ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * k ) ) + ( ( ( ( ( ( 8.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * k ) * x ) ) - ( ( ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * k ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( d, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( k, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( r, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( x, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * h ) * x ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( k, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( r, 2.0 ) ) ) - ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( k, 2.0 ) ) * x ) ) - ( ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( r, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( x, 3.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( k, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 4.0 ) ) ) + ( pow( d, 4.0 ) * pow( h, 4.0 ) ) ) - ( ( ( 4.0 * pow( d, 4.0 ) ) * pow( h, 3.0 ) ) * x ) ) + ( ( ( 6.0 * pow( d, 4.0 ) ) * pow( h, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * pow( d, 4.0 ) ) * h ) * pow( x, 3.0 ) ) ) + ( pow( d, 4.0 ) * pow( x, 4.0 ) ) ), 0.0 , EPSILON ) ) ) || ( within_eps( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( c, 2.0 ) ) - ( ( ( 2.0 * a ) * pow( c, 2.0 ) ) * x ) ) + ( pow( b, 2.0 ) * pow( c, 2.0 ) ) ) - ( ( ( 2.0 * b ) * pow( c, 2.0 ) ) * k ) ) + ( pow( c, 2.0 ) * pow( d, 2.0 ) ) ) + ( pow( c, 2.0 ) * pow( k, 2.0 ) ) ) - ( pow( c, 2.0 ) * pow( r, 2.0 ) ) ) + ( pow( c, 2.0 ) * pow( x, 2.0 ) ) ) - ( pow( d, 2.0 ) * pow( h, 2.0 ) ) ) + ( ( ( 2.0 * pow( d, 2.0 ) ) * h ) * x ) ) - ( pow( d, 2.0 ) * pow( x, 2.0 ) ) ), 0.0 , EPSILON ) && within_eps( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 4.0 ) * pow( c, 4.0 ) ) - ( ( ( 4.0 * pow( a, 3.0 ) ) * pow( c, 4.0 ) ) * x ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) ) - ( ( ( ( 4.0 * pow( a, 2.0 ) ) * b ) * pow( c, 4.0 ) ) * k ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 6.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( ( 4.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * x ) ) - ( ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( 4.0 * a ) * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * x ) ) + ( ( ( ( ( 8.0 * a ) * b ) * pow( c, 4.0 ) ) * k ) * x ) ) - ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * x ) ) - ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) * x ) ) - ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( x, 3.0 ) ) ) + ( ( ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * x ) ) - ( ( ( ( ( 8.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( x, 2.0 ) ) ) + ( ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 3.0 ) ) ) + ( pow( b, 4.0 ) * pow( c, 4.0 ) ) ) - ( ( ( 4.0 * pow( b, 3.0 ) ) * pow( c, 4.0 ) ) * k ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) ) + ( ( ( 6.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) - ( ( ( ( ( 4.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * x ) ) + ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * k ) ) - ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * pow( k, 3.0 ) ) ) + ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * k ) * pow( r, 2.0 ) ) ) - ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * k ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * k ) ) + ( ( ( ( ( ( 8.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * k ) * x ) ) - ( ( ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * k ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( d, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( k, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( r, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( x, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * h ) * x ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( k, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( r, 2.0 ) ) ) - ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( k, 2.0 ) ) * x ) ) - ( ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( r, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( x, 3.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( k, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 4.0 ) ) ) + ( pow( d, 4.0 ) * pow( h, 4.0 ) ) ) - ( ( ( 4.0 * pow( d, 4.0 ) ) * pow( h, 3.0 ) ) * x ) ) + ( ( ( 6.0 * pow( d, 4.0 ) ) * pow( h, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * pow( d, 4.0 ) ) * h ) * pow( x, 3.0 ) ) ) + ( pow( d, 4.0 ) * pow( x, 4.0 ) ) ), 0.0 , EPSILON ) ) ) ) || ( within_eps( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ), 0.0 , EPSILON ) && ( ( within_eps( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 4.0 ) * pow( c, 4.0 ) ) - ( ( ( 4.0 * pow( a, 3.0 ) ) * pow( c, 4.0 ) ) * x ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) ) - ( ( ( ( 4.0 * pow( a, 2.0 ) ) * b ) * pow( c, 4.0 ) ) * k ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 6.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( ( 4.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * x ) ) - ( ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( 4.0 * a ) * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * x ) ) + ( ( ( ( ( 8.0 * a ) * b ) * pow( c, 4.0 ) ) * k ) * x ) ) - ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * x ) ) - ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) * x ) ) - ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( x, 3.0 ) ) ) + ( ( ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * x ) ) - ( ( ( ( ( 8.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( x, 2.0 ) ) ) + ( ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 3.0 ) ) ) + ( pow( b, 4.0 ) * pow( c, 4.0 ) ) ) - ( ( ( 4.0 * pow( b, 3.0 ) ) * pow( c, 4.0 ) ) * k ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) ) + ( ( ( 6.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) - ( ( ( ( ( 4.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * x ) ) + ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * k ) ) - ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * pow( k, 3.0 ) ) ) + ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * k ) * pow( r, 2.0 ) ) ) - ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * k ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * k ) ) + ( ( ( ( ( ( 8.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * k ) * x ) ) - ( ( ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * k ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( d, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( k, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( r, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( x, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * h ) * x ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( k, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( r, 2.0 ) ) ) - ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( k, 2.0 ) ) * x ) ) - ( ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( r, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( x, 3.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( k, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 4.0 ) ) ) + ( pow( d, 4.0 ) * pow( h, 4.0 ) ) ) - ( ( ( 4.0 * pow( d, 4.0 ) ) * pow( h, 3.0 ) ) * x ) ) + ( ( ( 6.0 * pow( d, 4.0 ) ) * pow( h, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * pow( d, 4.0 ) ) * h ) * pow( x, 3.0 ) ) ) + ( pow( d, 4.0 ) * pow( x, 4.0 ) ) ), 0.0 , EPSILON ) && ( within_eps( c, 0.0 , EPSILON ) || within_eps( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * b ) * pow( c, 2.0 ) ) - ( ( pow( a, 2.0 ) * pow( c, 2.0 ) ) * k ) ) - ( ( ( ( 2.0 * a ) * b ) * pow( c, 2.0 ) ) * x ) ) + ( ( ( ( 2.0 * a ) * pow( c, 2.0 ) ) * k ) * x ) ) - ( pow( b, 3.0 ) * pow( c, 2.0 ) ) ) + ( ( ( 3.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * k ) ) + ( ( b * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( ( 3.0 * b ) * pow( c, 2.0 ) ) * pow( k, 2.0 ) ) ) - ( ( b * pow( c, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( b * pow( c, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( b * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( 2.0 * b ) * pow( d, 2.0 ) ) * h ) * x ) ) - ( ( b * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( pow( c, 2.0 ) * pow( d, 2.0 ) ) * k ) ) + ( pow( c, 2.0 ) * pow( k, 3.0 ) ) ) + ( ( pow( c, 2.0 ) * k ) * pow( r, 2.0 ) ) ) - ( ( pow( c, 2.0 ) * k ) * pow( x, 2.0 ) ) ) + ( ( pow( d, 2.0 ) * pow( h, 2.0 ) ) * k ) ) - ( ( ( ( 2.0 * pow( d, 2.0 ) ) * h ) * k ) * x ) ) + ( ( pow( d, 2.0 ) * k ) * pow( x, 2.0 ) ) ), 0.0 , EPSILON ) ) ) || ( within_eps( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 4.0 ) * pow( c, 4.0 ) ) - ( ( ( 4.0 * pow( a, 3.0 ) ) * pow( c, 4.0 ) ) * x ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) ) - ( ( ( ( 4.0 * pow( a, 2.0 ) ) * b ) * pow( c, 4.0 ) ) * k ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) ) + ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 6.0 * pow( a, 2.0 ) ) * pow( c, 4.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( ( 4.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * x ) ) - ( ( ( ( 2.0 * pow( a, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( 4.0 * a ) * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * x ) ) + ( ( ( ( ( 8.0 * a ) * b ) * pow( c, 4.0 ) ) * k ) * x ) ) - ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * x ) ) - ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) * x ) ) - ( ( ( 4.0 * a ) * pow( c, 4.0 ) ) * pow( x, 3.0 ) ) ) + ( ( ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * x ) ) - ( ( ( ( ( 8.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( x, 2.0 ) ) ) + ( ( ( ( 4.0 * a ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 3.0 ) ) ) + ( pow( b, 4.0 ) * pow( c, 4.0 ) ) ) - ( ( ( 4.0 * pow( b, 3.0 ) ) * pow( c, 4.0 ) ) * k ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) ) + ( ( ( 6.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) - ( ( ( ( ( 4.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * x ) ) + ( ( ( ( 2.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * k ) ) - ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * pow( k, 3.0 ) ) ) + ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * k ) * pow( r, 2.0 ) ) ) - ( ( ( ( 4.0 * b ) * pow( c, 4.0 ) ) * k ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * k ) ) + ( ( ( ( ( ( 8.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * k ) * x ) ) - ( ( ( ( ( 4.0 * b ) * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * k ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( d, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( k, 2.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( k, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( k, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( r, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 4.0 ) ) * pow( r, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( pow( c, 4.0 ) * pow( x, 4.0 ) ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * h ) * x ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 4.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( k, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( r, 2.0 ) ) ) - ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( k, 2.0 ) ) * x ) ) - ( ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( r, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * h ) * pow( x, 3.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( k, 2.0 ) ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( r, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 2.0 * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) * pow( x, 4.0 ) ) ) + ( pow( d, 4.0 ) * pow( h, 4.0 ) ) ) - ( ( ( 4.0 * pow( d, 4.0 ) ) * pow( h, 3.0 ) ) * x ) ) + ( ( ( 6.0 * pow( d, 4.0 ) ) * pow( h, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( ( 4.0 * pow( d, 4.0 ) ) * h ) * pow( x, 3.0 ) ) ) + ( pow( d, 4.0 ) * pow( x, 4.0 ) ) ), 0.0 , EPSILON ) && ( within_eps( c, 0.0 , EPSILON ) || within_eps( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * b ) * pow( c, 2.0 ) ) - ( ( pow( a, 2.0 ) * pow( c, 2.0 ) ) * k ) ) - ( ( ( ( 2.0 * a ) * b ) * pow( c, 2.0 ) ) * x ) ) + ( ( ( ( 2.0 * a ) * pow( c, 2.0 ) ) * k ) * x ) ) - ( pow( b, 3.0 ) * pow( c, 2.0 ) ) ) + ( ( ( 3.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * k ) ) + ( ( b * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( ( 3.0 * b ) * pow( c, 2.0 ) ) * pow( k, 2.0 ) ) ) - ( ( b * pow( c, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( b * pow( c, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( b * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( 2.0 * b ) * pow( d, 2.0 ) ) * h ) * x ) ) - ( ( b * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( pow( c, 2.0 ) * pow( d, 2.0 ) ) * k ) ) + ( pow( c, 2.0 ) * pow( k, 3.0 ) ) ) + ( ( pow( c, 2.0 ) * k ) * pow( r, 2.0 ) ) ) - ( ( pow( c, 2.0 ) * k ) * pow( x, 2.0 ) ) ) + ( ( pow( d, 2.0 ) * pow( h, 2.0 ) ) * k ) ) - ( ( ( ( 2.0 * pow( d, 2.0 ) ) * h ) * k ) * x ) ) + ( ( pow( d, 2.0 ) * k ) * pow( x, 2.0 ) ) ), 0.0 , EPSILON ) ) ) ) ) );
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


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * b ) * pow( c, 2.0 ) ) - ( ( pow( a, 2.0 ) * pow( c, 2.0 ) ) * k ) ) - ( ( ( ( 2.0 * a ) * b ) * pow( c, 2.0 ) ) * x ) ) + ( ( ( ( 2.0 * a ) * pow( c, 2.0 ) ) * k ) * x ) ) - ( pow( b, 3.0 ) * pow( c, 2.0 ) ) ) + ( ( ( 3.0 * pow( b, 2.0 ) ) * pow( c, 2.0 ) ) * k ) ) + ( ( b * pow( c, 2.0 ) ) * pow( d, 2.0 ) ) ) - ( ( ( 3.0 * b ) * pow( c, 2.0 ) ) * pow( k, 2.0 ) ) ) - ( ( b * pow( c, 2.0 ) ) * pow( r, 2.0 ) ) ) + ( ( b * pow( c, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( b * pow( d, 2.0 ) ) * pow( h, 2.0 ) ) ) + ( ( ( ( 2.0 * b ) * pow( d, 2.0 ) ) * h ) * x ) ) - ( ( b * pow( d, 2.0 ) ) * pow( x, 2.0 ) ) ) - ( ( pow( c, 2.0 ) * pow( d, 2.0 ) ) * k ) ) + ( pow( c, 2.0 ) * pow( k, 3.0 ) ) ) + ( ( pow( c, 2.0 ) * k ) * pow( r, 2.0 ) ) ) - ( ( pow( c, 2.0 ) * k ) * pow( x, 2.0 ) ) ) + ( ( pow( d, 2.0 ) * pow( h, 2.0 ) ) * k ) ) - ( ( ( ( 2.0 * pow( d, 2.0 ) ) * h ) * k ) * x ) ) + ( ( pow( d, 2.0 ) * k ) * pow( x, 2.0 ) ) );
	return result_polynomial_21393;
}



bool test_formula_at_sample_points(const double a, const double b, const double c, const double d, const double h, const double k, const double r , const std::vector<polynomial>& upolys) {
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

bool shapes_intersect( const double a, const double b, const double c, const double d, const double h, const double k, const double r ) {
	vector<polynomial> polys{make_polynomial_1(), make_polynomial_2(), make_polynomial_3(), make_polynomial_4(), make_polynomial_5(), make_polynomial_6(), make_polynomial_7(), make_polynomial_8() };
	vector<rational> rs{{a}, {b}, {c}, {d}, {h}, {k}, {r} };
	vector<polynomial> upolys;
	for (auto& p : polys) {
		polynomial p_univariate = evaluate_at(rs, p);
		upolys.push_back(p_univariate);
	}
	return test_formula_at_sample_points(a, b, c, d, h, k, r , upolys);

}

int main() {
  int a = -1;
  int b = -1;
  int r = 1000;

  int c = 1;
  int d = 1;

  int h = 3;
  int k = 2;

  bool i = shapes_intersect(a, b, c, d, h, k, r);
  cout << "Intersect ? " << i << endl;
}
