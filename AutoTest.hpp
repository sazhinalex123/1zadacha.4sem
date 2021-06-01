#pragma once

int AutoTest() {
	CRatVector0 a(2);
	a[0] = CRationalNumber(1, 1);
	a[1] = CRationalNumber(1, 1);
	CRatVector0 b(3);
	b[0] = CRationalNumber(1, 1);
	b[1] = CRationalNumber(1, 1);
	b[2] = CRationalNumber(1, 1);
	CRatVector0 c = a + b;
	if (c.size() != 3) {
		return 0;
	}
	if (c[0].div != 2 || c[0].den != 1) {
		return 0;
	}
	if (c[1].div != 2 || c[1].den != 1) {
		return 0;
	}
	if (c[2].div != 1 || c[2].den != 1) {
		return 0;
	}
	c = a - b;
	if (c.size() != 3) {
		return 0;
	}
	if (c[0].div != 0 || c[0].den != 1) {
		return 0;
	}
	if (c[1].div != 0 || c[1].den != 1) {
		return 0;
	}
	if (c[2].div != -1 || c[2].den != 1) {
		return 0;
	}
	a[0] = CRationalNumber(1, 1);
	a[1] = CRationalNumber(1, 1);
	b[0] = CRationalNumber(2, 1);
	b[1] = CRationalNumber(1, 1);
	b[2] = CRationalNumber(1, 1);
	if ((a * b).div != 3 || (a * b).den != 1) {
		return 0;
	}
	return 1;
}