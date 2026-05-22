// 0x803B03CC CasSimDescriptionS2C (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 26,5; subf 4,29,4; mr 27,6; srawi. 30,4,2; ble 3f; 0:; srawi 31,30,1; lwz 4,0x0(26); rlwinm 9,31,2,0,29; mtspr 8,27; lwzx 3,29,9; add 28,29,9; blrl; cmpwi 3,0; beq 1f; subf 9,31,30; addi 29,28,4; addi 30,9,-1; b 2f; 1:; mr 30,31; 2:; cmpwi 30,0; bgt 0b; 3:; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void f_803B03CC() {}
