void* AptAllocate2(unsigned int size);

struct AptFloat_ONA {
    static void* operator_new_arr(unsigned int size);
};

void* AptFloat_ONA::operator_new_arr(unsigned int size) {
    return AptAllocate2(size);
}
