load redlog;
rlset ofsf;
in "shape_formulas.red";

phi := ex( y, inCircleFormula( a, b, l ) and inEllipseFormula( c, d, h, k ) )$
out fresh_file$
rlqe phi;
shut fresh_file$