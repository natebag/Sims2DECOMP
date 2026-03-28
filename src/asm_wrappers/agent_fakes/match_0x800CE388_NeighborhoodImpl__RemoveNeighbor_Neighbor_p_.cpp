/* NeighborhoodImpl::RemoveNeighbor(Neighbor *) at 0x800CE388 (128B) */

struct NeighborhoodImpl { void RemoveNeighbor(); };

__attribute__((naked))
void NeighborhoodImpl::RemoveNeighbor() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFA1000C\n"
        ".long 0x9001001C\n"
        ".long 0x7C9F2378\n"
        ".long 0x7C7D1B78\n"
        ".long 0xABDF0004\n"
        ".long 0x386000F6\n"
        ".long 0x7FC4F378\n"
        ".long 0x4BFE5F11\n"
        ".long 0x813D0074\n"
        ".long 0x3BDEFFFF\n"
        ".long 0x57DE103A\n"
        ".long 0x38000000\n"
        ".long 0x7C09F12E\n"
        ".long 0x7FE4FB78\n"
        ".long 0x813D0000\n"
        ".long 0xA8690100\n"
        ".long 0x80090104\n"
        ".long 0x7C7D1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x2C1F0000\n"
        ".long 0x41820010\n"
        ".long 0x7FE3FB78\n"
        ".long 0x38800003\n"
        ".long 0x4BFFA911\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBA1000C\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
