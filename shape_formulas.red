procedure inCircleFormula(a, b, r); (x - a)^2 + (y - b)^2 <= r^2;

procedure inSquareFormula(a, b, l); (a <= x) and (x <= a + l) and (b <= y) and (y <= b + l);

procedure inRectangleFormula(a, b, c, d); (a <= x) and (x <= c) and (b <= y) and (y <= d);

procedure inCubeFormula(a, b, c, l); (a <= x) and (x <= a + l) and (b <= y) and (y <= b + l) and (c <= z) and (z <= c + l);

procedure inSphereFormula(a, b, c, r); (x - a)^2 + (y - b)^2 + (z - c)^2 <= r^2;

procedure inEllipseFormula(a, b, h, k); (b^2)*(x - h)^2 + (a^2)*(y - k)^2 = (a^2) * (b^2);

procedure onLineFormula2D(a, b); a*x + b = y;