// 0x80141324 cSimulatorImpl::IsPausedAtAll(void) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x98(3); cmpwi 0,0; beq 0f; li 3,1; blr; 0:; lha 0,0x36(3); li 3,1; cmpwi 0,0; bnelr; li 3,0"
extern "C" int f_80141324() {}
