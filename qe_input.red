load redlog;
rlset ofsf;
in "shape_formulas.red";

COMMENT phi := ex( x, (a*l^2*f + b + c*m^4 + d + f + h  + k + l + 2*m^2 + 3*g^4)*x^2 > 0 and (a^2*b + c^3*d + h^5*k^2  + f^2*k)*x < 0);

COMMENT phi := ex( y, (x - a)^2 + (y - b)^2 <= r^2 and d^2*(x - h)^2 + f^2*(y - k)^2 <=  d^2*f^2);

COMMENT asdf



COMMENT ex( y, (onLineFormula2D( a, b ) and onLineFormula2D( c, d)) or (onLineFormula2D( f, g) and onLineFormula2D(a, g)) );

COMMENT and inEllipseFormula( c, d, h, k ) );

phi := ex( y, inCircleFormula( a, b, r ) and inCircleFormula( c, d, l) );

COMMENT inEllipseFormula( c, d, h, k ) );

out formula_file$
val := rlqe phi;
shut formula_file$

COMMENT in "output.red"$
COMMENT writeFormula(val)$