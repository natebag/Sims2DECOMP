// 0x80142C40 ObjectSlot::ObjectSlot(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80142C40_0; lis 11,-32706; lis 9,-32698; lfs f0,-10516(11); li 10,0; addi 9,9,18960; li 0,0; li 11,50; stw 9,0x0(30); stfs f0,0x1c(30); mr 3,30; sth 0,0x4(30); stw 11,0xc(30); stw 10,0x8(30); stfs f0,0x14(30); stfs f0,0x18(30); stw 10,0x10(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80142C40_0();
extern "C" void f_80142C40() {}
