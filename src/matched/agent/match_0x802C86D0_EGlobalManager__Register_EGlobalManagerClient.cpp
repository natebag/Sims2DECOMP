// 0x802C86D0 EGlobalManager::Register(EGlobalManagerClient (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 8,13,-26872; lis 11,-32688; lwz 10,0x0(8); addi 11,11,-12960; rlwinm 9,10,3,0,28; stwx 3,9,11; addi 10,10,1; add 9,9,11; stw 4,0x4(9); stw 10,0x0(8)"
extern "C" void f_802C86D0() {}
