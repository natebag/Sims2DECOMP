// 0x800D37C8 MemoryCardCache::PutConfig(char (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 0,0x10(31); mr 30,5; cmpwi 0,0; bne 0f; li 3,1; b 2f; 0:; lwz 0,0x0(31); cmpwi 0,0; bne 1f; bl _s800D37C8_0; li 4,8192; li 5,64; li 6,0; li 7,0; bl _s800D37C8_1; cmpwi 3,0; stw 3,0x0(31); li 3,2; beq 2f; 1:; lwz 3,0x0(31); mr 4,29; mr 5,30; crxor 6,6,6; bl _s800D37C8_2; li 0,1; li 3,0; stw 0,0xc(31); 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800D37C8_0();
extern "C" void _s800D37C8_1();
extern "C" void _s800D37C8_2();
extern "C" void f_800D37C8() {}
