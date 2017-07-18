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

bool formula(const double a, const double b, const double c, const double j, const double k, const double l, const double m, const double r, const double x ) {
	return ( ( ( ( ( ( ( ( ( m >= 0.0 ) && ( ( j - x ) <= 0.0 ) ) && ( ( ( j + m ) - x ) >= 0.0 ) ) && ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + ( 2.0 * pow( m, 2.0 ) ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) || ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) && ( ( ( ( ( ( ( ( ( j - x ) <= 0.0 ) && ( ( ( j + m ) - x ) >= 0.0 ) ) && ( ( c - l ) >= 0.0 ) ) && ( ( ( c - l ) - m ) <= 0.0 ) ) && ( ( b - k ) >= 0.0 ) ) && ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) + pow( k, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( ( ( b - k ) - m ) <= 0.0 ) || ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) || ( ( ( ( ( ( ( ( j - x ) <= 0.0 ) && ( ( ( j + m ) - x ) >= 0.0 ) ) && ( ( c - l ) >= 0.0 ) ) && ( ( ( c - l ) - m ) <= 0.0 ) ) && ( ( ( b - k ) - m ) <= 0.0 ) ) && ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( ( b - k ) >= 0.0 ) || ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) + pow( k, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) ) ) ) || ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) + pow( l, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) && ( ( ( ( ( ( ( ( ( ( ( j - x ) <= 0.0 ) && ( ( ( j + m ) - x ) >= 0.0 ) ) && ( ( c - l ) >= 0.0 ) ) && ( ( b - k ) >= 0.0 ) ) && ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) + pow( k, 2.0 ) ) + pow( l, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( ( ( c - l ) - m ) <= 0.0 ) || ( ( ( ( ( 2.0 * c ) * m ) - ( ( 2.0 * l ) * m ) ) - pow( m, 2.0 ) ) >= 0.0 ) ) ) && ( ( ( ( b - k ) - m ) <= 0.0 ) || ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) || ( ( ( ( ( ( ( ( j - x ) <= 0.0 ) && ( ( ( j + m ) - x ) >= 0.0 ) ) && ( ( c - l ) >= 0.0 ) ) && ( ( ( b - k ) - m ) <= 0.0 ) ) && ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( ( ( c - l ) - m ) <= 0.0 ) || ( ( ( ( ( 2.0 * c ) * m ) - ( ( 2.0 * l ) * m ) ) - pow( m, 2.0 ) ) >= 0.0 ) ) ) && ( ( ( b - k ) >= 0.0 ) || ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) + pow( k, 2.0 ) ) + pow( l, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) ) || ( ( ( ( ( ( ( ( j - x ) <= 0.0 ) && ( ( ( j + m ) - x ) >= 0.0 ) ) && ( ( ( c - l ) - m ) <= 0.0 ) ) && ( ( ( ( ( 2.0 * c ) * m ) - ( ( 2.0 * l ) * m ) ) - pow( m, 2.0 ) ) <= 0.0 ) ) && ( ( b - k ) >= 0.0 ) ) && ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) + pow( k, 2.0 ) ) + pow( l, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( ( ( b - k ) - m ) <= 0.0 ) || ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) ) || ( ( ( ( ( ( ( ( j - x ) <= 0.0 ) && ( ( ( j + m ) - x ) >= 0.0 ) ) && ( ( ( c - l ) - m ) <= 0.0 ) ) && ( ( ( ( ( 2.0 * c ) * m ) - ( ( 2.0 * l ) * m ) ) - pow( m, 2.0 ) ) <= 0.0 ) ) && ( ( ( b - k ) - m ) <= 0.0 ) ) && ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( ( b - k ) >= 0.0 ) || ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) + pow( k, 2.0 ) ) + pow( l, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) ) ) ) || ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) && ( ( ( ( ( ( ( m >= 0.0 ) && ( ( j - x ) <= 0.0 ) ) && ( ( ( j + m ) - x ) >= 0.0 ) ) && ( ( b - k ) >= 0.0 ) ) && ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( ( ( b - k ) - m ) <= 0.0 ) || ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + ( 2.0 * pow( m, 2.0 ) ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) || ( ( ( ( ( ( m >= 0.0 ) && ( ( j - x ) <= 0.0 ) ) && ( ( ( j + m ) - x ) >= 0.0 ) ) && ( ( ( b - k ) - m ) <= 0.0 ) ) && ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + ( 2.0 * pow( m, 2.0 ) ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( ( b - k ) >= 0.0 ) || ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) ) ) ) || ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) && ( ( ( ( ( ( ( ( ( ( ( j - x ) <= 0.0 ) && ( ( ( j + m ) - x ) >= 0.0 ) ) && ( ( c - l ) >= 0.0 ) ) && ( ( ( ( ( 2.0 * c ) * m ) - ( ( 2.0 * l ) * m ) ) - pow( m, 2.0 ) ) >= 0.0 ) ) && ( ( b - k ) >= 0.0 ) ) && ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( ( ( b - k ) - m ) <= 0.0 ) || ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + ( 2.0 * pow( m, 2.0 ) ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) || ( ( ( ( ( ( ( ( j - x ) <= 0.0 ) && ( ( ( j + m ) - x ) >= 0.0 ) ) && ( ( c - l ) >= 0.0 ) ) && ( ( ( ( ( 2.0 * c ) * m ) - ( ( 2.0 * l ) * m ) ) - pow( m, 2.0 ) ) >= 0.0 ) ) && ( ( ( b - k ) - m ) <= 0.0 ) ) && ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + ( 2.0 * pow( m, 2.0 ) ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( ( b - k ) >= 0.0 ) || ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) ) || ( ( ( ( ( ( ( ( j - x ) <= 0.0 ) && ( ( ( j + m ) - x ) >= 0.0 ) ) && ( ( ( c - l ) - m ) <= 0.0 ) ) && ( ( b - k ) >= 0.0 ) ) && ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( ( c - l ) >= 0.0 ) || ( ( ( ( ( 2.0 * c ) * m ) - ( ( 2.0 * l ) * m ) ) - pow( m, 2.0 ) ) <= 0.0 ) ) ) && ( ( ( ( b - k ) - m ) <= 0.0 ) || ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + ( 2.0 * pow( m, 2.0 ) ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) ) || ( ( ( ( ( ( ( ( j - x ) <= 0.0 ) && ( ( ( j + m ) - x ) >= 0.0 ) ) && ( ( ( c - l ) - m ) <= 0.0 ) ) && ( ( ( b - k ) - m ) <= 0.0 ) ) && ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + ( 2.0 * pow( m, 2.0 ) ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( ( c - l ) >= 0.0 ) || ( ( ( ( ( 2.0 * c ) * m ) - ( ( 2.0 * l ) * m ) ) - pow( m, 2.0 ) ) <= 0.0 ) ) ) && ( ( ( b - k ) >= 0.0 ) || ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) ) ) ) || ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) && ( ( ( ( ( ( ( m >= 0.0 ) && ( ( j - x ) <= 0.0 ) ) && ( ( ( j + m ) - x ) >= 0.0 ) ) && ( ( c - l ) >= 0.0 ) ) && ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( ( ( c - l ) - m ) <= 0.0 ) || ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + ( 2.0 * pow( m, 2.0 ) ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) || ( ( ( ( ( ( m >= 0.0 ) && ( ( j - x ) <= 0.0 ) ) && ( ( ( j + m ) - x ) >= 0.0 ) ) && ( ( ( c - l ) - m ) <= 0.0 ) ) && ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + ( 2.0 * pow( m, 2.0 ) ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) >= 0.0 ) ) && ( ( ( c - l ) >= 0.0 ) || ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) ) <= 0.0 ) ) ) ) ) );
}


polynomial make_polynomial_1() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = m;
	return result_polynomial_21393;
}

polynomial make_polynomial_2() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( j - x );
	return result_polynomial_21393;
}

polynomial make_polynomial_3() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( ( j + m ) - x );
	return result_polynomial_21393;
}

