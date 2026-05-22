// 0x802694AC AptPreloadAnimation(char (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); addi 30,1,8; mr 31,3; lwz 29,-23000(13); mr 3,30; bl _s802694AC_0; mr 4,29; mr 5,30; mr 3,31; bl _s802694AC_1; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802694AC_2; 0:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802694AC_0();
extern "C" void _s802694AC_1();
extern "C" void _s802694AC_2();
extern "C" void f_802694AC() {}
