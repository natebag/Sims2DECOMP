// 0x803B57A8 deque<MMUTarget::MMU_MENU_STATE, (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 29,3; mr 8,4; lwz 7,0x1c(29); mr 26,5; lwz 10,0xc(29); lwz 11,0x2c(29); subf 9,10,7; stw 4,0xc(1); srawi 9,9,2; addi 27,9,1; add 31,27,8; add 0,31,31; cmplw 11,0; ble 2f; subf 0,31,11; lwz 9,0x24(29); rlwinm 0,0,1,0,29; cmpwi 26,0; add 3,9,0; beq 0f; rlwinm 0,8,2,0,29; add 3,3,0; 0:; mr 31,3; cmplw 31,10; bge 1f; addi 0,7,4; rlwinm 30,27,2,0,29; cmpw 0,10; beq 11f; mr 4,10; subf 5,4,0; bl _s803B57A8_0; b 11f; 1:; rlwinm 9,27,2,0,29; addi 0,7,4; add 3,9,31; subf. 5,10,0; mr 30,9; ble 11f; subf 3,5,3; mr 4,10; bl _s803B57A8_1; b 11f; 2:; cmplw 11,8; stw 11,0x8(1); addi 0,1,12; addi 9,1,8; bge 3f; mr 9,0; 3:; lwz 0,0x0(9); add 0,11,0; addic. 28,0,2; beq 5f; rlwinm 3,28,2,0,29; cmplwi 3,128; ble 4f; bl _s803B57A8_2; mr 30,3; b 6f; 4:; bl _s803B57A8_3; mr 30,3; b 6f; 5:; li 30,0; 6:; subf 0,31,28; cmpwi 26,0; rlwinm 0,0,1,0,29; add 3,30,0; beq 7f; lwz 0,0xc(1); rlwinm 0,0,2,0,29; add 3,3,0; 7:; lwz 9,0x1c(29); mr 31,3; lwz 4,0xc(29); addi 5,9,4; cmpw 5,4; beq 8f; subf 5,4,5; bl _s803B57A8_4; 8:; lwz 3,0x24(29); lwz 4,0x2c(29); cmpwi 3,0; beq 10f; rlwinm 4,4,2,0,29; cmplwi 4,128; ble 9f; bl _s803B57A8_5; b 10f; 9:; bl _s803B57A8_6; 10:; stw 30,0x24(29); stw 28,0x2c(29); rlwinm 30,27,2,0,29; 11:; stw 31,0xc(29); add 11,30,31; addi 10,29,16; addi 11,11,-4; lwz 9,0x0(31); addi 0,9,128; stw 9,0x4(29); stw 0,0x8(29); stw 11,0xc(10); lwz 9,0x0(11); addi 0,9,128; stw 9,0x4(10); stw 0,0x8(10); lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s803B57A8_0();
extern "C" void _s803B57A8_1();
extern "C" void _s803B57A8_2();
extern "C" void _s803B57A8_3();
extern "C" void _s803B57A8_4();
extern "C" void _s803B57A8_5();
extern "C" void _s803B57A8_6();
extern "C" void f_803B57A8() {}
