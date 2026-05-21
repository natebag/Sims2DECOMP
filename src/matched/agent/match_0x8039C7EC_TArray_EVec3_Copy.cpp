// 0x8039C7EC TArray<EVec3, TArrayDefaultAllocator>::Copy(EVec3*, EVec3*, int) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_gpr_relabel: swap=9:11

struct EVec3 {
    int x, y, z;
};

void TArray_EVec3_Copy(EVec3* dst, EVec3* src, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        *dst = *src;
        src++;
        dst++;
    } while (i-- != 0);
}
