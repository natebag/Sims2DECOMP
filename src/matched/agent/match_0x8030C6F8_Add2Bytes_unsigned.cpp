// 0x8030C6F8 Add2Bytes(unsigned (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,4,8,16,23; lwz 11,0x0(3); rlwinm 4,4,24,8,31; or 0,0,4; stw 0,0x0(11); lwz 9,0x0(3); addi 9,9,2; stw 9,0x0(3)"
extern "C" void f_8030C6F8() {}
