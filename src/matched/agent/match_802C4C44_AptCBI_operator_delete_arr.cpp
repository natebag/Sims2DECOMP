void AptDeallocate4(void* ptr);

struct AptCBI_ODA {
    static void operator_delete_arr(void* ptr);
};

void AptCBI_ODA::operator_delete_arr(void* ptr) {
    AptDeallocate4(ptr);
}
