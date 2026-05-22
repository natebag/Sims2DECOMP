// 0x800A6930 StringBuffer::charAt(int) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr. 30,4; blt 0f; bl _s800A6930_0; cmpw 30,3; bge 0f; mr 3,31; bl _s800A6930_1; lbzx 3,3,30; extsb 3,3; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800A6930_0();
extern "C" void _s800A6930_1();
extern "C" void f_800A6930() {}
