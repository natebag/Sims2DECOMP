// 0x8015597C XRoute::BuildGoalList(void) (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; mfcr 12; stmw 29,0xc(1); stw 0,0x1c(1); stw 12,0x8(1); mr 29,3; bl _s8015597C_0; lwz 3,0x50(29); cmpwi 3,0; beq 0f; lwz 3,0x0(3); li 4,2; bl _s8015597C_1; mr 31,3; b 1f; 0:; li 31,0; 1:; cmpwi 4,31,0; beq cr4,2f; bl _s8015597C_2; lwz 11,0x0(31); mr 30,3; lwz 9,0x4(11); lha 3,0x308(9); lwz 0,0x30c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 3,30; bl _s8015597C_3; mr. 3,3; beq 2f; bl _s8015597C_4; cmpwi 3,250; ble 2f; li 0,8; stw 0,0xa0(29); 2:; lwz 3,0x50(29); li 4,1; lwz 9,0x4(3); lha 0,0x260(9); lwz 9,0x264(9); add 3,3,0; mtspr 8,9; blrl; mr 30,3; beq cr4,3f; lwz 9,0x4(31); li 4,73; lha 5,0x9c(29); lha 3,0x140(9); lwz 0,0x144(9); add 3,31,3; mtspr 8,0; blrl; 3:; mr 3,29; bl _s8015597C_5; beq cr4,4f; lwz 9,0x4(31); li 4,73; li 5,0; lha 3,0x140(9); lwz 0,0x144(9); add 3,31,3; mtspr 8,0; blrl; 4:; lwz 3,0x50(29); mr 5,30; li 4,1; lwz 9,0x4(3); lha 0,0x1e8(9); lwz 9,0x1ec(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x1c(1); lwz 12,0x8(1); mtspr 8,0; lmw 29,0xc(1); mtcrf 8,12; addi 1,1,24"
extern "C" void _s8015597C_0();
extern "C" void _s8015597C_1();
extern "C" void _s8015597C_2();
extern "C" void _s8015597C_3();
extern "C" void _s8015597C_4();
extern "C" void _s8015597C_5();
extern "C" void f_8015597C() {}
