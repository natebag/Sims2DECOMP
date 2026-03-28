/* cXMTObjectImpl::SetLeader(cXMTObject *) at 0x800C58CC (140B) */

struct cXMTObjectImpl { void SetLeader(); };

__attribute__((naked))
void cXMTObjectImpl::SetLeader() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0x93E1000C\n"
        ".long 0x90010014\n"
        ".long 0x7C7F1B78\n"
        ".long 0x7C842379\n"
        ".long 0x41820020\n"
        ".long 0x81240004\n"
        ".long 0xA8690058\n"
        ".long 0x8009005C\n"
        ".long 0x7C641A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x48000008\n"
        ".long 0x38600000\n"
        ".long 0x38000000\n"
        ".long 0x907F000C\n"
        ".long 0x901F0008\n"
        ".long 0x2C030000\n"
        ".long 0x4182002C\n"
        ".long 0x80030008\n"
        ".long 0x38630008\n"
        ".long 0x2C000000\n"
        ".long 0x41820018\n"
        ".long 0x81230000\n"
        ".long 0x80090008\n"
        ".long 0x38690008\n"
        ".long 0x2C000000\n"
        ".long 0x4082FFF0\n"
        ".long 0x93E30000\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0x83E1000C\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
