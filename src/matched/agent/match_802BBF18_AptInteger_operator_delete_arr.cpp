void AptDeallocate3(void* ptr);

struct AptInt_ODA {
    static void operator_delete_arr(void* ptr);
};

void AptInt_ODA::operator_delete_arr(void* ptr) {
    AptDeallocate3(ptr);
}
