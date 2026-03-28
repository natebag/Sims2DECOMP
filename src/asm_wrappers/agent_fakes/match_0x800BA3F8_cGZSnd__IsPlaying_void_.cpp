/* cGZSnd::IsPlaying(void) at 0x800BA3F8 (160B) */

struct cGZSnd { void IsPlaying(); };

__attribute__((naked))
void cGZSnd::IsPlaying() {
    asm volatile(
        ".long 0x9421FFE0\n"
        ".long 0x7C0802A6\n"
        ".long 0x90010024\n"
        ".long 0x8083001C\n"
        ".long 0x2C040000\n"
        ".long 0x41820034\n"
        ".long 0x38000000\n"
        ".long 0x816D983C\n"
        ".long 0x90010008\n"
        ".long 0x38A10008\n"
        ".long 0x812B0000\n"
        ".long 0xA86900A8\n"
        ".long 0x800900AC\n"
        ".long 0x7C6B1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x80610018\n"
        ".long 0x4800004C\n"
        ".long 0x81230018\n"
        ".long 0x2C090000\n"
        ".long 0x4182003C\n"
        ".long 0x8003000C\n"
        ".long 0x7C030378\n"
        ".long 0x2C000000\n"
        ".long 0x41820030\n"
        ".long 0x80090014\n"
        ".long 0x39200000\n"
        ".long 0x2C000000\n"
        ".long 0x41820014\n"
        ".long 0x2F80FFF0\n"
        ".long 0x4FFEE382\n"
        ".long 0x7D200026\n"
        ".long 0x552907FE\n"
        ".long 0x2C090000\n"
        ".long 0x41820008\n"
        ".long 0x38600000\n"
        ".long 0x80010024\n"
        ".long 0x7C0803A6\n"
        ".long 0x38210020\n"
        ".long 0x4E800020\n"
    );
}
