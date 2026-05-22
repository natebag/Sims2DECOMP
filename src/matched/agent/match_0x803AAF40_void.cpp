// 0x803AAF40 void (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 26,0x20(1); stw 0,0x3c(1); mr 31,3; lis 30,-21846; lwz 9,0x0(31); ori 30,30,43691; lwz 0,0x4(31); mr 27,5; mr 26,6; mr 3,27; subf 0,9,0; addi 4,1,24; mullw 0,0,30; li 5,1; srawi 0,0,2; stw 0,0x18(1); bl _s803AAF40_0; lwz 28,0x4(31); lwz 0,0x0(31); lwz 29,0x18(1); subf 0,0,28; mullw 0,0,30; srawi 0,0,2; subf. 9,29,0; bge 0f; addi 30,1,8; subf 29,0,29; li 4,0; li 5,12; mr 3,30; crxor 6,6,6; bl _s803AAF40_1; mr 4,28; mr 5,29; mr 6,30; mr 3,31; bl _s803AAF40_2; b 3f; 0:; ble 3f; mulli 0,9,12; subf 0,0,28; lwz 11,0x4(31); mr 9,0; cmpw 0,11; beq 2f; 1:; addi 9,9,12; cmpw 9,11; bne 1b; 2:; stw 0,0x4(31); 3:; lwz 30,0x0(31); b 5f; 4:; mr 3,30; mr 4,27; mr 5,26; addi 30,30,12; bl _s803AAF40_3; 5:; lwz 0,0x4(31); cmpw 30,0; bne 4b; lwz 0,0x3c(1); mtspr 8,0; lmw 26,0x20(1); addi 1,1,56"
extern "C" void _s803AAF40_0();
extern "C" void _s803AAF40_1();
extern "C" void _s803AAF40_2();
extern "C" void _s803AAF40_3();
extern "C" void f_803AAF40() {}
