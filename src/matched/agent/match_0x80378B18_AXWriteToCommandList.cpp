// 0x80378B18 __AXWriteToCommandList (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-22220(13); sth 3,0x0(4); lwz 3,-22220(13); addi 0,3,2; stw 0,-22220(13)"
extern "C" void f_80378B18() {}
