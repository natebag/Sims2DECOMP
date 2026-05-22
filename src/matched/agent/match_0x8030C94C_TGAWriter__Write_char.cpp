// 0x8030C94C TGAWriter::Write(char (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 23,0x14(1); stw 0,0x3c(1); mr 29,3; mr 30,4; mr 25,6; mr 23,7; mr 24,8; mr. 31,5; beq 0f; cmpwi 30,0; beq 0f; mr 3,30; bl _s8030C94C_0; cmpwi 3,0; bne 1f; 0:; li 3,0; b 6f; 1:; li 0,0; mr 3,31; stw 0,0xc(1); li 28,0; stw 0,0x8(1); bl _s8030C94C_1; lbz 0,0x19(31); mr 26,3; cmpwi 0,0; beq 2f; li 28,1; 2:; lwz 9,0x24(31); li 4,1; li 27,0; lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 28,0; beq 3f; lwz 9,0x24(31); lha 3,0x48(9); lwz 0,0x4c(9); add 3,31,3; mtspr 8,0; blrl; mr 27,3; 3:; lwz 9,0x24(31); addi 5,1,8; addi 6,1,12; li 4,0; lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,31,3; blrl; mr 5,3; mr 7,31; mr 4,30; mr 6,27; mr 3,29; bl _s8030C94C_2; mr 3,29; bl _s8030C94C_3; lwz 9,0x24(31); lha 3,0x70(9); lwz 0,0x74(9); add 3,31,3; mtspr 8,0; blrl; mr 3,31; mr 4,26; bl _s8030C94C_4; cmpwi 25,0; beq 4f; mr 4,24; mr 3,29; bl _s8030C94C_5; 4:; cmpwi 23,0; beq 5f; mr 3,29; bl _s8030C94C_6; 5:; li 3,1; 6:; lwz 0,0x3c(1); mtspr 8,0; lmw 23,0x14(1); addi 1,1,56"
extern "C" void _s8030C94C_0();
extern "C" void _s8030C94C_1();
extern "C" void _s8030C94C_2();
extern "C" void _s8030C94C_3();
extern "C" void _s8030C94C_4();
extern "C" void _s8030C94C_5();
extern "C" void _s8030C94C_6();
extern "C" void f_8030C94C() {}
