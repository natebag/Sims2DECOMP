// 0x8004185C OrientObjectInstance(cXObject (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x0(31); lwz 9,0x18(3); lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 0f; lwz 11,0x0(31); lwz 9,0x18(11); lwz 0,0x9c(9); lha 3,0x98(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x320(3); addi 3,3,800; lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_8004185C() {}
