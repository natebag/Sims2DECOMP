/* cXObjectImpl::Error(short) at 0x800EBA98 (152B) */

struct cXObjectImpl { void Error(); };

__attribute__((naked))
void cXObjectImpl::Error() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFA1000C\n"
        ".long 0x9001001C\n"
        ".long 0x7C7D1B78\n"
        ".long 0x38800100\n"
        ".long 0x817D0004\n"
        ".long 0x38A00001\n"
        ".long 0x812B0004\n"
        ".long 0x80090074\n"
        ".long 0xA8690070\n"
        ".long 0x7C0803A6\n"
        ".long 0x7C6B1A14\n"
        ".long 0x4E800021\n"
        ".long 0x815D0004\n"
        ".long 0x83DD0058\n"
        ".long 0x812A0004\n"
        ".long 0x817E0000\n"
        ".long 0xA8690328\n"
        ".long 0x8129032C\n"
        ".long 0x3BAB0240\n"
        ".long 0x7C6A1A14\n"
        ".long 0xA80B0240\n"
        ".long 0x7D2803A6\n"
        ".long 0x7FDE0214\n"
        ".long 0x4E800021\n"
        ".long 0x801D0004\n"
        ".long 0x7C641B78\n"
        ".long 0x7FC3F378\n"
        ".long 0x38A00004\n"
        ".long 0x38C00001\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBA1000C\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
