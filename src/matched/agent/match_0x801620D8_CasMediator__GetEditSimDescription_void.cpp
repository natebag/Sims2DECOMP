// 0x801620D8 CasMediator::GetEditSimDescription(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x10(3); cmpwi 3,0; bne 0f; li 3,0; blr; 0:; addi 3,3,8"
extern "C" int f_801620D8() {}
