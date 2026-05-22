// 0x803ACC5C SpacePartition::~SpacePartition(void) (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; addi 11,31,76; lwz 9,0x4c(31); lwz 0,0x4(11); cmpw 9,0; beq 1f; 0:; addi 9,9,44; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(11); cmpwi 3,0; beq 3f; lwz 0,0xc(11); lis 9,-17874; ori 9,9,35747; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,44; cmplwi 4,128; ble 2f; bl _s803ACC5C_0; b 3f; 2:; bl _s803ACC5C_1; 3:; lwz 3,0x3c(31); addi 9,31,60; cmpwi 3,0; beq 5f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 4f; bl _s803ACC5C_2; b 5f; 4:; bl _s803ACC5C_3; 5:; lwz 3,0x2c(31); addi 9,31,44; cmpwi 3,0; beq 7f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 6f; bl _s803ACC5C_4; b 7f; 6:; bl _s803ACC5C_5; 7:; lwz 3,0x1c(31); addi 9,31,28; cmpwi 3,0; beq 9f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 8f; bl _s803ACC5C_6; b 9f; 8:; bl _s803ACC5C_7; 9:; addi 11,31,12; lwz 9,0xc(31); lwz 0,0x4(11); cmpw 9,0; beq 11f; 10:; addi 9,9,20; cmpw 9,0; bne 10b; 11:; lwz 3,0x0(11); cmpwi 3,0; beq 13f; lwz 0,0xc(11); lis 9,-13108; ori 9,9,52429; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,20; cmplwi 4,128; ble 12f; bl _s803ACC5C_8; b 13f; 12:; bl _s803ACC5C_9; 13:; andi. 0,30,1; beq 14f; mr 3,31; bl _s803ACC5C_10; 14:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803ACC5C_0();
extern "C" void _s803ACC5C_1();
extern "C" void _s803ACC5C_2();
extern "C" void _s803ACC5C_3();
extern "C" void _s803ACC5C_4();
extern "C" void _s803ACC5C_5();
extern "C" void _s803ACC5C_6();
extern "C" void _s803ACC5C_7();
extern "C" void _s803ACC5C_8();
extern "C" void _s803ACC5C_9();
extern "C" void _s803ACC5C_10();
extern "C" void f_803ACC5C() {}
