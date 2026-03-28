/* TArray<int, TArrayDefaultAllocator>::~TArray(void) - 0x803C252C (64 bytes) */

struct TArrayDefaultAllocator;

struct TArray_int {
    void Deallocate();
    ~TArray_int();
};

TArray_int::~TArray_int()
{
    Deallocate();
}
