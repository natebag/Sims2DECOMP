// 0x800D2BEC MemoryCardCache::Destroy(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x4(31); cmpwi 0,0; beq 3f; lwz 9,0x18(31); li 29,0; lwz 0,0xc(9); cmpw 29,0; bge 2f; li 28,0; li 30,0; 0:; lwz 9,0x4(31); lwzx 0,30,9; cmpwi 0,0; beq 1f; bl _s800D2BEC_0; lwz 9,0x4(31); lwzx 4,30,9; bl _s800D2BEC_1; lwz 9,0x4(31); stwx 28,30,9; 1:; lwz 9,0x18(31); addi 29,29,1; addi 30,30,4; lwz 0,0xc(9); cmpw 29,0; blt 0b; 2:; bl _s800D2BEC_2; lwz 4,0x4(31); bl _s800D2BEC_3; li 0,0; stw 0,0x4(31); 3:; lwz 0,0x0(31); cmpwi 0,0; beq 4f; bl _s800D2BEC_4; lwz 4,0x0(31); bl _s800D2BEC_5; li 0,0; stw 0,0x0(31); 4:; li 0,0; stw 0,0x10(31); stw 0,0x8(31); stw 0,0xc(31); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800D2BEC_0();
extern "C" void _s800D2BEC_1();
extern "C" void _s800D2BEC_2();
extern "C" void _s800D2BEC_3();
extern "C" void _s800D2BEC_4();
extern "C" void _s800D2BEC_5();
extern "C" void f_800D2BEC() {}
