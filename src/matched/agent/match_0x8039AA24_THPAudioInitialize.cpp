// 0x8039AA24 __THPAudioInitialize (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x0(3); li 0,2; stw 0,0x4(3); lwz 4,0x0(3); lbz 0,0x0(4); rlwinm 0,0,28,29,31; stb 0,0x8(3); lwz 4,0x0(3); lbz 0,0x0(4); rlwinm 0,0,0,28,31; stb 0,0x9(3); lwz 4,0x0(3); addi 0,4,1; stw 0,0x0(3)"
extern "C" void f_8039AA24() {}
