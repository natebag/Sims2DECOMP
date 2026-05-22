// 0x80196CA8 CASBodyTarget::HandleHairSubnav(int) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); cmpwi 4,1; bne 0f; lis 29,-32698; addi 30,1,8; lwz 3,0x84(3); addi 29,29,25096; stw 29,0x4(30); li 0,4; stw 0,0x8(1); li 9,0; li 0,18; mr 4,30; stw 0,0x8(30); stw 9,0x14(30); stw 9,0xc(30); stw 9,0x10(30); bl _s80196CA8_0; stw 29,0x4(30); mr 3,30; li 4,2; bl _s80196CA8_1; b 1f; 0:; lis 29,-32698; addi 30,1,8; lwz 3,0x84(3); addi 29,29,25096; stw 29,0x4(30); li 0,4; stw 0,0x8(1); li 11,0; li 0,18; li 9,1; mr 4,30; stw 0,0x8(30); stw 9,0xc(30); stw 11,0x14(30); stw 11,0x10(30); bl _s80196CA8_2; stw 29,0x4(30); mr 3,30; li 4,2; bl _s80196CA8_3; 1:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s80196CA8_0();
extern "C" void _s80196CA8_1();
extern "C" void _s80196CA8_2();
extern "C" void _s80196CA8_3();
extern "C" void f_80196CA8() {}
