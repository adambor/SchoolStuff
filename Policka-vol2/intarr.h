struct IntArr {
    int *arr;
    int length;
    int capacity;
};

extern const struct IntArr {
    struct IntArr (*new)();
} IntArr;
