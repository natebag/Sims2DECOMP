// 0x8039C784 TArray<ENLatticePoints, TArrayDefaultAllocator>::Construct(ENLatticePoints*, int) (76 B)
// FLAGS: -fno-schedule-insns

extern void EVec3_Ctor(void*);
struct ENLatticePoints { char pad[12]; };

void TArray_ENLatticePoints_Construct(ENLatticePoints* dst, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        EVec3_Ctor(dst);
        dst++;
    } while (i-- != 0);
}
