// 0x803A5D74 void (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 27,4; subf 0,29,27; mr 26,6; srawi 0,0,2; mr 28,7; cmpwi 0,16; ble 6f; 0:; cmpwi 26,0; bne 1f; mr 4,27; mr 3,29; mr 6,28; mr 5,4; bl _s803A5D74_0; b 6f; 1:; subf 0,29,27; mr 3,29; rlwinm 9,0,1,31,31; mtspr 8,28; srawi 0,0,2; addi 26,26,-1; add 0,0,9; addi 31,27,-4; rlwinm 0,0,1,0,29; add 30,0,29; mr 4,30; blrl; cmpwi 3,0; beq 3f; mr 3,30; mr 4,31; mtspr 8,28; blrl; cmpwi 3,0; beq 2f; mr 3,30; b 5f; 2:; mr 3,29; mr 4,31; mtspr 8,28; blrl; cmpwi 3,0; mr 3,29; b 4f; 3:; mr 3,29; mr 4,31; mtspr 8,28; blrl; cmpwi 3,0; mr 3,29; bne 5f; mr 3,30; mr 4,31; mtspr 8,28; blrl; cmpwi 3,0; mr 3,30; 4:; beq 5f; mr 3,31; 5:; lwz 5,0x0(3); mr 4,27; mr 6,28; mr 3,29; bl _s803A5D74_1; mr 30,3; mr 4,27; li 5,0; mr 6,26; mr 7,28; bl _s803A5D74_2; mr 27,30; subf 0,29,27; srawi 0,0,2; cmpwi 0,16; bgt 0b; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s803A5D74_0();
extern "C" void _s803A5D74_1();
extern "C" void _s803A5D74_2();
extern "C" void f_803A5D74() {}
