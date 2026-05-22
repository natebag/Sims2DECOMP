// 0x80363B28 EFontSize::EFontSize(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 30,3; addi 9,9,-9928; li 4,237; stw 9,0x0(30); addi 3,30,16; bl _s80363B28_0; addi 3,30,32; bl _s80363B28_1; li 9,0; li 0,1; stw 9,0x4(30); mr 3,30; stw 0,0xc(30); stw 9,0x8(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80363B28_0();
extern "C" void _s80363B28_1();
extern "C" void f_80363B28() {}
