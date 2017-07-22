load redlog;
rlset ofsf;
in "shape_formulas.red";

COMMENT phi := ex( y, ex( z, onPlaneFormula( a, b, c, d  ) and inEllipsoidFormula( f, g, h, l, m, n  ) ) )$

COMMENT procedure inSign(p1x, p1y, p2x, p2y, p3x, p3y); (p1x - p3x)*(p2y - p3y) - (p2x - p3x)*(p1y - p3y) < 0;

COMMENT s1 := inSign(x, y, v1x, v1y, v2x, v2y);
COMMENT s2 := inSign(x, y, v2x, v2y, v3x, v3y);
COMMENT s3 := inSign(x, y, v3x, v3y, v1x, v1y);

COMMENT inTriangleFm := (s1 < 0 and s2 < 0 and s3 < 0) or (s1 > 0 and s2 > 0 and s3 > 0) or (s1 = 0 and s2 = 0 and s3 = 0);

phi := ex(x, ex(y, inTriangleFormula( v1x, v1y, v2x, v2y, v3x, v3y ) ) );

out fresh_file$
rlqe phi;
shut fresh_file$