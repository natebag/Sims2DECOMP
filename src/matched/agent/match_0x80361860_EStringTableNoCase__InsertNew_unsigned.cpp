// 0x80361860 EStringTableNoCase::InsertNew(unsigned (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; mr 26,4; lwz 0,0x8(30); mr 28,5; mr 27,6; cmpwi 0,0; bne 0f; lwz 4,0xc(30); bl _s80361860_0; 0:; li 3,20; bl _s80361860_1; mr 31,3; addi 29,31,12; mr 3,29; bl _s80361860_2; cmpwi 31,0; li 3,0; beq 4f; mr 3,29; mr 4,28; bl _s80361860_3; stw 27,0x10(31); rlwinm 11,26,2,0,29; lwz 9,0x8(30); lwzx 0,9,11; stw 0,0x8(31); stwx 31,9,11; lwz 9,0x4(30); stw 9,0x0(31); cmpwi 9,0; beq 1f; stw 31,0x4(9); b 2f; 1:; stw 31,0x0(30); 2:; lwz 9,0x14(30); li 0,0; lwz 11,0xc(30); addi 9,9,1; stw 0,0x4(31); cmplw 9,11; stw 31,0x4(30); stw 9,0x14(30); ble 3f; mr 3,30; bl _s80361860_4; 3:; mr 3,31; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80361860_0();
extern "C" void _s80361860_1();
extern "C" void _s80361860_2();
extern "C" void _s80361860_3();
extern "C" void _s80361860_4();
extern "C" void f_80361860() {}
