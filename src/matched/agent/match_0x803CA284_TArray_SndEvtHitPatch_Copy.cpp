// FLAGS: -fno-schedule-insns
// TArray<SndEvtHitPatch, TArrayERSoundEventAllocator>::Copy(SndEvtHitPatch *, SndEvtHitPatch *, int)
// Address: 0x803CA284 | Size: 52 bytes

void Copy_SndEvtHitPatch(int dst[][2], int src[][2], int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        (*dst)[0] = (*src)[0];
        (*dst)[1] = (*src)[1];
        src++;
        dst++;
    } while (i-- != 0);
}
