// 0x800A5FA4 MemFile::MemFile(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 30,3; addi 9,9,-6928; stw 9,0x124(30); addi 4,30,8; li 5,260; bl _s800A5FA4_0; li 0,0; mr 3,30; stw 0,0x118(30); stw 0,0x110(30); stw 0,0x10c(30); stw 0,0x114(30); stw 0,0x120(30); stw 0,0x11c(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800A5FA4_0();
extern "C" void f_800A5FA4() {}
