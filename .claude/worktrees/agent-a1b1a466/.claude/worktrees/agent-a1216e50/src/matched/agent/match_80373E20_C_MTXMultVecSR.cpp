// 0x80373E20 (124 bytes)
// C_MTXMultVecSR

__attribute__((naked))
void C_MTXMultVecSR() {
    asm volatile(".long 0xC1440000\n.long 0xC0030000\n.long 0xC0430010\n.long 0xC1240004\n.long 0xEC2002B2\n.long 0xC0030004\n.long 0xECE202B2\n.long 0xC0430014\n.long 0xEC000272\n.long 0xECC20272\n.long 0xC0830020\n.long 0xC0630024\n.long 0xC1640008\n.long 0xC0430008\n.long 0xC1030018\n.long 0xEC01002A\n.long 0xEC2202F2\n.long 0xC0A30028\n.long 0xEC8402B2\n.long 0xEC430272\n.long 0xEC01002A\n.long 0xED0802F2\n.long 0xEC67302A\n.long 0xEC2502F2\n.long 0xD0050000\n.long 0xEC04102A\n.long 0xEC48182A\n.long 0xEC01002A\n.long 0xD0450004\n.long 0xD0050008\n.long 0x4E800020");
}
