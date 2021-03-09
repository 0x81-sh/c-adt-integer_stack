#pragma once

typedef struct Fraction *PFraction;

Fraction create(int num, int denom);
int Fraction_greaterThan(PFraction a, PFraction b);
int Fraction_lessThan(PFraction a, PFraction b);
void Fraction_print(PFraction _this);
