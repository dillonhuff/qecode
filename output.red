procedure writeVar(varList, i); begin
	  if length varList = i then write("const double ", part(varList, i)) else write("const double ", part(varList, i), ", ")$
	  end$

procedure writePartWithStr(str, valList, i); begin
	  writeFormulaAsCpp(part(valList, i)) $
	  write(" ", str)$
	  end;

procedure writeDecl(fm); begin
	  write("bool test(")$
	  for i := 1 step 1 until length vars do writeVar(vars, i)$
	  write(") {")$
	  end;

procedure writeVal(str, valList, i); begin
	  COMMENT write(valList, i);
	  COMMENT write ("TERM")$

	  if (length valList = i) or (length valList <= 1) then writeFormulaAsCpp(part(valList, i)) else writePartWithStr(str, valList, i)$

	  COMMENT writeFormulaAsCpp(part(valList, i))$

	end$

procedure writeClauseAsCpp(connective, fm); begin;
	  write("(")$
	  COMMENT for i := 1 step 1 until length(part(fm)) do writeVal(connective, fm, i)$
	  for i := 1 step 1 until length(part(fm)) do
	      writeVal(connective, fm, i)$
	  COMMENT writeFormulaAsCpp(part(fm, i))$
	  write(")")$
	  end$

procedure opString(op); if op = equal then "=="
	  else if op = leq then "<="
	  else if op = geq then ">="
	  else "!=";

procedure writeTerm(term); begin
	  on fort$
	  write("( ", lhs(term), " ", opString( part(term, 0) ), " ", rhs(term), " )")$
	  off fort$
	  end;

procedure writeFormulaAsCpp(fm); begin
	  if part(fm, 0) = or then writeClauseAsCpp("||", fm) else
	  if part(fm, 0) = and then writeClauseAsCpp("&&", fm) else
	  writeTerm(fm)$
	  end$

procedure writeFormula(fm); begin
	  COMMENT writeDecl(fm);
	  COMMENT write("return ");

	  out formula_file$
	  writeFormulaAsCpp(fm)$
	  shut formula_file$

	  write(";");
	  write("}")$
	  end$
