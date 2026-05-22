// 0x800778B0 CUnlockDisplay::makeObjects(void) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; li 9,0; lwz 0,0x44c(28); li 27,0; cmpwi 0,2; beq 2f; bgt 0f; cmpwi 0,1; beq 1f; b 4f; 0:; cmpwi 0,3; beq 3f; b 4f; 1:; li 9,1; b 4f; 2:; lwz 9,0x490(28); lwz 27,0x494(28); b 4f; 3:; li 27,2; 4:; li 30,0; li 29,0; cmpw 30,9; bge 8f; mr 31,9; 5:; li 3,136; bl _s800778B0_0; bl _s800778B0_1; cmpwi 30,0; bne 6f; stw 3,0x464(28); b 7f; 6:; stw 3,0x0(29); 7:; mr 29,3; addi 30,30,1; addic. 31,31,-1; bne 5b; 8:; cmpwi 27,0; ble 12f; mr 31,27; 9:; li 3,440; bl _s800778B0_2; bl _s800778B0_3; cmpwi 30,0; bne 10f; stw 3,0x464(28); b 11f; 10:; stw 3,0x0(29); 11:; mr 29,3; addi 30,30,1; addic. 31,31,-1; bne 9b; 12:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800778B0_0();
extern "C" void _s800778B0_1();
extern "C" void _s800778B0_2();
extern "C" void _s800778B0_3();
extern "C" void f_800778B0() {}
