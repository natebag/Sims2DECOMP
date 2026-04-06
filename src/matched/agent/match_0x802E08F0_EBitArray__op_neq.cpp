extern "C" int EBitArray_op_eq(void* a, void* b);
int EBitArray_op_neq(void* a, void* b) {
    return EBitArray_op_eq(a, b) ^ 1;
}
