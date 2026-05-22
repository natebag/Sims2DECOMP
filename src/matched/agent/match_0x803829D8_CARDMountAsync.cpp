// 0x803829D8 CARDMountAsync (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stmw 26,0x18(1); mr. 30,3; addi 26,4,0; addi 27,5,0; addi 29,6,0; blt 0f; cmpwi 30,2; blt 1f; 0:; li 3,-128; b 9f; 1:; lis 3,-32768; lbz 0,0x30e3(3); rlwinm. 0,0,0,24,24; beq 2f; li 3,-3; b 9f; 2:; mulli 4,30,272; lis 3,-32688; addi 0,3,-24000; add 31,0,4; bl _s803829D8_0; lwz 0,0x4(31); addi 28,3,0; cmpwi 0,-1; bne 3f; mr 3,28; bl _s803829D8_1; li 3,-1; b 9f; 3:; lwz 0,0x0(31); cmpwi 0,0; bne 4f; mr 3,30; bl _s803829D8_2; rlwinm. 0,3,0,28,28; beq 4f; mr 3,28; bl _s803829D8_3; li 3,-2; b 9f; 4:; li 0,-1; stw 0,0x4(31); cmplwi 29,0; stw 26,0x80(31); stw 27,0xc4(31); beq 5f; mr 0,29; b 6f; 5:; lis 3,-32712; addi 0,3,-4304; 6:; stw 0,0xd0(31); li 0,0; stw 0,0xcc(31); lwz 0,0x0(31); cmpwi 0,0; bne 7f; lis 3,-32712; addi 4,3,-4248; addi 3,30,0; bl _s803829D8_4; cmpwi 3,0; bne 7f; li 0,-3; stw 0,0x4(31); mr 3,28; bl _s803829D8_5; li 3,-3; b 9f; 7:; li 29,0; stw 29,0x24(31); li 0,1; addi 3,30,0; stw 0,0x0(31); li 4,0; bl _s803829D8_6; addi 3,31,224; bl _s803829D8_7; stw 29,0x84(31); mr 3,28; stw 29,0x88(31); bl _s803829D8_8; lis 3,-32712; addi 0,3,10400; lis 3,-32712; stw 0,0xdc(31); addi 5,3,-3584; addi 3,30,0; li 4,0; bl _s803829D8_9; cmpwi 3,0; bne 8f; li 3,0; b 9f; 8:; stw 29,0xdc(31); mr 3,30; bl _s803829D8_10; 9:; lmw 26,0x18(1); lwz 0,0x34(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s803829D8_0();
extern "C" void _s803829D8_1();
extern "C" void _s803829D8_2();
extern "C" void _s803829D8_3();
extern "C" void _s803829D8_4();
extern "C" void _s803829D8_5();
extern "C" void _s803829D8_6();
extern "C" void _s803829D8_7();
extern "C" void _s803829D8_8();
extern "C" void _s803829D8_9();
extern "C" void _s803829D8_10();
extern "C" void f_803829D8() {}
