/* TArray<int, TArrayERCharacterAllocator>::Construct(int *, int) at 0x802140E0 (32B) */

struct TArray_int_ERChar {
    void Construct(int *dest, int count);
};

extern void TArray_int_ERChar_Construct_impl(TArray_int_ERChar*, int*, int);

void TArray_int_ERChar::Construct(int *dest, int count) {
    TArray_int_ERChar_Construct_impl(this, dest, count);
}
