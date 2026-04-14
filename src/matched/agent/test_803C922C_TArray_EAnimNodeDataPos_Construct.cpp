// FLAGS: -fno-schedule-insns

extern int EAnimNodeDataPos_vtable;

void Construct_EAnimNodeDataPos(char* dst, int count) {
    int i = count - 1;
    if (count == 0) return;
    int vtable = (int)&EAnimNodeDataPos_vtable;
    dst += 36;
    do {
        *(int*)(dst - 36) = vtable;
        *(int*)(dst - 4) = 0;
    } while (i-- != 0);
}
