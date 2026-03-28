/* TArray_EILightPtr::~TArray_EILightPtr() - 0x8039F6C0 (64 bytes) */

struct TArray_EILightPtr {
    void Deallocate();
    ~TArray_EILightPtr();
};

TArray_EILightPtr::~TArray_EILightPtr()
{
    Deallocate();
}
