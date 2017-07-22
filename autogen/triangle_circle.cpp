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

bool formula(const double a, const double b, const double r, const double v1x, const double v1y, const double v2x, const double v2y, const double v3x, const double v3y, const double x ) {
	double p_1 = ( v2x - v3x );
	double p_2 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( v2x, 2.0 ) ) - ( ( ( 2.0 * pow( a, 2.0 ) ) * v2x ) * v3x ) ) + ( pow( a, 2.0 ) * pow( v3x, 2.0 ) ) ) - ( ( ( 2.0 * a ) * pow( v2x, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * a ) * v2x ) * v3x ) * x ) ) - ( ( ( 2.0 * a ) * pow( v3x, 2.0 ) ) * x ) ) + ( pow( b, 2.0 ) * pow( v2x, 2.0 ) ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * v2x ) * v3x ) ) + ( pow( b, 2.0 ) * pow( v3x, 2.0 ) ) ) - ( ( ( 2.0 * b ) * pow( v2x, 2.0 ) ) * v3y ) ) + ( ( ( ( 2.0 * b ) * v2x ) * v2y ) * v3x ) ) - ( ( ( ( 2.0 * b ) * v2x ) * v2y ) * x ) ) + ( ( ( ( 2.0 * b ) * v2x ) * v3x ) * v3y ) ) + ( ( ( ( 2.0 * b ) * v2x ) * v3y ) * x ) ) - ( ( ( 2.0 * b ) * v2y ) * pow( v3x, 2.0 ) ) ) + ( ( ( ( 2.0 * b ) * v2y ) * v3x ) * x ) ) - ( ( ( ( 2.0 * b ) * v3x ) * v3y ) * x ) ) - ( pow( r, 2.0 ) * pow( v2x, 2.0 ) ) ) + ( ( ( 2.0 * pow( r, 2.0 ) ) * v2x ) * v3x ) ) - ( pow( r, 2.0 ) * pow( v3x, 2.0 ) ) ) + ( pow( v2x, 2.0 ) * pow( v3y, 2.0 ) ) ) + ( pow( v2x, 2.0 ) * pow( x, 2.0 ) ) ) - ( ( ( ( 2.0 * v2x ) * v2y ) * v3x ) * v3y ) ) + ( ( ( ( 2.0 * v2x ) * v2y ) * v3y ) * x ) ) - ( ( ( 2.0 * v2x ) * v3x ) * pow( x, 2.0 ) ) ) - ( ( ( 2.0 * v2x ) * pow( v3y, 2.0 ) ) * x ) ) + ( pow( v2y, 2.0 ) * pow( v3x, 2.0 ) ) ) - ( ( ( 2.0 * pow( v2y, 2.0 ) ) * v3x ) * x ) ) + ( pow( v2y, 2.0 ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * v2y ) * v3x ) * v3y ) * x ) ) - ( ( ( 2.0 * v2y ) * v3y ) * pow( x, 2.0 ) ) ) + ( pow( v3x, 2.0 ) * pow( x, 2.0 ) ) ) + ( pow( v3y, 2.0 ) * pow( x, 2.0 ) ) );
	double p_3 = ( v3x - x );
	double p_4 = ( ( ( ( ( ( v1x * v2y ) - ( v1x * v3y ) ) - ( v1y * v2x ) ) + ( v1y * v3x ) ) + ( v2x * v3y ) ) - ( v2y * v3x ) );
	double p_5 = ( v2x - x );
	double p_6 = ( ( ( ( ( ( ( ( ( ( ( b * pow( v2x, 2.0 ) ) - ( ( ( 2.0 * b ) * v2x ) * v3x ) ) + ( b * pow( v3x, 2.0 ) ) ) - ( pow( v2x, 2.0 ) * v3y ) ) + ( ( v2x * v2y ) * v3x ) ) - ( ( v2x * v2y ) * x ) ) + ( ( v2x * v3x ) * v3y ) ) + ( ( v2x * v3y ) * x ) ) - ( v2y * pow( v3x, 2.0 ) ) ) + ( ( v2y * v3x ) * x ) ) - ( ( v3x * v3y ) * x ) );
	double p_7 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( v1x * v2x ) * v2y ) * v3x ) - ( ( ( v1x * v2x ) * v2y ) * x ) ) - ( ( ( v1x * v2x ) * v3x ) * v3y ) ) + ( ( ( v1x * v2x ) * v3y ) * x ) ) - ( ( v1x * v2y ) * pow( v3x, 2.0 ) ) ) + ( ( ( v1x * v2y ) * v3x ) * x ) ) + ( ( v1x * pow( v3x, 2.0 ) ) * v3y ) ) - ( ( ( v1x * v3x ) * v3y ) * x ) ) - ( ( v1y * pow( v2x, 2.0 ) ) * v3x ) ) + ( ( v1y * pow( v2x, 2.0 ) ) * x ) ) + ( ( ( 2.0 * v1y ) * v2x ) * pow( v3x, 2.0 ) ) ) - ( ( ( ( 2.0 * v1y ) * v2x ) * v3x ) * x ) ) - ( v1y * pow( v3x, 3.0 ) ) ) + ( ( v1y * pow( v3x, 2.0 ) ) * x ) ) + ( ( pow( v2x, 2.0 ) * v3x ) * v3y ) ) - ( ( pow( v2x, 2.0 ) * v3y ) * x ) ) - ( ( v2x * v2y ) * pow( v3x, 2.0 ) ) ) + ( ( ( v2x * v2y ) * v3x ) * x ) ) - ( ( v2x * pow( v3x, 2.0 ) ) * v3y ) ) + ( ( ( v2x * v3x ) * v3y ) * x ) ) + ( v2y * pow( v3x, 3.0 ) ) ) - ( ( v2y * pow( v3x, 2.0 ) ) * x ) );
	double p_8 = ( v1x - v3x );
	double p_9 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( v1x * pow( v2x, 2.0 ) ) * v2y ) - ( ( v1x * pow( v2x, 2.0 ) ) * v3y ) ) - ( ( ( v1x * v2x ) * v2y ) * v3x ) ) - ( ( ( v1x * v2x ) * v2y ) * x ) ) + ( ( ( v1x * v2x ) * v3x ) * v3y ) ) + ( ( ( v1x * v2x ) * v3y ) * x ) ) + ( ( ( v1x * v2y ) * v3x ) * x ) ) - ( ( ( v1x * v3x ) * v3y ) * x ) ) - ( v1y * pow( v2x, 3.0 ) ) ) + ( ( ( 2.0 * v1y ) * pow( v2x, 2.0 ) ) * v3x ) ) + ( ( v1y * pow( v2x, 2.0 ) ) * x ) ) - ( ( v1y * v2x ) * pow( v3x, 2.0 ) ) ) - ( ( ( ( 2.0 * v1y ) * v2x ) * v3x ) * x ) ) + ( ( v1y * pow( v3x, 2.0 ) ) * x ) ) + ( pow( v2x, 3.0 ) * v3y ) ) - ( ( pow( v2x, 2.0 ) * v2y ) * v3x ) ) - ( ( pow( v2x, 2.0 ) * v3x ) * v3y ) ) - ( ( pow( v2x, 2.0 ) * v3y ) * x ) ) + ( ( v2x * v2y ) * pow( v3x, 2.0 ) ) ) + ( ( ( v2x * v2y ) * v3x ) * x ) ) + ( ( ( v2x * v3x ) * v3y ) * x ) ) - ( ( v2y * pow( v3x, 2.0 ) ) * x ) );
	double p_10 = ( v1x - v2x );
	double p_11 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( v1x, 2.0 ) ) - ( ( ( 2.0 * pow( a, 2.0 ) ) * v1x ) * v3x ) ) + ( pow( a, 2.0 ) * pow( v3x, 2.0 ) ) ) - ( ( ( 2.0 * a ) * pow( v1x, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * a ) * v1x ) * v3x ) * x ) ) - ( ( ( 2.0 * a ) * pow( v3x, 2.0 ) ) * x ) ) + ( pow( b, 2.0 ) * pow( v1x, 2.0 ) ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * v1x ) * v3x ) ) + ( pow( b, 2.0 ) * pow( v3x, 2.0 ) ) ) - ( ( ( 2.0 * b ) * pow( v1x, 2.0 ) ) * v3y ) ) + ( ( ( ( 2.0 * b ) * v1x ) * v1y ) * v3x ) ) - ( ( ( ( 2.0 * b ) * v1x ) * v1y ) * x ) ) + ( ( ( ( 2.0 * b ) * v1x ) * v3x ) * v3y ) ) + ( ( ( ( 2.0 * b ) * v1x ) * v3y ) * x ) ) - ( ( ( 2.0 * b ) * v1y ) * pow( v3x, 2.0 ) ) ) + ( ( ( ( 2.0 * b ) * v1y ) * v3x ) * x ) ) - ( ( ( ( 2.0 * b ) * v3x ) * v3y ) * x ) ) - ( pow( r, 2.0 ) * pow( v1x, 2.0 ) ) ) + ( ( ( 2.0 * pow( r, 2.0 ) ) * v1x ) * v3x ) ) - ( pow( r, 2.0 ) * pow( v3x, 2.0 ) ) ) + ( pow( v1x, 2.0 ) * pow( v3y, 2.0 ) ) ) + ( pow( v1x, 2.0 ) * pow( x, 2.0 ) ) ) - ( ( ( ( 2.0 * v1x ) * v1y ) * v3x ) * v3y ) ) + ( ( ( ( 2.0 * v1x ) * v1y ) * v3y ) * x ) ) - ( ( ( 2.0 * v1x ) * v3x ) * pow( x, 2.0 ) ) ) - ( ( ( 2.0 * v1x ) * pow( v3y, 2.0 ) ) * x ) ) + ( pow( v1y, 2.0 ) * pow( v3x, 2.0 ) ) ) - ( ( ( 2.0 * pow( v1y, 2.0 ) ) * v3x ) * x ) ) + ( pow( v1y, 2.0 ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * v1y ) * v3x ) * v3y ) * x ) ) - ( ( ( 2.0 * v1y ) * v3y ) * pow( x, 2.0 ) ) ) + ( pow( v3x, 2.0 ) * pow( x, 2.0 ) ) ) + ( pow( v3y, 2.0 ) * pow( x, 2.0 ) ) );
	double p_12 = ( v1x - x );
	double p_13 = ( ( ( ( ( ( ( ( ( ( ( b * pow( v1x, 2.0 ) ) - ( ( ( 2.0 * b ) * v1x ) * v3x ) ) + ( b * pow( v3x, 2.0 ) ) ) - ( pow( v1x, 2.0 ) * v3y ) ) + ( ( v1x * v1y ) * v3x ) ) - ( ( v1x * v1y ) * x ) ) + ( ( v1x * v3x ) * v3y ) ) + ( ( v1x * v3y ) * x ) ) - ( v1y * pow( v3x, 2.0 ) ) ) + ( ( v1y * v3x ) * x ) ) - ( ( v3x * v3y ) * x ) );
	double p_14 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( v1x, 2.0 ) * v2y ) * v3x ) - ( ( pow( v1x, 2.0 ) * v2y ) * x ) ) - ( ( pow( v1x, 2.0 ) * v3x ) * v3y ) ) + ( ( pow( v1x, 2.0 ) * v3y ) * x ) ) - ( ( ( v1x * v1y ) * v2x ) * v3x ) ) + ( ( ( v1x * v1y ) * v2x ) * x ) ) + ( ( v1x * v1y ) * pow( v3x, 2.0 ) ) ) - ( ( ( v1x * v1y ) * v3x ) * x ) ) + ( ( ( v1x * v2x ) * v3x ) * v3y ) ) - ( ( ( v1x * v2x ) * v3y ) * x ) ) - ( ( ( 2.0 * v1x ) * v2y ) * pow( v3x, 2.0 ) ) ) + ( ( ( ( 2.0 * v1x ) * v2y ) * v3x ) * x ) ) + ( ( v1x * pow( v3x, 2.0 ) ) * v3y ) ) - ( ( ( v1x * v3x ) * v3y ) * x ) ) + ( ( v1y * v2x ) * pow( v3x, 2.0 ) ) ) - ( ( ( v1y * v2x ) * v3x ) * x ) ) - ( v1y * pow( v3x, 3.0 ) ) ) + ( ( v1y * pow( v3x, 2.0 ) ) * x ) ) - ( ( v2x * pow( v3x, 2.0 ) ) * v3y ) ) + ( ( ( v2x * v3x ) * v3y ) * x ) ) + ( v2y * pow( v3x, 3.0 ) ) ) - ( ( v2y * pow( v3x, 2.0 ) ) * x ) );
	double p_15 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( v1x, 3.0 ) * v2y ) - ( pow( v1x, 3.0 ) * v3y ) ) - ( ( pow( v1x, 2.0 ) * v1y ) * v2x ) ) + ( ( pow( v1x, 2.0 ) * v1y ) * v3x ) ) + ( ( pow( v1x, 2.0 ) * v2x ) * v3y ) ) - ( ( ( 2.0 * pow( v1x, 2.0 ) ) * v2y ) * v3x ) ) - ( ( pow( v1x, 2.0 ) * v2y ) * x ) ) + ( ( pow( v1x, 2.0 ) * v3x ) * v3y ) ) + ( ( pow( v1x, 2.0 ) * v3y ) * x ) ) + ( ( ( v1x * v1y ) * v2x ) * v3x ) ) + ( ( ( v1x * v1y ) * v2x ) * x ) ) - ( ( v1x * v1y ) * pow( v3x, 2.0 ) ) ) - ( ( ( v1x * v1y ) * v3x ) * x ) ) - ( ( ( v1x * v2x ) * v3x ) * v3y ) ) - ( ( ( v1x * v2x ) * v3y ) * x ) ) + ( ( v1x * v2y ) * pow( v3x, 2.0 ) ) ) + ( ( ( ( 2.0 * v1x ) * v2y ) * v3x ) * x ) ) - ( ( ( v1x * v3x ) * v3y ) * x ) ) - ( ( ( v1y * v2x ) * v3x ) * x ) ) + ( ( v1y * pow( v3x, 2.0 ) ) * x ) ) + ( ( ( v2x * v3x ) * v3y ) * x ) ) - ( ( v2y * pow( v3x, 2.0 ) ) * x ) );
	double p_16 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( v1x, 2.0 ) ) - ( ( ( 2.0 * pow( a, 2.0 ) ) * v1x ) * v2x ) ) + ( pow( a, 2.0 ) * pow( v2x, 2.0 ) ) ) - ( ( ( 2.0 * a ) * pow( v1x, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * a ) * v1x ) * v2x ) * x ) ) - ( ( ( 2.0 * a ) * pow( v2x, 2.0 ) ) * x ) ) + ( pow( b, 2.0 ) * pow( v1x, 2.0 ) ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * v1x ) * v2x ) ) + ( pow( b, 2.0 ) * pow( v2x, 2.0 ) ) ) - ( ( ( 2.0 * b ) * pow( v1x, 2.0 ) ) * v2y ) ) + ( ( ( ( 2.0 * b ) * v1x ) * v1y ) * v2x ) ) - ( ( ( ( 2.0 * b ) * v1x ) * v1y ) * x ) ) + ( ( ( ( 2.0 * b ) * v1x ) * v2x ) * v2y ) ) + ( ( ( ( 2.0 * b ) * v1x ) * v2y ) * x ) ) - ( ( ( 2.0 * b ) * v1y ) * pow( v2x, 2.0 ) ) ) + ( ( ( ( 2.0 * b ) * v1y ) * v2x ) * x ) ) - ( ( ( ( 2.0 * b ) * v2x ) * v2y ) * x ) ) - ( pow( r, 2.0 ) * pow( v1x, 2.0 ) ) ) + ( ( ( 2.0 * pow( r, 2.0 ) ) * v1x ) * v2x ) ) - ( pow( r, 2.0 ) * pow( v2x, 2.0 ) ) ) + ( pow( v1x, 2.0 ) * pow( v2y, 2.0 ) ) ) + ( pow( v1x, 2.0 ) * pow( x, 2.0 ) ) ) - ( ( ( ( 2.0 * v1x ) * v1y ) * v2x ) * v2y ) ) + ( ( ( ( 2.0 * v1x ) * v1y ) * v2y ) * x ) ) - ( ( ( 2.0 * v1x ) * v2x ) * pow( x, 2.0 ) ) ) - ( ( ( 2.0 * v1x ) * pow( v2y, 2.0 ) ) * x ) ) + ( pow( v1y, 2.0 ) * pow( v2x, 2.0 ) ) ) - ( ( ( 2.0 * pow( v1y, 2.0 ) ) * v2x ) * x ) ) + ( pow( v1y, 2.0 ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * v1y ) * v2x ) * v2y ) * x ) ) - ( ( ( 2.0 * v1y ) * v2y ) * pow( x, 2.0 ) ) ) + ( pow( v2x, 2.0 ) * pow( x, 2.0 ) ) ) + ( pow( v2y, 2.0 ) * pow( x, 2.0 ) ) );
	double p_17 = ( ( ( ( ( ( ( ( ( ( ( b * pow( v1x, 2.0 ) ) - ( ( ( 2.0 * b ) * v1x ) * v2x ) ) + ( b * pow( v2x, 2.0 ) ) ) - ( pow( v1x, 2.0 ) * v2y ) ) + ( ( v1x * v1y ) * v2x ) ) - ( ( v1x * v1y ) * x ) ) + ( ( v1x * v2x ) * v2y ) ) + ( ( v1x * v2y ) * x ) ) - ( v1y * pow( v2x, 2.0 ) ) ) + ( ( v1y * v2x ) * x ) ) - ( ( v2x * v2y ) * x ) );
	double p_18 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( v1x, 2.0 ) * v2x ) * v2y ) - ( ( pow( v1x, 2.0 ) * v2x ) * v3y ) ) - ( ( pow( v1x, 2.0 ) * v2y ) * x ) ) + ( ( pow( v1x, 2.0 ) * v3y ) * x ) ) - ( ( v1x * v1y ) * pow( v2x, 2.0 ) ) ) + ( ( ( v1x * v1y ) * v2x ) * v3x ) ) + ( ( ( v1x * v1y ) * v2x ) * x ) ) - ( ( ( v1x * v1y ) * v3x ) * x ) ) - ( ( v1x * pow( v2x, 2.0 ) ) * v2y ) ) + ( ( ( 2.0 * v1x ) * pow( v2x, 2.0 ) ) * v3y ) ) - ( ( ( v1x * v2x ) * v2y ) * v3x ) ) + ( ( ( v1x * v2x ) * v2y ) * x ) ) - ( ( ( ( 2.0 * v1x ) * v2x ) * v3y ) * x ) ) + ( ( ( v1x * v2y ) * v3x ) * x ) ) + ( v1y * pow( v2x, 3.0 ) ) ) - ( ( v1y * pow( v2x, 2.0 ) ) * v3x ) ) - ( ( v1y * pow( v2x, 2.0 ) ) * x ) ) + ( ( ( v1y * v2x ) * v3x ) * x ) ) - ( pow( v2x, 3.0 ) * v3y ) ) + ( ( pow( v2x, 2.0 ) * v2y ) * v3x ) ) + ( ( pow( v2x, 2.0 ) * v3y ) * x ) ) - ( ( ( v2x * v2y ) * v3x ) * x ) );
	double p_19 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( v1x, 3.0 ) * v2y ) - ( pow( v1x, 3.0 ) * v3y ) ) - ( ( pow( v1x, 2.0 ) * v1y ) * v2x ) ) + ( ( pow( v1x, 2.0 ) * v1y ) * v3x ) ) - ( ( pow( v1x, 2.0 ) * v2x ) * v2y ) ) + ( ( ( 2.0 * pow( v1x, 2.0 ) ) * v2x ) * v3y ) ) - ( ( pow( v1x, 2.0 ) * v2y ) * v3x ) ) - ( ( pow( v1x, 2.0 ) * v2y ) * x ) ) + ( ( pow( v1x, 2.0 ) * v3y ) * x ) ) + ( ( v1x * v1y ) * pow( v2x, 2.0 ) ) ) - ( ( ( v1x * v1y ) * v2x ) * v3x ) ) + ( ( ( v1x * v1y ) * v2x ) * x ) ) - ( ( ( v1x * v1y ) * v3x ) * x ) ) - ( ( v1x * pow( v2x, 2.0 ) ) * v3y ) ) + ( ( ( v1x * v2x ) * v2y ) * v3x ) ) + ( ( ( v1x * v2x ) * v2y ) * x ) ) - ( ( ( ( 2.0 * v1x ) * v2x ) * v3y ) * x ) ) + ( ( ( v1x * v2y ) * v3x ) * x ) ) - ( ( v1y * pow( v2x, 2.0 ) ) * x ) ) + ( ( ( v1y * v2x ) * v3x ) * x ) ) + ( ( pow( v2x, 2.0 ) * v3y ) * x ) ) - ( ( ( v2x * v2y ) * v3x ) * x ) );
	double p_20 = ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	double p_21 = ( ( ( ( ( ( b * v2x ) - ( b * v3x ) ) - ( v2x * v3y ) ) + ( v2y * v3x ) ) - ( v2y * x ) ) + ( v3y * x ) );
	double p_22 = ( ( ( ( ( ( b * v1x ) - ( b * v2x ) ) - ( v1x * v2y ) ) + ( v1y * v2x ) ) - ( v1y * x ) ) + ( v2y * x ) );
	double p_23 = ( ( ( ( ( ( b * v1x ) - ( b * v3x ) ) - ( v1x * v3y ) ) + ( v1y * v3x ) ) - ( v1y * x ) ) + ( v3y * x ) );


	return ( ( ( ( ( ( ( ( ( !within_eps( p_1, 0.0 , EPSILON ) && ( ( p_2 < 0.0 ) || within_eps( p_2, 0.0 , EPSILON ) ) ) && ( within_eps( p_3, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) && ( within_eps( p_5, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) || ( ( !within_eps( p_1, 0.0 , EPSILON ) && ( ( p_2 < 0.0 ) || ( ( p_6 < 0.0 ) && within_eps( p_2, 0.0 , EPSILON ) ) ) ) && ( ( ( ( ( p_1 < 0.0 ) || within_eps( p_1, 0.0 , EPSILON ) ) && ( ( p_7 > 0.0 ) || ( ( p_8 > 0.0 ) && ( within_eps( p_3, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) ) ) && ( ( p_9 < 0.0 ) || ( ( p_10 < 0.0 ) && ( within_eps( p_5, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) ) ) || ( ( ( ( p_1 > 0.0 ) || within_eps( p_1, 0.0 , EPSILON ) ) && ( ( p_7 < 0.0 ) || ( ( p_8 < 0.0 ) && ( within_eps( p_3, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) ) ) && ( ( p_9 > 0.0 ) || ( ( p_10 > 0.0 ) && ( within_eps( p_5, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) ) ) ) ) ) || ( ( ( !within_eps( p_8, 0.0 , EPSILON ) && ( ( p_11 < 0.0 ) || within_eps( p_11, 0.0 , EPSILON ) ) ) && ( within_eps( p_3, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) && ( within_eps( p_12, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) ) || ( ( !within_eps( p_8, 0.0 , EPSILON ) && ( ( p_11 < 0.0 ) || ( ( p_13 < 0.0 ) && within_eps( p_11, 0.0 , EPSILON ) ) ) ) && ( ( ( ( ( p_8 < 0.0 ) || within_eps( p_8, 0.0 , EPSILON ) ) && ( ( p_14 < 0.0 ) || ( ( p_1 > 0.0 ) && ( within_eps( p_3, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) ) ) && ( ( p_15 > 0.0 ) || ( ( p_10 > 0.0 ) && ( within_eps( p_12, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) ) ) || ( ( ( ( p_8 > 0.0 ) || within_eps( p_8, 0.0 , EPSILON ) ) && ( ( p_14 > 0.0 ) || ( ( p_1 < 0.0 ) && ( within_eps( p_3, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) ) ) && ( ( p_15 < 0.0 ) || ( ( p_10 < 0.0 ) && ( within_eps( p_12, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) ) ) ) ) ) || ( ( ( !within_eps( p_10, 0.0 , EPSILON ) && ( ( p_16 < 0.0 ) || within_eps( p_16, 0.0 , EPSILON ) ) ) && ( within_eps( p_5, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) && ( within_eps( p_12, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) ) || ( ( !within_eps( p_10, 0.0 , EPSILON ) && ( ( p_16 < 0.0 ) || ( ( p_17 < 0.0 ) && within_eps( p_16, 0.0 , EPSILON ) ) ) ) && ( ( ( ( ( p_10 < 0.0 ) || within_eps( p_10, 0.0 , EPSILON ) ) && ( ( p_18 > 0.0 ) || ( ( p_1 < 0.0 ) && ( within_eps( p_5, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) ) ) && ( ( p_19 < 0.0 ) || ( ( p_8 > 0.0 ) && ( within_eps( p_12, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) ) ) || ( ( ( ( p_10 > 0.0 ) || within_eps( p_10, 0.0 , EPSILON ) ) && ( ( p_18 < 0.0 ) || ( ( p_1 > 0.0 ) && ( within_eps( p_5, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) ) ) && ( ( p_19 > 0.0 ) || ( ( p_8 < 0.0 ) && ( within_eps( p_12, 0.0 , EPSILON ) || within_eps( p_4, 0.0 , EPSILON ) ) ) ) ) ) ) ) || ( ( ( p_20 < 0.0 ) || within_eps( p_20, 0.0 , EPSILON ) ) && ( ( ( ( ( ( ( ( ( ( ( ( p_6 < 0.0 ) || within_eps( p_6, 0.0 , EPSILON ) ) && ( ( p_13 < 0.0 ) || within_eps( p_13, 0.0 , EPSILON ) ) ) && ( ( p_17 < 0.0 ) || within_eps( p_17, 0.0 , EPSILON ) ) ) && within_eps( p_2, 0.0 , EPSILON ) ) && within_eps( p_11, 0.0 , EPSILON ) ) && within_eps( p_16, 0.0 , EPSILON ) ) || ( ( ( ( ( ( ( p_6 > 0.0 ) || within_eps( p_6, 0.0 , EPSILON ) ) && ( ( p_13 > 0.0 ) || within_eps( p_13, 0.0 , EPSILON ) ) ) && ( ( p_17 > 0.0 ) || within_eps( p_17, 0.0 , EPSILON ) ) ) && within_eps( p_2, 0.0 , EPSILON ) ) && within_eps( p_11, 0.0 , EPSILON ) ) && within_eps( p_16, 0.0 , EPSILON ) ) ) || ( ( ( ( ( ( p_1 < 0.0 ) || ( p_2 > 0.0 ) ) && ( ( p_10 < 0.0 ) || ( p_16 > 0.0 ) ) ) && ( ( p_21 < 0.0 ) || ( p_2 < 0.0 ) ) ) && ( ( p_22 < 0.0 ) || ( p_16 < 0.0 ) ) ) && ( ( ( ( p_8 > 0.0 ) || within_eps( p_8, 0.0 , EPSILON ) ) && ( ( p_23 > 0.0 ) || ( p_11 < 0.0 ) ) ) || ( ( p_23 > 0.0 ) && ( p_11 > 0.0 ) ) ) ) ) || ( ( ( ( ( ( p_1 > 0.0 ) || ( p_2 > 0.0 ) ) && ( ( p_10 > 0.0 ) || ( p_16 > 0.0 ) ) ) && ( ( p_21 < 0.0 ) || ( p_2 < 0.0 ) ) ) && ( ( p_22 < 0.0 ) || ( p_16 < 0.0 ) ) ) && ( ( ( ( p_8 < 0.0 ) || within_eps( p_8, 0.0 , EPSILON ) ) && ( ( p_23 > 0.0 ) || ( p_11 < 0.0 ) ) ) || ( ( p_23 > 0.0 ) && ( p_11 > 0.0 ) ) ) ) ) || ( ( ( ( ( p_8 < 0.0 ) || ( p_11 > 0.0 ) ) && ( ( p_23 < 0.0 ) || ( p_11 < 0.0 ) ) ) && ( ( ( ( p_1 > 0.0 ) || within_eps( p_1, 0.0 , EPSILON ) ) && ( ( p_21 > 0.0 ) || ( p_2 < 0.0 ) ) ) || ( ( p_21 > 0.0 ) && ( p_2 > 0.0 ) ) ) ) && ( ( ( ( p_10 > 0.0 ) || within_eps( p_10, 0.0 , EPSILON ) ) && ( ( p_22 > 0.0 ) || ( p_16 < 0.0 ) ) ) || ( ( p_22 > 0.0 ) && ( p_16 > 0.0 ) ) ) ) ) || ( ( ( ( ( p_8 > 0.0 ) || ( p_11 > 0.0 ) ) && ( ( p_23 < 0.0 ) || ( p_11 < 0.0 ) ) ) && ( ( ( ( p_1 < 0.0 ) || within_eps( p_1, 0.0 , EPSILON ) ) && ( ( p_21 > 0.0 ) || ( p_2 < 0.0 ) ) ) || ( ( p_21 > 0.0 ) && ( p_2 > 0.0 ) ) ) ) && ( ( ( ( p_10 < 0.0 ) || within_eps( p_10, 0.0 , EPSILON ) ) && ( ( p_22 > 0.0 ) || ( p_16 < 0.0 ) ) ) || ( ( p_22 > 0.0 ) && ( p_16 > 0.0 ) ) ) ) ) ) );
}


polynomial make_polynomial_1() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( v2x - v3x );
	return result_polynomial_21393;
}

polynomial make_polynomial_2() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( v2x, 2.0 ) ) - ( ( ( 2.0 * pow( a, 2.0 ) ) * v2x ) * v3x ) ) + ( pow( a, 2.0 ) * pow( v3x, 2.0 ) ) ) - ( ( ( 2.0 * a ) * pow( v2x, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * a ) * v2x ) * v3x ) * x ) ) - ( ( ( 2.0 * a ) * pow( v3x, 2.0 ) ) * x ) ) + ( pow( b, 2.0 ) * pow( v2x, 2.0 ) ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * v2x ) * v3x ) ) + ( pow( b, 2.0 ) * pow( v3x, 2.0 ) ) ) - ( ( ( 2.0 * b ) * pow( v2x, 2.0 ) ) * v3y ) ) + ( ( ( ( 2.0 * b ) * v2x ) * v2y ) * v3x ) ) - ( ( ( ( 2.0 * b ) * v2x ) * v2y ) * x ) ) + ( ( ( ( 2.0 * b ) * v2x ) * v3x ) * v3y ) ) + ( ( ( ( 2.0 * b ) * v2x ) * v3y ) * x ) ) - ( ( ( 2.0 * b ) * v2y ) * pow( v3x, 2.0 ) ) ) + ( ( ( ( 2.0 * b ) * v2y ) * v3x ) * x ) ) - ( ( ( ( 2.0 * b ) * v3x ) * v3y ) * x ) ) - ( pow( r, 2.0 ) * pow( v2x, 2.0 ) ) ) + ( ( ( 2.0 * pow( r, 2.0 ) ) * v2x ) * v3x ) ) - ( pow( r, 2.0 ) * pow( v3x, 2.0 ) ) ) + ( pow( v2x, 2.0 ) * pow( v3y, 2.0 ) ) ) + ( pow( v2x, 2.0 ) * pow( x, 2.0 ) ) ) - ( ( ( ( 2.0 * v2x ) * v2y ) * v3x ) * v3y ) ) + ( ( ( ( 2.0 * v2x ) * v2y ) * v3y ) * x ) ) - ( ( ( 2.0 * v2x ) * v3x ) * pow( x, 2.0 ) ) ) - ( ( ( 2.0 * v2x ) * pow( v3y, 2.0 ) ) * x ) ) + ( pow( v2y, 2.0 ) * pow( v3x, 2.0 ) ) ) - ( ( ( 2.0 * pow( v2y, 2.0 ) ) * v3x ) * x ) ) + ( pow( v2y, 2.0 ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * v2y ) * v3x ) * v3y ) * x ) ) - ( ( ( 2.0 * v2y ) * v3y ) * pow( x, 2.0 ) ) ) + ( pow( v3x, 2.0 ) * pow( x, 2.0 ) ) ) + ( pow( v3y, 2.0 ) * pow( x, 2.0 ) ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_3() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( v3x - x );
	return result_polynomial_21393;
}

