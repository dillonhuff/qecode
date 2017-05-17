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

procedure writeVal(str, valList, i); begin
	  if (length valList = i) or (length valList <= 1) then writeFormulaAsCpp(part(valList, i)) else
	  COMMENT write(str," ", writeFormulaAsCpp(part(valList, i)));
	  writeFormulaAsCpp(part(valList, i));
	  end;

procedure writeClauseAsCpp(connective, fm); begin;
	  write("(");
	  for i := 1 step 1 until length(part(fm)) do writeVal(connective, fm, i);
	  COMMENT writeFormulaAsCpp(part(fm, i));
	  write(")");
	  end;

procedure writeFormulaAsCpp(fm); begin
	  if part(fm, 0) = or then writeClauseAsCpp("||", fm) else
	  if part(fm, 0) = and then writeClauseAsCpp("&&", fm) else
	  write(fm);
	  end;

procedure writeFormula(fm);
	  begin writeDecl(fm);
	  write("return ");
	  writeFormulaAsCpp(fm);


	  write(";");
	  write("}");
	  end;

writeFormula(val);

s1 := "This is a value";
write("hey");
s2 := "YET";

s3 := concat(s1, s2);

write(s3);

kl := {1, 2, 3};
write kl;


COMMENT for each p in part val 1$

COMMENT for i := 0 step 1 until length vars do write $

COMMENT parts := part val$

COMMENT length parts$

COMMENT atoms := rlatl val$

