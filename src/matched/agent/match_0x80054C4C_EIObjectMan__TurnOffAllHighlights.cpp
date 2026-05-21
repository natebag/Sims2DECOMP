// 0x80054C4C EIObjectMan::TurnOffAllHighlights(unsigned int) (84B)

class EIObjectMan {
public:
    char pad[4];
    void* m_4;
    void TurnOffAllHighlights(unsigned int type);
};

void EIObjectMan::TurnOffAllHighlights(unsigned int type) {
    unsigned int mask = 0;
    if (type == 0) goto cs0;
    if (type == 1) goto cs1;
    goto loop_setup;
cs0:
    mask = 5;
    goto loop_setup;
cs1:
    mask = 0x28;
loop_setup:
    char* p = (char*)m_4;
    if (p == 0) return;
    unsigned int inv_mask = ~mask;
    do {
        char* x = *(char**)(p + 0x1C);
        unsigned int v = *(unsigned int*)(x + 0x32C);
        *(unsigned int*)(x + 0x32C) = v & inv_mask;
        p = *(char**)(p + 0x10);
    } while (p != 0);
}
