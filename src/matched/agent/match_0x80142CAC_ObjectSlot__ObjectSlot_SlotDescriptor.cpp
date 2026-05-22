// 0x80142CAC ObjectSlot::ObjectSlot(SlotDescriptor (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s80142CAC_0; lis 9,-32698; li 0,0; addi 9,9,18960; mr 3,30; stw 9,0x0(30); lfs f0,0x4(29); stfs f0,0x14(30); lfs f13,0x8(29); stfs f13,0x18(30); lfs f0,0xc(29); sth 0,0x4(30); stfs f0,0x1c(30); lwz 0,0x10(29); stw 0,0xc(30); lwz 9,0x14(29); stw 9,0x10(30); lwz 4,0x18(29); bl _s80142CAC_1; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80142CAC_0();
extern "C" void _s80142CAC_1();
extern "C" void f_80142CAC() {}
