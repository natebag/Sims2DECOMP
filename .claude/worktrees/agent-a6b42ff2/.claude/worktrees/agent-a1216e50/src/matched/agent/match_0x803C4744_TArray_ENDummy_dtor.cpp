/* TArray_ENDummy::~TArray_ENDummy() - 0x803C4744 (64 bytes) */

struct TArray_ENDummy {
    void Deallocate();
    ~TArray_ENDummy();
};

TArray_ENDummy::~TArray_ENDummy()
{
    Deallocate();
}
