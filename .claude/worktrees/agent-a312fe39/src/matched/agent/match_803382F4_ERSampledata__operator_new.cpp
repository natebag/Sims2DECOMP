// 0x803382F4 (8 bytes) - ERSampledata::operator new(unsigned int, void *)
typedef unsigned int size_t;

void* operator_new_ERSampledata(size_t size, void* ptr) {
    return ptr;
}
