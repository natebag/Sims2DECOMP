/* NeighborhoodImpl::NotifyAllNeighbors(WantFear::Notification &, Neighbor *) at 0x800D13D4 (152B) */

struct NeighborhoodImpl { void NotifyAllNeighbors(); };

__attribute__((naked))
void NeighborhoodImpl::NotifyAllNeighbors() {
    asm volatile(
        ".long 0x9421FFD8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF610014\n"
        ".long 0x9001002C\n"
        ".long 0x39230074\n"
        ".long 0x83E30074\n"
        ".long 0x80090004\n"
        ".long 0x7C9B2378\n"
        ".long 0x7CBC2B78\n"
        ".long 0x3BC00000\n"
        ".long 0x7C1F0000\n"
        ".long 0x41820054\n"
        ".long 0x7D3D4B78\n"
        ".long 0x807F0000\n"
        ".long 0x2C030000\n"
        ".long 0x41820034\n"
        ".long 0x7C03E000\n"
        ".long 0x4182002C\n"
        ".long 0x7F64DB78\n"
        ".long 0x38A00001\n"
        ".long 0x4BFF98ED\n"
        ".long 0x7C601B78\n"
        ".long 0x7FC3F378\n"
        ".long 0x7C030000\n"
        ".long 0x40800008\n"
        ".long 0x7C030378\n"
        ".long 0x90610008\n"
        ".long 0x7C7E1B78\n"
        ".long 0x801D0004\n"
        ".long 0x3BFF0004\n"
        ".long 0x7C1F0000\n"
        ".long 0x4082FFB8\n"
        ".long 0x7FC3F378\n"
        ".long 0x8001002C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB610014\n"
        ".long 0x38210028\n"
        ".long 0x4E800020\n"
    );
}
