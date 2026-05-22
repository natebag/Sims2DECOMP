// 0x80140924 cSimulatorImpl::CommitPendingFunds(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x78(3); cmpwi 11,0; beqlr; lwz 0,0x74(3); lis 9,15; ori 9,9,16959; add 0,0,11; cmpw 0,9; stw 0,0x74(3); ble 0f; stw 9,0x74(3); 0:; li 0,0; stw 0,0x78(3)"
extern "C" void f_80140924() {}
