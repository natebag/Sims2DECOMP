// FLAGS: -fno-schedule-insns
// TArray<SndEvtHitPatch, TArrayERSoundEventAllocator>::Construct(SndEvtHitPatch *, int)
// Address: 0x803CA258 | Size: 44 bytes

struct SndEvtHitPatch {
    int field_0;
    int field_4;
};

extern int g_zero;

void Construct_SndEvtHitPatch(SndEvtHitPatch* dst, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        dst++;
        dst[-1].field_0 = g_zero;
        dst[-1].field_4 = g_zero;
    } while (i-- != 0);
}
