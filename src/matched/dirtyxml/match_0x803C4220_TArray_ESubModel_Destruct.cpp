// 0x803C4220 TArray<ESubModel>::Destruct (80B)
// FLAGS: -fno-schedule-insns
extern void dtor(void*, int);
struct Element { char pad[24]; };
void Destruct(Element* ptr, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        dtor(ptr, 2);
        ptr++;
    } while (i-- != 0);
}
