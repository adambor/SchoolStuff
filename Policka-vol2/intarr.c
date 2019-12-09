#include "intarr.h"

static struct IntArr new() {
    return (struct Complex){.arr=malloc(10*sizeof(int)), .length=0, .capacity=10};
}

const struct IntArrClass IntArr={.new=&new};
