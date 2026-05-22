// 0x800AD670 cBoxX::cBoxX(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); lis 9,-32698; mr 29,3; li 30,0; addi 9,9,-5864; li 0,1; addi 28,29,32; stw 9,0x78(29); li 3,24; stw 0,0x4(29); stw 30,0x8(29); stw 30,0xc(29); stw 30,0x10(29); stw 30,0x14(29); stw 30,0x18(29); stw 30,0x4(28); bl _s800AD670_0; mr 9,3; stw 30,0x8(28); stw 9,0x4(28); addi 3,29,48; stb 30,0xc(28); stw 30,0x0(9); lwz 11,0x4(28); stw 30,0x4(11); lwz 9,0x4(28); stw 9,0x8(9); lwz 11,0x4(28); stw 11,0xc(11); bl _s800AD670_1; stw 30,0x74(29); mr 3,29; stw 30,0x64(29); stw 30,0x68(29); stw 30,0x6c(29); stw 30,0x70(29); stw 29,-24508(13); lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s800AD670_0();
extern "C" void _s800AD670_1();
extern "C" void f_800AD670() {}
