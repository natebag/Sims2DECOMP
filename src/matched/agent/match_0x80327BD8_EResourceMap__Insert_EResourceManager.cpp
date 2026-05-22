// 0x80327BD8 EResourceMap::Insert(EResourceManager (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 30,5; lwz 9,0x4(31); mr 29,4; lwz 0,0x8(31); mr 28,6; mr 5,7; cmpw 9,0; bne 0f; rlwinm 4,9,1,31,31; add 4,9,4; srawi 4,4,1; add 4,9,4; bl _s80327BD8_0; lwz 9,0x4(31); lwz 0,0x8(31); cmpw 9,0; bne 0f; mr 3,29; bl _s80327BD8_1; cmpwi 3,0; li 3,0; beq 7f; mr 3,29; bl _s80327BD8_2; 0:; lwz 10,0x4(31); li 3,0; cmpwi 10,0; beq 4f; lwz 0,0x0(31); rlwinm 9,10,3,0,28; add 9,9,0; lwz 11,-8(9); cmplw 30,11; ble 1f; mr 3,10; b 4f; 1:; mr 3,31; mr 4,30; bl _s80327BD8_3; lwz 9,0x0(31); rlwinm 11,3,3,0,28; lwzx 0,11,9; cmpw 0,30; bne 2f; li 3,0; b 7f; 2:; lwz 9,0x4(31); addi 8,9,-1; cmpw 8,3; blt 4f; rlwinm 7,8,3,0,28; 3:; lwz 11,0x0(31); addi 8,8,-1; cmpw 8,3; add 11,7,11; lwz 9,0x0(11); lwz 10,0x4(11); addi 7,7,-8; stw 9,0x8(11); stw 10,0xc(11); bge 3b; 4:; lwz 11,0x0(31); rlwinm 9,3,3,0,28; stwx 30,9,11; lwz 0,0x0(31); add 9,9,0; stw 28,0x4(9); lwz 11,0x4(31); lwz 0,0xc(31); addi 11,11,1; cmpw 11,0; stw 11,0x4(31); ble 5f; stw 11,0xc(31); 5:; mr 3,29; bl _s80327BD8_4; lwz 0,0x4(31); lwz 9,0x10(31); subf 0,3,0; cmpw 0,9; ble 6f; mr 3,29; bl _s80327BD8_5; lwz 0,0x4(31); subf 0,3,0; stw 0,0x10(31); 6:; li 3,1; 7:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80327BD8_0();
extern "C" void _s80327BD8_1();
extern "C" void _s80327BD8_2();
extern "C" void _s80327BD8_3();
extern "C" void _s80327BD8_4();
extern "C" void _s80327BD8_5();
extern "C" void f_80327BD8() {}
