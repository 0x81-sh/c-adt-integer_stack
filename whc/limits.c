#include "limits.h"
#include <stdlib.h>
#include <stdio.h>

struct Limits {
    PFraction max;
    PFraction min;
};

PLimits Limits_create() {
    PLimits ret = (PLimits) malloc(sizeof (struct Limits));

    ret->min = NULL;
    ret->max = NULL;

    return ret;
}

void Limits_check(PLimits _this, PFraction newV) {
    if (_this->min == NULL || Fraction_lessThan(newV, _this->min)) {
        _this->min = newV;
        return;
    }

    if (_this->max == NULL || Fraction_greaterThan(newV, _this->max)) {
        _this->max = newV;
        return;
    }
}

void Limits_print(PLimits _this) {
    printf("Largest fraction: ");
    Fraction_print(_this->max);
    
    printf("\nSmallest fraction: ");
    Fraction_print(_this->min);
    printf("\n");
}