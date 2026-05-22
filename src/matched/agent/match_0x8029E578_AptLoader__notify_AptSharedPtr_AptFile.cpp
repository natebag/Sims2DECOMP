// 0x8029E578 AptLoader::notify(AptSharedPtr<AptFile>) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,4; addi 30,1,8; lwz 3,0x0(31); stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s8029E578_0; 0:; mr 3,30; bl _s8029E578_1; lwz 3,0x0(31); cmpwi 3,0; beq 1f; bl _s8029E578_2; cmpwi 3,0; bne 1f; lwz 3,0x0(31); bl _s8029E578_3; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8029E578_0();
extern "C" void _s8029E578_1();
extern "C" void _s8029E578_2();
extern "C" void _s8029E578_3();
extern "C" void f_8029E578() {}