polynomial make_polynomial_4() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( v1x * v2y ) - ( v1x * v3y ) ) - ( v1y * v2x ) ) + ( v1y * v3x ) ) + ( v2x * v3y ) ) - ( v2y * v3x ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_5() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( v2x - x );
	return result_polynomial_21393;
}

polynomial make_polynomial_6() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( b * pow( v2x, 2.0 ) ) - ( ( ( 2.0 * b ) * v2x ) * v3x ) ) + ( b * pow( v3x, 2.0 ) ) ) - ( pow( v2x, 2.0 ) * v3y ) ) + ( ( v2x * v2y ) * v3x ) ) - ( ( v2x * v2y ) * x ) ) + ( ( v2x * v3x ) * v3y ) ) + ( ( v2x * v3y ) * x ) ) - ( v2y * pow( v3x, 2.0 ) ) ) + ( ( v2y * v3x ) * x ) ) - ( ( v3x * v3y ) * x ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_7() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( v1x * v2x ) * v2y ) * v3x ) - ( ( ( v1x * v2x ) * v2y ) * x ) ) - ( ( ( v1x * v2x ) * v3x ) * v3y ) ) + ( ( ( v1x * v2x ) * v3y ) * x ) ) - ( ( v1x * v2y ) * pow( v3x, 2.0 ) ) ) + ( ( ( v1x * v2y ) * v3x ) * x ) ) + ( ( v1x * pow( v3x, 2.0 ) ) * v3y ) ) - ( ( ( v1x * v3x ) * v3y ) * x ) ) - ( ( v1y * pow( v2x, 2.0 ) ) * v3x ) ) + ( ( v1y * pow( v2x, 2.0 ) ) * x ) ) + ( ( ( 2.0 * v1y ) * v2x ) * pow( v3x, 2.0 ) ) ) - ( ( ( ( 2.0 * v1y ) * v2x ) * v3x ) * x ) ) - ( v1y * pow( v3x, 3.0 ) ) ) + ( ( v1y * pow( v3x, 2.0 ) ) * x ) ) + ( ( pow( v2x, 2.0 ) * v3x ) * v3y ) ) - ( ( pow( v2x, 2.0 ) * v3y ) * x ) ) - ( ( v2x * v2y ) * pow( v3x, 2.0 ) ) ) + ( ( ( v2x * v2y ) * v3x ) * x ) ) - ( ( v2x * pow( v3x, 2.0 ) ) * v3y ) ) + ( ( ( v2x * v3x ) * v3y ) * x ) ) + ( v2y * pow( v3x, 3.0 ) ) ) - ( ( v2y * pow( v3x, 2.0 ) ) * x ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_8() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( v1x - v3x );
	return result_polynomial_21393;
}

