// 0x802DCAA8 EA::Allocator::GeneralAllocator::MMapAlloc(unsigned int, unsigned int*) (72 B)
// Allocate via the mmap path; on success, write the request size back through
// the optional out-pointer. Returns the allocation (or 0). r3=this (unused),
// r4=size, r5=pOutSize.
extern "C" void* MMapMalloc(unsigned int size);   // 0x802D1288

extern "C" void* f_802DCAA8(void* /*self*/, unsigned int size, unsigned int* pOutSize)
{
    void* result = MMapMalloc(size);
    if (result != 0 && pOutSize != 0)
        *pOutSize = size;
    return result;
}
