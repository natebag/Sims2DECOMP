// 0x800B24C4 ChainResFile::CountTypes(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 30,3; addi 31,1,8; li 4,0; bl _s800B24C4_0; li 0,0; addi 9,31,8; stw 0,0x8(1); mr 3,30; stw 0,0x4(31); mr 4,31; stw 0,0x4(9); bl _s800B24C4_1; lwz 3,0x8(1); lwz 0,0x4(31); mr. 9,3; subf 0,3,0; srawi 0,0,2; extsh 30,0; beq 1f; lwz 0,0xc(31); subf 0,9,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 0f; bl _s800B24C4_2; b 1f; 0:; bl _s800B24C4_3; 1:; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s800B24C4_0();
extern "C" void _s800B24C4_1();
extern "C" void _s800B24C4_2();
extern "C" void _s800B24C4_3();
extern "C" void f_800B24C4() {}
