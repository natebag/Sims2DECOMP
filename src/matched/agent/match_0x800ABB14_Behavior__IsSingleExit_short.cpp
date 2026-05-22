// 0x800ABB14 Behavior::IsSingleExit(short, (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; addi 6,1,8; bl _s800ABB14_0; cmpwi 3,0; beq 6f; lhz 0,0x8(1); rlwinm 4,0,0,17,31; cmpwi 4,255; bgt 0f; lwz 3,0x8(31); addi 4,1,8; lwz 9,0x0(3); lha 0,0x30(9); lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; b 7f; 0:; li 0,0; mr 3,31; stw 0,0x18(1); addi 5,1,24; li 6,1; bl _s800ABB14_1; cmpwi 3,0; beq 5f; lwz 3,0x18(1); li 31,0; bl _s800ABB14_2; mr 30,3; cmpw 31,30; bge 5f; 1:; lwz 3,0x18(1); mr 4,31; bl _s800ABB14_3; lbz 0,0x2(3); cmpwi 0,255; beq 2f; lwz 3,0x18(1); mr 4,31; bl _s800ABB14_4; lbz 0,0x3(3); cmpwi 0,255; bne 4f; 2:; lwz 11,0x18(1); cmpwi 11,0; beq 3f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 3:; li 3,0; b 7f; 4:; addi 31,31,1; cmpw 31,30; blt 1b; 5:; lwz 11,0x18(1); cmpwi 11,0; beq 6f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 6:; li 3,1; 7:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s800ABB14_0();
extern "C" void _s800ABB14_1();
extern "C" void _s800ABB14_2();
extern "C" void _s800ABB14_3();
extern "C" void _s800ABB14_4();
extern "C" void f_800ABB14() {}
