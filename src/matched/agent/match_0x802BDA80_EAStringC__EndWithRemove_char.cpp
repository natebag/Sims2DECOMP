// 0x802BDA80 EAStringC::EndWithRemove(char (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 28,3; mr 29,4; lwz 9,0x0(28); mr 3,29; lhz 30,0x2(9); bl _s802BDA80_0; mr 31,3; cmplw 30,31; li 3,0; blt 3f; lwz 3,0x0(28); mr 4,29; mr 5,31; addi 3,3,8; add 3,3,30; subf 3,31,3; bl _s802BDA80_1; cmpwi 3,0; bne 2f; mr 4,28; subf 5,31,30; addi 3,1,8; bl _s802BDA80_2; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x0(28); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BDA80_3; 0:; lwz 4,0x8(1); stw 4,0x0(28); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BDA80_4; 1:; li 3,1; b 3f; 2:; li 3,0; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s802BDA80_0();
extern "C" void _s802BDA80_1();
extern "C" void _s802BDA80_2();
extern "C" void _s802BDA80_3();
extern "C" void _s802BDA80_4();
extern "C" void f_802BDA80() {}
