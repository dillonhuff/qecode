load redlog;
rlset ofsf;
in "shape_formulas.red";

phi := ex( y, ex( z, onPlaneFormula( a, b, c, d  ) and inEllipsoidFormula( f, g, h, l, m, n  ) ) )$
out fresh_file$
rlqe phi;
shut fresh_file$