// 0x803CA424 TArray<TArray<SndEvtHitPatch>, TArrayERSoundEventAllocator>::Copy (88B)
// FLAGS: -fno-schedule-insns
extern void copy_assign(void* dst, void* src);
struct Element { char pad[12]; };
void Copy(Element* dst, Element* src, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        copy_assign(dst, src);
        dst++;
        src++;
    } while (i-- != 0);
}
