// 0x802C94C4 EMat4::GetColumn(int, (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; addi 9,3,16; lfsx f0,3,4; addi 11,3,32; addi 3,3,48; stfs f0,0x0(5); lfsx f0,9,4; stfs f0,0x4(5); lfsx f13,11,4; stfs f13,0x8(5); lfsx f0,3,4; stfs f0,0xc(5)"
extern "C" void f_802C94C4() {}
