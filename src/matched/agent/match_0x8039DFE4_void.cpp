// 0x8039DFE4 void (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; stw 4,0x8(1); mr 28,5; addi 31,30,-4; addi 29,1,8; b 1f; 0:; lwz 0,0x0(31); stw 0,0x0(30); mr 30,31; addi 31,30,-4; 1:; mr 3,29; mr 4,31; mtspr 8,28; blrl; cmpwi 3,0; bne 0b; lwz 0,0x8(1); stw 0,0x0(30); lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void f_8039DFE4() {}
