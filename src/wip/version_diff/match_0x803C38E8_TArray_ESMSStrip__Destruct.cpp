// FLAGS: -fno-schedule-insns
/* TArray<ESMSStrip, TArrayERModelAllocator>::Destruct(ESMSStrip *, int) at 0x803C38E8 (28B) */

struct ESMSStrip {};

static void Destruct_ESMSStrip(ESMSStrip* /*ptr*/, int count) {
    int n = count - 1;
    if (!count) return;
    while (n--) {}
}
