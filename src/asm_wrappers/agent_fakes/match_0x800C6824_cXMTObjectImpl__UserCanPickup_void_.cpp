/* cXMTObjectImpl::UserCanPickup(void) at 0x800C6824 (148B) */

struct cXMTObjectImpl { void UserCanPickup(); };

__attribute__((naked))
void cXMTObjectImpl::UserCanPickup() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0x93E1000C\n"
        ".long 0x90010014\n"
        ".long 0x80630004\n"
        ".long 0x81230004\n"
        ".long 0xA8090010\n"
        ".long 0x81290014\n"
        ".long 0x7C630214\n"
        ".long 0x7D2803A6\n"
        ".long 0x48000048\n"
        ".long 0x813F0004\n"
        ".long 0xA8690058\n"
        ".long 0x8009005C\n"
        ".long 0x7C7F1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x80630000\n"
        ".long 0x4801B289\n"
        ".long 0x2C030000\n"
        ".long 0x4082000C\n"
        ".long 0x38600000\n"
        ".long 0x48000028\n"
        ".long 0x813F0004\n"
        ".long 0xA8690018\n"
        ".long 0x8009001C\n"
        ".long 0x7C7F1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x7C7F1B79\n"
        ".long 0x4082FFB4\n"
        ".long 0x38600001\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0x83E1000C\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
