/* Test: Variable declaration order controls register allocation */

struct TestStruct {
    int field1;
    int field2;
};

/* Version 1: var1 first */
int test_order1(TestStruct* a, TestStruct* b) {
    int var1 = a->field1;
    int var2 = b->field2;
    return var1 + var2;
}

/* Version 2: var2 first */
int test_order2(TestStruct* a, TestStruct* b) {
    int var2 = b->field2;
    int var1 = a->field1;
    return var1 + var2;
}
