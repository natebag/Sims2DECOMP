// 0x8022F8D4 (8 bytes) - EIStaticSubModel::operator new(unsigned int, void *)
// or r3, r4, r4; blr  =>  return p;

typedef unsigned int size_t;

void* operator_new_EIStaticSubModel(size_t, void* p) {
    return p;
}
