load redlog;

procedure inCircleFormula(a, b, r); (x - a)^2 + (y - b)^2 <= r^2;
procedure inSquareFormula(a, b, l); (c <= x) and (x <= c + l) and (b <= y) and (y <= b + l);

rlset ofsf;
phi := ex(x, ex( y, inCircleFormula(a, b, r) and inSquareFormula(c, d, l) and (l > 0) and (r > 0) ) );

COMMENT phi := ex(y, ex(x, a*x^2+b*x+1=0));

rlqe phi;