polynomial make_polynomial_9() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( v1x * pow( v2x, 2.0 ) ) * v2y ) - ( ( v1x * pow( v2x, 2.0 ) ) * v3y ) ) - ( ( ( v1x * v2x ) * v2y ) * v3x ) ) - ( ( ( v1x * v2x ) * v2y ) * x ) ) + ( ( ( v1x * v2x ) * v3x ) * v3y ) ) + ( ( ( v1x * v2x ) * v3y ) * x ) ) + ( ( ( v1x * v2y ) * v3x ) * x ) ) - ( ( ( v1x * v3x ) * v3y ) * x ) ) - ( v1y * pow( v2x, 3.0 ) ) ) + ( ( ( 2.0 * v1y ) * pow( v2x, 2.0 ) ) * v3x ) ) + ( ( v1y * pow( v2x, 2.0 ) ) * x ) ) - ( ( v1y * v2x ) * pow( v3x, 2.0 ) ) ) - ( ( ( ( 2.0 * v1y ) * v2x ) * v3x ) * x ) ) + ( ( v1y * pow( v3x, 2.0 ) ) * x ) ) + ( pow( v2x, 3.0 ) * v3y ) ) - ( ( pow( v2x, 2.0 ) * v2y ) * v3x ) ) - ( ( pow( v2x, 2.0 ) * v3x ) * v3y ) ) - ( ( pow( v2x, 2.0 ) * v3y ) * x ) ) + ( ( v2x * v2y ) * pow( v3x, 2.0 ) ) ) + ( ( ( v2x * v2y ) * v3x ) * x ) ) + ( ( ( v2x * v3x ) * v3y ) * x ) ) - ( ( v2y * pow( v3x, 2.0 ) ) * x ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_10() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( v1x - v2x );
	return result_polynomial_21393;
}

