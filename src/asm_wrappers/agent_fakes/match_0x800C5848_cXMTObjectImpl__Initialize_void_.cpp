/* cXMTObjectImpl::Initialize(void) at 0x800C5848 (132B) */

struct cXMTObjectImpl { void Initialize(); };

__attribute__((naked))
void cXMTObjectImpl::Initialize() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFC10008\n"
        ".long 0x90010014\n"
        ".long 0x7C7E1B78\n"
        ".long 0x807E0000\n"
        ".long 0x48014B79\n"
        ".long 0x813E0000\n"
        ".long 0x81490004\n"
        ".long 0x816A0004\n"
        ".long 0x800B0314\n"
        ".long 0xA86B0310\n"
        ".long 0x7C0803A6\n"
        ".long 0x7C6A1A14\n"
        ".long 0x4E800021\n"
        ".long 0x389E0010\n"
        ".long 0x38BE0014\n"
        ".long 0x48013BA5\n"
        ".long 0x813E0000\n"
        ".long 0x81490004\n"
        ".long 0x816A0004\n"
        ".long 0x800B0314\n"
        ".long 0xA86B0310\n"
        ".long 0x7C0803A6\n"
        ".long 0x7C6A1A14\n"
        ".long 0x4E800021\n"
        ".long 0xA8030070\n"
        ".long 0x901E0018\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBC10008\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
