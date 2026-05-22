// 0x800B44C8 CTilePt::GetEVec3M(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); stmw 30,0x10(1); lbz 0,0x1(4); lbz 9,0x0(4); lis 30,17200; extsb 0,0; mr 7,8; xori 0,0,32768; extsb 9,9; stw 0,0xc(1); xori 9,9,32768; lbz 11,0x2(4); lis 5,-32706; stw 30,0x8(1); mr 6,8; extsb 11,11; lfd f12,-26448(5); lfd f0,0x8(1); xori 11,11,32768; stw 9,0xc(1); mr 10,3; fsub f0,f0,f12; stw 30,0x8(1); frsp f0,f0; stfs f0,0x0(10); lfd f13,0x8(1); stw 11,0xc(1); fsub f13,f13,f12; stw 30,0x8(1); frsp f13,f13; stfs f13,0x4(10); lfd f0,0x8(1); fsub f0,f0,f12; frsp f0,f0; stfs f0,0x8(10); lmw 30,0x10(1); addi 1,1,24"
extern "C" void f_800B44C8() {}
