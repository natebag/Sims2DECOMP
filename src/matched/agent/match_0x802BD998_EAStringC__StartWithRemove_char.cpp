// 0x802BD998 EAStringC::StartWithRemove(char (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,3; mr 30,4; mr 3,30; bl _s802BD998_0; mr 31,3; lwz 3,0x0(29); lhz 0,0x2(3); cmplw 0,31; blt 2f; addi 3,3,8; mr 4,30; mr 5,31; bl _s802BD998_1; cmpwi 3,0; bne 2f; mr 4,29; mr 5,31; addi 3,1,8; bl _s802BD998_2; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x0(29); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BD998_3; 0:; lwz 4,0x8(1); stw 4,0x0(29); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BD998_4; 1:; li 3,1; b 3f; 2:; li 3,0; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802BD998_0();
extern "C" void _s802BD998_1();
extern "C" void _s802BD998_2();
extern "C" void _s802BD998_3();
extern "C" void _s802BD998_4();
extern "C" void f_802BD998() {}
