// 0x8004145C EGlobal::AllocInstance(cXObject (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; lwz 9,0x4(31); lha 3,0x368(9); lwz 0,0x36c(9); add 3,31,3; mtspr 8,0; blrl; bl _s8004145C_0; cmpwi 3,0; bne 2f; lwz 3,0x0(31); lwz 9,0x18(3); lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 1f; lwz 9,0xc8(30); mr 4,31; lwz 5,0x1c(9); lwz 3,0x4(9); bl _s8004145C_1; mr. 3,3; li 0,0; beq 0f; addi 0,3,800; 0:; lwz 9,0x0(31); stw 0,0x10(9); b 2f; 1:; lwz 11,0x0(31); lwz 9,0x18(11); lwz 0,0x9c(9); lha 3,0x98(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x320(3); addi 3,3,800; lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8004145C_0();
extern "C" void _s8004145C_1();
extern "C" void f_8004145C() {}
