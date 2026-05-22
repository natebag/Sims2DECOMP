// 0x802693E8 AptLoadAnimation(char (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 30,3; addi 3,1,8; bl _s802693E8_0; lwz 11,0x8(1); li 0,0; mr 4,30; stw 0,-23004(13); stw 11,0x10(1); addi 3,1,24; lwz 30,-22996(13); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); bl _s802693E8_1; addi 4,1,24; mr 3,30; addi 5,1,16; bl _s802693E8_2; lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802693E8_3; 0:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802693E8_4; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s802693E8_0();
extern "C" void _s802693E8_1();
extern "C" void _s802693E8_2();
extern "C" void _s802693E8_3();
extern "C" void _s802693E8_4();
extern "C" void f_802693E8() {}
