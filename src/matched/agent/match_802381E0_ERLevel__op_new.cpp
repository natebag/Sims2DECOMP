// 0x802381E0 (8 bytes) - ERLevel::operator new(unsigned int, void *)
// or r3, r4, r4; blr  =>  return p;

typedef unsigned int size_t;

void* operator_new_ERLevel(size_t, void* p) {
    return p;
}
