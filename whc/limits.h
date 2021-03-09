#pragma once
#include "fraction.h"

typedef struct Limits *PLimits;

PLimits Limits_create();
void Limits_check(PLimits _this, PFraction newV);
void Limits_print(PLimits _this);