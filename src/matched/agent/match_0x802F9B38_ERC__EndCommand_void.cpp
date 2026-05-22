// 0x802F9B38 ERC::EndCommand(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 9,0x18(3); li 0,1; stw 0,0x14(3); addi 9,9,-1; stb 9,0x18(3)"
extern "C" void f_802F9B38() {}
