load redlog;
rlset ofsf;
in "shape_formulas.red";

phi := ex( y, onLineFormula2D( a, b ) and inRectangleFormula( c, d, h, k  ) )$
out fresh_file$
rlqe phi;
shut fresh_file$