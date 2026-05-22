// 0x803C6AEC void (400 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 24,0x18(1); stw 0,0x3c(1); mr 29,3; mr 27,4; lis 0,-21846; subf 9,29,27; ori 0,0,43691; mr 26,6; mullw 9,9,0; mr 28,7; srawi 9,9,2; cmpwi 9,16; ble 6f; lis 24,-21846; addi 25,1,8; ori 24,24,43691; 0:; cmpwi 26,0; bne 1f; mr 4,27; mr 3,29; mr 6,28; mr 5,4; bl _s803C6AEC_0; b 6f; 1:; subf 0,29,27; mr 3,29; mullw 0,0,24; mtspr 8,28; addi 26,26,-1; addi 31,27,-12; rlwinm 9,0,1,31,31; srawi 0,0,2; add 0,0,9; srawi 0,0,1; mulli 30,0,12; add 30,30,29; mr 4,30; blrl; cmpwi 3,0; beq 3f; mr 3,30; mr 4,31; mtspr 8,28; blrl; cmpwi 3,0; beq 2f; mr 3,30; b 5f; 2:; mr 3,29; mr 4,31; mtspr 8,28; blrl; cmpwi 3,0; mr 3,29; b 4f; 3:; mr 3,29; mr 4,31; mtspr 8,28; blrl; cmpwi 3,0; mr 3,29; bne 5f; mr 3,30; mr 4,31; mtspr 8,28; blrl; cmpwi 3,0; mr 3,30; 4:; beq 5f; mr 3,31; 5:; lwz 9,0x0(3); mr 4,27; lwz 0,0x4(3); mr 5,25; lwz 11,0x8(3); mr 6,28; stw 9,0x8(1); mr 3,29; stw 0,0x4(25); stw 11,0x8(25); bl _s803C6AEC_1; mr 30,3; mr 4,27; li 5,0; mr 6,26; mr 7,28; bl _s803C6AEC_2; mr 27,30; subf 0,29,27; mullw 0,0,24; srawi 0,0,2; cmpwi 0,16; bgt 0b; 6:; lwz 0,0x3c(1); mtspr 8,0; lmw 24,0x18(1); addi 1,1,56"
extern "C" void _s803C6AEC_0();
extern "C" void _s803C6AEC_1();
extern "C" void _s803C6AEC_2();
extern "C" void f_803C6AEC() {}
