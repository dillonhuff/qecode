load redlog;
rlset ofsf;
in "shape_formulas.red";

phi := ex( y, inSquareFormula( a, b, l ) and inCircleFormula( c, d, r ) )$
out fresh_file$
rlqe phi;
shut fresh_file$