// FLAGS: -fno-elide-constructors
// 0x8039BE30 (48 bytes)
// TArray<EString, TArrayDefaultAllocator>::TArray(void)

extern "C" void TArray_Init(void* self);

void* TArray_EString_ctor(void* self) {
    TArray_Init(self);
    return self;
}
