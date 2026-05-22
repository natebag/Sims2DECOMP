// 0x8017D10C UIQDTarget::UIQDRemoveEmbeddedControl(unsigned (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 22,0x8(1); stw 0,0x34(1); mr 27,3; li 24,0; bl _s8017D10C_0; mr 23,3; li 4,60; mr 3,27; bl _s8017D10C_1; cmpwi 3,0; beq 8f; bl _s8017D10C_2; li 30,0; li 4,8192; li 5,0; bl _s8017D10C_3; li 25,0; mr 26,3; li 22,0; mr 28,26; 0:; add 31,30,30; lhzx 9,31,27; add 29,31,27; rlwinm 0,9,0,16,31; cmpwi 0,60; bne 3f; mr 3,29; li 4,62; bl _s8017D10C_4; cmpwi 3,0; beq 5f; lhzx 0,31,27; cmpwi 0,62; beq 2f; mr 3,29; 1:; lhzu 0,0x2(3); addi 30,30,1; cmpwi 0,62; bne 1b; 2:; addi 30,30,1; li 24,1; b 5f; 3:; cmpwi 0,0; bne 4f; sth 9,0x0(28); addi 30,30,1; addi 28,28,2; li 25,1; b 5f; 4:; sth 9,0x0(28); addi 30,30,1; sthu 22,0x2(28); 5:; cmpwi 25,0; bne 6f; cmpw 30,23; blt 0b; 6:; cmpwi 24,0; beq 7f; mr 3,27; mr 4,26; bl _s8017D10C_5; mr 3,27; bl _s8017D10C_6; 7:; bl _s8017D10C_7; mr 4,26; bl _s8017D10C_8; 8:; mr 3,24; lwz 0,0x34(1); mtspr 8,0; lmw 22,0x8(1); addi 1,1,48"
extern "C" void _s8017D10C_0();
extern "C" void _s8017D10C_1();
extern "C" void _s8017D10C_2();
extern "C" void _s8017D10C_3();
extern "C" void _s8017D10C_4();
extern "C" void _s8017D10C_5();
extern "C" void _s8017D10C_6();
extern "C" void _s8017D10C_7();
extern "C" void _s8017D10C_8();
extern "C" void f_8017D10C() {}
