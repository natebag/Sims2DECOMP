/* NeighborhoodImpl::RemoveNeighborRelationships(Neighbor *) at 0x800CE300 (136B) */

struct NeighborhoodImpl { void RemoveNeighborRelationships(); };

__attribute__((naked))
void NeighborhoodImpl::RemoveNeighborRelationships() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF810008\n"
        ".long 0x9001001C\n"
        ".long 0x39230074\n"
        ".long 0x83E30074\n"
        ".long 0x80090004\n"
        ".long 0x7C9C2378\n"
        ".long 0xABBC0004\n"
        ".long 0x7C1F0000\n"
        ".long 0x41820044\n"
        ".long 0x7D3E4B78\n"
        ".long 0x807F0000\n"
        ".long 0x2C030000\n"
        ".long 0x41820024\n"
        ".long 0x4BFFAD79\n"
        ".long 0x81230000\n"
        ".long 0x7FA4EB78\n"
        ".long 0xA8090030\n"
        ".long 0x81290034\n"
        ".long 0x7C630214\n"
        ".long 0x7D2803A6\n"
        ".long 0x4E800021\n"
        ".long 0x801E0004\n"
        ".long 0x3BFF0004\n"
        ".long 0x7C1F0000\n"
        ".long 0x4082FFC8\n"
        ".long 0x7F83E378\n"
        ".long 0x4BFFC161\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB810008\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
