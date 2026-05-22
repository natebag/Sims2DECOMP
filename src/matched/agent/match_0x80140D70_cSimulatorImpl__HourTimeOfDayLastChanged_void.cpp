// 0x80140D70 cSimulatorImpl::HourTimeOfDayLastChanged(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 0,0x1c(3); cmpwi 0,1; beq 3f; bgt 0f; cmpwi 0,0; beq 4f; b 5f; 0:; cmpwi 0,2; beq 1f; cmpwi 0,3; beq 2f; b 5f; 1:; li 3,19; blr; 2:; li 3,6; blr; 3:; li 3,18; blr; 4:; li 3,7; blr; 5:; li 3,-1"
extern "C" int f_80140D70() {}
