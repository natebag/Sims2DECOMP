void* AptAllocate(unsigned int size);

struct AptBool_ONA {
    static void* operator_new_arr(unsigned int size);
};

void* AptBool_ONA::operator_new_arr(unsigned int size) {
    return AptAllocate(size);
}
