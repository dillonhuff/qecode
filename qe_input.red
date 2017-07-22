load redlog;
rlset ofsf;
in "shape_formulas.red";

phi := ex( y, inTriangleFormula( v1x, v1y, v2x, v2y, v3x, v3y  ) and inCircleFormula( a, b, r ) )$
out fresh_file$
rlqe phi;
shut fresh_file$