// 0x80140D28 cSimulatorImpl::ComputeTimeOfDay(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 0,0x14(3); cmpwi 0,5; bgt 0f; li 3,2; blr; 0:; cmpwi 0,6; bgt 1f; li 3,3; blr; 1:; cmpwi 0,17; bgt 2f; li 3,0; blr; 2:; cmpwi 0,18; li 3,2; bgtlr; li 3,1"
extern "C" int f_80140D28() {}
