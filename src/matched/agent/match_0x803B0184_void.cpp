// 0x803B0184 void (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 28,5; b 1f; 0:; lwz 0,0x0(31); stw 0,0x0(30); mr 30,31; 1:; addi 31,30,-4; mr 3,29; lwz 4,0x0(31); mtspr 8,28; blrl; cmpwi 3,0; bne 0b; stw 29,0x0(30); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void f_803B0184() {}
