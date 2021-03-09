#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define bufferSize 16

struct SIntStack {
    int *stack;
    int maxSize;
    int size;
    char *str;
};

IntStack IntStack_create(int size) {
    IntStack ret = (IntStack) malloc(sizeof (struct SIntStack));

    ret->maxSize = size;
    ret->size = 0;
    ret->stack = NULL;
    ret->str = NULL;

    return ret;
}

int IntStack_getSize(IntStack _this) {
    return _this->maxSize;
}

int IntStack_getElementCount(IntStack _this) {
    return _this->size;
}

bool IntStack_isFull(IntStack _this) {
    return _this->size == _this->maxSize;
}

bool IntStack_isEmpty(IntStack _this) {
    return _this->size == 0;
}

void IntStack_push(IntStack _this, int next) {
    if (_this->size == _this->maxSize) {
        printf("Error: Cannot push to full stack.\n");
        return;
    }

    _this->size += 1;
    if (_this->size == 0) {
        _this->stack = (int *) malloc(sizeof (int));
    } else {
        _this->stack = (int *) realloc(_this->stack, sizeof (int) * _this->size);
    }

    *(_this->stack + (_this->size - 1)) = next;
}

int IntStack_pop(IntStack _this) {
    if (_this->size == 0) {
        printf("Error: Cannot pop off empty stack.\n");
        return -1;
    }

    int value = *(_this->stack + _this->size - 1);
    _this->size -= 1;

    if (_this->size == 0) {
        free(_this->stack);
        _this->stack = NULL;
    } else {
        _this->stack = (int *) realloc(_this->stack, sizeof (int) * _this->size);
    }

    return value;
}

int IntStack_peek(IntStack _this) {
    return *(_this->stack + _this->size - 1);
}

char *IntStack_toString(IntStack _this) {
    if (_this->str == NULL) {
        _this->str = (char *) malloc(sizeof (char));
        _this->str[0] = '\0';
    }

    for (int i = 0; i < _this->size; i++) {
        char tempStr[bufferSize];
        sprintf(tempStr, "%d; ", *(_this->stack + i));

        _this->str = (char *) realloc(_this->str, strlen(_this->str) + strlen(tempStr) + 1);
        i == 0 ? strcpy(_this->str, tempStr) : strcat(_this->str, tempStr);
    }

    return _this->size == 0 ? NULL : _this->str;
}

void IntStack_delete(IntStack _this) {
    free(_this->stack);
    free(_this->str);

    free(_this);
}