polynomial make_polynomial_11() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( v1x, 2.0 ) ) - ( ( ( 2.0 * pow( a, 2.0 ) ) * v1x ) * v3x ) ) + ( pow( a, 2.0 ) * pow( v3x, 2.0 ) ) ) - ( ( ( 2.0 * a ) * pow( v1x, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * a ) * v1x ) * v3x ) * x ) ) - ( ( ( 2.0 * a ) * pow( v3x, 2.0 ) ) * x ) ) + ( pow( b, 2.0 ) * pow( v1x, 2.0 ) ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * v1x ) * v3x ) ) + ( pow( b, 2.0 ) * pow( v3x, 2.0 ) ) ) - ( ( ( 2.0 * b ) * pow( v1x, 2.0 ) ) * v3y ) ) + ( ( ( ( 2.0 * b ) * v1x ) * v1y ) * v3x ) ) - ( ( ( ( 2.0 * b ) * v1x ) * v1y ) * x ) ) + ( ( ( ( 2.0 * b ) * v1x ) * v3x ) * v3y ) ) + ( ( ( ( 2.0 * b ) * v1x ) * v3y ) * x ) ) - ( ( ( 2.0 * b ) * v1y ) * pow( v3x, 2.0 ) ) ) + ( ( ( ( 2.0 * b ) * v1y ) * v3x ) * x ) ) - ( ( ( ( 2.0 * b ) * v3x ) * v3y ) * x ) ) - ( pow( r, 2.0 ) * pow( v1x, 2.0 ) ) ) + ( ( ( 2.0 * pow( r, 2.0 ) ) * v1x ) * v3x ) ) - ( pow( r, 2.0 ) * pow( v3x, 2.0 ) ) ) + ( pow( v1x, 2.0 ) * pow( v3y, 2.0 ) ) ) + ( pow( v1x, 2.0 ) * pow( x, 2.0 ) ) ) - ( ( ( ( 2.0 * v1x ) * v1y ) * v3x ) * v3y ) ) + ( ( ( ( 2.0 * v1x ) * v1y ) * v3y ) * x ) ) - ( ( ( 2.0 * v1x ) * v3x ) * pow( x, 2.0 ) ) ) - ( ( ( 2.0 * v1x ) * pow( v3y, 2.0 ) ) * x ) ) + ( pow( v1y, 2.0 ) * pow( v3x, 2.0 ) ) ) - ( ( ( 2.0 * pow( v1y, 2.0 ) ) * v3x ) * x ) ) + ( pow( v1y, 2.0 ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * v1y ) * v3x ) * v3y ) * x ) ) - ( ( ( 2.0 * v1y ) * v3y ) * pow( x, 2.0 ) ) ) + ( pow( v3x, 2.0 ) * pow( x, 2.0 ) ) ) + ( pow( v3y, 2.0 ) * pow( x, 2.0 ) ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_12() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( v1x - x );
	return result_polynomial_21393;
}

