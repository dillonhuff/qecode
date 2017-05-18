load redlog;
rlset ofsf;

procedure inCircleFormula(a, b, r); (x - a)^2 + (y - b)^2 <= r^2;
procedure inSquareFormula(a, b, l); (a <= x) and (x <= a + l) and (b <= y) and (y <= b + l);

procedure inCubeFormula(a, b, c, l); (a <= x) and (x <= a + l) and (b <= y) and (y <= b + l) and (c <= z) and (z <= c + l);

procedure inSphereFormula(a, b, c, r); (x - a)^2 + (y - b)^2 + (z - c)^2 <= r^2;


COMMENT phi := ex( x, ex( y, ex( z, inCubeFormula( a, b, c, l ) and inSphereFormula( d, f, g, r) and (l > 0) and (r > 0) ) ) );


COMMENT phi := (x^2 + y^2 = 0) and (x = 0) and (z = 2);

phi := ex( x, ex( y, inCircleFormula(a, b, r) and inSquareFormula(c, d, l) and (l > 0) and (r > 0) ) );

val := rlqe phi;

subed_vals := sub({a=102.0, b=2.01, c=1.0, d=1.0, x=101 - 1.4, y=1.01, l=100, r=1.4}, val);

vars := rlfvarl val;

parts := part val;

in "output.red"$

writeFormula(val);

