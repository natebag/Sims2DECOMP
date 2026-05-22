// 0x800A7080 StringBuffer2::charAt(int) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr. 31,4; blt 0f; bl _s800A7080_0; cmpw 31,3; bge 0f; mr 3,30; bl _s800A7080_1; add 0,31,31; lhzx 3,3,0; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800A7080_0();
extern "C" void _s800A7080_1();
extern "C" void f_800A7080() {}
