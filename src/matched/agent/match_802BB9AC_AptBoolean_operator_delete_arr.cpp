void AptDeallocate(void* ptr);

struct AptBool_ODA {
    static void operator_delete_arr(void* ptr);
};

void AptBool_ODA::operator_delete_arr(void* ptr) {
    AptDeallocate(ptr);
}
