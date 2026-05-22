// 0x8000D5BC AptWord::SetWord(unsigned (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); lwz 9,0x4(6); mr 28,3; lwz 0,0x0(6); mr 29,5; stw 9,0x20(28); mr 27,4; stw 0,0x1c(28); lwz 31,0x8(28); bl _s8000D5BC_0; addi 4,29,1; li 5,0; rlwinm 4,4,1,0,30; bl _s8000D5BC_1; mr 30,3; mr 5,29; mr 4,27; bl _s8000D5BC_2; li 0,0; add 29,29,29; sthx 0,29,30; mr 5,30; stw 30,0x8(28); addi 3,1,8; lwz 4,-32708(13); li 6,1; li 7,0; li 8,0; bl _s8000D5BC_3; lwz 9,0x8(1); cmpwi 31,0; lwz 0,0xc(1); stw 9,0x24(28); stw 0,0x28(28); beq 0f; bl _s8000D5BC_4; mr 4,31; bl _s8000D5BC_5; 0:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8000D5BC_0();
extern "C" void _s8000D5BC_1();
extern "C" void _s8000D5BC_2();
extern "C" void _s8000D5BC_3();
extern "C" void _s8000D5BC_4();
extern "C" void _s8000D5BC_5();
extern "C" void f_8000D5BC() {}
