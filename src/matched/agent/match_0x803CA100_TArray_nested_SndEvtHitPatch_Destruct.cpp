// 0x803CA100 TArray<nested_SndEvtHitPatch>::Destruct (80B)
// FLAGS: -fno-schedule-insns
extern void dtor(void*, int);
struct Element { char pad[12]; };
void Destruct(Element* ptr, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        dtor(ptr, 2);
        ptr++;
    } while (i-- != 0);
}
