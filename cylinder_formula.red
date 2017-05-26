load redlog;
rlset ofsf;

procedure CylTest_CapsFirst( pt1_x, pt1_y, pt1_z, pt2_x, pt2_y, pt2_z, lengthsq, radius_sq, testpt_x, testpt_y, testpt_z ); begin

	dx := pt2_x - pt1_x;	COMMENT translate so pt1 is origin.  Make vector from;
	dy := pt2_y - pt1_y;     COMMENT pt1 to pt2.  Need for this is easily eliminated;
	dz := pt2_z - pt1_z;

	pdx := testpt_x - pt1_x;		COMMENT vector from pt1 to test point;
	pdy := testpt_y - pt1_y;
	pdz := testpt_z - pt1_z;

	COMMENT Dot the d and pd vectors to see if point lies behind the ;
	COMMENT cylinder cap at pt1.x, pt1.y, pt1.z;

	dot := pdx * dx + pdy * dy + pdz * dz;

	dsq := (pdx*pdx + pdy*pdy + pdz*pdz)*lengthsq - dot*dot;

	return (not (dot < 0.0)) and (not (dot > lengthsq)) and (dsq > radius_sq*lengthsq);
	end;

	COMMENT if (dot < 0.0f) or (dot > lengthsq) then return -1.0;
	COMMENT else begin;


	COMMENT      if dsq > radius_sq then return -1.0 else return dsq;

	COMMENT end;
	COMMENT end;

val := ex(testpt_x, ex(testpt_y, ex(testpt_z, CylTest_CapsFirst( pt1_x, pt1_y, pt1_z, pt2_x, pt2_y, pt2_z, lengthsq, radius_sq, testpt_x, testpt_y, testpt_z ) ) ) );

res := rlqe val;