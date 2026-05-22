// 0x8038C8B0 GXReadBoundingBox (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 7,-21992(13); lhz 0,0x10(7); sth 0,0x0(3); lwz 3,-21992(13); lhz 0,0x14(3); sth 0,0x0(4); lwz 3,-21992(13); lhz 0,0x12(3); sth 0,0x0(5); lwz 3,-21992(13); lhz 0,0x16(3); sth 0,0x0(6)"
extern "C" void f_8038C8B0() {}
