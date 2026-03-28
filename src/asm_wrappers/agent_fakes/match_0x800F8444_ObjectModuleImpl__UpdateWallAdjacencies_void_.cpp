/* ObjectModuleImpl::UpdateWallAdjacencies(void) at 0x800F8444 (148B) */

struct ObjectModuleImpl { void UpdateWallAdjacencies(); };

__attribute__((naked))
void ObjectModuleImpl::UpdateWallAdjacencies() {
    asm volatile(
        ".long 0x9421FFF0\n"
        ".long 0x7C0802A6\n"
        ".long 0x93E1000C\n"
        ".long 0x90010014\n"
        ".long 0x83E3002C\n"
        ".long 0x2C1F0000\n"
        ".long 0x41820068\n"
        ".long 0x817F0004\n"
        ".long 0x812B0004\n"
        ".long 0x800901CC\n"
        ".long 0xA86901C8\n"
        ".long 0x7C0803A6\n"
        ".long 0x7C6B1A14\n"
        ".long 0x4E800021\n"
        ".long 0x81230000\n"
        ".long 0x38800006\n"
        ".long 0xA8090070\n"
        ".long 0x81290074\n"
        ".long 0x7C630214\n"
        ".long 0x7D2803A6\n"
        ".long 0x4E800021\n"
        ".long 0x2C030000\n"
        ".long 0x38000001\n"
        ".long 0x40820008\n"
        ".long 0x38000000\n"
        ".long 0x2C000000\n"
        ".long 0x4182000C\n"
        ".long 0x7FE3FB78\n"
        ".long 0x4BFE90E1\n"
        ".long 0x83FF005C\n"
        ".long 0x2C1F0000\n"
        ".long 0x4082FFA0\n"
        ".long 0x80010014\n"
        ".long 0x7C0803A6\n"
        ".long 0x83E1000C\n"
        ".long 0x38210010\n"
        ".long 0x4E800020\n"
    );
}
