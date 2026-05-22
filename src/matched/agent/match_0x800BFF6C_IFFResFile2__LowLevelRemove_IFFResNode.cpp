// 0x800BFF6C IFFResFile2::LowLevelRemove(IFFResNode (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; lwz 4,0x0(30); cmpwi 4,-1; beq 0f; bl _s800BFF6C_0; mr. 3,3; bne 3f; 0:; lwz 31,0xc(30); cmpwi 31,0; beq 2f; lwz 0,0x8(31); cmpwi 0,0; beq 1f; bl _s800BFF6C_1; lwz 4,0x4(31); bl _s800BFF6C_2; 1:; bl _s800BFF6C_3; mr 4,31; bl _s800BFF6C_4; 2:; li 0,0; li 3,0; stw 0,0xc(30); 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800BFF6C_0();
extern "C" void _s800BFF6C_1();
extern "C" void _s800BFF6C_2();
extern "C" void _s800BFF6C_3();
extern "C" void _s800BFF6C_4();
extern "C" void f_800BFF6C() {}
