// 0x803C68C4 void (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 24,0x28(1); stw 0,0x4c(1); mr 26,4; mr 25,5; mr 28,7; mr 29,3; mr 5,28; mr 31,26; bl _s803C68C4_0; cmplw 26,25; bge 2f; lis 0,-21846; subf 9,29,26; ori 0,0,43691; addi 27,1,8; mullw 24,9,0; 0:; mr 3,31; mr 4,29; mtspr 8,28; blrl; cmpwi 3,0; beq 1f; lwz 0,0x0(31); mr 3,29; lwz 9,0x4(31); li 4,0; lwz 11,0x8(31); srawi 5,24,2; stw 0,0x8(1); addi 6,1,24; stw 9,0x4(27); mr 7,28; stw 11,0x8(27); lwz 11,0x8(29); lwz 0,0x0(29); lwz 9,0x4(29); lwz 10,0x8(1); lwz 8,0xc(1); lwz 30,0x10(1); stw 0,0x0(31); stw 9,0x4(31); stw 11,0x8(31); stw 10,0x18(1); stw 8,0x1c(1); stw 30,0x20(1); bl _s803C68C4_1; 1:; addi 31,31,12; cmplw 31,25; blt 0b; 2:; mr 30,26; lis 9,-21846; subf 0,29,30; ori 9,9,43691; mullw 0,0,9; srawi 0,0,2; cmpwi 0,1; ble 4f; lis 0,21845; mullw 9,30,9; ori 0,0,21845; mullw 0,29,0; add 31,9,0; 3:; mr 4,30; mr 3,29; mr 5,28; addi 31,31,-4; bl _s803C68C4_2; addi 30,30,-12; srawi 0,31,2; cmpwi 0,1; bgt 3b; 4:; lwz 0,0x4c(1); mtspr 8,0; lmw 24,0x28(1); addi 1,1,72"
extern "C" void _s803C68C4_0();
extern "C" void _s803C68C4_1();
extern "C" void _s803C68C4_2();
extern "C" void f_803C68C4() {}