polynomial make_polynomial_13() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( b * pow( v1x, 2.0 ) ) - ( ( ( 2.0 * b ) * v1x ) * v3x ) ) + ( b * pow( v3x, 2.0 ) ) ) - ( pow( v1x, 2.0 ) * v3y ) ) + ( ( v1x * v1y ) * v3x ) ) - ( ( v1x * v1y ) * x ) ) + ( ( v1x * v3x ) * v3y ) ) + ( ( v1x * v3y ) * x ) ) - ( v1y * pow( v3x, 2.0 ) ) ) + ( ( v1y * v3x ) * x ) ) - ( ( v3x * v3y ) * x ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_14() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( v1x, 2.0 ) * v2y ) * v3x ) - ( ( pow( v1x, 2.0 ) * v2y ) * x ) ) - ( ( pow( v1x, 2.0 ) * v3x ) * v3y ) ) + ( ( pow( v1x, 2.0 ) * v3y ) * x ) ) - ( ( ( v1x * v1y ) * v2x ) * v3x ) ) + ( ( ( v1x * v1y ) * v2x ) * x ) ) + ( ( v1x * v1y ) * pow( v3x, 2.0 ) ) ) - ( ( ( v1x * v1y ) * v3x ) * x ) ) + ( ( ( v1x * v2x ) * v3x ) * v3y ) ) - ( ( ( v1x * v2x ) * v3y ) * x ) ) - ( ( ( 2.0 * v1x ) * v2y ) * pow( v3x, 2.0 ) ) ) + ( ( ( ( 2.0 * v1x ) * v2y ) * v3x ) * x ) ) + ( ( v1x * pow( v3x, 2.0 ) ) * v3y ) ) - ( ( ( v1x * v3x ) * v3y ) * x ) ) + ( ( v1y * v2x ) * pow( v3x, 2.0 ) ) ) - ( ( ( v1y * v2x ) * v3x ) * x ) ) - ( v1y * pow( v3x, 3.0 ) ) ) + ( ( v1y * pow( v3x, 2.0 ) ) * x ) ) - ( ( v2x * pow( v3x, 2.0 ) ) * v3y ) ) + ( ( ( v2x * v3x ) * v3y ) * x ) ) + ( v2y * pow( v3x, 3.0 ) ) ) - ( ( v2y * pow( v3x, 2.0 ) ) * x ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_15() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( v1x, 3.0 ) * v2y ) - ( pow( v1x, 3.0 ) * v3y ) ) - ( ( pow( v1x, 2.0 ) * v1y ) * v2x ) ) + ( ( pow( v1x, 2.0 ) * v1y ) * v3x ) ) + ( ( pow( v1x, 2.0 ) * v2x ) * v3y ) ) - ( ( ( 2.0 * pow( v1x, 2.0 ) ) * v2y ) * v3x ) ) - ( ( pow( v1x, 2.0 ) * v2y ) * x ) ) + ( ( pow( v1x, 2.0 ) * v3x ) * v3y ) ) + ( ( pow( v1x, 2.0 ) * v3y ) * x ) ) + ( ( ( v1x * v1y ) * v2x ) * v3x ) ) + ( ( ( v1x * v1y ) * v2x ) * x ) ) - ( ( v1x * v1y ) * pow( v3x, 2.0 ) ) ) - ( ( ( v1x * v1y ) * v3x ) * x ) ) - ( ( ( v1x * v2x ) * v3x ) * v3y ) ) - ( ( ( v1x * v2x ) * v3y ) * x ) ) + ( ( v1x * v2y ) * pow( v3x, 2.0 ) ) ) + ( ( ( ( 2.0 * v1x ) * v2y ) * v3x ) * x ) ) - ( ( ( v1x * v3x ) * v3y ) * x ) ) - ( ( ( v1y * v2x ) * v3x ) * x ) ) + ( ( v1y * pow( v3x, 2.0 ) ) * x ) ) + ( ( ( v2x * v3x ) * v3y ) * x ) ) - ( ( v2y * pow( v3x, 2.0 ) ) * x ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_16() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( a, 2.0 ) * pow( v1x, 2.0 ) ) - ( ( ( 2.0 * pow( a, 2.0 ) ) * v1x ) * v2x ) ) + ( pow( a, 2.0 ) * pow( v2x, 2.0 ) ) ) - ( ( ( 2.0 * a ) * pow( v1x, 2.0 ) ) * x ) ) + ( ( ( ( 4.0 * a ) * v1x ) * v2x ) * x ) ) - ( ( ( 2.0 * a ) * pow( v2x, 2.0 ) ) * x ) ) + ( pow( b, 2.0 ) * pow( v1x, 2.0 ) ) ) - ( ( ( 2.0 * pow( b, 2.0 ) ) * v1x ) * v2x ) ) + ( pow( b, 2.0 ) * pow( v2x, 2.0 ) ) ) - ( ( ( 2.0 * b ) * pow( v1x, 2.0 ) ) * v2y ) ) + ( ( ( ( 2.0 * b ) * v1x ) * v1y ) * v2x ) ) - ( ( ( ( 2.0 * b ) * v1x ) * v1y ) * x ) ) + ( ( ( ( 2.0 * b ) * v1x ) * v2x ) * v2y ) ) + ( ( ( ( 2.0 * b ) * v1x ) * v2y ) * x ) ) - ( ( ( 2.0 * b ) * v1y ) * pow( v2x, 2.0 ) ) ) + ( ( ( ( 2.0 * b ) * v1y ) * v2x ) * x ) ) - ( ( ( ( 2.0 * b ) * v2x ) * v2y ) * x ) ) - ( pow( r, 2.0 ) * pow( v1x, 2.0 ) ) ) + ( ( ( 2.0 * pow( r, 2.0 ) ) * v1x ) * v2x ) ) - ( pow( r, 2.0 ) * pow( v2x, 2.0 ) ) ) + ( pow( v1x, 2.0 ) * pow( v2y, 2.0 ) ) ) + ( pow( v1x, 2.0 ) * pow( x, 2.0 ) ) ) - ( ( ( ( 2.0 * v1x ) * v1y ) * v2x ) * v2y ) ) + ( ( ( ( 2.0 * v1x ) * v1y ) * v2y ) * x ) ) - ( ( ( 2.0 * v1x ) * v2x ) * pow( x, 2.0 ) ) ) - ( ( ( 2.0 * v1x ) * pow( v2y, 2.0 ) ) * x ) ) + ( pow( v1y, 2.0 ) * pow( v2x, 2.0 ) ) ) - ( ( ( 2.0 * pow( v1y, 2.0 ) ) * v2x ) * x ) ) + ( pow( v1y, 2.0 ) * pow( x, 2.0 ) ) ) + ( ( ( ( 2.0 * v1y ) * v2x ) * v2y ) * x ) ) - ( ( ( 2.0 * v1y ) * v2y ) * pow( x, 2.0 ) ) ) + ( pow( v2x, 2.0 ) * pow( x, 2.0 ) ) ) + ( pow( v2y, 2.0 ) * pow( x, 2.0 ) ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_17() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( b * pow( v1x, 2.0 ) ) - ( ( ( 2.0 * b ) * v1x ) * v2x ) ) + ( b * pow( v2x, 2.0 ) ) ) - ( pow( v1x, 2.0 ) * v2y ) ) + ( ( v1x * v1y ) * v2x ) ) - ( ( v1x * v1y ) * x ) ) + ( ( v1x * v2x ) * v2y ) ) + ( ( v1x * v2y ) * x ) ) - ( v1y * pow( v2x, 2.0 ) ) ) + ( ( v1y * v2x ) * x ) ) - ( ( v2x * v2y ) * x ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_18() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( v1x, 2.0 ) * v2x ) * v2y ) - ( ( pow( v1x, 2.0 ) * v2x ) * v3y ) ) - ( ( pow( v1x, 2.0 ) * v2y ) * x ) ) + ( ( pow( v1x, 2.0 ) * v3y ) * x ) ) - ( ( v1x * v1y ) * pow( v2x, 2.0 ) ) ) + ( ( ( v1x * v1y ) * v2x ) * v3x ) ) + ( ( ( v1x * v1y ) * v2x ) * x ) ) - ( ( ( v1x * v1y ) * v3x ) * x ) ) - ( ( v1x * pow( v2x, 2.0 ) ) * v2y ) ) + ( ( ( 2.0 * v1x ) * pow( v2x, 2.0 ) ) * v3y ) ) - ( ( ( v1x * v2x ) * v2y ) * v3x ) ) + ( ( ( v1x * v2x ) * v2y ) * x ) ) - ( ( ( ( 2.0 * v1x ) * v2x ) * v3y ) * x ) ) + ( ( ( v1x * v2y ) * v3x ) * x ) ) + ( v1y * pow( v2x, 3.0 ) ) ) - ( ( v1y * pow( v2x, 2.0 ) ) * v3x ) ) - ( ( v1y * pow( v2x, 2.0 ) ) * x ) ) + ( ( ( v1y * v2x ) * v3x ) * x ) ) - ( pow( v2x, 3.0 ) * v3y ) ) + ( ( pow( v2x, 2.0 ) * v2y ) * v3x ) ) + ( ( pow( v2x, 2.0 ) * v3y ) * x ) ) - ( ( ( v2x * v2y ) * v3x ) * x ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_19() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( pow( v1x, 3.0 ) * v2y ) - ( pow( v1x, 3.0 ) * v3y ) ) - ( ( pow( v1x, 2.0 ) * v1y ) * v2x ) ) + ( ( pow( v1x, 2.0 ) * v1y ) * v3x ) ) - ( ( pow( v1x, 2.0 ) * v2x ) * v2y ) ) + ( ( ( 2.0 * pow( v1x, 2.0 ) ) * v2x ) * v3y ) ) - ( ( pow( v1x, 2.0 ) * v2y ) * v3x ) ) - ( ( pow( v1x, 2.0 ) * v2y ) * x ) ) + ( ( pow( v1x, 2.0 ) * v3y ) * x ) ) + ( ( v1x * v1y ) * pow( v2x, 2.0 ) ) ) - ( ( ( v1x * v1y ) * v2x ) * v3x ) ) + ( ( ( v1x * v1y ) * v2x ) * x ) ) - ( ( ( v1x * v1y ) * v3x ) * x ) ) - ( ( v1x * pow( v2x, 2.0 ) ) * v3y ) ) + ( ( ( v1x * v2x ) * v2y ) * v3x ) ) + ( ( ( v1x * v2x ) * v2y ) * x ) ) - ( ( ( ( 2.0 * v1x ) * v2x ) * v3y ) * x ) ) + ( ( ( v1x * v2y ) * v3x ) * x ) ) - ( ( v1y * pow( v2x, 2.0 ) ) * x ) ) + ( ( ( v1y * v2x ) * v3x ) * x ) ) + ( ( pow( v2x, 2.0 ) * v3y ) * x ) ) - ( ( ( v2x * v2y ) * v3x ) * x ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_20() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( pow( a, 2.0 ) - ( ( 2.0 * a ) * x ) ) - pow( r, 2.0 ) ) + pow( x, 2.0 ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_21() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( b * v2x ) - ( b * v3x ) ) - ( v2x * v3y ) ) + ( v2y * v3x ) ) - ( v2y * x ) ) + ( v3y * x ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_22() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( b * v1x ) - ( b * v2x ) ) - ( v1x * v2y ) ) + ( v1y * v2x ) ) - ( v1y * x ) ) + ( v2y * x ) );
	return result_polynomial_21393;
}

