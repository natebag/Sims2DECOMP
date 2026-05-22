// 0x80269614 AptIsFileLoaded(AptSharedPtr<AptFile>) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; lwz 9,0x0(31); li 0,1; cmpwi 9,0; bne 0f; li 0,0; 0:; cmpwi 0,0; beq 1f; lwz 0,0x8(9); cmpwi 0,4; bne 1f; li 30,1; 1:; lwz 3,0x0(31); cmpwi 3,0; beq 2f; bl _s80269614_0; cmpwi 3,0; bne 2f; lwz 3,0x0(31); bl _s80269614_1; 2:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80269614_0();
extern "C" void _s80269614_1();
extern "C" void f_80269614() {}
