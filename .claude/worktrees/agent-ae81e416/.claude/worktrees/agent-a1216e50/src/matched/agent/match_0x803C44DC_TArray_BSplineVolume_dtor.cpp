/* TArray_BSplineVolume::~TArray_BSplineVolume() - 0x803C44DC (64 bytes) */

struct TArray_BSplineVolume {
    void Deallocate();
    ~TArray_BSplineVolume();
};

TArray_BSplineVolume::~TArray_BSplineVolume()
{
    Deallocate();
}