polynomial make_polynomial_4() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + ( 2.0 * pow( m, 2.0 ) ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_5() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_6() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( c - l );
	return result_polynomial_21393;
}

polynomial make_polynomial_7() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( ( c - l ) - m );
	return result_polynomial_21393;
}

polynomial make_polynomial_8() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( b - k );
	return result_polynomial_21393;
}

polynomial make_polynomial_9() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) + pow( k, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_10() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( ( b - k ) - m );
	return result_polynomial_21393;
}

polynomial make_polynomial_11() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_12() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) + pow( l, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_13() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) + pow( k, 2.0 ) ) + pow( l, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_14() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( ( ( ( 2.0 * c ) * m ) - ( ( 2.0 * l ) * m ) ) - pow( m, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_15() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) - ( ( 2.0 * b ) * m ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) + pow( k, 2.0 ) ) + ( ( 2.0 * k ) * m ) ) + pow( l, 2.0 ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_16() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_17() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_c(1, {0, 0, 1, 0, 0, 0, 0, 0, 0 }, 9);
	monomial m_j(1, {0, 0, 0, 1, 0, 0, 0, 0, 0 }, 9);
	monomial m_k(1, {0, 0, 0, 0, 1, 0, 0, 0, 0 }, 9);
	monomial m_l(1, {0, 0, 0, 0, 0, 1, 0, 0, 0 }, 9);
	monomial m_m(1, {0, 0, 0, 0, 0, 0, 1, 0, 0 }, 9);
	monomial m_r(1, {0, 0, 0, 0, 0, 0, 0, 1, 0 }, 9);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 1 }, 9);


	polynomial a({m_a}, 9);
	polynomial b({m_b}, 9);
	polynomial c({m_c}, 9);
	polynomial j({m_j}, 9);
	polynomial k({m_k}, 9);
	polynomial l({m_l}, 9);
	polynomial m({m_m}, 9);
	polynomial r({m_r}, 9);
	polynomial x({m_x}, 9);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) + pow( b, 2.0 ) ) - ( ( 2.0 * b ) * k ) ) + pow( c, 2.0 ) ) - ( ( 2.0 * c ) * l ) ) - ( ( 2.0 * c ) * m ) ) + pow( k, 2.0 ) ) + pow( l, 2.0 ) ) + ( ( 2.0 * l ) * m ) ) + pow( m, 2.0 ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	return result_polynomial_21393;
}



