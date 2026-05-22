// 0x801A2F98 ACTTarget::UpdateCancelModeWidgets(void) (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stw 31,0x24(1); stw 0,0x2c(1); mr 31,3; lwz 0,0x648(31); cmpwi 0,0; bne 0f; lwz 0,0x64c(31); cmpwi 0,0; beq 3f; 0:; addi 3,1,8; bl _s801A2F98_0; addi 3,1,8; bl _s801A2F98_1; lwz 0,0x648(31); cmpwi 0,0; beq 1f; lwz 5,0xdc(31); lis 4,-32705; addi 3,1,8; addi 4,4,-8784; bl _s801A2F98_2; addi 3,1,8; li 4,1; bl _s801A2F98_3; lwz 9,0x648(31); addi 3,1,8; lwz 4,0x10(9); addi 4,4,32; bl _s801A2F98_4; lwz 9,0x648(31); addi 3,1,8; lwz 4,0x14(9); addi 4,4,-14; bl _s801A2F98_5; lwz 9,0x648(31); addi 3,1,8; lwz 5,0xdc(31); lwz 4,0x2c(9); bl _s801A2F98_6; lis 4,255; addi 3,1,8; ori 4,4,26214; bl _s801A2F98_7; 1:; lwz 9,0x64c(31); cmpwi 9,0; beq 2f; lwz 4,0x2c(9); addi 3,1,8; lwz 5,0xdc(31); bl _s801A2F98_8; lis 4,255; addi 3,1,8; ori 4,4,65535; bl _s801A2F98_9; 2:; addi 3,1,8; bl _s801A2F98_10; addi 3,1,8; li 4,2; bl _s801A2F98_11; 3:; lwz 0,0x2c(1); mtspr 8,0; lwz 31,0x24(1); addi 1,1,40"
extern "C" void _s801A2F98_0();
extern "C" void _s801A2F98_1();
extern "C" void _s801A2F98_2();
extern "C" void _s801A2F98_3();
extern "C" void _s801A2F98_4();
extern "C" void _s801A2F98_5();
extern "C" void _s801A2F98_6();
extern "C" void _s801A2F98_7();
extern "C" void _s801A2F98_8();
extern "C" void _s801A2F98_9();
extern "C" void _s801A2F98_10();
extern "C" void _s801A2F98_11();
extern "C" void f_801A2F98() {}
