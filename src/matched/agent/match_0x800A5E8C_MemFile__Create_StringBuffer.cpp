// 0x800A5E8C MemFile::Create(StringBuffer (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; bl _s800A5E8C_0; cmpwi 3,0; beq 0f; li 3,-47; b 2f; 0:; lis 9,-32688; mr 3,31; addi 30,9,-1852; bl _s800A5E8C_1; mr 4,3; mr 3,30; bl _s800A5E8C_2; cmpwi 3,0; bne 1f; mr 3,31; bl _s800A5E8C_3; mr 4,3; mr 3,30; bl _s800A5E8C_4; cmpwi 3,0; li 3,-42; beq 2f; li 3,0; b 2f; 1:; li 3,-43; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800A5E8C_0();
extern "C" void _s800A5E8C_1();
extern "C" void _s800A5E8C_2();
extern "C" void _s800A5E8C_3();
extern "C" void _s800A5E8C_4();
extern "C" void f_800A5E8C() {}
