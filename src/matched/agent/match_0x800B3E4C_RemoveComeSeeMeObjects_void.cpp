// 0x800B3E4C RemoveComeSeeMeObjects(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 31,-21484(13); bl _s800B3E4C_0; mr 28,3; 0:; lwz 9,0x0(31); lha 3,0x98(9); lwz 0,0x9c(9); add 3,31,3; b 3f; 1:; lwz 9,0x4(30); lha 3,0x368(9); lwz 0,0x36c(9); add 3,30,3; mtspr 8,0; blrl; cmpw 3,28; bne 2f; lwz 9,0x4(30); lwz 11,0x0(31); lwz 0,0x32c(9); lha 3,0x328(9); addi 29,11,88; mtspr 8,0; add 3,30,3; lha 30,0x58(11); add 30,31,30; blrl; lwz 0,0x4(29); mr 4,3; mr 3,30; mtspr 8,0; blrl; b 0b; 2:; lwz 9,0x4(30); lha 3,0x490(9); lwz 0,0x494(9); add 3,30,3; 3:; mtspr 8,0; blrl; mr. 30,3; bne 1b; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800B3E4C_0();
extern "C" void f_800B3E4C() {}
