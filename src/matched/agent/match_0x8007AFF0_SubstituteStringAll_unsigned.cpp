// 0x8007AFF0 SubstituteStringAll(unsigned (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 28,4; mr 31,6; mr 4,3; mr 29,5; addi 3,1,8; li 30,0; bl _s8007AFF0_0; li 4,0; li 5,-1; mr 3,31; bl _s8007AFF0_1; mr 3,31; addi 4,1,8; li 5,0; li 6,-1; bl _s8007AFF0_2; 0:; mr 3,31; bl _s8007AFF0_3; mr 4,28; mr 5,29; mr 6,31; bl _s8007AFF0_4; cmpwi 30,0; bne 1f; cmpwi 3,0; beq 2f; li 30,1; 1:; cmpwi 3,0; bne 0b; 2:; addi 3,1,8; li 4,2; bl _s8007AFF0_5; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8007AFF0_0();
extern "C" void _s8007AFF0_1();
extern "C" void _s8007AFF0_2();
extern "C" void _s8007AFF0_3();
extern "C" void _s8007AFF0_4();
extern "C" void _s8007AFF0_5();
extern "C" void f_8007AFF0() {}
