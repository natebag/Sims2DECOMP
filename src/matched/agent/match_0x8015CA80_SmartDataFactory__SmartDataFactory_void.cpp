// 0x8015CA80 SmartDataFactory::SmartDataFactory(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); lis 9,-32698; mr 28,3; addi 9,9,23328; addi 30,28,4; li 29,0; stw 9,0x0(28); stw 29,0x4(30); li 3,32; bl _s8015CA80_0; mr 9,3; stw 29,0x8(30); stw 9,0x4(30); mr 3,28; stb 29,0xc(30); stw 29,0x0(9); lwz 11,0x4(30); stw 29,0x4(11); lwz 9,0x4(30); stw 9,0x8(9); lwz 11,0x4(30); stw 11,0xc(11); stw 29,0x14(28); lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s8015CA80_0();
extern "C" void f_8015CA80() {}
