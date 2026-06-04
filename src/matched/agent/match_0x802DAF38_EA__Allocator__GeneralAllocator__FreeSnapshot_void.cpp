// 0x802DAF38 EA::Allocator::GeneralAllocator::FreeSnapshot(Snapshot*) (64 B)
// Free a snapshot only if it carries the 'SNAP' magic (0x534E4150) at +0 and its
// +0x0C guard word is 0. magic @ +0x00, guard @ +0x0C.
struct Snapshot {
    unsigned int mMagic;   // 0x00
    char         pad4[8];
    unsigned int mGuard;   // 0x0C
};
struct GeneralAllocator {
    void FreeInternal(void* p);
};

// r3 = this, r4 = snapshot
extern "C" void f_802DAF38(GeneralAllocator* self, Snapshot* snapshot)
{
    if (snapshot->mMagic == 0x534E4150 && snapshot->mGuard == 0)
        self->FreeInternal(snapshot);
}
