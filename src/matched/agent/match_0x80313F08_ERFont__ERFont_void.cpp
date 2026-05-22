// 0x80313F08 ERFont::ERFont(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80313F08_0; lis 9,-32697; addi 3,30,20; addi 9,9,-19400; stw 9,0x0(30); bl _s80313F08_1; lis 9,-32702; lis 11,-32702; lfs f0,0x6b0(9); li 0,0; lfs f13,0x6b4(11); addi 9,30,88; stw 0,0x54(30); li 11,-1; stfs f13,0x4c(30); mr 3,30; stfs f0,0x50(30); stfs f0,0x4(9); stfs f0,0xc(9); stfs f0,0x8(9); stfs f0,0x58(30); stw 11,0x68(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80313F08_0();
extern "C" void _s80313F08_1();
extern "C" void f_80313F08() {}
