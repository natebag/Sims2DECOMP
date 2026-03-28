#include "types.h"

class TArrayDefaultAllocator;

template <typename T, typename A = int>
class TArray {
public:
    void Init() { *(int*)((char*)this + 0x4) = 0; *(int*)((char*)this + 0x0) = 0; *(int*)((char*)this + 0x8) = 0; }
    char _stub_data[16];
};

template class TArray<unsigned char *, TArrayDefaultAllocator>;
