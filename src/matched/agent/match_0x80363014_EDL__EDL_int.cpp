// 0x80363014 EDL::EDL(int) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 30,3; addi 9,9,-10040; mr 29,4; stw 9,0x64(30); bl _s80363014_0; mr 4,29; addi 3,30,24; bl _s80363014_1; li 0,0; addi 9,30,48; stw 0,0x4(9); li 10,1; stw 0,0x30(30); addi 11,30,60; stw 10,0x8(9); mr 3,30; stw 0,0x4(11); stw 0,0x3c(30); stw 10,0x8(11); stw 0,0x4c(30); stw 0,0x48(30); stw 0,0x50(30); stw 0,0x54(30); stw 0,0x5c(30); stw 0,0x58(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80363014_0();
extern "C" void _s80363014_1();
extern "C" void f_80363014() {}
