/* TArray_FileCreator::~TArray_FileCreator() - 0x803C1914 (64 bytes) */

struct TArray_FileCreator {
    void Deallocate();
    ~TArray_FileCreator();
};

TArray_FileCreator::~TArray_FileCreator()
{
    Deallocate();
}
