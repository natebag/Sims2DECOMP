// 0x8037F040 __CARDExiHandler (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); addi 31,3,0; mulli 4,31,272; stw 30,0x20(1); lis 3,-32688; stw 29,0x1c(1); addi 0,3,-24000; add 30,0,4; addi 3,30,224; bl _s8037F040_0; lwz 0,0x0(30); cmpwi 0,0; beq 5f; addi 3,31,0; li 4,0; li 5,0; bl _s8037F040_1; cmpwi 3,0; bne 0f; li 29,-128; b 4f; 0:; addi 3,31,0; addi 4,1,16; bl _s8037F040_2; mr. 29,3; blt 3f; mr 3,31; bl _s8037F040_3; mr. 29,3; blt 3f; lbz 0,0x10(1); rlwinm. 0,0,0,27,28; beq 1f; li 0,-5; b 2f; 1:; li 0,0; 2:; mr 29,0; cmpwi 29,-5; bne 3f; lwz 3,0xa8(30); addic. 0,3,-1; stw 0,0xa8(30); ble 3f; mr 3,31; bl _s8037F040_4; mr. 29,3; blt 4f; b 5f; 3:; mr 3,31; bl _s8037F040_5; 4:; lwz 0,0xcc(30); cmplwi 0,0; mr 12,0; beq 5f; li 0,0; mtspr 8,12; stw 0,0xcc(30); addi 3,31,0; addi 4,29,0; blrl; 5:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8037F040_0();
extern "C" void _s8037F040_1();
extern "C" void _s8037F040_2();
extern "C" void _s8037F040_3();
extern "C" void _s8037F040_4();
extern "C" void _s8037F040_5();
extern "C" void f_8037F040() {}
