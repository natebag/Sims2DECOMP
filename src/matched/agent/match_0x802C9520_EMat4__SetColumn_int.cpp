// 0x802C9520 EMat4::SetColumn(int, (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x0(5); rlwinm 4,4,2,0,29; addi 9,3,16; addi 11,3,32; stfsx f0,3,4; addi 3,3,48; lfs f0,0x4(5); stfsx f0,9,4; lfs f13,0x8(5); stfsx f13,11,4; lfs f0,0xc(5); stfsx f0,3,4"
extern "C" void f_802C9520() {}
