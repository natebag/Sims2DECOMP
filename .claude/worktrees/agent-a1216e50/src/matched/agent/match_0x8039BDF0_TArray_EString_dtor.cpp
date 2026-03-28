/* TArray_EString::~TArray_EString() - 0x8039BDF0 (64 bytes) */

struct TArray_EString {
    void Deallocate();
    ~TArray_EString();
};

TArray_EString::~TArray_EString()
{
    Deallocate();
}
