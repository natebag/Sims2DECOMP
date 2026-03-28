/* TArray_EAnimNote::~TArray_EAnimNote() - 0x8039D844 (64 bytes) */

struct TArray_EAnimNote {
    void Deallocate();
    ~TArray_EAnimNote();
};

TArray_EAnimNote::~TArray_EAnimNote()
{
    Deallocate();
}
