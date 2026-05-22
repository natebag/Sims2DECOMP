// 0x803B002C void (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,3; mr 29,4; subf 0,31,29; mr 26,6; srawi 0,0,2; mr 28,7; cmpwi 0,16; ble 7f; 0:; cmpwi 26,0; bne 1f; mr 4,29; mr 3,31; mr 6,28; mr 5,4; bl _s803B002C_0; b 7f; 1:; subf 0,31,29; lwz 3,0x0(31); rlwinm 9,0,1,31,31; mtspr 8,28; srawi 0,0,2; addi 26,26,-1; add 0,0,9; addi 25,29,-4; rlwinm 30,0,1,0,29; lwzx 4,30,31; add 27,30,31; blrl; cmpwi 3,0; beq 3f; lwzx 3,30,31; mtspr 8,28; lwz 4,-4(29); blrl; cmpwi 3,0; beq 2f; mr 5,27; b 6f; 2:; lwz 3,0x0(31); mtspr 8,28; lwz 4,-4(29); blrl; cmpwi 3,0; mr 5,31; b 5f; 3:; lwz 3,0x0(31); mtspr 8,28; lwz 4,-4(29); blrl; cmpwi 3,0; beq 4f; mr 5,31; b 6f; 4:; lwzx 3,30,31; mtspr 8,28; lwz 4,-4(29); blrl; cmpwi 3,0; mr 5,27; 5:; beq 6f; mr 5,25; 6:; lwz 5,0x0(5); mr 4,29; mr 6,28; mr 3,31; bl _s803B002C_1; mr 30,3; mr 4,29; li 5,0; mr 6,26; mr 7,28; bl _s803B002C_2; mr 29,30; subf 0,31,29; srawi 0,0,2; cmpwi 0,16; bgt 0b; 7:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s803B002C_0();
extern "C" void _s803B002C_1();
extern "C" void _s803B002C_2();
extern "C" void f_803B002C() {}
