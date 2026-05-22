// 0x80246138 CasEventStoreSim::Log(void) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_80246184" lines="beq 0f; addi 0,9,1; stb 0,0x0(29); 0:; lbz 9,0x0(29); lwz 11,0x8(29); extsb 0,9; addi 9,9,2; rlwinm 0,0,2,0,29; stb 9,0x0(29); add 3,11,0"
extern "C" void f_80246184();
extern "C" void f_80246138() {}
