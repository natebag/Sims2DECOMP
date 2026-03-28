/* cXMTObjectImpl::PostLoad(int, bool) at 0x800C6DAC (152B) */

struct cXMTObjectImpl { void PostLoad(); };

__attribute__((naked))
void cXMTObjectImpl::PostLoad() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFC10008\n"
        ".long 0x90010014\n"
        ".long 0x7C7F1B78\n"
        ".long 0x7C9E2378\n"
        ".long 0x807F0000\n"
        ".long 0x48013FF5\n"
        ".long 0x2C1E0039\n"
        ".long 0x41810020\n"
        ".long 0x807F0004\n"
        ".long 0x81230004\n"
        ".long 0xA8090028\n"
        ".long 0x8129002C\n"
        ".long 0x7C630214\n"
        ".long 0x7D2803A6\n"
        ".long 0x4E800021\n"
        ".long 0x807F0004\n"
        ".long 0x81230004\n"
        ".long 0xA8090040\n"
        ".long 0x81290044\n"
        ".long 0x7C630214\n"
        ".long 0x7D2803A6\n"
        ".long 0x4E800021\n"
        ".long 0x2C030000\n"
        ".long 0x41820020\n"
        ".long 0x807F0004\n"
        ".long 0x81230004\n"
        ".long 0xA8090048\n"
        ".long 0x8129004C\n"
        ".long 0x7C630214\n"
        ".long 0x7D2803A6\n"
        ".long 0x4E800021\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBC10008\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
