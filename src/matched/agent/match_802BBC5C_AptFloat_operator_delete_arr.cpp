void AptDeallocate2(void* ptr);

struct AptFloat_ODA {
    static void operator_delete_arr(void* ptr);
};

void AptFloat_ODA::operator_delete_arr(void* ptr) {
    AptDeallocate2(ptr);
}
