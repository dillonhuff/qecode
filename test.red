load redlog;
rlset ofsf;

procedure inCircleFormula(a, b, r); (x - a)^2 + (y - b)^2 <= r^2;
procedure inSquareFormula(a, b, l); (a <= x) and (x <= a + l) and (b <= y) and (y <= b + l);

procedure inCubeFormula(a, b, c, l); (a <= x) and (x <= a + l) and (b <= y) and (y <= b + l) and (c <= x) and (x <= c + l);

procedure inSphereFormula(a, b, c, r); (x - a)^2 + (y - b)^2 + (z - c)^2 <= r^2;



rlset ofsf;
phi := ex( x, ex( y, inCircleFormula(a, b, r) and inSquareFormula(c, d, l) and (l > 0) and (r > 0) ) );

COMMENT phi := ex( x, ex( y, ex( z, inCubeFormula( a, b, c, l ) and inSphereFormula( a, b, c, r) and (l > 0) and (r > 0) ) ) );



val := rlqe phi;

if part(val, 0) = or then write "OR!!" else "NOT OR!!";

vars := rlfvarl val;

parts := part val;
length parts;

procedure writePart(str, val, i); begin
	  write(str, part(val, i));
	  end;

procedure writeVar(varList, i); begin
	  if length varList = i then write("const double ", part(varList, i)) else write("const double ", part(varList, i), ", ");
	  end;

procedure writeDecl(fm); begin
	  write("bool test(");
	  for i := 1 step 1 until length vars do writeVar(vars, i);
	  write(") {");
	  end;

procedure writeFormula(fm);
	  begin writeDecl(fm);
	  write("return ");
	  COMMENT for i := 1 step 1 until length parts do writePart("|| ", fm, i);
	  write(";");
	  write("}");
	  end;

writeFormula(val);

COMMENT for each p in part val 1;

COMMENT for i := 0 step 1 until length vars do write .

COMMENT parts := part val;

COMMENT length parts;

COMMENT atoms := rlatl val;

