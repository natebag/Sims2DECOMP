// 0x8022E16C (8 bytes) - EIStaticModel::operator new(unsigned int, void *)
// or r3, r4, r4; blr  =>  return p;

typedef unsigned int size_t;

void* operator_new_EIStaticModel(size_t, void* p) {
    return p;
}
