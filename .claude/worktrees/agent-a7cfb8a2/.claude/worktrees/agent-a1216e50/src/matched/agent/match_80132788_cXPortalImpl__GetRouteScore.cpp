// 0x80132788 (64 bytes)
// cXPortalImpl::GetRouteScore(short)

class cXPortalImpl { public: void GetRouteScore(short); };

__attribute__((naked))
void cXPortalImpl::GetRouteScore(short) {
    asm volatile(".long 0x7C842379\n.long 0x40810030\n.long 0x81630008\n.long 0x5489043E\n.long 0x8003000C\n.long 0x7C0B0050\n.long 0x7C001670\n.long 0x7C090040\n.long 0x41810014\n.long 0x3924FFFF\n.long 0x5529103A\n.long 0x7C2B4C2E\n.long 0x4E800020\n.long 0x3D20803E\n.long 0xC029D02C\n.long 0x4E800020");
}
