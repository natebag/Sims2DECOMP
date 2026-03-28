/* TArray_SndEvtHitPatch::~TArray_SndEvtHitPatch() - 0x803CA0C0 (64 bytes) */

struct TArray_SndEvtHitPatch {
    void Deallocate();
    ~TArray_SndEvtHitPatch();
};

TArray_SndEvtHitPatch::~TArray_SndEvtHitPatch()
{
    Deallocate();
}
