// 0x8020B020 InteractorModule::InteractorManager::~InteractorManager(void) (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 27,4; addi 11,29,64; lwz 9,0x40(29); lwz 0,0x4(11); cmpw 9,0; beq 1f; 0:; addi 9,9,16; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(11); cmpwi 3,0; beq 3f; lwz 0,0xc(11); subf 0,3,0; rlwinm 4,0,0,0,27; cmplwi 4,128; ble 2f; bl _s8020B020_0; b 3f; 2:; bl _s8020B020_1; 3:; addi 11,29,44; lwz 9,0x2c(29); lwz 0,0x4(11); addi 31,29,28; addi 28,29,12; cmpw 9,0; beq 5f; 4:; addi 9,9,8; cmpw 9,0; bne 4b; 5:; lwz 3,0x0(11); cmpwi 3,0; beq 7f; lwz 0,0xc(11); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 6f; bl _s8020B020_2; b 7f; 6:; bl _s8020B020_3; 7:; lwz 0,0x4(31); lwz 9,0x1c(29); cmpw 9,0; beq 9f; 8:; addi 9,9,8; cmpw 9,0; bne 8b; 9:; lwz 3,0x0(31); cmpwi 3,0; beq 11f; lwz 0,0xc(31); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 10f; bl _s8020B020_4; b 11f; 10:; bl _s8020B020_5; 11:; lwz 30,0x4(28); lwz 31,0xc(29); cmpw 31,30; beq 15f; 12:; lwz 3,0x0(31); cmpwi 3,0; beq 14f; lwz 0,0xc(31); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 13f; bl _s8020B020_6; b 14f; 13:; bl _s8020B020_7; 14:; addi 31,31,16; cmpw 31,30; bne 12b; 15:; lwz 3,0x0(28); cmpwi 3,0; beq 17f; lwz 0,0xc(28); subf 0,3,0; rlwinm 4,0,0,0,27; cmplwi 4,128; ble 16f; bl _s8020B020_8; b 17f; 16:; bl _s8020B020_9; 17:; andi. 0,27,1; beq 18f; mr 3,29; bl _s8020B020_10; 18:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8020B020_0();
extern "C" void _s8020B020_1();
extern "C" void _s8020B020_2();
extern "C" void _s8020B020_3();
extern "C" void _s8020B020_4();
extern "C" void _s8020B020_5();
extern "C" void _s8020B020_6();
extern "C" void _s8020B020_7();
extern "C" void _s8020B020_8();
extern "C" void _s8020B020_9();
extern "C" void _s8020B020_10();
extern "C" void f_8020B020() {}
