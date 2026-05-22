// 0x800A6174 MemFile::Close(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; bl _s800A6174_0; lwz 0,0x114(31); cmpwi 0,0; beq 1f; lwz 0,0x10c(31); cmpwi 0,0; beq 0f; lwz 0,0x110(31); cmpwi 0,0; beq 0f; mr 3,31; bl _s800A6174_1; 0:; bl _s800A6174_2; lwz 4,0x114(31); bl _s800A6174_3; li 0,0; stw 0,0x114(31); b 2f; 1:; li 30,-49; 2:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800A6174_0();
extern "C" void _s800A6174_1();
extern "C" void _s800A6174_2();
extern "C" void _s800A6174_3();
extern "C" void f_800A6174() {}
