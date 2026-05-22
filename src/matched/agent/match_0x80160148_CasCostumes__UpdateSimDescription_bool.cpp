// 0x80160148 CasCostumes::UpdateSimDescription(bool, (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-344(1); mfspr 0,8; mfcr 12; stmw 27,0x144(1); stw 0,0x15c(1); stw 12,0x140(1); mr 28,3; mr 27,5; mr 31,6; cmpwi 4,4,0; addi 3,1,8; mfcr 30; rlwinm 30,30,19,31,31; bl _s80160148_0; addi 4,1,12; li 5,32; mr 3,27; bl _s80160148_1; rlwinm 30,30,4,0,27; addi 0,1,8; add 29,30,28; lwzx 4,30,28; lwz 5,0x4(29); lis 7,-32746; stw 0,0x138(1); addi 7,7,-2592; addi 3,1,304; addi 6,1,312; li 8,0; bl _s80160148_2; lwz 4,0x130(1); lwz 0,0x4(29); cmpw 4,0; beq 3f; lwz 30,0x0(4); mr 6,31; li 11,288; mr 9,30; 0:; lwz 0,0x0(6); addic. 11,11,-24; stw 0,0x0(9); lwz 0,0x4(6); stw 0,0x4(9); lwz 0,0x8(6); stw 0,0x8(9); lwz 0,0xc(6); stw 0,0xc(9); lwz 0,0x10(6); stw 0,0x10(9); lwz 0,0x14(6); addi 6,6,24; stw 0,0x14(9); addi 9,9,24; bne 0b; lwz 0,0x0(6); mr 3,27; addi 4,30,4; li 5,32; stw 0,0x0(9); bl _s80160148_3; beq cr4,1f; lis 3,-32706; addi 4,30,68; addi 3,3,-4564; li 5,32; bl _s80160148_4; b 2f; 1:; lis 3,-32706; addi 4,30,68; addi 3,3,-4556; li 5,32; bl _s80160148_5; 2:; li 0,0; li 3,1; stw 0,0x118(30); b 4f; 3:; li 3,0; 4:; lwz 0,0x15c(1); lwz 12,0x140(1); mtspr 8,0; lmw 27,0x144(1); mtcrf 8,12; addi 1,1,344"
extern "C" void _s80160148_0();
extern "C" void _s80160148_1();
extern "C" void _s80160148_2();
extern "C" void _s80160148_3();
extern "C" void _s80160148_4();
extern "C" void _s80160148_5();
extern "C" void f_80160148() {}
