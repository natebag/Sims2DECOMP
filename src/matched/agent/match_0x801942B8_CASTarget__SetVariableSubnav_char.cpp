// 0x801942B8 CASTarget::SetVariableSubnav(char (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 30,4; mr 31,3; addi 29,1,16; addi 3,1,8; li 5,2; bl _s801942B8_0; addi 4,30,2; li 5,2; mr 3,29; bl _s801942B8_1; li 0,0; addi 3,1,8; stb 0,0x12(1); stb 0,0xa(1); bl _s801942B8_2; mr 30,3; mr 3,29; bl _s801942B8_3; lwz 0,0x90(31); mr 29,3; cmpwi 0,0; beq 10f; lwz 0,0x9c(31); cmpw 30,0; beq 0f; stw 30,0x9c(31); mr 3,31; bl _s801942B8_4; 0:; lwz 0,0x90(31); mr 4,0; cmpwi 0,8; beq 6f; bgt 2f; cmpwi 4,5; beq 4f; bgt 1f; cmpwi 4,3; beq 5f; b 10f; 1:; cmpwi 4,6; beq 6f; b 10f; 2:; cmpwi 4,17; beq 7f; bgt 3f; cmpwi 4,10; beq 7f; b 10f; 3:; cmpwi 4,20; beq 8f; cmpwi 4,24; beq 9f; b 10f; 4:; lwz 3,0x1378(31); mr 4,30; mr 5,29; bl _s801942B8_5; b 10f; 5:; lwz 3,0x1370(31); mr 4,30; mr 5,29; bl _s801942B8_6; b 10f; 6:; lwz 3,0x1374(31); mr 5,30; mr 6,29; bl _s801942B8_7; b 10f; 7:; lwz 3,0x1384(31); mr 5,30; mr 6,29; bl _s801942B8_8; b 10f; 8:; lwz 3,0x1388(31); mr 5,30; mr 6,29; li 4,20; bl _s801942B8_9; b 10f; 9:; lwz 3,0x1390(31); mr 4,30; mr 5,29; bl _s801942B8_10; 10:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s801942B8_0();
extern "C" void _s801942B8_1();
extern "C" void _s801942B8_2();
extern "C" void _s801942B8_3();
extern "C" void _s801942B8_4();
extern "C" void _s801942B8_5();
extern "C" void _s801942B8_6();
extern "C" void _s801942B8_7();
extern "C" void _s801942B8_8();
extern "C" void _s801942B8_9();
extern "C" void _s801942B8_10();
extern "C" void f_801942B8() {}
