// 0x8039EB7C void (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); mr 31,3; mr 29,4; subf 0,31,29; mr 26,6; srawi 0,0,2; mr 25,7; cmpwi 0,16; ble 6f; 0:; cmpwi 26,0; bne 1f; lwz 0,0x0(25); mr 4,29; mr 3,31; mr 5,4; stw 0,0x8(1); addi 6,1,8; bl _s8039EB7C_0; b 6f; 1:; subf 0,31,29; lwz 11,0x0(25); rlwinm 9,0,1,31,31; lwz 4,0x0(31); srawi 0,0,2; stw 11,0xc(1); add 0,0,9; addi 3,1,12; rlwinm 30,0,1,0,29; addi 26,26,-1; lwzx 5,30,31; add 28,30,31; stw 11,0x8(1); addi 27,29,-4; bl _s8039EB7C_1; cmpwi 3,0; beq 3f; lwzx 4,30,31; addi 3,1,12; lwz 5,-4(29); bl _s8039EB7C_2; cmpwi 3,0; beq 2f; mr 5,28; b 5f; 2:; lwz 5,-4(29); addi 3,1,12; lwz 4,0x0(31); bl _s8039EB7C_3; cmpwi 3,0; mr 5,31; b 4f; 3:; lwz 4,0x0(31); addi 3,1,12; lwz 5,-4(29); bl _s8039EB7C_4; cmpwi 3,0; mr 5,31; bne 5f; lwz 5,-4(29); addi 3,1,12; lwzx 4,30,31; bl _s8039EB7C_5; cmpwi 3,0; mr 5,28; 4:; beq 5f; mr 5,27; 5:; lwz 5,0x0(5); mr 4,29; addi 6,1,8; mr 3,31; bl _s8039EB7C_6; lwz 0,0x0(25); mr 30,3; mr 4,29; stw 0,0xc(1); li 5,0; mr 6,26; addi 7,1,12; bl _s8039EB7C_7; mr 29,30; subf 0,31,29; srawi 0,0,2; cmpwi 0,16; bgt 0b; 6:; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s8039EB7C_0();
extern "C" void _s8039EB7C_1();
extern "C" void _s8039EB7C_2();
extern "C" void _s8039EB7C_3();
extern "C" void _s8039EB7C_4();
extern "C" void _s8039EB7C_5();
extern "C" void _s8039EB7C_6();
extern "C" void _s8039EB7C_7();
extern "C" void f_8039EB7C() {}
