// 0x8038DF8C GXInitTexPreLoadRegion (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 9,0; stw 9,0x0(3); rlwinm 0,4,27,5,31; li 8,1; lwz 4,0x0(3); rlwimi 4,0,0,17,31; stw 4,0x0(3); rlwinm 4,5,27,16,31; lwz 0,0x0(3); rlwimi 0,9,15,14,16; stw 0,0x0(3); rlwinm 0,7,27,16,31; lwz 5,0x0(3); rlwimi 5,9,18,11,13; stw 5,0x0(3); lwz 5,0x0(3); rlwimi 5,8,21,10,10; stw 5,0x0(3); stw 9,0x4(3); lwz 5,0x4(3); rlwimi 5,6,27,17,31; stw 5,0x4(3); lwz 5,0x4(3); rlwimi 5,9,15,14,16; stw 5,0x4(3); lwz 5,0x4(3); rlwimi 5,9,18,11,13; stw 5,0x4(3); stb 9,0xc(3); stb 9,0xd(3); sth 4,0x8(3); sth 0,0xa(3)"
extern "C" void f_8038DF8C() {}
