load redlog;
rlset ofsf;
in "shape_formulas.red";

phi := ex( y, ex( z, inSphereFormula( a, b, c, r  ) and inCubeFormula( j, k, l, m  ) ) )$
out fresh_file$
rlqe phi;
shut fresh_file$