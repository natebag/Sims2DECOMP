void* AptAllocate3(unsigned int size);

struct AptInt_ONA {
    static void* operator_new_arr(unsigned int size);
};

void* AptInt_ONA::operator_new_arr(unsigned int size) {
    return AptAllocate3(size);
}