bool test_formula_at_sample_points(const double a, const double b, const double c, const double j, const double k, const double l, const double m, const double r , const std::vector<polynomial>& upolys) {
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
		return formula(a, b, c, j, k, l, m, r , 0.0);
	 }

	for (auto& pt : test_points) { double test_x = pt.to_double();
	 bool fm_true = formula(a, b, c, j, k, l, m, r , test_x);
	 cout << "At x = " << test_x << " the formula is " << fm_true << endl;
	 if (fm_true) {
		return true;
	 }
	}
	return false;
	
}

bool shapes_intersect( const double a, const double b, const double c, const double j, const double k, const double l, const double m, const double r ) {
	vector<polynomial> polys{make_polynomial_1(), make_polynomial_2(), make_polynomial_3(), make_polynomial_4(), make_polynomial_5(), make_polynomial_6(), make_polynomial_7(), make_polynomial_8(), make_polynomial_9(), make_polynomial_10(), make_polynomial_11(), make_polynomial_12(), make_polynomial_13(), make_polynomial_14(), make_polynomial_15(), make_polynomial_16(), make_polynomial_17() };
	vector<rational> rs{{a}, {b}, {c}, {j}, {k}, {l}, {m}, {r} };
	vector<polynomial> upolys;
	for (auto& p : polys) {
		polynomial p_univariate = evaluate_at(rs, p);
		upolys.push_back(p_univariate);
	}
	return test_formula_at_sample_points(a, b, c, j, k, l, m, r , upolys);

}

int main() {
  double a = 0;
  double b = 0;
  double c = 0;
  double r = 20.0;

  double j = 30.0;
  double k = 30.0;
  double l = 30.0;
  double m = 3.0;


  bool it = shapes_intersect(  a,  b,  c,  j,  k,  l,  m,  r );

  cout << "it = " << it << endl;

  
}