polynomial make_polynomial_23() {
	monomial m_a(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_b(1, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_r(1, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1x(1, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 10);
	monomial m_v1y(1, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 10);
	monomial m_v2x(1, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, 10);
	monomial m_v2y(1, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, 10);
	monomial m_v3x(1, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, 10);
	monomial m_v3y(1, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, 10);
	monomial m_x(1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 10);


	polynomial a({m_a}, 10);
	polynomial b({m_b}, 10);
	polynomial r({m_r}, 10);
	polynomial v1x({m_v1x}, 10);
	polynomial v1y({m_v1y}, 10);
	polynomial v2x({m_v2x}, 10);
	polynomial v2y({m_v2y}, 10);
	polynomial v3x({m_v3x}, 10);
	polynomial v3y({m_v3y}, 10);
	polynomial x({m_x}, 10);


	polynomial result_polynomial_21393 = ( ( ( ( ( ( b * v1x ) - ( b * v3x ) ) - ( v1x * v3y ) ) + ( v1y * v3x ) ) - ( v1y * x ) ) + ( v3y * x ) );
	return result_polynomial_21393;
}



std::vector<interval> find_roots(const polynomial& p, const rational& max_width) {
	return isolate_roots(p, max_width);
}

bool test_formula_at_sample_points(const double a, const double b, const double r, const double v1x, const double v1y, const double v2x, const double v2y, const double v3x, const double v3y , const std::vector<polynomial>& upolys) {
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
		return formula(a, b, r, v1x, v1y, v2x, v2y, v3x, v3y , 0.0);
	 }

	for (auto& pt : test_points) { double test_x = pt.to_double();
	 bool fm_true = formula(a, b, r, v1x, v1y, v2x, v2y, v3x, v3y , test_x);
	 cout << "At x = " << test_x << " the formula is " << fm_true << endl;
	 if (fm_true) {
		return true;
	 }
	}
	return false;
	
}

bool triangle_circle( const double a, const double b, const double r, const double v1x, const double v1y, const double v2x, const double v2y, const double v3x, const double v3y ) {
	vector<polynomial> polys{make_polynomial_1(), make_polynomial_2(), make_polynomial_3(), make_polynomial_4(), make_polynomial_5(), make_polynomial_6(), make_polynomial_7(), make_polynomial_8(), make_polynomial_9(), make_polynomial_10(), make_polynomial_11(), make_polynomial_12(), make_polynomial_13(), make_polynomial_14(), make_polynomial_15(), make_polynomial_16(), make_polynomial_17(), make_polynomial_18(), make_polynomial_19(), make_polynomial_20(), make_polynomial_21(), make_polynomial_22(), make_polynomial_23() };
	vector<rational> rs{{a}, {b}, {r}, {v1x}, {v1y}, {v2x}, {v2y}, {v3x}, {v3y} };
	vector<polynomial> upolys;
	for (auto& p : polys) {
		polynomial p_univariate = evaluate_at(rs, p);
		upolys.push_back(p_univariate);
	}
	return test_formula_at_sample_points(a, b, r, v1x, v1y, v2x, v2y, v3x, v3y , upolys);

}