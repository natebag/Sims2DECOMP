// 0x802A9888 AptNativeHash::AptNativeHash(int) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; addi 9,4,-1; stw 0,0x10(3); and. 11,4,9; stw 4,0x0(3); stw 0,0x4(3); stw 0,0x8(3); stw 0,0xc(3); beqlr; li 0,1; cmpw 0,4; bge 1f; 0:; rlwinm 0,0,1,0,30; cmpw 0,4; blt 0b; 1:; stw 0,0x0(3)"
extern "C" void f_802A9888() {}
