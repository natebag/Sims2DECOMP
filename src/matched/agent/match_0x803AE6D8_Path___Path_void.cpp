// 0x803AE6D8 Path::~Path(void) (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,4; lwz 3,0x4c(31); addi 9,31,76; cmpwi 3,0; beq 1f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 0f; bl _s803AE6D8_0; b 1f; 0:; bl _s803AE6D8_1; 1:; lwz 3,0x3c(31); addi 9,31,60; cmpwi 3,0; beq 3f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 2f; bl _s803AE6D8_2; b 3f; 2:; bl _s803AE6D8_3; 3:; addi 11,31,36; lwz 9,0x24(31); lwz 0,0x4(11); addi 30,31,20; addi 29,31,4; cmpw 9,0; beq 5f; 4:; addi 9,9,8; cmpw 9,0; bne 4b; 5:; lwz 3,0x0(11); cmpwi 3,0; beq 7f; lwz 0,0xc(11); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 6f; bl _s803AE6D8_4; b 7f; 6:; bl _s803AE6D8_5; 7:; lwz 3,0x14(31); cmpwi 3,0; beq 9f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 8f; bl _s803AE6D8_6; b 9f; 8:; bl _s803AE6D8_7; 9:; lwz 3,0x4(31); cmpwi 3,0; beq 11f; lwz 0,0xc(29); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 10f; bl _s803AE6D8_8; b 11f; 10:; bl _s803AE6D8_9; 11:; andi. 0,28,1; beq 12f; mr 3,31; bl _s803AE6D8_10; 12:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803AE6D8_0();
extern "C" void _s803AE6D8_1();
extern "C" void _s803AE6D8_2();
extern "C" void _s803AE6D8_3();
extern "C" void _s803AE6D8_4();
extern "C" void _s803AE6D8_5();
extern "C" void _s803AE6D8_6();
extern "C" void _s803AE6D8_7();
extern "C" void _s803AE6D8_8();
extern "C" void _s803AE6D8_9();
extern "C" void _s803AE6D8_10();
extern "C" void f_803AE6D8() {}
