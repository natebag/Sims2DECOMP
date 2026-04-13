// 0x8032FE7C ENgcMemoryCard::ENgcMemoryCard (32b)
// Pattern A+: Vtable + zero field + SDA

extern int ENgcMemoryCard_vtable[];

struct ENgcMemoryCard {
    int* m_vt;
    int m_field4;
    ENgcMemoryCard();
};

ENgcMemoryCard::ENgcMemoryCard() {
    ENgcMemoryCard* p = this;
    p->m_vt = (int*)ENgcMemoryCard_vtable;
    p->m_field4 = 0;
}
