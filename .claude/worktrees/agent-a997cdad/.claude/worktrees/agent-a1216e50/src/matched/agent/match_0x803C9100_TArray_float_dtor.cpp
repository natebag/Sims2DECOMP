/* TArray_float::~TArray_float() - 0x803C9100 (64 bytes) */

struct TArray_float {
    void Deallocate();
    ~TArray_float();
};

TArray_float::~TArray_float()
{
    Deallocate();
}
