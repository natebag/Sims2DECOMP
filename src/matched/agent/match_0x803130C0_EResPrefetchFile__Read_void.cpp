// 0x803130C0 EResPrefetchFile::Read(void (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 27,4; mr. 28,5; bne 0f; li 3,0; b 5f; 0:; lwz 5,0x30(31); lwz 0,0x34(31); lwz 9,0x38(31); add 11,5,28; add 0,0,9; cmplw 11,0; blt 3f; subf 5,5,0; subf 29,5,28; cmpwi 5,0; bne 1f; lwz 3,0x2c(31); mr 4,27; lwz 5,0x40(31); mr 6,28; bl _s803130C0_0; lwz 0,0x40(31); mr 30,3; add 0,0,28; stw 0,0x40(31); b 4f; 1:; mr 3,31; mr 4,27; bl _s803130C0_1; mr 30,3; cmpwi 29,0; beq 2f; lwz 3,0x2c(31); mr 4,27; lwz 5,0x40(31); mr 6,29; add 30,30,29; bl _s803130C0_2; 2:; lwz 0,0x40(31); add 0,0,29; stw 0,0x40(31); b 4f; 3:; mr 3,31; mr 4,27; mr 5,28; bl _s803130C0_3; mr 30,3; 4:; mr 3,30; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s803130C0_0();
extern "C" void _s803130C0_1();
extern "C" void _s803130C0_2();
extern "C" void _s803130C0_3();
extern "C" void f_803130C0() {}
