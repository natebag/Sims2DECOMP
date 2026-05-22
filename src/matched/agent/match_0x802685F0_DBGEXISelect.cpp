// 0x802685F0 DBGEXISelect (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-13312; addi 4,4,26624; lwz 5,0x28(4); rlwinm 0,3,4,0,27; ori 0,0,128; andi. 5,5,1029; li 3,1; or 5,5,0; stw 5,0x28(4)"
extern "C" void f_802685F0() {}
