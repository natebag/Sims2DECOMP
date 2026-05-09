// TArray<ECharacterNode, TArrayERCharacterAllocator>::Construct(ECharacterNode*, int) @ 0x803C9AE8 (92B)
// FLAGS: -fno-schedule-insns
// ECharacterNode element size = 184. Sub-objects at offset 4 (ctor at 0x803C9AB8) and offset 180 (ctor at 0x802D293C).
// Pre-decremented pointers (ptr-180, ptr-4) advanced by 184 at loop top.

extern "C" void ECharNode_sub1_ctor(char*);
extern "C" void ECharNode_sub2_ctor(char*);

void TArray_ECharacterNode_Construct(char* ptr, int count) {
    int i = count - 1;
    if (count == 0) return;
    char* p1 = ptr - 180;
    char* p2 = ptr - 4;
    do {
        p1 += 184;
        p2 += 184;
        ECharNode_sub1_ctor(p1);
        ECharNode_sub2_ctor(p2);
    } while (i--);
}
