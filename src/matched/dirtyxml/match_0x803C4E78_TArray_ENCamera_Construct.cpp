// 0x803C4E78 TArray<ENCamera>::Construct (76B)
// FLAGS: -fno-schedule-insns
extern void ElementCtor(void*);
struct Element { char pad[88]; };
void Construct(Element* dst, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        ElementCtor(dst);
        dst++;
    } while (i-- != 0);
}
