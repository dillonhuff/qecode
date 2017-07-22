procedure inCircleFormula(a, b, r); (x - a)^2 + (y - b)^2 <= r^2;

procedure inSquareFormula(a, b, l); (a <= x) and (x <= a + l) and (b <= y) and (y <= b + l);

procedure inRectangleFormula(a, b, c, d); (a <= x) and (x <= c) and (b <= y) and (y <= d);

procedure inCubeFormula(a, b, c, l); (a <= x) and (x <= a + l) and (b <= y) and (y <= b + l) and (c <= z) and (z <= c + l);

procedure inSphereFormula(a, b, c, r); (x - a)^2 + (y - b)^2 + (z - c)^2 <= r^2;

procedure onPlaneFormula(a, b, c, d); a*x + b*y + c*z + d = 0;

procedure belowPlaneFormula(a, b, c, d); a*x + b*y + c*z + d < 0;

procedure abovePlaneFormula(a, b, c, d); a*x + b*y + c*z + d > 0;

procedure inEllipseFormula(a, b, h, k); (b^2)*(x - h)^2 + (a^2)*(y - k)^2 <= (a^2) * (b^2);

procedure onLineFormula2D(a, b); a*x + b = y;

procedure onParabolaFormula(a, b, c); a*x^2 + b*x + c - y = 0;

procedure inEllipsoidFormula(a, b, c, h, k, l); (k^2)*(l^2)*(x - a)^2 + (h^2)*(l^2)*(y - b)^2 + (h^2)*(k^2)*(z - c)^2 <= h^2 * k^2 + l^2;

procedure inSign(p1x, p1y, p2x, p2y, p3x, p3y); (p1x - p3x)*(p2y - p3y) - (p2x - p3x)*(p1y - p3y);

procedure inTriangleFormula(v1x, v1y, v2x, v2y, v3x, v3y); begin
	  s1 := inSign(x, y, v1x, v1y, v2x, v2y);
	  s2 := inSign(x, y, v2x, v2y, v3x, v3y);
	  s3 := inSign(x, y, v3x, v3y, v1x, v1y);

	  return (s1 < 0 and s2 < 0 and s3 < 0) or (s1 > 0 and s2 > 0 and s3 > 0) or (s1 = 0 and s2 = 0 and s3 = 0);

	  end;
