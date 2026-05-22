// 0x801622F4 CasMediator::SetControllerFilterId(unsigned (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 5,1; bgtlr; rlwinm 0,5,2,0,29; addi 9,3,32; stwx 4,9,0"
extern "C" void f_801622F4() {}
