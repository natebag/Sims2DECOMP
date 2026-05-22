// 0x803266A8 EResourceManager::PrintResourceSizes(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; li 4,-1; stw 30,0x8(1); lwz 9,0x0(30); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,30,3; blrl; lwz 4,0x40(30); addi 3,30,3336; bl _s803266A8_0; lwz 11,0x8(1); lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s803266A8_0();
extern "C" void f_803266A8() {}
