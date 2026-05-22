// 0x8038E8D4 __GXGetSUTexSize (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-17720(13); rlwinm 3,3,2,0,29; add 6,0,3; lwz 0,0xb8(6); rlwinm 3,0,0,16,31; addi 0,3,1; sth 0,0x0(4); lwz 0,0xd8(6); rlwinm 3,0,0,16,31; addi 0,3,1; sth 0,0x0(5)"
extern "C" void f_8038E8D4() {}
