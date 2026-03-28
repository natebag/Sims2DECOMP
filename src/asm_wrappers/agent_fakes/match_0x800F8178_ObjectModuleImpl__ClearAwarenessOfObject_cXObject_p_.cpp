/* ObjectModuleImpl::ClearAwarenessOfObject(cXObject *) at 0x800F8178 (156B) */

struct ObjectModuleImpl { void ClearAwarenessOfObject(); };

__attribute__((naked))
void ObjectModuleImpl::ClearAwarenessOfObject() {
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
        ".long 0x41820064\n"
        ".long 0x7D3E4B78\n"
        ".long 0x813F0000\n"
        ".long 0x39600000\n"
        ".long 0x2C090000\n"
        ".long 0x4182001C\n"
        ".long 0x81690004\n"
        ".long 0x38800002\n"
        ".long 0x812B0000\n"
        ".long 0x80690000\n"
        ".long 0x4BFFA9E1\n"
        ".long 0x7C6B1B78\n"
        ".long 0x2C0B0000\n"
        ".long 0x41820020\n"
        ".long 0x812B0004\n"
        ".long 0x7FA4EB78\n"
        ".long 0xA86902F8\n"
        ".long 0x800902FC\n"
        ".long 0x7C6B1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x801E0004\n"
        ".long 0x3BFF0004\n"
        ".long 0x7C1F0000\n"
        ".long 0x4082FFA8\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBA1000C\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
