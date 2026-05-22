// 0x801C1CEC InteractionList::InteractionList(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" int f_801C1CEC() {}
