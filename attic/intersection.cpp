#include<cmath>

bool test( const double r, const double l, const double b, const double d, const double a, const double c ) { return ( ( ( ( ( ( ( ( ( ( ( ( r != 0.0 ) && ( l != 0.0 ) ) && ( b - d >= 0.0 ) ) && ( b - d - l <= 0.0 ) ) && ( a - c - r >= 0.0 ) ) && ( a - c - l - r <= 0.0 ) ) || ( ( ( ( ( ( r != 0.0 ) && ( l != 0.0 ) ) && ( b - d >= 0.0 ) ) && ( b - d - l <= 0.0 ) ) && ( a - c + r >= 0.0 ) ) && ( a - c - l + r <= 0.0 ) ) ) || ( ( ( r != 0.0 ) && ( l != 0.0 ) ) && ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( c, 2 ) + 2.0 * c * l + pow( d, 2 ) + 2.0 * d * l + 2.0 * pow( l, 2 ) - pow( r, 2 ) <= 0.0 ) ) ) || ( ( pow( b, 2 ) - 2.0 * b * d + pow( d, 2 ) - pow( r, 2 ) <= 0.0 ) && ( ( ( ( ( ( ( ( ( ( r != 0.0 ) && ( l != 0.0 ) ) && ( b - d >= 0.0 ) ) && ( a - c >= 0.0 ) ) && ( pow( a, 2 ) - 2.0 * a * c + pow( b, 2 ) - 2.0 * b * d + pow( c, 2 ) + pow( d, 2 ) - pow( r, 2 ) >= 0.0 ) ) && ( ( b - d - l <= 0.0 ) || ( l * 2.0 * b - 2.0 * d - l >= 0.0 ) ) ) && ( ( a - c - l <= 0.0 ) || ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( b, 2 ) - 2.0 * b * d + pow( c, 2 ) + 2.0 * c * l + pow( d, 2 ) + pow( l, 2 ) - pow( r, 2 ) <= 0.0 ) ) ) || ( ( ( ( ( ( ( r != 0.0 ) && ( l != 0.0 ) ) && ( b - d >= 0.0 ) ) && ( a - c - l <= 0.0 ) ) && ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( b, 2 ) - 2.0 * b * d + pow( c, 2 ) + 2.0 * c * l + pow( d, 2 ) + pow( l, 2 ) - pow( r, 2 ) >= 0.0 ) ) && ( ( b - d - l <= 0.0 ) || ( l * 2.0 * b - 2.0 * d - l >= 0.0 ) ) ) && ( ( a - c >= 0.0 ) || ( pow( a, 2 ) - 2.0 * a * c + pow( b, 2 ) - 2.0 * b * d + pow( c, 2 ) + pow( d, 2 ) - pow( r, 2 ) <= 0.0 ) ) ) ) || ( ( ( ( ( ( ( r != 0.0 ) && ( l != 0.0 ) ) && ( b - d - l <= 0.0 ) ) && ( l * 2.0 * b - 2.0 * d - l <= 0.0 ) ) && ( a - c >= 0.0 ) ) && ( pow( a, 2 ) - 2.0 * a * c + pow( b, 2 ) - 2.0 * b * d + pow( c, 2 ) + pow( d, 2 ) - pow( r, 2 ) >= 0.0 ) ) && ( ( a - c - l <= 0.0 ) || ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( b, 2 ) - 2.0 * b * d + pow( c, 2 ) + 2.0 * c * l + pow( d, 2 ) + pow( l, 2 ) - pow( r, 2 ) <= 0.0 ) ) ) ) || ( ( ( ( ( ( ( r != 0.0 ) && ( l != 0.0 ) ) && ( b - d - l <= 0.0 ) ) && ( l * 2.0 * b - 2.0 * d - l <= 0.0 ) ) && ( a - c - l <= 0.0 ) ) && ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( b, 2 ) - 2.0 * b * d + pow( c, 2 ) + 2.0 * c * l + pow( d, 2 ) + pow( l, 2 ) - pow( r, 2 ) >= 0.0 ) ) && ( ( a - c >= 0.0 ) || ( pow( a, 2 ) - 2.0 * a * c + pow( b, 2 ) - 2.0 * b * d + pow( c, 2 ) + pow( d, 2 ) - pow( r, 2 ) <= 0.0 ) ) ) ) ) ) || ( ( pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( d, 2 ) + 2.0 * d * l + pow( l, 2 ) - pow( r, 2 ) <= 0.0 ) && ( ( ( ( ( ( ( ( ( ( r != 0.0 ) && ( l != 0.0 ) ) && ( b - d >= 0.0 ) ) && ( l * 2.0 * b - 2.0 * d - l >= 0.0 ) ) && ( a - c >= 0.0 ) ) && ( pow( a, 2 ) - 2.0 * a * c + pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( c, 2 ) + pow( d, 2 ) + 2.0 * d * l + pow( l, 2 ) - pow( r, 2 ) >= 0.0 ) ) && ( ( a - c - l <= 0.0 ) || ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( c, 2 ) + 2.0 * c * l + pow( d, 2 ) + 2.0 * d * l + 2.0 * pow( l, 2 ) - pow( r, 2 ) <= 0.0 ) ) ) || ( ( ( ( ( ( ( r != 0.0 ) && ( l != 0.0 ) ) && ( b - d >= 0.0 ) ) && ( l * 2.0 * b - 2.0 * d - l >= 0.0 ) ) && ( a - c - l <= 0.0 ) ) && ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( c, 2 ) + 2.0 * c * l + pow( d, 2 ) + 2.0 * d * l + 2.0 * pow( l, 2 ) - pow( r, 2 ) >= 0.0 ) ) && ( ( a - c >= 0.0 ) || ( pow( a, 2 ) - 2.0 * a * c + pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( c, 2 ) + pow( d, 2 ) + 2.0 * d * l + pow( l, 2 ) - pow( r, 2 ) <= 0.0 ) ) ) ) || ( ( ( ( ( ( ( r != 0.0 ) && ( l != 0.0 ) ) && ( b - d - l <= 0.0 ) ) && ( a - c >= 0.0 ) ) && ( pow( a, 2 ) - 2.0 * a * c + pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( c, 2 ) + pow( d, 2 ) + 2.0 * d * l + pow( l, 2 ) - pow( r, 2 ) >= 0.0 ) ) && ( ( b - d >= 0.0 ) || ( l * 2.0 * b - 2.0 * d - l <= 0.0 ) ) ) && ( ( a - c - l <= 0.0 ) || ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( c, 2 ) + 2.0 * c * l + pow( d, 2 ) + 2.0 * d * l + 2.0 * pow( l, 2 ) - pow( r, 2 ) <= 0.0 ) ) ) ) || ( ( ( ( ( ( ( r != 0.0 ) && ( l != 0.0 ) ) && ( b - d - l <= 0.0 ) ) && ( a - c - l <= 0.0 ) ) && ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( c, 2 ) + 2.0 * c * l + pow( d, 2 ) + 2.0 * d * l + 2.0 * pow( l, 2 ) - pow( r, 2 ) >= 0.0 ) ) && ( ( b - d >= 0.0 ) || ( l * 2.0 * b - 2.0 * d - l <= 0.0 ) ) ) && ( ( a - c >= 0.0 ) || ( pow( a, 2 ) - 2.0 * a * c + pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( c, 2 ) + pow( d, 2 ) + 2.0 * d * l + pow( l, 2 ) - pow( r, 2 ) <= 0.0 ) ) ) ) ) ) || ( ( pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( d, 2 ) + 2.0 * d * l + pow( l, 2 ) - pow( r, 2 ) <= 0.0 ) && ( ( ( ( ( ( r != 0.0 ) && ( l != 0.0 ) ) && ( a - c >= 0.0 ) ) && ( pow( a, 2 ) - 2.0 * a * c + pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( c, 2 ) + pow( d, 2 ) + 2.0 * d * l + pow( l, 2 ) - pow( r, 2 ) >= 0.0 ) ) && ( ( a - c - l <= 0.0 ) || ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( c, 2 ) + 2.0 * c * l + pow( d, 2 ) + 2.0 * d * l + 2.0 * pow( l, 2 ) - pow( r, 2 ) <= 0.0 ) ) ) || ( ( ( ( ( r != 0.0 ) && ( l != 0.0 ) ) && ( a - c - l <= 0.0 ) ) && ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( c, 2 ) + 2.0 * c * l + pow( d, 2 ) + 2.0 * d * l + 2.0 * pow( l, 2 ) - pow( r, 2 ) >= 0.0 ) ) && ( ( a - c >= 0.0 ) || ( pow( a, 2 ) - 2.0 * a * c + pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( c, 2 ) + pow( d, 2 ) + 2.0 * d * l + pow( l, 2 ) - pow( r, 2 ) <= 0.0 ) ) ) ) ) ) || ( ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( c, 2 ) + 2.0 * c * l + pow( l, 2 ) - pow( r, 2 ) <= 0.0 ) && ( ( ( ( ( ( r != 0.0 ) && ( l != 0.0 ) ) && ( b - d >= 0.0 ) ) && ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( b, 2 ) - 2.0 * b * d + pow( c, 2 ) + 2.0 * c * l + pow( d, 2 ) + pow( l, 2 ) - pow( r, 2 ) >= 0.0 ) ) && ( ( b - d - l <= 0.0 ) || ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( c, 2 ) + 2.0 * c * l + pow( d, 2 ) + 2.0 * d * l + 2.0 * pow( l, 2 ) - pow( r, 2 ) <= 0.0 ) ) ) || ( ( ( ( ( r != 0.0 ) && ( l != 0.0 ) ) && ( b - d - l <= 0.0 ) ) && ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( b, 2 ) - 2.0 * b * d - 2.0 * b * l + pow( c, 2 ) + 2.0 * c * l + pow( d, 2 ) + 2.0 * d * l + 2.0 * pow( l, 2 ) - pow( r, 2 ) >= 0.0 ) ) && ( ( b - d >= 0.0 ) || ( pow( a, 2 ) - 2.0 * a * c - 2.0 * a * l + pow( b, 2 ) - 2.0 * b * d + pow( c, 2 ) + 2.0 * c * l + pow( d, 2 ) + pow( l, 2 ) - pow( r, 2 ) <= 0.0 ) ) ) ) ) ); }