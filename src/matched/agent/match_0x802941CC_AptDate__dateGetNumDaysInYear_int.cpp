// 0x802941CC AptDate::dateGetNumDaysInYear(int) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s802941CC_0; cmpwi 3,0; li 3,365; beq 0f; li 3,366; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802941CC_0();
extern "C" void f_802941CC() {}
