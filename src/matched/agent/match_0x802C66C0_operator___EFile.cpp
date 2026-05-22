// 0x802C66C0 operator>>(EFile (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 28,0x48(1); stw 0,0x5c(1); mr 28,4; mr 29,3; mr 3,28; li 30,0; bl _s802C66C0_0; addi 31,1,8; b 1f; 0:; cmpwi 30,62; addi 30,30,1; bne 1f; li 0,0; mr 3,28; stb 0,0x47(1); mr 4,31; bl _s802C66C0_1; li 30,0; 1:; lwz 9,0x28(29); add 4,31,30; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,29,3; blrl; lbzx 0,31,30; cmpwi 0,0; bne 0b; mr 3,28; addi 4,1,8; bl _s802C66C0_2; mr 3,29; lwz 0,0x5c(1); mtspr 8,0; lmw 28,0x48(1); addi 1,1,88"
extern "C" void _s802C66C0_0();
extern "C" void _s802C66C0_1();
extern "C" void _s802C66C0_2();
extern "C" void f_802C66C0() {}
