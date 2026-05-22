// 0x801A2204 ACTTarget::UpdateActionQueue(void) (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); mr 30,3; li 28,1; addi 31,30,236; li 29,18; 0:; lwz 0,0x20(31); cmpwi 0,0; bne 8f; lwz 0,0x18(31); lwz 11,0x10(31); cmpw 0,11; bne 1f; lwz 9,0x1c(31); lwz 0,0x14(31); cmpw 9,0; beq 8f; 1:; lwz 0,0x14(31); addi 3,1,8; stw 11,0x18(31); stw 0,0x1c(31); bl _s801A2204_0; lwz 0,0x10(31); cmpwi 0,0; bne 2f; lwz 0,0x8(31); cmpwi 0,0; beq 3f; 2:; lwz 4,0x24(31); addi 3,1,8; lwz 7,0x30(31); li 5,125; lwz 8,0xdc(30); li 6,0; bl _s801A2204_1; addi 3,1,8; li 4,0; bl _s801A2204_2; stw 28,0x8(31); b 4f; 3:; lwz 4,0x24(31); addi 3,1,8; lwz 7,0x30(31); li 5,250; lwz 8,0xdc(30); li 6,0; bl _s801A2204_3; addi 3,1,8; li 4,255; bl _s801A2204_4; 4:; lwz 4,0x10(31); addi 3,1,8; bl _s801A2204_5; lwz 4,0x14(31); addi 3,1,8; bl _s801A2204_6; addi 3,1,8; bl _s801A2204_7; stw 28,0x20(31); stw 28,0x4(31); lwz 0,0x648(30); cmpw 0,31; bne 7f; lwz 0,0x8(31); cmpwi 0,0; beq 6f; lwz 0,0x44(31); cmpwi 0,0; beq 5f; stw 31,0x64c(30); mr 3,30; lwz 0,0x44(31); stw 0,0x648(30); bl _s801A2204_8; b 7f; 5:; mr 3,30; bl _s801A2204_9; b 7f; 6:; lwz 8,0xdc(30); lis 4,-32705; lis 7,-32705; addi 3,1,8; addi 4,4,-8784; addi 7,7,-8764; li 5,250; li 6,0; bl _s801A2204_10; lwz 4,0x10(31); addi 3,1,8; addi 4,4,32; bl _s801A2204_11; lwz 4,0x14(31); addi 3,1,8; addi 4,4,-14; bl _s801A2204_12; addi 3,1,8; bl _s801A2204_13; 7:; addi 3,1,8; li 4,2; bl _s801A2204_14; 8:; addi 31,31,76; addic. 29,29,-1; bne 0b; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s801A2204_0();
extern "C" void _s801A2204_1();
extern "C" void _s801A2204_2();
extern "C" void _s801A2204_3();
extern "C" void _s801A2204_4();
extern "C" void _s801A2204_5();
extern "C" void _s801A2204_6();
extern "C" void _s801A2204_7();
extern "C" void _s801A2204_8();
extern "C" void _s801A2204_9();
extern "C" void _s801A2204_10();
extern "C" void _s801A2204_11();
extern "C" void _s801A2204_12();
extern "C" void _s801A2204_13();
extern "C" void _s801A2204_14();
extern "C" void f_801A2204() {}
