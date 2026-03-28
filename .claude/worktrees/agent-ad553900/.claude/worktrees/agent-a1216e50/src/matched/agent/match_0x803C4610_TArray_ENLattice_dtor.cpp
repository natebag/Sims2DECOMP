/* TArray_ENLattice::~TArray_ENLattice() - 0x803C4610 (64 bytes) */

struct TArray_ENLattice {
    void Deallocate();
    ~TArray_ENLattice();
};

TArray_ENLattice::~TArray_ENLattice()
{
    Deallocate();
}
