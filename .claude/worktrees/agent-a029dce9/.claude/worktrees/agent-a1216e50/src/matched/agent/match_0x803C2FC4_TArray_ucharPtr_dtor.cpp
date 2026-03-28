/* TArray_ucharPtr::~TArray_ucharPtr() - 0x803C2FC4 (64 bytes) */

struct TArray_ucharPtr {
    void Deallocate();
    ~TArray_ucharPtr();
};

TArray_ucharPtr::~TArray_ucharPtr()
{
    Deallocate();
}
