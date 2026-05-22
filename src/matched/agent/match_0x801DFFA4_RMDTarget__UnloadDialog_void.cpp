// 0x801DFFA4 RMDTarget::UnloadDialog(void) (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 0,4; stw 0,0x88(30); li 29,0; li 28,0; addi 31,30,140; 0:; lwz 4,0x0(31); cmpwi 4,0; beq 1f; mr 3,29; bl _s801DFFA4_0; stw 28,0x0(31); 1:; addi 29,29,1; addi 31,31,4; cmpwi 29,1; ble 0b; lwz 0,0x94(30); cmpwi 0,0; beq 2f; li 3,0; bl _s801DFFA4_1; li 0,0; stw 0,0x94(30); 2:; lwz 0,0x84(30); cmpwi 0,0; beq 13f; lwz 0,0x0(30); cmpwi 0,0; beq 12f; lwz 3,0x4(30); addi 4,30,40; bl _s801DFFA4_2; lwz 3,0x8(30); addi 4,30,56; bl _s801DFFA4_3; lwz 3,0xc(30); addi 4,30,72; bl _s801DFFA4_4; addi 9,30,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 3f; lwz 0,0x58(30); cmpwi 0,0; beq 4f; 3:; li 11,1; 4:; cmpwi 11,0; beq 5f; lwz 3,0x10(30); bl _s801DFFA4_5; 5:; addi 9,30,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 6f; lwz 0,0x68(30); cmpwi 0,0; beq 7f; 6:; li 11,1; 7:; cmpwi 11,0; beq 8f; lwz 3,0x14(30); bl _s801DFFA4_6; 8:; lwz 3,0x18(30); cmpwi 3,0; beq 9f; lwz 4,0x7c(30); bl _s801DFFA4_7; 9:; lwz 3,0x1c(30); cmpwi 3,0; beq 10f; lwz 4,0x7c(30); bl _s801DFFA4_8; 10:; lwz 3,0x20(30); cmpwi 3,0; beq 11f; lwz 4,0x7c(30); bl _s801DFFA4_9; 11:; lwz 3,0x24(30); cmpwi 3,0; beq 12f; lwz 4,0x7c(30); bl _s801DFFA4_10; 12:; lis 9,-32697; li 4,67; lwz 3,0x5f10(9); bl _s801DFFA4_11; li 0,0; lis 9,-32697; stw 0,0x84(30); lwz 3,0x5bcc(9); cmpwi 3,0; beq 13f; bl _s801DFFA4_12; 13:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801DFFA4_0();
extern "C" void _s801DFFA4_1();
extern "C" void _s801DFFA4_2();
extern "C" void _s801DFFA4_3();
extern "C" void _s801DFFA4_4();
extern "C" void _s801DFFA4_5();
extern "C" void _s801DFFA4_6();
extern "C" void _s801DFFA4_7();
extern "C" void _s801DFFA4_8();
extern "C" void _s801DFFA4_9();
extern "C" void _s801DFFA4_10();
extern "C" void _s801DFFA4_11();
extern "C" void _s801DFFA4_12();
extern "C" void f_801DFFA4() {}
