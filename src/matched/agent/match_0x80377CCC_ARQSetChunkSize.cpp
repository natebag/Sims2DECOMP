// 0x80377CCC ARQSetChunkSize (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm. 0,3,0,27,31; beq 0f; subfic 0,0,32; add 0,3,0; stw 0,-22296(13); blr; 0:; stw 3,-22296(13)"
extern "C" void f_80377CCC() {}
