// 0x8031B390 (8 bytes) - ERModel::operator new(unsigned int, void *)
typedef unsigned int size_t;

void* operator_new_ERModel(size_t size, void* ptr) {
    return ptr;
}
