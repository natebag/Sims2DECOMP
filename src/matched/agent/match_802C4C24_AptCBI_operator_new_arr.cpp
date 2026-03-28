void* AptAllocate4(unsigned int size);

struct AptCBI_ONA {
    static void* operator_new_arr(unsigned int size);
};

void* AptCBI_ONA::operator_new_arr(unsigned int size) {
    return AptAllocate4(size);
}
