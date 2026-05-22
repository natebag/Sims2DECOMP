// 0x8034FC40 ENgcTextureBase::ENgcTextureBase(unsigned (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 29,4; mr 28,5; mr 27,6; bl _s8034FC40_0; lis 9,-32697; addi 3,30,40; addi 9,9,-12264; stw 9,0x24(30); bl _s8034FC40_1; li 0,0; stw 29,0x70(30); stb 28,0x7c(30); mr 3,30; stb 27,0x7d(30); stw 0,0x90(30); stw 0,0x44(30); stw 0,0x68(30); stw 0,0x6c(30); stw 0,0x74(30); stw 0,0x78(30); stw 0,0x80(30); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8034FC40_0();
extern "C" void _s8034FC40_1();
extern "C" void f_8034FC40() {}
