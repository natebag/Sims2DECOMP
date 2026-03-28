/* ObjectModuleImpl::GetPersonByGUID(int) at 0x800F4A14 (156B) */

struct ObjectModuleImpl { void GetPersonByGUID(); };

__attribute__((naked))
void ObjectModuleImpl::GetPersonByGUID() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFA1000C\n"
        ".long 0x9001001C\n"
        ".long 0x39232058\n"
        ".long 0x83E32058\n"
        ".long 0x80090004\n"
        ".long 0x7C9D2378\n"
        ".long 0x7C1F0000\n"
        ".long 0x41820060\n"
        ".long 0x7D3E4B78\n"
        ".long 0x813F0000\n"
        ".long 0x81690000\n"
        ".long 0x814B0004\n"
        ".long 0x812A0004\n"
        ".long 0xA8690368\n"
        ".long 0x8009036C\n"
        ".long 0x7C6A1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x4801BE79\n"
        ".long 0x7C03E800\n"
        ".long 0x4082001C\n"
        ".long 0x813F0000\n"
        ".long 0x38600000\n"
        ".long 0x2C090000\n"
        ".long 0x41820020\n"
        ".long 0x80690004\n"
        ".long 0x48000018\n"
        ".long 0x801E0004\n"
        ".long 0x3BFF0004\n"
        ".long 0x7C1F0000\n"
        ".long 0x4082FFAC\n"
        ".long 0x38600000\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBA1000C\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
