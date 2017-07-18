load redlog;
rlset ofsf;
in "shape_formulas.red";

phi := ex( x, ex( y, ex( z, inSphereFormula( a, b, c, r  ) and inCubeFormula( j, k, l, m  ) ) ) );
val := rlqe phi$
in "output.red"$
writeFormula(val)$