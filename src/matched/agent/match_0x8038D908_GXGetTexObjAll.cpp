// 0x8038D908 GXGetTexObjAll (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc(3); rlwinm 0,0,5,6,26; stw 0,0x0(4); lwz 0,0x8(3); rlwinm 4,0,0,22,31; addi 0,4,1; sth 0,0x0(5); lwz 0,0x8(3); rlwinm 4,0,22,22,31; addi 0,4,1; sth 0,0x0(6); lwz 0,0x14(3); stw 0,0x0(7); lwz 0,0x0(3); rlwinm 0,0,0,30,31; stw 0,0x0(8); lwz 0,0x0(3); rlwinm 0,0,30,30,31; stw 0,0x0(9); lbz 0,0x1f(3); rlwinm 3,0,0,31,31; addi 0,3,-1; cntlzw 0,0; rlwinm 0,0,27,24,31; stb 0,0x0(10)"
extern "C" void f_8038D908() {}
