/* cXObjectImpl::GetPlacementInfo(FTilePt *, int *, cXObject **, short *, bool *) at 0x800DCACC (132B) */

struct cXObjectImpl { void GetPlacementInfo(); };

__attribute__((naked))
void cXObjectImpl::GetPlacementInfo() {
    asm volatile(
        ".long 0x9421FFC8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF610024\n"
        ".long 0x9001003C\n"
        ".long 0x7C9E2378\n"
        ".long 0x7CFC3B78\n"
        ".long 0x7C641B78\n"
        ".long 0x7CBD2B78\n"
        ".long 0x7D1B4378\n"
        ".long 0x7CDF3378\n"
        ".long 0x38610008\n"
        ".long 0x480002C5\n"
        ".long 0x8121000C\n"
        ".long 0x81410010\n"
        ".long 0x38E00000\n"
        ".long 0x81010014\n"
        ".long 0x8161001C\n"
        ".long 0x913E0000\n"
        ".long 0x915E0004\n"
        ".long 0x2C080000\n"
        ".long 0x917D0000\n"
        ".long 0xA001001A\n"
        ".long 0xB01C0000\n"
        ".long 0x41820008\n"
        ".long 0x80E80004\n"
        ".long 0x80010008\n"
        ".long 0x90FF0000\n"
        ".long 0x901B0000\n"
        ".long 0x8001003C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB610024\n"
        ".long 0x38210038\n"
        ".long 0x4E800020\n"
    );
}
