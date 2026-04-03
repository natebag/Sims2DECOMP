// 0x80368178 (8 bytes) - ERAnim::operator new(unsigned int, void *)
typedef unsigned int size_t;

void* operator_new_ERAnim(size_t size, void* ptr) {
    return ptr;
}
