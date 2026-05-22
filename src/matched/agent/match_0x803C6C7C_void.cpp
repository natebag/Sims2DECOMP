// 0x803C6C7C void (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 28,5; b 1f; 0:; lwz 0,0x0(31); lwz 11,0x4(31); lwz 9,0x8(31); stw 0,0x0(30); stw 9,0x8(30); stw 11,0x4(30); mr 30,31; 1:; addi 31,30,-12; mr 3,29; mr 4,31; mtspr 8,28; blrl; cmpwi 3,0; bne 0b; lwz 0,0x8(29); lwz 9,0x0(29); lwz 11,0x4(29); stw 0,0x8(30); stw 9,0x0(30); stw 11,0x4(30); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void f_803C6C7C() {}
