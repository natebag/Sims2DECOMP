/* TArray_SimsLightInfo::~TArray_SimsLightInfo() - 0x803C43A8 (64 bytes) */

struct TArray_SimsLightInfo {
    void Deallocate();
    ~TArray_SimsLightInfo();
};

TArray_SimsLightInfo::~TArray_SimsLightInfo()
{
    Deallocate();
}
