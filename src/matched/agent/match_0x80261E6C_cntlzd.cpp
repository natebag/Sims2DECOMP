// 0x80261E6C cntlzd (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 5,32; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,3,0; stw 30,0x10(1); addi 30,4,0; bl _s80261E6C_0; cntlzw 3,4; cmpwi 3,32; li 0,-1; and 0,30,0; bge 0f; b 1f; 0:; cntlzw 3,0; addi 3,3,32; 1:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80261E6C_0();
extern "C" void f_80261E6C() {}
