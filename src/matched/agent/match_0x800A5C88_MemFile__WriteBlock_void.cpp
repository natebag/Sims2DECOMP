// 0x800A5C88 MemFile::WriteBlock(void (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; mr 26,4; mr 29,5; bl _s800A5C88_0; li 27,0; cmpwi 3,0; bne 0f; li 27,-49; b 7f; 0:; lwz 0,0x10c(31); cmpwi 0,0; bne 1f; li 27,-45; b 7f; 1:; lwz 0,0x11c(31); lwz 9,0x0(29); lwz 11,0x118(31); add 30,0,9; cmplw 30,11; ble 5f; addi 0,30,4096; rlwinm 30,0,0,0,19; bl _s800A5C88_1; mr 4,30; li 5,64; li 6,0; li 7,0; bl _s800A5C88_2; mr. 28,3; bne 3f; lwz 0,0x118(31); lwz 9,0x0(29); subf 0,30,0; add 9,9,0; cmpwi 9,0; stw 9,0x0(29); bge 2f; stw 27,0x0(29); 2:; li 27,-46; b 5f; 3:; lwz 4,0x114(31); cmpwi 4,0; beq 4f; lwz 5,0x118(31); mr 3,28; bl _s800A5C88_3; bl _s800A5C88_4; lwz 4,0x114(31); bl _s800A5C88_5; 4:; stw 28,0x114(31); stw 30,0x118(31); 5:; lwz 0,0x114(31); mr 4,26; lwz 3,0x11c(31); lwz 5,0x0(29); add 3,0,3; bl _s800A5C88_6; lwz 0,0x0(29); lwz 9,0x11c(31); add 9,9,0; stw 9,0x11c(31); lwz 0,0x0(29); cmpwi 0,0; beq 7f; lwz 0,0x120(31); cmplw 9,0; bge 6f; mr 9,0; 6:; li 0,1; stw 9,0x120(31); stw 0,0x110(31); 7:; mr 3,27; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800A5C88_0();
extern "C" void _s800A5C88_1();
extern "C" void _s800A5C88_2();
extern "C" void _s800A5C88_3();
extern "C" void _s800A5C88_4();
extern "C" void _s800A5C88_5();
extern "C" void _s800A5C88_6();
extern "C" void f_800A5C88() {}
