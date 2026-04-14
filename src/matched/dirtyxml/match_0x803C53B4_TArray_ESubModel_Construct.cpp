// 0x803C53B4 TArray<ESubModel>::Construct (76B)
// FLAGS: -fno-schedule-insns
extern void ElementCtor(void*);
struct Element { char pad[24]; };
void Construct(Element* dst, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        ElementCtor(dst);
        dst++;
    } while (i-- != 0);
}
