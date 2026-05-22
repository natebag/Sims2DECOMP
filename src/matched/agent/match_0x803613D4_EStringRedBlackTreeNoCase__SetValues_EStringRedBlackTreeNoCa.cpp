// 0x803613D4 EStringRedBlackTreeNoCase::SetValues(EStringRedBlackTreeNoCase (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; mfcr 12; stmw 30,0x10(1); stw 0,0x1c(1); stw 12,0xc(1); lwz 31,0x0(4); mr 30,3; cmpwi 4,5,0; b 3f; 0:; lwz 5,0x18(31); beq cr4,1f; lwz 4,0x1c(31); mr 3,30; bl _s803613D4_0; b 2f; 1:; lwz 4,0x1c(31); bl _s803613D4_1; 2:; lwz 31,0x10(31); 3:; mr 3,30; li 6,1; li 0,1; cmpwi 31,0; bne 4f; li 0,0; 4:; cmpwi 0,0; bne 0b; lwz 0,0x1c(1); lwz 12,0xc(1); mtspr 8,0; lmw 30,0x10(1); mtcrf 8,12; addi 1,1,24"
extern "C" void _s803613D4_0();
extern "C" void _s803613D4_1();
extern "C" void f_803613D4() {}
