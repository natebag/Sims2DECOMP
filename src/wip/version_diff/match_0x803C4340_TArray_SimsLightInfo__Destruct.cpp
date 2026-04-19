/* TArray<SimsLightInfo, TArrayERModelAllocator>::Destruct(SimsLightInfo *, int) at 0x803C4340 (28B) */

struct SimsLightInfo_D {};

static void Destruct_SimsLightInfo(SimsLightInfo_D* /*ptr*/, int count) {
    int n = count - 1;
    if (!count) return;
    while (n--) {}
}
