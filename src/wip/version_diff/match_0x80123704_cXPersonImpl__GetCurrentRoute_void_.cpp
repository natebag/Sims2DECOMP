/* 0x80123704 (56B) cXPersonImpl::GetCurrentRoute(void) */

// Disassembly analysis:
// 8163040C   lwz r11, 0x040C(r3)
// 3D20C18F   lis r9, 0xC18F
// 80030410   lwz r0, 0x0410(r3)
// 61299C19   ori r9, r9, 0x9C19
// 7C0B0050   cmpw r11, r0
// 7C0049D6   mtctr r11
// 7C031671   and. r3, r0, r11
// 4082000C   bne +12
// 38600000   li r3, 0
// 4E800020   blr
// 3863FFFF   addi r3, r3, -1
// 1C6300A4   mulli r3, r3, 0xA4
// 7C6B1A14   add r3, r11, r3
// 4E800020   blr

struct cXPersonImpl_GCR {
    char pad[0x40C];
    void* m_currentRoute;
    void* m_routeEnd;

    void* GetCurrentRoute(void);
};

void* cXPersonImpl_GCR::GetCurrentRoute(void) {
    void* current = m_currentRoute;
    void* end = m_routeEnd;
    unsigned int magic = 0xC18F9C19;

    if (current == end) {
        return 0;
    }

    unsigned int index = (unsigned int)end & (unsigned int)current;
    index--;
    index *= 0xA4;

    return (void*)((unsigned int)current + index);
}
