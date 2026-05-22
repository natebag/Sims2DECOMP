// 0x8026B570 AptSetInputRoot(char (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr. 3,3; bne 0f; lwz 3,-23008(13); li 4,0; bl _s8026B570_0; b 5f; 0:; addi 30,1,8; mr 4,3; mr 3,30; bl _s8026B570_1; li 3,0; bl _s8026B570_2; mr 4,3; mr 6,30; lis 3,-32694; li 5,0; addi 3,3,-16032; li 7,1; li 8,1; li 9,0; bl _s8026B570_3; mr. 4,3; beq 2f; lwz 0,0x0(4); li 11,0; rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 1f; rlwinm 11,0,5,31,31; 1:; cmpwi 11,0; bne 4f; 2:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 3f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026B570_4; 3:; li 3,0; b 6f; 4:; lwz 3,-23008(13); bl _s8026B570_5; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 5f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026B570_6; 5:; li 3,1; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8026B570_0();
extern "C" void _s8026B570_1();
extern "C" void _s8026B570_2();
extern "C" void _s8026B570_3();
extern "C" void _s8026B570_4();
extern "C" void _s8026B570_5();
extern "C" void _s8026B570_6();
extern "C" void f_8026B570() {}
