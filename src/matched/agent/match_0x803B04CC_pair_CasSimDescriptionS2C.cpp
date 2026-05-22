// 0x803B04CC pair<CasSimDescriptionS2C (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 31,4; mr 23,3; subf 5,31,5; mr 26,6; mr 25,7; srawi. 27,5,2; ble 4f; 0:; srawi 29,27,1; lwz 4,0x0(26); rlwinm 30,29,2,0,29; mtspr 8,25; lwzx 3,31,30; add 28,31,30; mr 24,28; blrl; cmpwi 3,0; beq 1f; subf 9,29,27; addi 31,28,4; addi 27,9,-1; b 3f; 1:; lwzx 4,31,30; mtspr 8,25; lwz 3,0x0(26); blrl; cmpwi 3,0; bne 2f; mr 4,24; mr 5,26; mr 6,25; li 7,0; mr 3,31; bl _s803B04CC_0; mr 30,3; rlwinm 4,27,2,0,29; add 4,31,4; addi 3,24,4; mr 5,26; mr 6,25; li 7,0; bl _s803B04CC_1; stw 30,0x0(23); stw 3,0x4(23); b 5f; 2:; mr 27,29; 3:; cmpwi 27,0; bgt 0b; 4:; stw 31,0x4(23); stw 31,0x0(23); 5:; mr 3,23; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s803B04CC_0();
extern "C" void _s803B04CC_1();
extern "C" void f_803B04CC() {}
