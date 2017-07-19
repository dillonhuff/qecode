load redlog;
rlset ofsf;

in "shape_formulas.red";

phi := ex( x, ex( y, inCircleFormula(a, b, r) and inSquareFormula(c, d, l) and (l > 0) and (r > 0) ) );

val := rlqe phi;

in "output.red"$

writeFormula(val);

