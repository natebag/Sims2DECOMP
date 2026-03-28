/* TArray_EFontPagePtr::~TArray_EFontPagePtr() - 0x803C7C2C (64 bytes) */

struct TArray_EFontPagePtr {
    void Deallocate();
    ~TArray_EFontPagePtr();
};

TArray_EFontPagePtr::~TArray_EFontPagePtr()
{
    Deallocate();
}
