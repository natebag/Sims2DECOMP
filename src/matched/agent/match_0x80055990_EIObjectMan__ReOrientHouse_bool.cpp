// 0x80055990 EIObjectMan::ReOrientHouse(bool) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 30,0x4(3); cmpwi 30,0; beq 2f; 0:; lwz 31,0x1c(30); mr 3,31; bl _s80055990_0; cmpwi 3,0; bne 1f; lwz 9,0x320(31); addi 0,31,800; lha 3,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; 1:; lwz 30,0x10(30); cmpwi 30,0; bne 0b; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80055990_0();
extern "C" void f_80055990() {}
